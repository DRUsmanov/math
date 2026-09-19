cmake_minimum_required(VERSION 3.14)

project(math VERSION 1.0.0 LANGUAGES CXX)

add_library(math INTERFACE)
add_library(math::math ALIAS math)

target_include_directories(math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
