cmake_minimum_required(VERSION 3.27)
project(Proiect_Colectiv)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proiect_Colectiv main.cpp
        Domain/Car_Domain/Car.cpp
        Domain/Order_Domain/Order.cpp
        Domain/User_Domain/User.cpp
        Domain/Customer_Domain/Customer.cpp
        Domain/Coworker_Domain/Coworker.cpp)
add_subdirectory(Google_tests)