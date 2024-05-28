#include "../../Controller/Customer_Controller/CustomerController.h"
#include <algorithm>  // For std::remove_if

CustomerController::CustomerController(const shared_ptr<IRepo<Customer>> &customer_repo,
                                       const shared_ptr<IRepo<Car>> &car_repo,
                                       const shared_ptr<IRepo<Order>> &order_repo)
        : customerRepo(customer_repo), carRepo(car_repo), orderRepo(order_repo){}




CustomerController::CustomerController() {
    repo = make_shared<Repo<Customer>>("../../Repository/CustomerRepo.txt");
    this->customerRepo = make_shared<Repo<Customer>>("../../Repository/CustomerRepo.txt");
    this->carRepo = make_shared<Repo<Car>>("../../Repository/CarRepo.txt");
    this->orderRepo = make_shared<Repo<Order>>("../../Repository/OrderRepo.txt");
}


bool CustomerController::add_car_to_favorites(int customer_id, const Car &car) {
    try {
        Customer customer = customerRepo->get_by_Id(customer_id);
        customer.add_favorite(car);
        customerRepo->update(customer_id, customer);
        return true;
    } catch (const std::exception &e) {
        return false;
    }
}

bool CustomerController::remove_car_from_favorites(int customer_id, const Car &car) {
    try {
        // Get the customer from the repository
        Customer customer = customerRepo->get_by_Id(customer_id);

        // Get the favorites vector
        auto favorites = customer.get_favorites();

        // Create a temporary vector to hold the elements we want to keep
        std::vector<Car> temp;
        temp.reserve(favorites.size()); // Reserve memory to avoid reallocation

        // Copy elements to temp vector, excluding the one to be removed
        for (const auto &favorite : favorites) {
            if (favorite.getLicensePlate() != car.getLicensePlate()) {
                temp.push_back(favorite);
            }
        }

        // Create a new Customer object with the modified favorites
        Customer new_customer(customer.get_id(), customer.get_email(), customer.get_password(), customer.get_first_name(),
                              customer.get_last_name(), customer.get_phone(), customer.get_address(), customer.is_GDPRdeleted(),
                              temp); // Assuming there is a constructor to create a new Customer with modified favorites

        // Update the customer in the repository with the new object
        customerRepo->update(customer_id, new_customer);

        return true;
    } catch (const std::exception &e) {
        return false;
    }
}

vector<Car> CustomerController::get_favorites(int customer_id)
{
    vector<Car> favorites;
    Customer customer = customerRepo->get_by_Id(customer_id);
    favorites = customer.get_favorites();
    return favorites;
}

bool CustomerController::create_customer(Customer customer) {

    return customerRepo->add(customer);
}

bool CustomerController::update_customer(int customer_id, Customer customer) {
    return customerRepo->update(customer_id,customer);
}

bool CustomerController::delete_customer(int customer_id) {
    return customerRepo->delete_by_id(customer_id);
}

bool CustomerController::GDPR_customer(int customer_id) {
    Customer customer=customerRepo->get_by_Id(customer_id);
    return customer.is_GDPRdeleted();
}

vector<Customer> CustomerController::get_all_customers_sorted() {
    vector<Customer> customers=customerRepo->get_all();
    sort(customers.begin(), customers.end(), [](const Customer &customer1, const Customer &customer2) {
        return customer1.get_last_name() < customer2.get_last_name();
    });


    return customers;
}

Customer CustomerController::search_by_email(string email) {
    vector<Customer> customers=customerRepo->get_all();

    for(const auto &customer:customers)
    {
        if(customer.get_email()==email)
            return customer;
    }
}

Customer CustomerController::search_by_phone(string phone) {
    vector<Customer> customers=customerRepo->get_all();

    for(const auto &customer:customers)
    {
        if(customer.get_phone()==phone)
            return customer;
    }
}

Customer CustomerController::search_by_name(string first_name, string last_name) {
    vector<Customer> customers=customerRepo->get_all();

    for(const auto &customer:customers)
    {
        if(customer.get_first_name()==first_name && customer.get_last_name()==last_name)
            return customer;
    }
}







