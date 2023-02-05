cmake_minimum_required(VERSION 3.24)
project(Limerence)

set(CMAKE_CXX_STANDARD 17)

add_executable(Limerence src/engine.cpp src/render/window.cpp src/math/vector2.cpp)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(Limerence glfw OpenGL::GL GLEW::GLEW)


