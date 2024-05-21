#include "gtest/gtest.h"
#include "../Domain/Car_Domain/Car.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Domain/Employee_Domain/Employee.h"
#include <fstream>

TEST(TestGtest, FirstTest) {
    ASSERT_EQ(2, 2);
    //ASSERT_EQ(1, 2);
}

TEST(SavingData, CarSaving){
    Car c("SB12OGV", "Sandero", "Dacia", 2017, 100000.5, 12,
          Car::Gas, Car::Manual, "Red", vector<string>());

    c.save_to_CSV("../../Google_tests/TestRepos/CarRepoTest.txt");

    ifstream file("../../Google_tests/TestRepos/CarRepoTest.txt");
    string line;
    getline(file, line); // Removing Header

    getline(file, line);

    c = c.From_String_To_Object(line);
    ASSERT_EQ(c.getLicensePlate(), "SB12OGV");
    ASSERT_EQ(c.getModel(), "Sandero");
    ASSERT_EQ(c.getBrand(), "Dacia");
    ASSERT_EQ(c.getYearOfFirstReg(), 2017);
    //ASSERT_EQ(c.getMileage(), 100000.5);
    ASSERT_EQ(c.getPricePerDay(), 12);
    ASSERT_EQ(c.getFuel(), Car::Gas);
    ASSERT_EQ(c.getTrans(), Car::Manual);
    ASSERT_EQ(c.getColor(), "Red");
    for(int i = 0; i < c.getRemarks().size(); i++){
        ASSERT_EQ(true, false);
    }
}

TEST(SavingData, CustomerSaving){
    vector<string> rm;
    rm.push_back("primul");
    rm.push_back("second");
    Car c("SB12OGV", "Sandero", "Dacia", 2017, 100000.5, 12,
          Car::Gas, Car::Manual, "Red", rm);
    vector<Car> fav;
    fav.push_back(c);
    fav.push_back(c);
    Customer cus(1, "this", "password", "Gica", "Popescu", "1234",
                 "Str. Lui", false, fav);
    cus.save_to_CSV("../../Google_tests/TestRepos/CustomerRepoTest.txt");

    ifstream file("../../Google_tests/TestRepos/CustomerRepoTest.txt");
    string line;

    getline(file, line); //Removing Header

    getline(file, line);

    cus = Customer().From_String_To_Object(line);

    ASSERT_EQ(cus.get_id(), 1);
    ASSERT_EQ(cus.get_email(), "this");
    ASSERT_EQ(cus.get_password(), "password");
    ASSERT_EQ(cus.get_first_name(), "Gica");
    ASSERT_EQ(cus.get_last_name(), "Popescu");
    ASSERT_EQ(cus.get_phone(), "1234");
    ASSERT_EQ(cus.get_address(), "Str. Lui");
    ASSERT_EQ(cus.is_GDPRdeleted(), false);
    ASSERT_EQ(cus.get_favorites()[0].getRemarks()[0], "primul");
}


TEST(SavingData, EmployeeSaving){
    Employee e(1, "this", "pass", "Gigel", "Fronel",
               "buna", Date(12, 12, 1996), "GF",
               1204.4, false);

    e.save_to_CSV("../../Google_tests/TestRepos/EmployeeRepoTest.txt");

    ifstream file("../../Google_tests/TestRepos/EmployeeRepoTest.txt");

    string line;

    getline(file, line); // Remove Header

    getline(file, line);


    e = e.From_String_To_Object(line);
    ASSERT_EQ(e.get_id(), 1);
    ASSERT_EQ(e.get_email(), "this");
    ASSERT_EQ(e.get_password(), "pass");
    ASSERT_EQ(e.get_first_name(), "Gigel");
    ASSERT_EQ(e.get_last_name(), "Fronel");
    ASSERT_EQ(e.get_position(), "buna");
    ASSERT_EQ(e.getBirthday().getDay(), 12);
    ASSERT_EQ(e.getBirthday().getMonth(), 12);
    ASSERT_EQ(e.getBirthday().getYear(), 1996);
    ASSERT_EQ(e.get_initials(), "GF");
    //ASSERT_EQ(e.get_salary(), 1204.4); TODO: Needs to add a comparison with float
    ASSERT_EQ(e.is_administrator(), false);
}
