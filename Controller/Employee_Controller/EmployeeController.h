

#ifndef PROIECT_COLECTIV_EMPLOYEECONTROLLER_H
#define PROIECT_COLECTIV_EMPLOYEECONTROLLER_H


#include "../../Domain/Employee_Domain/Employee.h"
#include "../../Repository/Repo.h"
#include "../../Repository/IRepo.h"
#include "../../Domain/Car_Domain/Car.h"
#include "../../Domain/Order_Domain/Order.h"


class EmployeeController {
private:
    IRepo<Employee>& employee_repo;
    IRepo<Car>& car_repo;
    IRepo<Order>& order_repo;

public:
    EmployeeController(IRepo<Employee>& emp_repo, IRepo<Car>& car_repo, IRepo<Order>& order_repo)
            : employee_repo(emp_repo), car_repo(car_repo), order_repo(order_repo) {}

    float get_employee_salary(int employee_id);
};


#endif //PROIECT_COLECTIV_EMPLOYEECONTROLLER_H
