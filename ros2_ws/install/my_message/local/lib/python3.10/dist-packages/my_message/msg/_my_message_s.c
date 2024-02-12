// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_message:msg/MyMessage.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "my_message/msg/detail/my_message__struct.h"
#include "my_message/msg/detail/my_message__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_message__msg__my_message__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("my_message.msg._my_message.MyMessage", full_classname_dest, 36) == 0);
  }
  my_message__msg__MyMessage * ros_message = _ros_message;
  {  // ice
    PyObject * field = PyObject_GetAttrString(_pymsg, "ice");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ice = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // prad
    PyObject * field = PyObject_GetAttrString(_pymsg, "prad");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->prad = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_message__msg__my_message__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MyMessage */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_message.msg._my_message");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MyMessage");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_message__msg__MyMessage * ros_message = (my_message__msg__MyMessage *)raw_ros_message;
  {  // ice
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ice);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ice", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // prad
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->prad);
    {
      int rc = PyObject_SetAttrString(_pymessage, "prad", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
