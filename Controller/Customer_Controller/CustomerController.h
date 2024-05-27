
#ifndef PROIECT_COLECTIV_CUSTOMERCONTROLLER_H
#define PROIECT_COLECTIV_CUSTOMERCONTROLLER_H

#include "../../Repository/IRepo.h"
#include "../../Domain/Customer_Domain/Customer.h"
#include "../../Domain/Car_Domain/Car.h"
#include "../../Domain/Order_Domain/Order.h"
#include <vector>
#include <string>
#include <memory>

class CustomerController {
private:
    std::shared_ptr<IRepo<Customer>> customerRepo;
    std::shared_ptr<IRepo<Car>> carRepo;
    std::shared_ptr<IRepo<Order>> orderRepo;

public:
    CustomerController(const std::shared_ptr<IRepo<Customer>> &customer_repo, const std::shared_ptr<IRepo<Car>> &car_repo);

    bool add_car_to_favorites(int customer_id, const Car &car);
    bool remove_car_from_favorites(int customer_id, const Car &car);
};


#endif //PROIECT_COLECTIV_CUSTOMERCONTROLLER_H
