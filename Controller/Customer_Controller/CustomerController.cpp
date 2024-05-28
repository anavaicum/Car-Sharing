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

Customer CustomerController::search_by_phone(const std::string& phone) const {
    auto customers = customerRepo->get_all();
    auto it = std::find_if(customers.begin(), customers.end(), [&phone](const Customer& customer) {
        return customer.get_phone() == phone;
    });

    if (it != customers.end()) {
        return *it;
    }

    throw std::runtime_error("Customer with the given phone number not found.");
}


std::vector<Customer> CustomerController::search_by_name(const std::string& first_name, const std::string& last_name) const {
    auto customers = customerRepo->get_all();
    std::vector<Customer> result;
    std::copy_if(customers.begin(), customers.end(), std::back_inserter(result), [&first_name, &last_name](const Customer& customer) {
        return customer.get_first_name() == first_name && customer.get_last_name() == last_name;
    });

    return result;
}


std::vector<Customer> CustomerController::search_by_car(const Car& car) const {
    auto customers = customerRepo->get_all();
    std::vector<Customer> result;

    for (const auto& customer : customers) {
        const auto& favorites = customer.get_favorites();
        if (std::any_of(favorites.begin(), favorites.end(), [&car](const Car& favoriteCar) {
            return favoriteCar.getLicensePlate() == car.getLicensePlate() &&
                   favoriteCar.getModel() == car.getModel() &&
                   favoriteCar.getBrand() == car.getBrand() &&
                   favoriteCar.getYearOfFirstReg() == car.getYearOfFirstReg() &&
                   favoriteCar.getMileage() == car.getMileage() &&
                   favoriteCar.getPricePerDay() == car.getPricePerDay() &&
                   favoriteCar.getFuel() == car.getFuel() &&
                   favoriteCar.getTrans() == car.getTrans() &&
                   favoriteCar.getColor() == car.getColor();
        })) {
            result.push_back(customer);
        }
    }

    return result;
}




