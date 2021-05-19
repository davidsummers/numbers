cmake_minimum_required( VERSION 3.17 )

project( Numbers )

set( CMAKE_CXX_STANDARD          11  )
set( CMAKE_CXX_STANDARD_REQUIRED ON  )
set( CMAKE_CXX_EXTENSIONS        OFF )

set( SOURCE_FILES
     nt.cpp
     int8_t.cpp
   )

set( HEADER_FILES
     int8_t.h
   )

add_executable( nt
                ${SOURCE_FILES}
                ${HEADER_FILES}
              )

