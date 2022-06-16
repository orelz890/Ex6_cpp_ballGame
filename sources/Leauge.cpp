#include "Leauge.hpp"


Leauge::Leauge()
{
    this->current_size = 0;
    for(Team& t : this->all_teams)
    {
        std::string n = this->generate_name();
        t = Team(n,rand()/(double)RAND_MAX);
        this->current_size++;
    }
}


Leauge::Leauge(Team* teams, const int size)
{
    this->current_size = 0;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        if (i < size)
        {
            this->all_teams[i] = teams[i];
        }
        else
        {
            std::string n = this->generate_name();
            this->all_teams[i] = Team(n,rand()/(double)RAND_MAX);
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


my_iterator<Leauge,Team> Leauge::begin()
{
    return my_iterator<Leauge,Team>{this};
}


my_iterator<Leauge,Team> Leauge::end()
{
    return my_iterator<Leauge,Team>{};
}


std::string Leauge::generate_name()
{
    std::string ans;
    ans.clear();
    ans += "Team_";
    ans+= (this->current_size + 'A');
    // printf("ans = %s\n",ans.c_str());
    return ans;
}


