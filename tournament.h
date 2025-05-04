#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>

class Tournament {
public:
    static void addTournament();
    static void viewTournaments();
    static void editTournament();
    static void registerForTournament(const std::string& athleteName);
    static void viewSchedule();
};

#endif
