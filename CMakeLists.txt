cmake_minimum_required(VERSION 3.10)

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)
#add_compile_options(-Wall -Wextra -pedantic -Werror)

set(PROJECT_NAME raylib-c-screen-tearing-test)
project(${PROJECT_NAME})

set(LIBRARY_NAME raylib)
add_subdirectory(${LIBRARY_NAME})

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBRARY_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/${LIBRARY_NAME}")