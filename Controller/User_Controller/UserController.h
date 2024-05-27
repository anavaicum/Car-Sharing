

#ifndef PROIECT_COLECTIV_USERCONTROLLER_H
#define PROIECT_COLECTIV_USERCONTROLLER_H


#include "../../Domain/User_Domain/User.h"
#include "../../Repository/IRepo.h"

class UserController {
private:
    IRepo<User>& repo;
public:


    void login(const string& email, const string& password);
    bool change_password(const string& new_password);
    bool change_remarks(const vector<string>& remarks);
};


#endif //PROIECT_COLECTIV_USERCONTROLLER_H
