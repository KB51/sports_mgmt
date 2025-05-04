#ifndef ATHLETE_H
#define ATHLETE_H

#include "user.h"

class Athlete : public User {
public:
    Athlete();
    Athlete(const std::string& uname);
    void athleteMenu();
    void registerForTournament();
    void viewTournaments();
    void viewSchedule();
};

#endif
