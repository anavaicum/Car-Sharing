#include <gtest/gtest.h>
#include <memory>
#include "../Controller/Order_Controller/OrderController.h"
#include "gtest/gtest.h"
#include "../Domain/Car_Domain/Car.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Domain/Employee_Domain/Employee.h"
#include "../Domain/Order_Domain/Order.h"
#include "../Repository/Repo.h"

class OrderControllerTest : public ::testing::Test {
protected:
    std::shared_ptr<Order_Controller> controller;

    void SetUp() override {
        // Initialize the OrderController
        controller = std::make_shared<Order_Controller>();
    }
};

TEST_F(OrderControllerTest, CreateOrder) {
    // Create a new order
    Date orderDate(29, 5, 2024);
    Date startDate(30, 5, 2024);
    Date endDate(6, 6, 2024);
    ASSERT_TRUE(controller->create_order(orderDate, "Reserved", startDate, endDate, 1500.0f, 1, 1, 1));

    // Verify that the order was added successfully
    std::vector<Order> orders = controller->get_orders_sorted_by_price();
    EXPECT_EQ(orders.size(), 1);
    EXPECT_EQ(orders[0].getStat(), Order::Reserved);
}

TEST_F(OrderControllerTest, UpdateOrder) {
    // Create a new order
    Date orderDate(29, 5, 2024);
    Date startDate(30, 5, 2024);
    Date endDate(6, 6, 2024);
    controller->create_order(orderDate, "Reserved", startDate, endDate, 1500.0f, 1, 1, 1);

    // Get the newly created order
    std::vector<Order> orders = controller->get_orders_sorted_by_price();
    ASSERT_EQ(orders.size(), 1);
    Order existingOrder = orders[0];

    // Update the order status
    existingOrder.setStat("Completed");
    ASSERT_TRUE(controller->update_order(existingOrder, existingOrder));

    // Verify that the order status was updated successfully
    orders = controller->get_orders_sorted_by_price();
    EXPECT_EQ(orders.size(), 1);
    EXPECT_EQ(orders[0].getStat(), Order::Completed);
}

TEST_F(OrderControllerTest, CompleteOrder) {
    // Create a new order
    Date orderDate(29, 5, 2024);
    Date startDate(30, 5, 2024);
    Date endDate(6, 6, 2024);
    controller->create_order(orderDate, "Reserved", startDate, endDate, 1500.0f, 1, 1, 1);

    // Get the newly created order
    std::vector<Order> orders = controller->get_orders_sorted_by_price();
    ASSERT_EQ(orders.size(), 1);
    int orderId = orders[0].get_id();

    // Mark the order as completed
    ASSERT_TRUE(controller->complete_order(orderId));

    // Verify that the order status was updated to "Completed"
    Order completedOrder = controller->get_by_id(orderId);
    EXPECT_EQ(completedOrder.getStat(), Order::Completed);
}

TEST_F(OrderControllerTest, GetTotalPriceYear) {
    // Create multiple orders for different years
    controller->create_order(Date(29, 5, 2023), "Completed", Date(30, 5, 2023), Date(6, 6, 2023), 1000.0f, 1, 1, 1);
    controller->create_order(Date(29, 5, 2024), "Completed", Date(30, 5, 2024), Date(6, 6, 2024), 1500.0f, 2, 2, 2);
    controller->create_order(Date(29, 5, 2024), "Completed", Date(30, 5, 2024), Date(6, 6, 2024), 2000.0f, 3, 3, 3);

    // Verify total price for the year 2024
    float totalPrice = controller->get_total_price_year(2024);
    EXPECT_FLOAT_EQ(totalPrice, 3500.0f);
}

TEST_F(OrderControllerTest, GetTotalPriceMonth) {
    // Create multiple orders for different months
    controller->create_order(Date(29, 5, 2024), "Completed", Date(30, 5, 2024), Date(6, 6, 2024), 1500.0f, 1, 1, 1);
    controller->create_order(Date(1, 6, 2024), "Completed", Date(2, 6, 2024), Date(10, 6, 2024), 2000.0f, 2, 2, 2);
    controller->create_order(Date(5, 6, 2024), "Completed", Date(6, 6, 2024), Date(12, 6, 2024), 1000.0f, 3, 3, 3);

    // Verify total price for the month of June (month 6)
    float totalPrice = controller->get_total_price_month(6);
    EXPECT_FLOAT_EQ(totalPrice, 3000.0f);
}

TEST_F(OrderControllerTest, GetOrdersBetweenDates) {
    // Create multiple orders for different dates
    controller->create_order(Date(29, 5, 2024), "Completed", Date(30, 5, 2024), Date(6, 6, 2024), 1500.0f, 1, 1, 1);
    controller->create_order(Date(1, 6, 2024), "Completed", Date(2, 6, 2024), Date(10, 6, 2024), 2000.0f, 2, 2, 2);
    controller->create_order(Date(5, 6, 2024), "Completed", Date(6, 6, 2024), Date(12, 6, 2024), 1000.0f, 3, 3, 3);

    // Get orders between two dates
    std::vector<Order> orders = controller->get_orders_between_dates(Date(1, 6, 2024), Date(10, 6, 2024));

    // Verify the number of orders retrieved
    EXPECT_EQ(orders.size(), 2);
}

TEST_F(OrderControllerTest, GiveOrderToCoworker) {
    // Create a new order
    controller->create_order(Date(29, 5, 2024), "Reserved", Date(30, 5, 2024), Date(6, 6, 2024), 1500.0f, 1, 1, 1);

    // Retrieve the order
    Order order = controller->get_by_id(1);

    // Assign the order to a coworker
    bool success = controller->give_order_to_coworker(order);

    // Verify that the order was successfully assigned
    EXPECT_TRUE(success);
}

TEST_F(OrderControllerTest, DeleteReservation) {
    // Create a new reservation
    controller->create_reservation(Date(29, 5, 2024), Date(30, 5, 2024), Date(6, 6, 2024), 1, 1, 1);

    // Retrieve the reservation
    Order reservation = controller->get_by_id(1);

    // Delete the reservation
    bool success = controller->delete_reservation(1);

    // Verify that the reservation was successfully deleted
    EXPECT_TRUE(success);

    // Verify that the reservation is no longer marked as reserved
    EXPECT_FALSE(reservation.isReserved());
}

TEST_F(OrderControllerTest, MakeReservation) {
    // Create a new order
    controller->create_order(Date(29, 5, 2024), "Reserved", Date(30, 5, 2024), Date(6, 6, 2024), 1500.0f, 1, 1, 1);

    // Retrieve the order
    Order order = controller->get_by_id(1);

    // Create a new customer
    Customer customer(1, "john.doe@example.com", "password", "John", "Doe", "1234567890", "123 Main St", false, {});

    // Make a reservation for the order
    bool success = controller->make_reservation(1, 1);

// Retrieve the updated order after making the reservation
    Order updatedOrder = controller->get_by_id(1);

// Verify that the reservation was successfully made
    EXPECT_TRUE(success);

// Verify that the updated order is now marked as reserved
    EXPECT_TRUE(updatedOrder.isReserved());

}

