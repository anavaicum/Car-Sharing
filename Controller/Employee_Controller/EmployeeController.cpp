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

vector<Employee> EmployeeController::get_all_employees() {
    return employee_repo->get_all();
}

