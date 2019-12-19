add_definitions(-DGP_NO_LUA_BINDINGS)

set(EGIN_DIR ${CMAKE_CURRENT_LIST_DIR})
message("EGIN DIR: ${EGIN_DIR}")

function(include_egin)
  include_directories(
    ${EGIN_DIR}/src
    ${EGIN_DIR}/thirdparty/bullet/src
    ${EGIN_DIR}/thirdparty/openal/include
    ${EGIN_DIR}/thirdparty/vorbis/include
    ${EGIN_DIR}/thirdparty/ogg/include
    ${EGIN_DIR}/thirdparty/lua/src
    ${EGIN_DIR}/thirdparty/bgfx-cmake/bgfx/include
    ${EGIN_DIR}/thirdparty/bgfx-cmake/bimg/include
    ${EGIN_DIR}/thirdparty/bgfx-cmake/bx/include
    ${EGIN_DIR}/thirdparty/bgfx-cmake
    ${EGIN_DIR}/thirdparty/SDL2/include
    ${EGIN_DIR}/thirdparty/efsw/include
    ${EGIN_DIR}/thirdparty/spark/spark/include
    ${EGIN_DIR}/thirdparty/bgfx-cmake/bgfx/3rdparty
    ${EGIN_DIR}/thirdparty/imgui
    ${EGIN_DIR}/thirdparty/glm
  )

  if(WINDOWS)
    include_directories(${EGIN_DIR}/thirdparty/bx/compat/msvc)
  endif()

  link_directories(${EGIN_DIR}/build/Debug)
  link_directories(${EGIN_DIR}/output/lib)
  link_directories(${EGIN_DIR}/thirdparty/lib)
endfunction(include_egin)

function(link_egin target)
  target_link_libraries(
    ${target}
    egin
    gplay-deps          
    opengl32
    kernel32
    user32
    winmm
    gdi32
    winspool
    comdlg32
    advapi32
    shell32
    imm32
    ole32
    oleaut32
    uuid
    version
    odbc32
    odbccp32
  )
endfunction(link_egin)