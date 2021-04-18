cmake_minimum_required(VERSION 3.19)
project(04_unit_testing)

set(CMAKE_CXX_STANDARD 14)

include_directories(AFTER "/usr/X11R6/include")

add_link_options(-lm -lpthread -L/usr/X11R6/lib -lX11)

add_executable(04_unit_testing main.cpp MyRectangle.h MyRectangle.cpp CImgGIP05.h catch.h collision_test.cpp)