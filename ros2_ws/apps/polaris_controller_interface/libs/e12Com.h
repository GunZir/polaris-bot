#ifndef E12COM
#define E12COM
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "lwip/igmp.h"

#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "soc/rtc_periph.h"
#include "driver/spi_slave.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

#define GPIO_HANDSHAKE 2
#define GPIO_MOSI 13
#define GPIO_MISO 12
#define GPIO_SCLK 14
#define GPIO_CS 15

#ifdef CONFIG_IDF_TARGET_ESP32
#define RCV_HOST    HSPI_HOST
#define DMA_CHAN    2

#elif defined CONFIG_IDF_TARGET_ESP32S2
#define RCV_HOST    SPI2_HOST
#define DMA_CHAN    RCV_HOST

#endif


typedef struct commonFrame {
  int64_t encoderA;
  int64_t encoderB;
  uint64_t epoch;
  float speedA;
  float speedB;
  float kp;
  float ki;
  float kd;
  uint32_t powerOn;
  uint32_t doOpenLoop;
  uint32_t encoderFaultA;
  uint32_t encoderFaultB;
  int16_t pwmA;
  int16_t pwmB;
  int16_t currentPWMA;
  int16_t currentPWMB;
}commonFrame;

uint64_t prevMicros = 0;

esp_err_t ret;


WORD_ALIGNED_ATTR commonFrame dataESP2STM = {
    .powerOn = 1,
    .kp = 2.05,
    .ki = 9,
    .kd = 0.0005,
    .doOpenLoop = 0,
    .speedA = 0,
};
WORD_ALIGNED_ATTR commonFrame dataSTM2ESP = {
    .speedA = 0,
    .doOpenLoop = 0,
};
spi_slave_transaction_t t = {
        .length = sizeof(commonFrame)*8,
        //.trans_len = sizeof(commonFrame)*8,
        .tx_buffer = (void*)(&dataESP2STM),
        .rx_buffer = (void*)(&dataSTM2ESP),
};

void my_post_setup_cb(spi_slave_transaction_t *trans) {
    //WRITE_PERI_REG(GPIO_OUT_W1TS_REG, (1<<GPIO_HANDSHAKE));
}

//Called after transaction is sent/received. We use this to set the handshake line low.
void my_post_trans_cb(spi_slave_transaction_t *trans) {
    //printf("Transmitted");
}


void E12_init(){

    //Configuration for the SPI bus
    spi_bus_config_t buscfg={
        .mosi_io_num=GPIO_MOSI,
        .miso_io_num=GPIO_MISO,
        .sclk_io_num=GPIO_SCLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
    };

    //Configuration for the SPI slave interface
    spi_slave_interface_config_t slvcfg={
        .mode=0,
        .spics_io_num=GPIO_CS,
        .queue_size=3,
        .flags=0,
        .post_setup_cb=my_post_setup_cb,
        .post_trans_cb=my_post_trans_cb
    };

    //Configuration for the handshake line
    gpio_config_t io_conf={
        .intr_type=GPIO_INTR_DISABLE,
        .mode=GPIO_MODE_OUTPUT,
        .pin_bit_mask=(1<<GPIO_HANDSHAKE)
    };

    //Configure handshake line as output
    gpio_config(&io_conf);
    //Enable pull-ups on SPI lines so we don't detect rogue pulses when no master is connected.
    gpio_set_pull_mode(GPIO_MOSI, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_SCLK, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_CS, GPIO_PULLUP_ONLY);

    //Initialize SPI slave interface
    ret=spi_slave_initialize(RCV_HOST, &buscfg, &slvcfg, DMA_CHAN);
    assert(ret==ESP_OK);

    //memset(recvbuf, 0, 33);
    //memset(&t, 0, sizeof(t));
}

void E12_transmit(){
    t.length=sizeof(commonFrame)*8;
    t.tx_buffer=(void*)(&dataESP2STM);
    t.rx_buffer=(void*)(&dataSTM2ESP);
    ret=spi_slave_transmit(RCV_HOST, &t, portMAX_DELAY);
}

//Called after a transaction is queued and ready for pickup by master. We use this to set the handshake line high.


//COPY1 DN BOUNDED

//COPY2 BOUNDED



#endif