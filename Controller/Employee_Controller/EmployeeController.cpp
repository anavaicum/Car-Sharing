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
std::vector<Employee> EmployeeController::search_by_email(const std::string& email) const {
    std::vector<Employee> result;
    try {
        auto employees = employee_repo->get_all();
        for (const auto& employee : employees) {
            if (employee.get_email() == email) {
                result.push_back(employee);
            }
        }
    } catch (const std::exception& e) {
        // std::cerr << "Failed to search by email: " << e.what() << std::endl;
    }
    return result;
}

std::vector<Employee> EmployeeController::search_by_full_name(const std::string& first_name, const std::string& last_name) const {
    std::vector<Employee> result;
    try {
        auto employees = employee_repo->get_all();
        for (const auto& employee : employees) {
            if (employee.get_first_name() == first_name && employee.get_last_name() == last_name) {  // Use get_first_name and get_last_name
                result.push_back(employee);
            }
        }
    } catch (const std::exception& e) {
        // std::cerr << "Failed to search by full name: " << e.what() << std::endl;
    }
    return result;
}

std::vector<Employee> EmployeeController::search_between_dates(const Date& start_date, const Date& end_date) const {
    std::vector<Employee> result;
    try {
        auto employees = employee_repo->get_all();
        for (const auto& employee : employees) {
            Date birthdate = employee.get_Birthday();
            if (birthdate >= start_date && birthdate <= end_date) {
                result.push_back(employee);
            }
        }
    } catch (const std::exception& e) {
        // std::cerr << "Failed to search between dates: " << e.what() << std::endl;
    }
    return result;
}

vector<Employee> EmployeeController::get_all_employees() {
    return employee_repo->get_all();
}

