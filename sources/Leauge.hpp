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
    std::string generate_name() const;

    Leauge();
    Leauge(Team* teams, const int size);
    Leauge(Team* teams);
    ~Leauge();
    Leauge(Leauge&& other) noexcept;

    Leauge& operator=(Leauge&& other) noexcept;
    Team& operator[](int);
    Iterator begin();
    static Iterator end();
    // Team* operator++(int);
    // Team* operator++();
};
