cmake_minimum_required(VERSION 3.31.6)

project(SdlSh)

find_package(SDL3 REQUIRED)

add_subdirectory(build-tools)
add_subdirectory(src)
