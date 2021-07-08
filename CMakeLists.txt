cmake_minimum_required( VERSION 3.17 )

project( Numbers )

set( CMAKE_CXX_STANDARD          17  )
set( CMAKE_CXX_STANDARD_REQUIRED ON  )
set( CMAKE_CXX_EXTENSIONS        OFF )

set( HEADER_FILES
     intX_t.h
     intXu_t.h
   )

add_executable( demo
                demo.cpp
                ${HEADER_FILES}
              )

add_executable( nt
                nt.cpp
                ${HEADER_FILES}
              )

