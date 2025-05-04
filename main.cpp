#include <iostream>
#include "user.h"
#include "admin.h"
#include "athlete.h"

int main() {
    int choice;
    while (true) {
        std::cout << "\n--- Sports Management System ---\n";
        std::cout << "1. Sign Up\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            User u;
            u.signUp();
        } else if (choice == 2) {
            User u;
            if (u.login()) {
                if (u.getRole() == "admin") {
                    Admin admin(u.getUserName());
                    admin.adminMenu();
                } else {
                    Athlete athlete(u.getUserName());
                    athlete.athleteMenu();
                }
            }
        } else if (choice == 3) {
            std::cout << "Exiting program.\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
