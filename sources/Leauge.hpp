#pragma once
#include "Team.hpp"
#include "my_iterator.hpp"

class Leauge
{
private:
    Team all_teams[TEAMS_SIZE];
    int current_size;
    using Iterator = my_iterator<Leauge,Team>;

public:
    std::string generate_name();

    Leauge();
    Leauge(Team* teams, const int size);
    Leauge(Team teams[20]);
    ~Leauge();

    Team& operator[](int);
    Iterator begin();
    Iterator end();
    // Team* operator++(int);
    // Team* operator++();
};
