

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
    bool disable_employee(int employee_id);
    bool enable_employee(int employee_id);
    bool delete_employee(int employee_id);
    std::vector<Employee> search_by_email(const std::string& email) const;
    std::vector<Employee> search_by_full_name(const std::string& first_name, const std::string& last_name) const;
    std::vector<Employee> search_between_dates(const Date& start_date, const Date& end_date) const;
};


#endif //PROIECT_COLECTIV_EMPLOYEECONTROLLER_H
