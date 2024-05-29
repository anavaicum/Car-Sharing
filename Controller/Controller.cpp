#include "Controller.h"

// Constructor implementation
template <class T>
Controller<T>::Controller(IRepo<T>& repository) : repo(repository) {}

// Getter for repo implementation
template <class T>
IRepo<T>& Controller<T>::get_repo() const {
    return repo;
}

// Setter for repo implementation
template <class T>
void Controller<T>::set_repo(IRepo<T>& repository) {
    repo = repository;
}


