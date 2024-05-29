#include <gtest/gtest.h>
#include "../Controller/Car_Controller/CarController.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Domain/Employee_Domain/Employee.h"
#include "../Domain/Order_Domain/Order.h"

class CarControllerTest : public ::testing::Test {
protected:
    std::unique_ptr<Car_Controller> controller;

    void SetUp() override {
        controller = std::make_unique<Car_Controller>();
    }
};

TEST_F(CarControllerTest, SearchByLicensePlate) {
    // Add a car to the repository
    Car car(1, "ABC123", "Model1", "Brand1", 2020, 10000, 50, "Petrol", "Automatic", "Red");
    controller->create_car("ABC123", "Model1", "Brand1", "Petrol", "Automatic", "Red", 2020, 10000, 50);

    // Search for the car by license plate
    Car foundCar = controller->search_by_license_plate("ABC123");

    // Verify that the correct car was found
    EXPECT_EQ(foundCar.get_id(), car.get_id());
    EXPECT_EQ(foundCar.getLicensePlate(), car.getLicensePlate());

    // Search for a non-existent car
    EXPECT_THROW(controller->search_by_license_plate("XYZ789"), std::runtime_error);
}

TEST_F(CarControllerTest, GetOrderedCars) {
    // Add cars to the repository
    //Car car1(1, "ABC123", "Model1", "Brand1", 2020, 10000, 50, "Petrol", "Automatic", "Red");
    controller->create_car("ABC123", "Model1", "Brand1", "Petrol", "Automatic", "Red", 2020, 10000, 50);
    controller->create_car("XYZ789", "Model2", "Brand2", "Diesel", "Manual", "Blue", 2019, 20000, 40);
    //Car car2(1, "XYZ789", "Model2", "Brand2", "Diesel", "Manual", "Blue", 2019, 20000, 40);
    //Car car2(2, "XYZ789", "Model2", "Brand2", 2019, 20000, 40, "Diesel", "Manual", "Blue");

    // Get ordered cars
    std::vector<Car> orderedCars = controller->get_ordered_cars();

    // Verify the order
    ASSERT_EQ(orderedCars.size(), 2);
    EXPECT_EQ(orderedCars[0].getLicensePlate(), "XYZ789");
    EXPECT_EQ(orderedCars[1].getLicensePlate(), "ABC123");
}

TEST_F(CarControllerTest, GetById) {
    // Add a car to the repository
    controller->create_car("ABC123", "Model1", "Brand1", "Petrol", "Automatic", "Red", 2020, 10000, 50);

    // Get the car by ID
    Car foundCar = controller->get_by_id(1);

    // Verify that the correct car was found
    EXPECT_EQ(foundCar.getLicensePlate(), "ABC123");

    // Try to get a non-existent car
    EXPECT_THROW(controller->get_by_id(2), std::runtime_error);
}

TEST_F(CarControllerTest, GetCarsBetweenDates) {
    // Add cars to the repository
    controller->create_car("ABC123", "Model1", "Brand1", "Petrol", "Automatic", "Red", 2020, 10000, 50);
    controller->create_car("XYZ789", "Model2", "Brand2", "Diesel", "Manual", "Blue", 2019, 20000, 40);
    controller->create_car("LMN456", "Model3", "Brand3", "Electric", "Automatic", "Green", 2018, 15000, 60);

    // Get cars between years 2019 and 2020
    std::vector<Car> carsInRange = controller->get_cars_between_dates(2019, 2020);

    // Verify the cars in range
    ASSERT_EQ(carsInRange.size(), 2);
    EXPECT_EQ(carsInRange[0].getLicensePlate(), "XYZ789");
    EXPECT_EQ(carsInRange[1].getLicensePlate(), "ABC123");
}

TEST_F(CarControllerTest, CreateCar) {
    // Create a new car
    bool result = controller->create_car("ABC123", "Model1", "Brand1", "Petrol", "Automatic", "Red", 2020, 10000, 50);

    // Verify that the car was successfully created
    EXPECT_TRUE(result);
    ASSERT_EQ(controller->get_ordered_cars().size(), 1);
    EXPECT_EQ(controller->get_ordered_cars()[0].getLicensePlate(), "ABC123");
}

TEST_F(CarControllerTest, UpdateCar) {
    // Add a car to the repository
    controller->create_car("ABC123", "Model1", "Brand1", "Petrol", "Automatic", "Red", 2020, 10000, 50);

    // Update the car's details
    bool result = controller->update_car("ABC123", "UpdatedModel", "UpdatedBrand", "Petrol", "Automatic", "Red", 2020, 10000, 50);

    // Verify that the car was updated successfully
    EXPECT_TRUE(result);
    EXPECT_EQ(controller->get_ordered_cars()[0].getModel(), "UpdatedModel");
    EXPECT_EQ(controller->get_ordered_cars()[0].getBrand(), "UpdatedBrand");
}

TEST_F(CarControllerTest, DeleteCar) {
    // Add a car to the repository
    controller->create_car("ABC123", "Model1", "Brand1", "Petrol", "Automatic", "Red", 2020, 10000, 50);

    // Delete the car
    bool result = controller->delete_car(1);

    // Verify that the car was deleted
    EXPECT_TRUE(result);
    EXPECT_TRUE(controller->get_ordered_cars().empty());
}

