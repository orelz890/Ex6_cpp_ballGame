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
    Game(const Game& g);
    ~Game();
    Game(Game&& other) noexcept;

    Game& operator=(const Game& g);
    Game& operator=(Game&& other) noexcept;
    Team& winning_team();
    Team& lossing_team();
};
