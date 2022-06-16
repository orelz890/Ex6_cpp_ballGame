#pragma once
#include <string>

const int TEAMS_SIZE = 20;

class Team
{
private:
    std::string name;
    double skill_level;
    int wins;
    int losses;

public:
    Team(std::string& name, double skill);
    Team(const Team& other);
    Team();
    ~Team();

    Team& operator=(const Team& other);
    bool operator==(const Team& other);
    bool operator!=(const Team& other);
    bool operator>(const Team& other);
    bool operator<(const Team& other);

    std::string get_name();
    int get_wins();
    int get_losses();
    void inc_wins();
    void inc_losses();
    double get_skill_lvl();

    double preformance_val();
};
