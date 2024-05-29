cmake_minimum_required(VERSION 3.27)
project(Proiect_Colectiv)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proiect_Colectiv main.cpp
        Domain/Car_Domain/Car.cpp
        Domain/Customer_Domain/Customer.cpp
        Domain/Order_Domain/Order.cpp
        Domain/User_Domain/User.cpp
        Domain/Employee_Domain/Employee.cpp
        UI/UI.cpp
        Domain/Date.cpp
        Domain/Entity.cpp
        Controller/Car_Controller/CarController.cpp
        Controller/Customer_Controller/CustomerController.cpp
        Controller/Order_Controller/OrderController.cpp
        Controller/Employee_Controller/EmployeeController.cpp
        Controller/Controller.cpp
        UI/UI_employee.cpp
        UI/CustomerUI.cpp
        UI/AdminUI.cpp)
add_subdirectory(Google_tests)