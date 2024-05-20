#ifndef PROIECT_COLECTIV_ADMINUI_H
#define PROIECT_COLECTIV_ADMINUI_H


#include "EmployeeUI.h"

class AdminUI : public EmployeeUI {
public:
    void createWorker();
    void updateWorker();
    void activateWorker();
    void deactivateWorker();
    void deleteWorker();
    void giveAdminRights();
    void workerSalary();
    void changeWorkerSalary();
};


#endif //PROIECT_COLECTIV_ADMINUI_H
