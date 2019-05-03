cmake_minimum_required(VERSION 3.13)
project(Majcraft2)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set (GLEW_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../openGLtest/Librairies/glew/include)
set (GLEW_LIBRARY ${PROJECT_SOURCE_DIR}/../openGLtest/Librairies/glew/lib/libglew32.a)
set (Boost_Path "C:/boost_1_70_0")
set (BOOST_INCLUDEDIR "${Boost_Path}")

find_package(Boost 1.70.0)

if(Boost_FOUND)
    message(STATUS "It works!")
    include_directories(${BOOST_INCLUDEDIR})
endif()

add_subdirectory("openGLtest/Librairies/glfw")
add_subdirectory("openGLtest/Librairies/glew/build/cmake")

include_directories(
        "openGLtest/Librairies/glfw/include"
        "openGLtest/Librairies/glew/include"
        "openGLtest/Librairies/glm"
)

set(SOURCE_FILES openGLtest/main.cpp openGLtest/shader.hpp openGLtest/ObjLoader.h openGLtest/stb_image.h openGLtest/stb_image.cpp openGLtest/Object.hpp openGLtest/DisplayManager.hpp openGLtest/camera.hpp)

add_executable(Majcraft2 ${SOURCE_FILES})

target_link_libraries(
        Majcraft2
        glfw ${GLFW_LIBRAIRIES}
        glew ${GLEW_LIBRAIRIES}
        ${OPENGL_LIBRAIRIES}
)