#include <gtest/gtest.h>
#include "../Controller/Customer_Controller/CustomerController.h"

#include "../Domain/Car_Domain/Car.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Domain/Employee_Domain/Employee.h"
#include "../Domain/Order_Domain/Order.h"
#include "../Repository/Repo.h"

class CustomerControllerTest : public ::testing::Test {
protected:
    std::unique_ptr<CustomerController> controller;

    void SetUp() override {
        controller = std::make_unique<CustomerController>();
    }
};

TEST_F(CustomerControllerTest, CreateCustomer) {
    // Create a new customer
    bool result = controller->create_customer("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.");

    // Verify that the customer was successfully created
    EXPECT_TRUE(result);
    ASSERT_EQ(controller->get_all_customers().size(), 1);
    EXPECT_EQ(controller->get_all_customers()[0].get_email(), "test@example.com");
}

TEST_F(CustomerControllerTest, GetFavorites) {
    // Add a customer to the repository
    controller->create_customer("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.");

    // Add a car to the customer's favorites
    Car car(1, "ABC123", "Model1", "Brand1", 2020, 10000, 50, "Petrol", "Automatic", "Red");
    controller->add_car_to_favorites(1, car);

    // Get the customer's favorites
    std::vector<Car> favorites = controller->get_favorites(1);

    // Verify that the correct car is in the favorites
    ASSERT_EQ(favorites.size(), 1);
    EXPECT_EQ(favorites[0].getLicensePlate(), "ABC123");
}

TEST_F(CustomerControllerTest, RemoveCarFromFavorites) {
    // Add a customer to the repository
    controller->create_customer("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.");

    // Add two cars to the customer's favorites
    Car car1(1, "ABC123", "Model1", "Brand1", 2020, 10000, 50, "Petrol", "Automatic", "Red");
    Car car2(2, "XYZ789", "Model2", "Brand2", 2021, 15000, 60, "Diesel", "Manual", "Blue");
    controller->add_car_to_favorites(1, car1);
    controller->add_car_to_favorites(1, car2);

    // Remove one car from the customer's favorites
    bool result = controller->remove_car_from_favorites(1, car1);

    // Verify that the car was successfully removed from favorites
    EXPECT_TRUE(result);
    std::vector<Car> favorites = controller->get_favorites(1);
    ASSERT_EQ(favorites.size(), 1);
    EXPECT_EQ(favorites[0].getLicensePlate(), "XYZ789");
}

TEST_F(CustomerControllerTest, UpdateCustomer) {
    // Add a customer to the repository
    controller->create_customer("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.");

    // Update the customer's details
    bool result = controller->update_customer(1, "updated@example.com", "newpassword", "Jane", "Smith", "987654321", "456 Main St.");

    // Verify that the customer was updated successfully
    EXPECT_TRUE(result);
    Customer updatedCustomer = controller->get_by_id(1);
    EXPECT_EQ(updatedCustomer.get_email(), "updated@example.com");
    EXPECT_EQ(updatedCustomer.get_password(), "newpassword");
    EXPECT_EQ(updatedCustomer.get_first_name(), "Jane");
    EXPECT_EQ(updatedCustomer.get_last_name(), "Smith");
    EXPECT_EQ(updatedCustomer.get_phone(), "987654321");
    EXPECT_EQ(updatedCustomer.get_address(), "456 Main St.");
}

TEST_F(CustomerControllerTest, GDPRCustomer) {
    // Add a customer to the repository
    controller->create_customer("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.");

    // Set GDPR flag for the customer
    bool result = controller->update_customer(1, true);

    // Verify that the GDPR flag was set
    EXPECT_TRUE(result);
    EXPECT_TRUE(controller->GDPR_customer(1));
}

TEST_F(CustomerControllerTest, SearchByEmail) {
    // Add several customers to the repository
    controller->create_customer("test1@example.com", "password1", "John", "Doe", "123456789", "123 Test St.");
    controller->create_customer("test2@example.com", "password2", "Jane", "Doe", "987654321", "456 Main St.");
    controller->create_customer("test3@example.com", "password3", "Alice", "Smith", "111222333", "789 Park Ave.");

    // Search for a customer by email
    std::vector<Customer> foundCustomers = controller->search_by_email("test2@example.com");

    // Verify that the correct customer was found
    ASSERT_EQ(foundCustomers.size(), 1);
    EXPECT_EQ(foundCustomers[0].get_email(), "test2@example.com");
}

TEST_F(CustomerControllerTest, SearchByPhone) {
    // Add several customers to the repository
    controller->create_customer("test1@example.com", "password1", "John", "Doe", "123456789", "123 Test St.");
    controller->create_customer("test2@example.com", "password2", "Jane", "Doe", "987654321", "456 Main St.");
    controller->create_customer("test3@example.com", "password3", "Alice", "Smith", "111222333", "789 Park Ave.");

    // Search for a customer by phone number
    std::vector<Customer> foundCustomers = controller->search_by_phone("987654321");

    // Verify that the correct customer was found
    ASSERT_EQ(foundCustomers.size(), 1);
    EXPECT_EQ(foundCustomers[0].get_phone(), "987654321");
}

TEST_F(CustomerControllerTest, SearchByName) {
    // Add several customers to the repository
    controller->create_customer("test1@example.com", "password1", "John", "Doe", "123456789", "123 Test St.");
    controller->create_customer("test2@example.com", "password2", "Jane", "Doe", "987654321", "456 Main St.");
    controller->create_customer("test3@example.com", "password3", "Alice", "Smith", "111222333", "789 Park Ave.");

    // Search for customers by first and last name
    std::vector<Customer> foundCustomers = controller->search_by_name("Jane", "Doe");

    // Verify that the correct customer was found
    ASSERT_EQ(foundCustomers.size(), 1);
    EXPECT_EQ(foundCustomers[0].get_first_name(), "Jane");
    EXPECT_EQ(foundCustomers[0].get_last_name(), "Doe");
}