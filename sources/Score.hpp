#pragma once
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"


class Score
{
private:
    Leauge *leauge;
    Schedule *schedule;
    std::map<std::pair<int,std::pair<int, std::string>>, Game*> games_schedule;
    std::map<std::string, std::pair<int, int>> game_wins_losses;
    std::map<std::string, std::pair<int, int>> team_scores_lost;

    int longest_wins_series;
    int longest_losses_series;
    bool flag;

public:
    Score();
    Score(Leauge *l, Schedule* s);
    ~Score();
    Score(Score&& other) noexcept;
    Score(const Score& other);
    Score& operator=(Score&& other) noexcept;

    Score& operator=(const Score& other);

    int longest_wins_in_a_row() const ;
    int longest_losses_in_a_row() const ;
    int teams_with_more_wins() const ;
    void leading_teams(int num);
    void wining_table();
    void basket_scores_minus_losses_table();
};
