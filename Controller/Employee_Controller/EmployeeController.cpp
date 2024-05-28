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