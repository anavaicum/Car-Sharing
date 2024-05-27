
#ifndef PROIECT_COLECTIV_CONTROLLER_H
#define PROIECT_COLECTIV_CONTROLLER_H

#include "../Repository/Repo.h"

template <class T>
class Controller {
private:
    IRepo<T>& repo;

public:
    // Constructor
    Controller(IRepo<T>& repository);

    // Getter for repo
    IRepo<T>& get_repo() const;

    // Setter for repo
    void set_repo(IRepo<T>& repository);
};

#endif //PROIECT_COLECTIV_CONTROLLER_H
