cmake_minimum_required(VERSION 3.19)
project(05_unit_test_mock_data)

set(CMAKE_CXX_STANDARD 14)

include_directories(AFTER "/usr/X11R6/include")

add_link_options(-lm -lpthread -L/usr/X11R6/lib -lX11)

add_executable(05_unit_test_mock_data main.cpp CImgGIP05Mock.h catch.h MyRectangle.cpp MyRectangle.h collision_test.cpp)