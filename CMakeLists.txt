cmake_minimum_required( VERSION 3.17 )

project( Numbers )

set( CMAKE_CXX_STANDARD          17  )
set( CMAKE_CXX_STANDARD_REQUIRED ON  )
set( CMAKE_CXX_EXTENSIONS        OFF )

set( SOURCE_FILES
     nt.cpp
   )

set( HEADER_FILES
     intX_t.h
     intXu_t.h
   )

add_executable( nt
                ${SOURCE_FILES}
                ${HEADER_FILES}
              )

