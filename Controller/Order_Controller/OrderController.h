#ifndef PROIECT_COLECTIV_ORDERCONTROLLER_H
#define PROIECT_COLECTIV_ORDERCONTROLLER_H


#include "../../Repository/IRepo.h"
#include "../../Domain/Order_Domain/Order.h"

class Order_Controller {
private:
    IRepo<Order>& order_repo;

public:
    Order_Controller(IRepo<Order>& repo);

    bool create_order(const Order& order);


};



#endif //PROIECT_COLECTIV_ORDERCONTROLLER_H
