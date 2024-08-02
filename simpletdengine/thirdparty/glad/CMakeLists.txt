cmake_minimum_required(VERSION 3.5)

project(glad C)

add_library(glad src/glad.c include/glad/glad.h include/KHR/khrplatform.h)

target_include_directories(glad PRIVATE include)