cmake_minimum_required(VERSION 3.1)
project(egin)

set(CMAKE_CXX_STANDARD 11)
include(${CMAKE_CURRENT_LIST_DIR}/egin.cmake)
include_egin()

file(GLOB EGIN_SRC
  ${EGIN_DIR}/src/core/*.cpp
  ${EGIN_DIR}/src/interfaces/*.cpp
  ${EGIN_DIR}/src/math/*.cpp
  ${EGIN_DIR}/src/renderer/*.cpp
)

add_library(egin STATIC ${EGIN_SRC})
