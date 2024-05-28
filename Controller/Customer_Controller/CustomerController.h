
#ifndef PROIECT_COLECTIV_CUSTOMERCONTROLLER_H
#define PROIECT_COLECTIV_CUSTOMERCONTROLLER_H

#include "../../Repository/IRepo.h"
#include "../../Repository/Repo.h"
#include "../../Domain/Customer_Domain/Customer.h"
#include "../../Domain/Car_Domain/Car.h"
#include "../../Domain/Order_Domain/Order.h"
#include "../User_Controller/UserController.h"
#include <vector>
#include <string>
#include <memory>

class CustomerController : public UserController<Customer>{
private:
    std::shared_ptr<IRepo<Customer>> customerRepo;
    std::shared_ptr<IRepo<Car>> carRepo;
    std::shared_ptr<IRepo<Order>> orderRepo;
    int find_next_id();

public:

    //I would say this isn't necessary, so that we don't include the Repos in the UI as well, instead use a normal constructor
    CustomerController(const std::shared_ptr<IRepo<Customer>> &customer_repo,
                       const std::shared_ptr<IRepo<Car>> &car_repo, const std::shared_ptr<IRepo<Order>> &order_repo);

    CustomerController();

    vector<Customer> get_all_customers();
    bool add_car_to_favorites(int customer_id, const Car &car);
    bool remove_car_from_favorites(int customer_id, const Car &car);


    std::vector<Customer> search_by_car(const Car& car) const;
    bool create_customer(const Customer& customer);
    bool create_customer(string mail, string pass,
                         string f_name, string l_name, string ph, string address);
    vector<Car> get_favorites(int customer_id);
    bool update_customer(int customer_id, Customer customer);
    bool delete_customer(int customer_id);
    bool GDPR_customer(int customer_id);
    vector<Customer> get_all_customers_sorted();
    Customer search_by_email(string email);
    Customer search_by_phone(string phone);
    Customer search_by_name(string first_name,string last_name);

};


#endif //PROIECT_COLECTIV_CUSTOMERCONTROLLER_H
