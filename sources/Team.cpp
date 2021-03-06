#include "Team.hpp"


Team::Team(std::string& name, double skill) : name(name), skill_level(skill), wins(0), losses(0)
{
}


Team::Team(const Team& other) : name(other.name), skill_level(other.skill_level), wins(0), losses(0)
{
}


Team::Team() : skill_level(0), wins(0), losses(0)
{
}


Team::Team(Team&& other) noexcept : Team()
{
    *this = std::move(other);
}


// Team& Team::operator=(Team&& other) noexcept
// {
//     *this = std::move(other);
//     return *this;
// }


Team::~Team()
{

}


int Team::get_wins() const
{
    return this->wins;
}


int Team::get_losses() const
{
    return this->losses;
}


void Team::inc_wins()
{
    this->wins++;
}


void Team::inc_losses()
{
    this->losses++;
}


Team& Team::operator=(const Team& other)
{
    this->name = other.name;
    this->skill_level = other.skill_level;
    return *this;
}


bool Team::operator==(const Team& other) const
{
    return this->skill_level == other.skill_level;
}


bool Team::operator!=(const Team& other) const
{
    return !(*this == other);
}


bool Team::operator>(const Team& other) const
{
    return this->skill_level > other.skill_level;
}


bool Team::operator<(const Team& other) const
{
    return !((*this == other) || (*this > other));
}


std::string& Team::operator*()
{
    return this->name;
}


std::string Team::get_name()
{
    return this->name;
}


double Team::get_skill_lvl() const
{
    return this->skill_level;
}


double Team::set_skill_lvl(double skill)
{
    this->skill_level = skill;
    return skill;
}


double Team::preformance_val() const
{
    return (double)(this->wins)/((double)(this->losses + this->wins));
}


std::ostream& operator<<(std::ostream& os , const Team& t)
{
    os << t.name;
    return os;
}
