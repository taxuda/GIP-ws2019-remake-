cmake_minimum_required(VERSION 3.17)
project(03_Animation)

set(CMAKE_CXX_STANDARD 14)

include_directories(AFTER "/usr/X11R6/include")

add_link_options(-lm -lpthread -L/usr/X11R6/lib -lX11)

add_executable(03_Animation animation.cpp CImgGIP05.h)
