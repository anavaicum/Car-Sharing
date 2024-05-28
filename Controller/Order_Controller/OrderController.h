#ifndef PROIECT_COLECTIV_ORDERCONTROLLER_H
#define PROIECT_COLECTIV_ORDERCONTROLLER_H


#include "../../Repository/IRepo.h"
#include "../../Domain/Order_Domain/Order.h"

#include "../../Repository/Repo.h"
#include <vector>

class Order_Controller {
private:
    shared_ptr<IRepo<Order>> order_repo;
    shared_ptr<IRepo<Customer>> customer_repo;
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

    bool update_reservation(const Order& updated_order);

    std::vector<Order> get_orders_between_dates(const Date& start_date, const Date& end_date) const;
    std::vector<Order> get_orders_sorted_by_price() const;

    bool give_order_to_coworker(Order& order);

    bool delete_reservation(int id);

    bool make_reservation(int orderId, int customerId);




};



#endif //PROIECT_COLECTIV_ORDERCONTROLLER_H
