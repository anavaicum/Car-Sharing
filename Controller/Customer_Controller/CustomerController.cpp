#include "../../Controller/Customer_Controller/CustomerController.h"
#include <algorithm>  // For std::remove_if

CustomerController::CustomerController(const std::shared_ptr<IRepo<Customer>> &customer_repo, const std::shared_ptr<IRepo<Car>> &car_repo)
        : customerRepo(customer_repo), carRepo(car_repo) {
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



