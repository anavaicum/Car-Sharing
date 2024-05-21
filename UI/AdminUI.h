#ifndef PROIECT_COLECTIV_ADMINUI_H
#define PROIECT_COLECTIV_ADMINUI_H


#include "EmployeeUI.h"
#include <vector>

class AdminUI : public EmployeeUI {
private:
    std::vector<Employee> workers;
public:
    void create_worker();
    void update_worker();
    void activate_worker();
    void deactivate_worker();
    void delete_worker();
    void give_admin_rights();
    void worker_salary();
    void change_worker_salary();
};


#endif //PROIECT_COLECTIV_ADMINUI_H
