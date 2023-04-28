#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "websockets-evlib_uv" for configuration "Release"
set_property(TARGET websockets-evlib_uv APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(websockets-evlib_uv PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libwebsockets-evlib_uv.so"
  IMPORTED_SONAME_RELEASE "libwebsockets-evlib_uv.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS websockets-evlib_uv )
list(APPEND _IMPORT_CHECK_FILES_FOR_websockets-evlib_uv "${_IMPORT_PREFIX}/lib/libwebsockets-evlib_uv.so" )

# Import target "websockets_shared" for configuration "Release"
set_property(TARGET websockets_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(websockets_shared PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libwebsockets.so.19"
  IMPORTED_SONAME_RELEASE "libwebsockets.so.19"
  )

list(APPEND _IMPORT_CHECK_TARGETS websockets_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_websockets_shared "${_IMPORT_PREFIX}/lib/libwebsockets.so.19" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
