cmake_minimum_required(VERSION 2.8)

project(kepler90)

set (CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(kepler90
    src/main.cpp
    src/Object.cpp
    src/Vec3.cpp
    src/Sphere.cpp
    src/Cube.cpp
)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(kepler90 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )