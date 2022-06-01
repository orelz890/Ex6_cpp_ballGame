#include "Leauge.hpp"


Leauge::Leauge()
{
    for(Team& t : this->all_teams)
    {
        std::string n = this->generate_name();
        t = Team(n,rand()/RAND_MAX);
        this->current_size++;
    }
}


Leauge::Leauge(Team* teams, const int size)
{
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        if (i < size)
        {
            this->all_teams[i] = teams[i];
        }
        else
        {
            std::string n = this->generate_name();
            this->all_teams[i] = Team(n,rand()/RAND_MAX);
            this->current_size++;
        }
    }
}


Leauge::Leauge(Team teams[TEAMS_SIZE]) : Leauge(teams, TEAMS_SIZE) 
{
}


Leauge::~Leauge()
{
}


Team& Leauge::operator[](int i)
{
    return this->all_teams[i];
}


std::string Leauge::generate_name()
{
    std::string ans;
    ans += ("Team" + this->current_size);
    return ans;
}