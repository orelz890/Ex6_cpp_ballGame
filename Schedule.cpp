#include "Schedule.hpp"


Schedule::Schedule(Leauge& l)
{
    this->leauge = &l;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        std::string home = l[i].get_name();
        for (int j = i + 1; j < TEAMS_SIZE; j++)
        {
            std::pair<int,std::string> key;
            std::pair<int, std::pair<int,std::string>> key2;
            key = {i, home};
            key2 = {0, key};
            this->games_schedule.at(key2) = l[j].get_name();
            key = {i, l[j].get_name()};
            key2 = {1, key};
            this->games_schedule.at(key2) = home;
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


std::string Schedule::get_oponnent(int round, int game, int team)
{
    std::pair<int,std::string> key = {game, (*this->leauge)[team].get_name()};
    std::pair<int, std::pair<int,std::string>> key2 = {round, key};
    return this->games_schedule.at(key2);
}
