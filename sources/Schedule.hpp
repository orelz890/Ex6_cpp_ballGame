#pragma once
#include <map>
#include "Leauge.hpp"

const int ROUNDS_NUM = 2;

class Schedule
{
private:
    std::map<std::pair<int, std::pair<int, std::string>>, std::string> games_schedule;
    Leauge* leauge;
    int games_counter;

public:
    Schedule(Leauge* l);
    ~Schedule();

    Leauge* get_leauge();
    int get_games_counter();
    std::string& get_oponnent(int round, int game, int team);
    void print_games_schedule();

};
