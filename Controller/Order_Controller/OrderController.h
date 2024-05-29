#ifndef PROIECT_COLECTIV_ORDERCONTROLLER_H
#define PROIECT_COLECTIV_ORDERCONTROLLER_H


#include "../../Repository/IRepo.h"
#include "../../Domain/Order_Domain/Order.h"

#include "../../Repository/Repo.h"
#include <vector>

class Order_Controller {
private:
    shared_ptr<IRepo<Car>> car_repo;
    shared_ptr<IRepo<Order>> order_repo;
    shared_ptr<IRepo<Customer>> customer_repo;
    shared_ptr<IRepo<Employee>> employee_repo;
    std::string type; // Field to store type of controller
    int find_next_id();
public:
    /**
     * Initialises the necessary Repos
     */
    Order_Controller();

    bool create_order(const Order& order);
    /**
     * Creates an order with the following params
     * @param o_date
     * @param stat
     * @param b_date
     * @param e_date
     * @param tot_price
     * @param car_id
     * @param emp_id
     * @param cus_id
     * @return
     */
    bool create_order(Date o_date, string stat, Date b_date, Date e_date,
                      float tot_price, int car_id, int emp_id, int cus_id);

    /**
     * Creates an Order with the status as Reserved
     * @param o_date
     * @param b_date
     * @param e_date
     * @param car_id
     * @param emp_id
     * @param cus_id
     * @return
     */
    bool create_reservation(Date o_date, Date b_date, Date e_date,int car_id , int emp_id, int cus_id);

    bool update_order(const Order& existing_order, const Order& new_order);
    /**
     * Sets order as completed
     * @param id
     * @return
     */
    bool complete_order(int id);

    bool take_over_order(Order& order, int employee_id);
    /**
     *
     * @param id
     * @return Order that has the same id as the param
     */
    Order get_by_id(int id) const;

    float get_total_price_year(int year) const;

    float get_total_price_month(int month) const;

    bool update_reservation(const Order& updated_order);
    /**
     * @param start_date
     * @param end_date
     * @return Orders that have their order_date between the dates in the params
     */
    std::vector<Order> get_orders_between_dates(const Date& start_date, const Date& end_date) const;
    std::vector<Order> get_orders_sorted_by_price() const;

    bool give_order_to_coworker(Order& order);

    bool delete_reservation(int id);
    /**
     * Make a order into a Reservation
     * @param orderId
     * @param customerId
     * @return
     */
    bool make_reservation(int orderId, int customerId);
    /**
     * @param car_id
     * @return vector of all customers that have ordered a car with the id
     */
    vector<Customer> get_customers_by_ordered_car(int car_id);


};



#endif //PROIECT_COLECTIV_ORDERCONTROLLER_H
