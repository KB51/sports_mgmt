#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string userName;
    std::string password;
    std::string role;
public:
    User();
    User(const std::string& uname, const std::string& pwd, const std::string& r);
    virtual ~User() {}
    bool isValidUsername(const std::string& username);
    virtual void signUp();
    virtual bool login();
    std::string getRole() const;
    std::string getUserName() const;
};

#endif
