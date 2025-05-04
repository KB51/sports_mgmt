#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin : public User {
public:
    Admin();
    Admin(const std::string& uname);
    void adminMenu();
    void addTournament();
    void editTournament();
    void viewRegistrations();
};

#endif
