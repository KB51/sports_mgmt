#include "athlete.h"
#include "tournament.h"
#include <iostream>

Athlete::Athlete() : User() {}
Athlete::Athlete(const std::string& uname) : User(uname, "", "athlete") {}

void Athlete::athleteMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- Athlete Menu ---\n";
        std::cout << "1. View Tournaments\n";
        std::cout << "2. Register for Tournament\n";
        std::cout << "3. View Tournament Schedule\n";
        std::cout << "4. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: viewTournaments(); break;
            case 2: registerForTournament(); break;
            case 3: viewSchedule(); break;
            case 4: return;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

void Athlete::viewTournaments() {
    Tournament::viewTournaments();
}

void Athlete::registerForTournament() {
    Tournament::registerForTournament(userName);
}

void Athlete::viewSchedule() {
    Tournament::viewSchedule();
}
