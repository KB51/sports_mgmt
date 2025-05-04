#include "tournament.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void Tournament::addTournament() {
    std::string name, date, time, location;
    std::cin.ignore();
    std::cout << "Enter tournament name: ";
    getline(std::cin, name);
    std::cout << "Enter date (YYYY-MM-DD): ";
    getline(std::cin, date);
    std::cout << "Enter time (HH:MM): ";
    getline(std::cin, time);
    std::cout << "Enter location: ";
    getline(std::cin, location);

    std::ofstream file("tournaments.txt", std::ios::app);
    file << name << "," << date << "," << time << "," << location << "\n";
    std::cout << "Tournament added successfully!\n";
}

void Tournament::viewTournaments() {
    std::ifstream file("tournaments.txt");
    if (!file) {
        std::cout << "No tournaments found.\n";
        return;
    }
    std::string line;
    std::cout << "\n--- Tournaments ---\n";
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string name, date, time, location;
        getline(iss, name, ',');
        getline(iss, date, ',');
        getline(iss, time, ',');
        getline(iss, location, ',');
        std::cout << "Name: " << name << ", Date: " << date << ", Time: " << time << ", Location: " << location << "\n";
    }
}

void Tournament::editTournament() {
    std::vector<std::string> lines;
    std::ifstream file("tournaments.txt");
    if (!file) {
        std::cout << "No tournaments to edit.\n";
        return;
    }
    std::string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    std::string target;
    std::cin.ignore();
    std::cout << "Enter tournament name to edit: ";
    getline(std::cin, target);

    bool found = false;
    for (auto& l : lines) {
        std::istringstream iss(l);
        std::string name, date, time, location;
        getline(iss, name, ',');
        if (name == target) {
            std::cout << "Editing " << name << "\n";
            std::cout << "Enter new date (YYYY-MM-DD): ";
            getline(std::cin, date);
            std::cout << "Enter new time (HH:MM): ";
            getline(std::cin, time);
            std::cout << "Enter new location: ";
            getline(std::cin, location);
            l = name + "," + date + "," + time + "," + location;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Tournament not found.\n";
        return;
    }
    std::ofstream out("tournaments.txt");
    for (const auto& l : lines) {
        out << l << "\n";
    }
    std::cout << "Tournament updated.\n";
}

void Tournament::registerForTournament(const std::string& athleteName) {
    std::string tournament;
    std::cin.ignore();
    std::cout << "Enter tournament name to register: ";
    getline(std::cin, tournament);

    // Check if tournament exists
    std::ifstream file("tournaments.txt");
    bool exists = false;
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        getline(iss, name, ',');
        if (name == tournament) {
            exists = true;
            break;
        }
    }
    if (!exists) {
        std::cout << "Tournament not found.\n";
        return;
    }

    std::ofstream reg("registrations.txt", std::ios::app);
    reg << athleteName << " registered for " << tournament << "\n";
    std::cout << "Registration successful!\n";
}

void Tournament::viewSchedule() {
    viewTournaments();
}
