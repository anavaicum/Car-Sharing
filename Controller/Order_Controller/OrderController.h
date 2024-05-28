#ifndef PROIECT_COLECTIV_ORDERCONTROLLER_H
#define PROIECT_COLECTIV_ORDERCONTROLLER_H


#include "../../Repository/IRepo.h"
#include "../../Domain/Order_Domain/Order.h"

#include "../../Repository/Repo.h"
#include <vector>

class Order_Controller {
private:
    shared_ptr<IRepo<Order>> order_repo;
    std::string type; // Field to store type of controller

public:
    Order_Controller(IRepo<Order>& repo);

    bool create_order(const Order& order);


};



#endif //PROIECT_COLECTIV_ORDERCONTROLLER_H
