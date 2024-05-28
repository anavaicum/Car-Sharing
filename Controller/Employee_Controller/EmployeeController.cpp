#include "../../Controller/Employee_Controller/EmployeeController.h"


float EmployeeController::get_employee_salary(int employee_id) {
    try {
        Employee employee = employee_repo->get_by_Id(employee_id);
        return employee.get_salary();
    } catch (...) {
        // Handle the case where the employee with the given ID is not found
        return -1; // Return a special value indicating error
    }
}

EmployeeController::EmployeeController() {
    repo = make_shared<Repo<Employee>>("../../Repository/EmployeeRepo.txt");
    employee_repo = make_shared<Repo<Employee>>("../../Repository/EmployeeRepo.txt");
    car_repo = make_shared<Repo<Car>>("../../Repository/CarRepo.txt");
    order_repo = make_shared<Repo<Order>>("../../Repository/OrderRepo.txt");

}


bool EmployeeController::disable_employee(int employee_id) {
    try {
        Employee employee = employee_repo->get_by_Id(employee_id);
        employee.set_salary(0.0f); // Disable the employee by setting their salary to 0
        employee_repo->update(employee_id, employee);
        return true;
    } catch (const std::exception& e) {
        // Handle exception (e.g., employee not found)
        return false;
    }
}


bool EmployeeController::enable_employee(int employee_id) {
    try {
        Employee employee = employee_repo->get_by_Id(employee_id);
        // Assuming enabling an employee means setting their salary back to a non-zero value
        // You can adjust this logic based on your requirements
        employee.set_salary(1000.0f); // Example: Set salary to 1000
        employee_repo->update(employee_id, employee);
        return true;
    } catch (const std::exception& e) {
        // Handle exception (e.g., employee not found)
        return false;
    }
}

bool EmployeeController::delete_employee(int employee_id) {
    try {
        employee_repo->delete_by_id(employee_id);
        // Assuming that deleting an employee also involves removing any associated orders or cars
        // from the system
        order_repo->delete_by_id(employee_id);
        car_repo->delete_by_id(employee_id);
        return true;
    } catch (const std::exception& e) {
        // Handle exception (e.g., employee not found)
        return false;
    }
}

bool EmployeeController::disable_employee(int employee_id) {
    try {
        Employee employee = employee_repo->get_by_Id(employee_id);
        employee.set_salary(0.0f); // Disable the employee by setting their salary to 0
        employee_repo->update(employee_id, employee);
        return true;
    } catch (const std::exception& e) {
        // Handle exception (e.g., employee not found)
        return false;
    }
}


bool EmployeeController::enable_employee(int employee_id) {
    try {
        Employee employee = employee_repo->get_by_Id(employee_id);
        // Assuming enabling an employee means setting their salary back to a non-zero value
        // You can adjust this logic based on your requirements
        employee.set_salary(1000.0f); // Example: Set salary to 1000
        employee_repo->update(employee_id, employee);
        return true;
    } catch (const std::exception& e) {
        // Handle exception (e.g., employee not found)
        return false;
    }
}

bool EmployeeController::delete_employee(int employee_id) {
    try {
        employee_repo->delete_by_id(employee_id);
        // Assuming that deleting an employee also involves removing any associated orders or cars
        // from the system
        order_repo->delete_by_id(employee_id);
        car_repo->delete_by_id(employee_id);
        return true;
    } catch (const std::exception& e) {
        // Handle exception (e.g., employee not found)
        return false;
    }
}
