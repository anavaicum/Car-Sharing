#include "gtest/gtest.h"
#include "../Domain/Car_Domain/Car.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Domain/Employee_Domain/Employee.h"
#include "../Domain/Order_Domain/Order.h"
#include "../Repository/Repo.h"
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
    //sa adaugi la obiectul tau "c" id ca nu are
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



// Test pentru update la Car
TEST(UpdateData, CarUpdate) {
    // Creare repo de test
    Repo<Car> repo("");

    // Adăugare mașină inițială
    Car oldCar(1, "SB12OGV", "Sandero", "Dacia", 2017, 100000.5, 12, Car::Gas, Car::Manual, "Red", vector<string>());
    repo.add(oldCar);

    // Creare mașină nouă
    Car newCar(1, "SB12OGV", "Logan", "Dacia", 2019, 50000.0, 15, Car::Diesel, Car::Automatic, "Blue", vector<string>());

    // Actualizare mașină
    bool updateResult = repo.update(oldCar.get_id(), newCar);
    ASSERT_TRUE(updateResult);

    // Verificare actualizare
    Car fetchedCar = repo.get_by_Id(1);
    ASSERT_EQ(fetchedCar.getModel(), "Logan");
    ASSERT_EQ(fetchedCar.getYearOfFirstReg(), 2019);
    ASSERT_EQ(fetchedCar.getMileage(), 50000.0);
    ASSERT_EQ(fetchedCar.getPricePerDay(), 15);
    ASSERT_EQ(fetchedCar.getFuel(), Car::Diesel);
    ASSERT_EQ(fetchedCar.getTrans(), Car::Automatic);
    ASSERT_EQ(fetchedCar.getColor(), "Blue");

    // Testăm update pentru un ID care nu există
    Car nonExistentCar(2, "XYZ123", "Focus", "Ford", 2020, 30000, 20, Car::Gas, Car::Manual, "Green", vector<string>());
    bool updateNonExistent = repo.update(nonExistentCar.get_id(), nonExistentCar);
    ASSERT_FALSE(updateNonExistent);
}

// Test pentru update la Customer
TEST(UpdateData, CustomerUpdate) {
    // Creare repo de test
    Repo<Customer> repo("");

    // Adăugare client inițial
    vector<Car> fav;
    Customer oldCus(1, "this", "password", "Gica", "Popescu", "1234", "Str. Lui", false, fav);
    repo.add(oldCus);

    // Creare client nou
    Customer newCus(1, "this_updated", "new_password", "Gica", "Ionescu", "5678", "Str. Ei", true, fav);

    // Actualizare client
    bool updateResult = repo.update(oldCus.get_id(), newCus);
    ASSERT_TRUE(updateResult);

    // Verificare actualizare
    Customer fetchedCus = repo.get_by_Id(1);
    ASSERT_EQ(fetchedCus.get_email(), "this_updated");
    ASSERT_EQ(fetchedCus.get_password(), "new_password");
    ASSERT_EQ(fetchedCus.get_last_name(), "Ionescu");
    ASSERT_EQ(fetchedCus.get_phone(), "5678");
    ASSERT_EQ(fetchedCus.get_address(), "Str. Ei");
    ASSERT_TRUE(fetchedCus.is_GDPRdeleted());

    // Testăm update pentru un ID care nu există
    Customer nonExistentCus(2, "nonexistent", "password", "John", "Doe", "0000", "Str. LOR", false, fav);
    bool updateNonExistent = repo.update(nonExistentCus.get_id(), nonExistentCus);
    ASSERT_FALSE(updateNonExistent);
}

// Test pentru update la Employee
TEST(UpdateData, EmployeeUpdate) {
    // Creare repo de test
    Repo<Employee> repo("");

    // Adăugare angajat inițial
    Employee oldE(1, "this", "pass", "Gigel", "Fronel", "buna", Date(12, 12, 1996), "GF", 1204.4, false);
    repo.add(oldE);

    // Creare angajat nou
    Employee newE(1, "this_updated", "new_pass", "Gigel", "Popescu", "noua", Date(1, 1, 1995), "GP", 1500.0, true);

    // Actualizare angajat
    bool updateResult = repo.update(oldE.get_id(), newE);
    ASSERT_TRUE(updateResult);

    // Verificare actualizare
    Employee fetchedE = repo.get_by_Id(1);
    ASSERT_EQ(fetchedE.get_email(), "this_updated");
    ASSERT_EQ(fetchedE.get_password(), "new_pass");
    ASSERT_EQ(fetchedE.get_last_name(), "Popescu");
    ASSERT_EQ(fetchedE.get_position(), "noua");
    ASSERT_EQ(fetchedE.get_Birthday(), Date(1, 1, 1995));
    ASSERT_EQ(fetchedE.get_initials(), "GP");
    ASSERT_EQ(fetchedE.get_salary(), 1500.0);
    ASSERT_TRUE(fetchedE.is_administrator());

    // Testăm update pentru un ID care nu există
    Employee nonExistentE(2, "nonexistent", "pass", "John", "Doe", "noua", Date(1, 1, 1990), "JD", 2000.0, false);
    bool updateNonExistent = repo.update(nonExistentE.get_id(), nonExistentE);
    ASSERT_FALSE(updateNonExistent);
}

// Test pentru update la Order
TEST(UpdateData, OrderUpdate) {
    // Creare repo de test
    Repo<Order> repo("");

    // Adăugare comandă inițială
    vector<string> remark;
    vector<Car> fav;
    Customer cus(1, "this", "password", "Gica", "Popescu", "1234", "Str. Lui", false, fav);
    Employee e(1, "this", "pass", "Gigel", "Fronel", "buna", Date(12, 12, 1996), "GF", 1204.4, false);
    Order oldO(1, Date(12, 12, 2022), Order::Reserved, Date(24, 12, 2022), Date(25, 12, 2022), 120.3, remark, true, fav, e, cus);
    repo.add(oldO);

    // Creare comandă nouă
    Order newO(1, Date(13, 12, 2022), Order::Completed, Date(26, 12, 2022), Date(27, 12, 2022), 150.0, remark, false, fav, e, cus);

    // Actualizare comandă
    bool updateResult = repo.update(oldO.get_id(), newO);
    ASSERT_TRUE(updateResult);

    // Verificare actualizare
    Order fetchedO = repo.get_by_Id(1);
    ASSERT_EQ(fetchedO.getOrderDate(), Date(13, 12, 2022));
    ASSERT_EQ(fetchedO.getStat(), Order::Completed);
    ASSERT_EQ(fetchedO.getBeginDate(), Date(26, 12, 2022));
    ASSERT_EQ(fetchedO.getEndDate(), Date(27, 12, 2022));
    ASSERT_EQ(fetchedO.getTotalPrice(), 150.0);
    ASSERT_FALSE(fetchedO.isReserved());

    // Testăm update pentru un ID care nu există
    Order nonExistentO(2, Date(14, 12, 2022), Order::Ordered, Date(28, 12, 2022), Date(29, 12, 2022), 180.0, remark, true, fav, e, cus);
    bool updateNonExistent = repo.update(nonExistentO.get_id(), nonExistentO);
    ASSERT_FALSE(updateNonExistent);
}
