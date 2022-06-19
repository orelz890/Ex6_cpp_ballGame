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
    Team(Team&& other) noexcept;

    // Team& operator=(Team&& other) noexcept;
    Team& operator=(const Team& other);
    bool operator==(const Team& other) const;
    bool operator!=(const Team& other) const;
    bool operator>(const Team& other) const;
    bool operator<(const Team& other) const;
    std::string& operator*();
    friend std::ostream& operator<<(std::ostream& os , const Team& t);


    std::string get_name();
    int get_wins() const;
    int get_losses() const;
    void inc_wins();
    void inc_losses();
    double get_skill_lvl() const;
    double set_skill_lvl(double skill);

    double preformance_val() const;
};
