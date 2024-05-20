#include "gtest/gtest.h"
#include "../Domain/Car_Domain/Car.h"
#include <fstream>

TEST(TestGtest, FirstTest) {
    ASSERT_EQ(2, 2);
    //ASSERT_EQ(1, 2);
}

TEST(SavingData, SavingData){
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
