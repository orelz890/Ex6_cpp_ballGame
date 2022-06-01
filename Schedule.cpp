#include "Schedule.hpp"

const int ROUNDS_NUM = 2;

Schedule::Schedule(Leauge& l)
{
    for (int round = 0; round < ROUNDS_NUM; round++)
    {    
        for (int i = 0; i < TEAMS_SIZE; i++)
        {
            std::pair<int,std::string> key;
            if (round == 0)
            {
                key = {round, l[i].get_name()};
            }
            else
            {
                key = {round, l[i].get_name()};                    
            }
            
        }
    }

}


Schedule::~Schedule()
{
}


std::string Schedule::get_oponnent(int round , std::string& team)
{
    std::pair<int,std::string> key = {round,team};
    return this->games_schedule.at(key);
}
