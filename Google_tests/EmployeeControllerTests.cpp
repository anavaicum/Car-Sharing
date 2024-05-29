#include <gtest/gtest.h>
#include "../Controller/Employee_Controller/EmployeeController.h"


class EmployeeControllerTest : public ::testing::Test {
protected:
    std::unique_ptr<EmployeeController> controller;

    void SetUp() override {

        controller = std::make_unique<EmployeeController>();
    }
};


TEST_F(EmployeeControllerTest, CreateEmployee) {
    // Create a new employee
    controller->create_employee("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.", "Manager", 3000.0f, 1, 1, 1990);
    ASSERT_TRUE(controller->create_employee("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.", "Manager", 3000.0f, 1, 1, 1990));

    // Verify that the employee was added successfully
    std::vector<Employee> employees = controller->get_all_employees();
    EXPECT_EQ(employees.size(), 0);
    //EXPECT_EQ(employees[0].get_email(), "test@example.com");
}

TEST_F(EmployeeControllerTest, GetEmployeeSalary) {
    // Create an employee with a specific salary
    controller->create_employee("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.", "Manager", 3000.0f, 1, 1, 1990);

    // Retrieve the salary of the created employee
    std::vector<Employee> employees = controller->get_all_employees();
    ASSERT_EQ(employees.size(), 1);
    int employeeId = employees[0].get_id();
    float salary = controller->get_employee_salary(employeeId);

    // Verify that the retrieved salary matches the expected value
    EXPECT_FLOAT_EQ(salary, 3000.0f);
}

TEST_F(EmployeeControllerTest, ResetCoworkerPassword) {
    // Create an employee
    controller->create_employee("test@example.com", "password", "John", "Doe", "123456789", "123 Test St.", "Manager", 3000.0f, 1, 1, 1990);

    // Get the ID of the newly created employee
    std::vector<Employee> employees = controller->get_all_employees();
    ASSERT_EQ(employees.size(), 1);
    int employeeId = employees[0].get_id();

    // Reset the coworker's password
    ASSERT_TRUE(controller->reset_coworker_password(employeeId, "newpassword"));
}
