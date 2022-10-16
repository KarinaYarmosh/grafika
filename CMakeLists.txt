cmake_minimum_required(VERSION 3.21)
project(untitled2)
find_package(OpenGL REQUIRED)
find_package(FREEGLUT REQUIRED)
#find_package(GLFW REQUIRED)

add_executable(untitled2 src/main.cpp)
target_include_directories(untitled2 PUBLIC include)
include_directories(include shaders/)

target_link_libraries(untitled2 ${OPENGL_LIBRARIES})
target_link_libraries(untitled2 ${FREEGLUT_LIBRARIES})
target_link_libraries(untitled2 -lopengl32 -g -lfreeglut -lglew32 -lglu32 -lglfw3)
