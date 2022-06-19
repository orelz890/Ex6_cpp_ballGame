#include "Game.hpp"


Game::Game() : Game(NULL, NULL, -1, -1)
{
}


Game::Game(Team* t1, Team* other,int home_score, int other_score)
{
    this->home_Team = t1;
    this->other_Team = other;
    this->home_team_score = home_score;
    this->other_team_score = other_score;
}


Game::~Game()
{

}


Game::Game(Game&& other) noexcept : Game()
{
    *this = std::move(other);
}


Game::Game(const Game& g) : home_Team(g.home_Team), home_team_score(g.home_team_score),
     other_team_score(g.other_team_score), other_Team(g.other_Team) 
{
}

Game& Game::operator=(const Game& g)
{
    this->home_Team = g.home_Team;
    this->home_team_score = g.home_team_score;
    this->other_team_score = g.other_team_score;
    this->other_Team = g.other_Team;
    
    return *this;
}

Game& Game::operator=(Game&& other) noexcept
{
    *this = std::move(other);
    return *this;
}


Team& Game::winning_team()
{
    if (this->home_team_score != this->other_team_score)
    {
        return this->home_team_score > this->other_team_score ? *this->home_Team : *this->other_Team;
    }
    return *this->other_Team;
}

Team& Game::lossing_team()
{
    if (this->home_team_score != this->other_team_score)
    {
        return this->home_team_score < this->other_team_score ? *this->home_Team : *this->other_Team;
    }
    return *this->home_Team;
}
