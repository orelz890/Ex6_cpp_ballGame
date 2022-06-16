#include "Schedule.hpp"
#include <iostream>

Schedule::Schedule(Leauge* l)
{
    this->leauge = l;
    this->games_counter = 0;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        std::string home = (*l)[i].get_name();
        for (int j = i + 1; j < TEAMS_SIZE; j++)
        {
            std::string other_team = (*l)[j].get_name();
            std::pair<int,std::string> key;
            std::pair<int, std::pair<int,std::string>> key2;
            key = {j, home};
            key2 = {0, key};
            this->games_schedule[key2] = other_team;
            key = {i, other_team};
            key2 = {1, key};
            this->games_schedule[key2] = home;
            this->games_counter += 2;
        }
    }
}


Schedule::~Schedule()
{
}


Leauge* Schedule::get_leauge()
{
    return this->leauge;
}

// 0 0 1
std::string& Schedule::get_oponnent(int round, int game, int team)
{
    std::pair<int,std::string> key = {game, (*this->leauge)[team].get_name()};
    std::pair<int, std::pair<int,std::string>> key2 = {round, key};
    // std::cout << "round = "<<  key2.first << " game = " << key2.second.first << " team = " << key2.second.second << '\n';
    return this->games_schedule.at(key2);
}


int Schedule::get_games_counter()
{
    return this->games_counter;
}


void Schedule::print_games_schedule()
{
    for (const auto& kv : this->games_schedule)
    {
        std::cout << "round = "<<  kv.first.first << " game = " << kv.first.second.first << " team = " << kv.first.second.second << " VS " << kv.second << '\n';
    }
}
