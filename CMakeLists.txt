cmake_minimum_required(VERSION 3.27)
project(Proiect_Colectiv)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proiect_Colectiv main.cpp
        Domain/Car_Domain/Car.cpp
        Domain/Order_Domain/Order.cpp
        Controller/Car_Controller/CarController.h
        Controller/Order_Controller/OrderController.h
        Controller/Car_Controller/CarController.cpp
        Controller/Order_Controller/OrderController.cpp
        Domain/Order_Domain/Order.h)
add_subdirectory(Google_tests)