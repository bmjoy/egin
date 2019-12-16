cmake_minimum_required(VERSION 3.1)
project(egin)

set(CMAKE_CXX_STANDARD 11)
include("egin.cmake")
include_egin()

file(GLOB EGIN_SRC
  ${EGIN_DIR}/src/ai/*.cpp
  ${EGIN_DIR}/src/animation/*.cpp
  ${EGIN_DIR}/src/audio/*.cpp
  ${EGIN_DIR}/src/core/*.cpp
  ${EGIN_DIR}/src/events/*.cpp
  ${EGIN_DIR}/src/graphics/*.cpp
  ${EGIN_DIR}/src/input/*.cpp
  ${EGIN_DIR}/src/math/*.cpp
  ${EGIN_DIR}/src/physics/*.cpp
  ${EGIN_DIR}/src/renderer/*.cpp
  ${EGIN_DIR}/src/sparkparticles/*.cpp
  ${EGIN_DIR}/src/ui/*.cpp
  ${EGIN_DIR}/src/editor/*.cpp
)

add_library(egin STATIC ${EGIN_SRC})
