cmake_minimum_required(VERSION 3.19)
project(02_class_myrectangle)

set(CMAKE_CXX_STANDARD 14)

include_directories(AFTER "/usr/X11R6/include")

add_link_options(-lm -lpthread -L/usr/X11R6/lib -lX11)

add_executable(02_class_myrectangle main.cpp CImgGIP05.h MyRectangle.cpp MyRectangle.h)