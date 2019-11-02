cmake_minimum_required (VERSION 3.10)
project(ShatNet CXX)

set (VERSION_MAJOR 0)
set (VERSION_MINOR 0)
set (VERSION_PATCH 1)
set(CMAKE_CXX_STANDARD 17)


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/win32 WINDOWS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/unix LINUX)

add_executable(Linux ShatNet.cxx ${SRC} ${UNIX})
target_compile_definitions(Linux PUBLIC -D POSIX)
target_compile_options(Linux PUBLIC -pthread)


add_executable(Windows ShatNet.cxx ${SRC} ${WINDOWS})
target_compile_definitions(Windows PUBLIC -D WIN32)
target_link_libraries(Windows PUBLIC WS2_32.lib)



