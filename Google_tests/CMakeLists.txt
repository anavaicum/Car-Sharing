# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
add_executable(Google_Tests_run Tests.cpp ../Domain/Car_Domain/Car.cpp
../Domain/Customer_Domain/Customer.cpp
../Domain/Order_Domain/Order.cpp
../Domain/User_Domain/User.cpp
../Domain/Employee_Domain/Employee.cpp
../Domain/Date.cpp
../Domain/Entity.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)