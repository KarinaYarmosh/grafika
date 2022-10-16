cmake_minimum_required(VERSION 3.21)
project(grafika_komputerowa)
find_package(OpenGL REQUIRED)
find_package(FREEGLUT REQUIRED)
#find_package(GLFW REQUIRED)

add_executable(grafika_komputerowa src/main.cpp)
#target_include_directories(grafika_komputerowa PUBLIC include)
include_directories(include shaders/)

target_link_libraries(grafika_komputerowa ${OPENGL_LIBRARIES})
target_link_libraries(grafika_komputerowa ${FREEGLUT_LIBRARIES})
target_link_libraries(grafika_komputerowa -lopengl32 -g -lfreeglut -lglew32 -lglu32 -lglfw3)
