
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

public:

    //I would say this isn't necessary, so that we don't include the Repos in the UI as well, instead use a normal constructor
    CustomerController(const std::shared_ptr<IRepo<Customer>> &customer_repo,
                       const std::shared_ptr<IRepo<Car>> &car_repo, const std::shared_ptr<IRepo<Order>> &order_repo);

    CustomerController();

    bool add_car_to_favorites(int customer_id, const Car &car);
    bool remove_car_from_favorites(int customer_id, const Car &car);
    std::vector<Car> get_favorites(const Customer& customer) const;
    bool create_customer(const Customer& customer);
};


#endif //PROIECT_COLECTIV_CUSTOMERCONTROLLER_H
