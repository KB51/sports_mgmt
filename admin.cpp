#include "admin.h"
#include "tournament.h"
#include <iostream>
#include <fstream>
#include <sstream>

Admin::Admin() : User() {}
Admin::Admin(const std::string& uname) : User(uname, "", "admin") {}

void Admin::adminMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. Add Tournament\n";
        std::cout << "2. Edit Tournament Schedule\n";
        std::cout << "3. View Tournaments\n";
        std::cout << "4. View Registrations\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: addTournament(); break;
            case 2: editTournament(); break;
            case 3: Tournament::viewTournaments(); break;
            case 4: viewRegistrations(); break;
            case 5: return;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

void Admin::addTournament() {
    Tournament::addTournament();
}

void Admin::editTournament() {
    Tournament::editTournament();
}

void Admin::viewRegistrations() {
    std::ifstream file("registrations.txt");
    if (!file) {
        std::cout << "No registrations found.\n";
        return;
    }
    std::string line;
    std::cout << "\n--- Tournament Registrations ---\n";
    while (getline(file, line)) {
        std::cout << line << "\n";
    }
}
