

#ifndef PROIECT_COLECTIV_EMPLOYEECONTROLLER_H
#define PROIECT_COLECTIV_EMPLOYEECONTROLLER_H


#include "../../Domain/Employee_Domain/Employee.h"
#include "../../Repository/Repo.h"
#include "../../Repository/IRepo.h"
#include "../../Domain/Car_Domain/Car.h"
#include "../../Domain/Order_Domain/Order.h"
#include "../User_Controller/UserController.h"


class EmployeeController : public UserController<Employee>{
private:
    shared_ptr<IRepo<Employee>> employee_repo;
    shared_ptr<IRepo<Car>> car_repo;
    shared_ptr<IRepo<Order>> order_repo;

public:
    //I would say this isn't necessary, so that we don't include the Repos in the UI as well, instead use a normal constructor
//    EmployeeController(IRepo<Employee>& emp_repo, IRepo<Car>& car_repo, IRepo<Order>& order_repo)
//            : employee_repo(emp_repo), car_repo(car_repo), order_repo(order_repo) {}
    EmployeeController();
    vector<Employee> get_all_employees();
    float get_employee_salary(int employee_id);
};


#endif //PROIECT_COLECTIV_EMPLOYEECONTROLLER_H
