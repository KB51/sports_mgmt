#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.h"

User::User() : userName(""), password(""), role("") {}

User::User(const std::string& uname, const std::string& pwd, const std::string& r)
    : userName(uname), password(pwd), role(r) {}

bool User::isValidUsername(const std::string& username) {
    std::ifstream file("users.txt");
    if (!file) return false;
    std::string line, uname, pwd, r;
    while (getline(file, line)) {
        std::istringstream iss(line);
        iss >> uname >> pwd >> r;
        if (uname == username) return true;
    }
    return false;
}

void User::signUp() {
    clearScreen();
    std::cout << "Enter username: ";
    std::cin >> userName;
    if (isValidUsername(userName)) {
        std::cout << "Username already exists. Try another.\n";
        return;
    }
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter role (athlete/admin): ";
    std::cin >> role;
    std::ofstream file("users.txt", std::ios::app);
    file << userName << " " << password << " " << role << "\n";
    std::cout << "Sign up successful!\n";
}

bool User::login() {
    clearScreen();
    std::string uname, pwd;
    std::cout << "Enter username: ";
    std::cin >> uname;
    std::cout << "Enter password: ";
    std::cin >> pwd;
    std::ifstream file("users.txt");
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string fileU, fileP, fileR;
        iss >> fileU >> fileP >> fileR;
        if (fileU == uname && fileP == pwd) {
            userName = fileU;
            password = fileP;
            role = fileR;
            std::cout << "Login successful! Role: " << role << "\n";
            return true;
        }
    }
    std::cout << "Invalid credentials.\n";
    return false;
}

std::string User::getRole() const { return role; }
std::string User::getUserName() const { return userName; }
