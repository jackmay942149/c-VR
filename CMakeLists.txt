cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set( SOURCEFILES
  ./src/main.c
  ./src/color.c
  ./src/file-manager.c
  ./src/renderer.c
  ./src/shader.c
  ./src/application.c
  ./src/object.c
  ./src/math/vector.c
  ./src/math/ray.c
  ./src/math/matrix.c
  ./src/data-structures/array.c
  ./src/data-structures/stack.c
  ./include/glad.c
)
project(c-VR VERSION 1.0)
include_directories(./include)
add_executable(c-VR ${SOURCEFILES})
target_link_directories(c-VR PRIVATE ./lib)
target_link_libraries(c-VR glfw3)
target_link_libraries(c-VR opengl32)
