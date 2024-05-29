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
    repo = make_shared<Repo<Employee>>("../Repository/EmployeeRepo.txt");
    employee_repo = make_shared<Repo<Employee>>("../Repository/EmployeeRepo.txt");
    car_repo = make_shared<Repo<Car>>("../Repository/CarRepo.txt");
    order_repo = make_shared<Repo<Order>>("../Repository/OrderRepo.txt");

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

std::vector<Employee> EmployeeController::search_by_birth_date(const Date &birth) const {
    std::vector<Employee> result;
    try {
        auto employees = employee_repo->get_all();
        for (const auto& employee : employees) {
            Date birthdate = employee.get_Birthday();
            if (birthdate == birth) {
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

bool
EmployeeController::create_employee(string mail, string pass, string f_name, string l_name, string ph, string address,
                                    string pos, float salary ,int day, int month, int year) {

    string initials = make_initials(f_name, l_name);
    Employee e = Employee(find_next_id(), mail, pass, f_name,
                          l_name, pos, Date(day, month, year), initials, salary,false);

    employee_repo->add(e);
    return true;
}

int EmployeeController::find_next_id() {
    vector<Employee> employees = employee_repo->get_all();
    int max = 0;

    for(auto employee : employees){
        if(max < employee.get_id()){
            max = employee.get_id();
        }
    }
    return max + 1;

}

bool EmployeeController::reset_coworker_password(int employee_id,string password) {
    try {
        Employee employee = employee_repo->get_by_Id(employee_id);
        employee.set_password(password);
        employee_repo->update(employee_id, employee);
        return true;
    } catch (const std::exception& e) {
        return false; // ex.: if employee not found
    }
}

vector<Employee> EmployeeController::get_sorted_coworkers() {
//    vector<Employee> employees = employee_repo->get_all();
//    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
//        return a.get_last_name() < b.get_last_name();
//    });
//    return employees;
}

Employee EmployeeController::search_by_initials(const string& initials) {
    vector<Employee> employees = employee_repo->get_all();
    for (const auto& employee : employees) {
        if (employee.get_initials() == initials) {
            return employee;
        }
    }
    throw std::runtime_error("Employee not found");
}

string EmployeeController::make_initials(string f_name, string l_name) {

    return string(1, f_name[0]) + string(1, l_name[0]);
}

bool EmployeeController::change_employee_password(int employee_id, string new_password) {
    for(auto employee : employee_repo->get_all()){
        if(employee.get_id() == employee_id){
            employee.set_password(new_password);
            return true;
        }
    }
    return false;
}

bool EmployeeController::create_employee(Employee emp) {
    employee_repo->add(emp);
    return true;
}
