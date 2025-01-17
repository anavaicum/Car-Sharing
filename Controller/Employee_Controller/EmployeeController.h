

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
    int find_next_id();
    string make_initials(string f_name, string l_name);
public:
    //I would say this isn't necessary, so that we don't include the Repos in the UI as well, instead use a normal constructor
//    EmployeeController(IRepo<Employee>& emp_repo, IRepo<Car>& car_repo, IRepo<Order>& order_repo)
//            : employee_repo(emp_repo), car_repo(car_repo), order_repo(order_repo) {}
    EmployeeController();
    vector<Employee> get_all_employees();
    /**
     * Creates a new employee with the following params
     * @param mail
     * @param pass
     * @param f_name
     * @param l_name
     * @param ph
     * @param address
     * @param pos
     * @param salary
     * @param day
     * @param month
     * @param year
     * @return
     */
    bool create_employee(string mail, string pass, string f_name, string l_name,
                         string ph, string address, string pos, float salary ,int day, int month, int year);

    bool create_employee(Employee emp);
    float get_employee_salary(int employee_id);
    /**
     * Changes password with a new one
     * @param employee_id
     * @param password password that it will be changed into
     * @return
     */
    bool reset_coworker_password(int employee_id, string password);
    vector<Employee> get_sorted_coworkers();
    Employee search_by_initials(const string& initials);

    bool disable_employee(int employee_id);
    bool enable_employee(int employee_id);
    bool delete_employee(int employee_id);
    /**
     * @param email
     * @return vector of all Employees who have the same email
     */
    std::vector<Employee> search_by_email(const std::string& email) const;
    /**
     * @param first_name
     * @param last_name
     * @return vector of all employees who have the same name
     */
    std::vector<Employee> search_by_full_name(const std::string& first_name, const std::string& last_name) const;
    /**
     *
     * @param start_date
     * @param end_date
     * @return vector of all Employees that have their birthday between 2 dates
     */
    std::vector<Employee> search_between_dates(const Date& start_date, const Date& end_date) const;
    std::vector<Employee> search_by_birth_date(const Date& birth) const;
    /**
     * Changes password with a new one
     * @param employee_id
     * @param password password that it will be changed into
     * @return
     */
    bool change_employee_password(int employee_id, string new_password);
};


#endif //PROIECT_COLECTIV_EMPLOYEECONTROLLER_H
