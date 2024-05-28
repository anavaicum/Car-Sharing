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
    Employee e(1, "this", "pass", "Gigel", "Fronel",
               "buna", Date(12, 12, 1996), "GF",
               1204.4, false);

    Employee e1;
    e1 = e1.From_String_To_Object(e.to_CSV());

    ASSERT_EQ(e1.get_id(), e.get_id());
    ASSERT_EQ(e1.get_email(), e.get_email());
    ASSERT_EQ(e1.get_password(), e.get_password());
    ASSERT_EQ(e1.get_first_name(), e.get_first_name());
    ASSERT_EQ(e1.get_last_name(), e.get_last_name());
    ASSERT_EQ(e1.get_position(), e.get_position());
    ASSERT_EQ(e1.get_Birthday(), e.get_Birthday());
    ASSERT_EQ(e1.get_initials(), e.get_initials());
    ASSERT_EQ(e1.get_salary(), e.get_salary());
    ASSERT_EQ(e1.is_administrator(), e.is_administrator());
}

TEST(SavingData, OrderSaving){
    vector<string> remark;
//    remark.push_back("this");
//    remark.push_back("that");
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

    Employee e(1, "this", "pass", "Gigel", "Fronel",
               "buna", Date(12, 12, 1996), "GF",
               1204.4, false);


    Order o(1, Date(12, 12, 2022), Order::Reserved, Date(24, 12, 2022),
            Date(25, 12, 2022), 120.3, remark, true,
            fav, e, cus);

    Order o1;
    o1 = o1.From_String_To_Object(o.to_CSV());

    ASSERT_EQ(o1.getOrderId(), o.getOrderId());
    ASSERT_EQ(o1.getOrderDate(), o.getOrderDate());
    ASSERT_EQ(o1.getStat(), o.getStat());
    ASSERT_EQ(o1.getBeginDate(), o.getBeginDate());
    ASSERT_EQ(o1.getEndDate(), o.getEndDate());
    ASSERT_EQ(o1.getTotalPrice(), o.getTotalPrice());
    ASSERT_EQ(o1.getRemarks().size(), o.getRemarks().size());
    ASSERT_EQ(o1.isReserved(), o.isReserved());
    ASSERT_EQ(o1.getCar().size(), o.getCar().size());
    ASSERT_EQ(o1.getEmployee().get_id(), o.getEmployee().get_id());
    ASSERT_EQ(o1.getCustomer().get_id(), o.getCustomer().get_id());

}
