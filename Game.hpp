#pragma once
#include "Team.hpp"

class Game
{
private:
    Team* home_Team;
    Team* other_Team;
    int home_team_score;
    int other_team_score;

public:
    Game();
    Game(Team* t1, Team* other,int home_score, int other_score);
    ~Game();

    Team& winning_team();
    Team& lossing_team();
};
