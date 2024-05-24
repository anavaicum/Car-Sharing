#include "gtest/gtest.h"
#include "../Domain/Car_Domain/Car.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Domain/Employee_Domain/Employee.h"
#include "../Domain/Order_Domain/Order.h"
#include <fstream>

TEST(TestGtest, FirstTest) {
    ASSERT_EQ(2, 2);
    //ASSERT_EQ(1, 2);
}

TEST(SavingData, CarSaving){
    Car c("SB12OGV", "Sandero", "Dacia", 2017, 100000.5, 12,
          Car::Gas, Car::Manual, "Red", vector<string>());
    Car c2;
    c2 = c2.From_String_To_Object(c.to_CSV());

    ASSERT_EQ(c2.getLicensePlate(), c.getLicensePlate());
    ASSERT_EQ(c2.getModel(), c.getModel());
    ASSERT_EQ(c2.getBrand(), c.getBrand());
    ASSERT_EQ(c2.getYearOfFirstReg(), c.getYearOfFirstReg());
    ASSERT_EQ(c2.getMileage(), c.getMileage());
    ASSERT_EQ(c2.getPricePerDay(), c.getPricePerDay());
    ASSERT_EQ(c2.getFuel(), c.getFuel());
    ASSERT_EQ(c2.getTrans(), c.getTrans());
    ASSERT_EQ(c2.getColor(), c.getColor());
    ASSERT_EQ(c2.getRemarks().size(), c.getRemarks().size());

}

TEST(SavingData, CustomerSaving) {
    vector<string> rm;
    rm.push_back("primul");
    rm.push_back("second");
    Car c("SB12OGV", "Sandero", "Dacia", 2017, 100000.5, 12,
          Car::Gas, Car::Manual, "Red", rm);
    vector<Car> fav;
//    fav.push_back(c);
//    fav.push_back(c);
    Customer cus(1, "this", "password", "Gica", "Popescu", "1234",
                 "Str. Lui", false, fav);

    Customer cus1;
    cus1 = cus1.From_String_To_Object(cus.to_CSV());

    ASSERT_EQ(cus.get_id(), cus1.get_id());
    ASSERT_EQ(cus.get_email(), cus1.get_email());
    ASSERT_EQ(cus.get_first_name(), cus1.get_first_name());
    ASSERT_EQ(cus.get_last_name(), cus1.get_last_name());
    ASSERT_EQ(cus.get_phone(), cus1.get_phone());
    ASSERT_EQ(cus.get_password(), cus1.get_password());
    ASSERT_EQ(cus.get_address(), cus1.get_address());
    ASSERT_EQ(cus.is_GDPRdeleted(), cus1.is_GDPRdeleted());
    ASSERT_EQ(cus.get_favorites().size(), cus1.get_favorites().size());

}


TEST(SavingData, EmployeeSaving){
//    Employee e(1, "this", "pass", "Gigel", "Fronel",
//               "buna", Date(12, 12, 1996), "GF",
//               1204.4, false);
//
//    e.save_to_CSV("../../Google_tests/TestRepos/EmployeeRepoTest.txt");
//
//    ifstream file("../../Google_tests/TestRepos/EmployeeRepoTest.txt");
//
//    string line;
//
//    getline(file, line); // Remove Header
//
//    getline(file, line);
//
//
//    e = e.From_String_To_Object(line);
//    ASSERT_EQ(e.get_id(), 1);
//    ASSERT_EQ(e.get_email(), "this");
//    ASSERT_EQ(e.get_password(), "pass");
//    ASSERT_EQ(e.get_first_name(), "Gigel");
//    ASSERT_EQ(e.get_last_name(), "Fronel");
//    ASSERT_EQ(e.get_position(), "buna");
//    ASSERT_EQ(e.getBirthday().getDay(), 12);
//    ASSERT_EQ(e.getBirthday().getMonth(), 12);
//    ASSERT_EQ(e.getBirthday().getYear(), 1996);
//    ASSERT_EQ(e.get_initials(), "GF");
//    //ASSERT_EQ(e.get_salary(), 1204.4); TODO: Needs to add a comparison with float
//    ASSERT_EQ(e.is_administrator(), false);
}

TEST(SavingData, OrderSaving){
//    vector<string> remark;
//    remark.push_back("this");
//    remark.push_back("that");
//    vector<string> rm;
//    rm.push_back("primul");
//    rm.push_back("second");
//
//
//    Car c("SB12OGV", "Sandero", "Dacia", 2017, 100000.5, 12,
//          Car::Gas, Car::Manual, "Red", rm);
//
//    vector<Car> fav;
//    fav.push_back(c);
//    fav.push_back(c);
//    Customer cus(1, "this", "password", "Gica", "Popescu", "1234",
//                 "Str. Lui", false, fav);
//
//    Employee e(1, "this", "pass", "Gigel", "Fronel",
//               "buna", Date(12, 12, 1996), "GF",
//               1204.4, false);
//
//
//    Order o(1, Date(12, 12, 2022), Order::Reserved, Date(24, 12, 2022),
//            Date(25, 12, 2022), 120.3, remark, true,
//            fav, e, cus);
//
//
//    o.save_to_CSV("../../Google_tests/TestRepos/OrderRepoTest.txt");
//
//    ifstream file("../../Google_tests/TestRepos/OrderRepoTest.txt");
//
//    string line;
//
//    getline(file, line); //Remove Header
//
//    getline(file, line);
//
//    o = o.From_String_To_Object(line);
//
//    ASSERT_EQ(o.getOrderId(), 1);
//    ASSERT_EQ(o.getOrderDate().getDay(), 12);
//    ASSERT_EQ(o.getOrderDate().getMonth(), 12);
//    ASSERT_EQ(o.getOrderDate().getYear(), 2022);

}
