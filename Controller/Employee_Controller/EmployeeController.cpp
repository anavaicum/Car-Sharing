

#include "../../Controller/Employee_Controller/EmployeeController.h"
float EmployeeController::get_employee_salary(int employee_id) {
    try {
        Employee employee = employee_repo.get_by_Id(employee_id);
        return employee.get_salary();
    } catch (...) {
        // Handle the case where the employee with the given ID is not found
        return -1; // Return a special value indicating error
    }
}

