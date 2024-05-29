#include "../../Controller/Customer_Controller/CustomerController.h"
#include <algorithm>  // For std::remove_if

CustomerController::CustomerController(const shared_ptr<IRepo<Customer>> &customer_repo,
                                       const shared_ptr<IRepo<Car>> &car_repo,
                                       const shared_ptr<IRepo<Order>> &order_repo)
        : customerRepo(customer_repo), carRepo(car_repo), orderRepo(order_repo){}




CustomerController::CustomerController() {
    repo = make_shared<Repo<Customer>>("../Repository/CustomerRepo.txt");
    this->customerRepo = make_shared<Repo<Customer>>("../Repository/CustomerRepo.txt");
    this->carRepo = make_shared<Repo<Car>>("../Repository/CarRepo.txt");
    this->orderRepo = make_shared<Repo<Order>>("../Repository/OrderRepo.txt");
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


bool GDPR_customer(int customerID) {
//    CustomerRepository customerRepo;
//    Customer* customer = customerRepo.getCustomerByID(customerID);
//    if (customer == nullptr) {  // Customer not found
//        return false;
//    }
//    return customer->is_GDPRdeleted();
}

std::vector<Customer> get_all_customers_sorted() {
//    CustomerRepository customerRepo;
//    std::vector<Customer> customers = customerRepo.getAllCustomers();
//    std::sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {    //by last name
//        return a.get_last_name() < b.get_last_name();
//    });
//
//    return customers;
}


vector<Customer> CustomerController::search_by_email(string email) {
    vector<Customer> customers=customerRepo->get_all();
    vector<Customer> result;
    for(const auto &customer:customers)
    {
        if(customer.get_email()==email)
            result.push_back(customer);
    }
    return result;
}

vector<Customer> CustomerController::search_by_phone(string phone) {
    vector<Customer> customers=customerRepo->get_all();
    vector<Customer> result;
    for(const auto &customer:customers)
    {
        if(customer.get_phone()==phone)
        {
            result.push_back(customer);
        }
    }
    return result;
}

vector<Customer> CustomerController::search_by_name(string first_name, string last_name) {
    vector<Customer> customers=customerRepo->get_all();
    vector<Customer> result;
    for(const auto &customer:customers)
    {
        if(customer.get_first_name()==first_name && customer.get_last_name()==last_name)
        {
            result.push_back(customer);
        }
    }
    return result;
}

bool CustomerController::create_customer(string mail, string pass, string f_name, string l_name,
                                         string ph, string address) {


    Customer cus = Customer(find_next_id(), mail, pass, f_name,
                            l_name, ph, address, false, vector<Car>());

    customerRepo->add(cus);

    return true;
}

int CustomerController::find_next_id() {
    vector<Customer> customers = customerRepo->get_all();
    int max = 0;
    for(auto customer : customers){
        if(max < customer.get_id()){
            max = customer.get_id();
        }
    }
    return max + 1;
}

bool CustomerController::update_customer(int customer_id, string mail, string pass, string f_name,
                                         string l_name, string ph,string addr) {

    for(auto customer : customerRepo->get_all()){
        if(customer.get_id() == customer_id){
            Customer cus = Customer(customer_id, mail, pass, f_name,
                                    l_name, ph, addr, customer.is_GDPRdeleted(), customer.get_favorites());
            customerRepo->update(customer_id, cus);
            return true;
        }
    }
    return false;
}

bool CustomerController::update_customer(int customer_id, bool gdpr) {
    for(auto c : customerRepo->get_all()){
        if(c.get_id() == customer_id){
            Customer cus(customer_id, c.get_email(), c.get_password(), c.get_first_name(), c.get_last_name(),
                         c.get_phone(), c.get_address(), gdpr, c.get_favorites());
            customerRepo->update(customer_id, cus);
            return true;
        }
    }
    return false;
}

vector<Customer> CustomerController::get_all_customers() {
    return customerRepo->get_all();
}

bool CustomerController::delete_customer(int customer_id) {
    customerRepo->delete_by_id(customer_id);
    return false;
}

vector<Customer> CustomerController::get_all_customers_sorted() {
    return vector<Customer>();
}

Customer CustomerController::get_by_id(int customer_id) {
    return customerRepo->get_by_Id(customer_id);
}

