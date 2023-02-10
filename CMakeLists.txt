cmake_minimum_required(VERSION 3.24)
project(Limerence)

set(CMAKE_CXX_STANDARD 17)

add_executable(Limerence src/engine.cpp src/core/window.cpp src/math/vector2.cpp src/math/transform.h src/math/raycast.cpp src/render/shader.h src/render/shader.cpp src/render/vertexbuffer.h src/render/vertexarray.h)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(Limerence glfw OpenGL::GL GLEW::GLEW)


