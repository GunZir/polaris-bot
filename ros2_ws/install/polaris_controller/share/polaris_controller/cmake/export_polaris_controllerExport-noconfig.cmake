#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "polaris_controller::polaris_controller" for configuration ""
set_property(TARGET polaris_controller::polaris_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(polaris_controller::polaris_controller PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpolaris_controller.so"
  IMPORTED_SONAME_NOCONFIG "libpolaris_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS polaris_controller::polaris_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_polaris_controller::polaris_controller "${_IMPORT_PREFIX}/lib/libpolaris_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
