#include "Team.hpp"


Team::Team(std::string& name, double skill)
{
    this->name = name;
    this->skill_level = skill;
}


Team::Team(const Team& other) : name(other.name), skill_level(other.skill_level)
{
}

Team::Team() : skill_level(0) 
{
}


Team::~Team()
{

}


Team& Team::operator=(const Team& other)
{
    this->name = other.name;
    this->skill_level = other.skill_level;
}


bool Team::operator==(const Team& other)
{
    return this->skill_level == other.skill_level;
}


bool Team::operator!=(const Team& other)
{
    return !(*this == other);
}


bool Team::operator>(const Team& other)
{
    return this->skill_level > other.skill_level;
}


bool Team::operator<(const Team& other)
{
    return !((*this == other) || (*this > other));
}


std::string Team::get_name()
{
    return this->name;
}


double Team::get_skill_lvl()
{
    return this->skill_level;
}
