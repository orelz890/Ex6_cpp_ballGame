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


Leauge::Leauge(Team teams[TEAMS_SIZE], const int size)
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


Leauge::Leauge(Leauge&& other) noexcept : Leauge()
{
    *this = std::move(other);
}


Leauge& Leauge::operator=(Leauge&& other) noexcept
{
    *this = std::move(other);
    return *this;
}


Team& Leauge::operator[](int i)
{
    if (i < 0 || i >= TEAMS_SIZE)
    {
        throw "Leauge - Out of bounds!\n";
    }
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


std::string Leauge::generate_name() const
{
    std::string ans;
    ans.clear();
    ans += "Team_";
    ans+= ((char)this->current_size + 'A');
    return ans;
}
