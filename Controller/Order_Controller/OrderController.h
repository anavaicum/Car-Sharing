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
    Order_Controller();

    bool create_order(const Order& order);

    bool update_order(const Order& existing_order, const Order& new_order);

    bool complete_order(Order& order);

    bool take_over_order(Order& order, int employee_id);

    Order get_by_id(int id) const;

    float get_total_price_year(int year) const;

    float get_total_price_month(int month) const;



};



#endif //PROIECT_COLECTIV_ORDERCONTROLLER_H
