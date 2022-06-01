#include "Game.hpp"
    
Game::Game(Team& t1, Team& other,int home_score, int other_score)
{
    this->home_Team = &t1;
    this->other_Team = &other;
    this->home_team_score = home_score;
    this->other_team_score = other_score;
}


Game::~Game()
{

}

Team& Game::winning_team()
{
    if (this->home_team_score != this->other_team_score)
    {
        return this->home_team_score > this->other_team_score ? *this->home_Team : *this->other_Team;
    }
    return *this->other_Team;
}
