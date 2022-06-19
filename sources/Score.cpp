#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include "Score.hpp"

const int FIFTY = 50;
const int FIFTYFIVE = 55;
const int FORTYFIVE = 45;

Score::Score()
{
    this->flag = true;
    this->leauge = new Leauge();
    this->schedule = new Schedule(leauge);
    Score(this->leauge,this->schedule);
}


Score::Score(Leauge *l, Schedule* s)
{
    this->flag = false;
    this->leauge = l;
    this->schedule = s;
    this->longest_losses_series = 0;
    this->longest_wins_series = 0;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        this->game_wins_losses[(*this->leauge)[i].get_name()] = {0,0};
        this->team_scores_lost[(*this->leauge)[i].get_name()] = {0,0};
    }
    
    for (int  round = 0; round < 2; round++)
    {    
        for (int i = 0; i < TEAMS_SIZE; i++)
        {
            Team* home = &(*this->leauge)[i];
            for (int j = i + 1; j < TEAMS_SIZE; j++)
            {
                Team* opponent = &(*this->leauge)[j];
                // Create the current 2 teams game
                std::pair<int,std::string> key;
                std::pair<int, std::pair<int,std::string>> key2;
                key = {i, home->get_name()};
                key2 = {round, key};
                int home_score = (int)(FIFTYFIVE + rand()%FORTYFIVE);
                this->team_scores_lost[home->get_name()].first += home_score;
                // Rand is not really random therefore change its pointer pos
                srand(time(NULL));
                int opponent_score = (int)(FIFTY + rand()%FIFTY);
                this->team_scores_lost[opponent->get_name()].second += opponent_score;
                this->games_schedule[key2] = new Game(home, opponent, home_score, opponent_score);
                
                // Update the scores
                Team* winningTeam = &(this->games_schedule.at(key2)->winning_team());
                Team* lossingTeam = &(this->games_schedule.at(key2)->lossing_team());
                winningTeam->inc_wins();
                lossingTeam->inc_losses();

                int curr_winning_team_wins_in_a_row = this->game_wins_losses[winningTeam->get_name()].first + 1;
                this->game_wins_losses[winningTeam->get_name()] = {curr_winning_team_wins_in_a_row, 0};
                if (curr_winning_team_wins_in_a_row > this->longest_wins_series)
                {
                    this->longest_wins_series = curr_winning_team_wins_in_a_row;
                }
                int current_lossing_team_losses = this->game_wins_losses[lossingTeam->get_name()].second + 1;
                this->game_wins_losses[lossingTeam->get_name()] = {0, current_lossing_team_losses};
                if (current_lossing_team_losses > this->longest_losses_series)
                {
                    this->longest_losses_series = current_lossing_team_losses;
                }
            }
        }
    }
}


Score::~Score()
{
    if (this->flag)
    {
        delete this->leauge;
        delete this->schedule;
    }
}


Score::Score(Score&& other) noexcept :Score()
{
    *this = std::move(other);
}


Score::Score(const Score& other)
{
    *this = other;
}


Score& Score::operator=(const Score& other)
{
    this->leauge = other.leauge;
    this->flag = other.flag;
    this->game_wins_losses = other.game_wins_losses;
    this->games_schedule = other.games_schedule;
    this->longest_losses_series = other.longest_losses_series;
    this->longest_wins_series = other.longest_wins_series;
    this->schedule = other.schedule;
    this->team_scores_lost = other.team_scores_lost;
    return *this;
}


Score& Score::operator=(Score&& other) noexcept
{
    *this = std::move(other);
    return *this;
}


int Score::longest_wins_in_a_row() const 
{
    return this->longest_wins_series;
}


int Score::longest_losses_in_a_row() const 
{
    return longest_losses_series;
}


int Score::teams_with_more_wins() const
{
    int ans = 0;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        if ((*this->leauge)[i].get_wins() > (*this->leauge)[i].get_losses())
        {
            ans++;
        }
    }
    return ans;
}


bool compereElements(std::pair<std::string, double> e1, std::pair<std::string, double> e2)
{
    return e1.second < e2.second;
}


void Score::leading_teams(int num)
{
    if (num < 0 || num >= TEAMS_SIZE)
    {
        throw "Score - Out of bounds!\n";
    }
    
    std::vector<std::pair<std::string, double>> preformance;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        Team* curr_team = &(*this->leauge)[i];
        preformance.push_back({curr_team->get_name(), curr_team->preformance_val()});
    }
    std::sort(preformance.begin(), preformance.end(), compereElements);
    std::vector<std::pair<std::string, double>> ans = {preformance.begin(), preformance.begin() + num};
    int i = 0;
    for (std::pair<std::string, double>& p : ans)
    {
        std::cout << "Number " << i++ << ": " << p.first << ", with preformance value = " << p.second << "\n";        
    }   
}


void Score::wining_table()
{
    // Find the longest score & name for preatty output
    int longest_name = 0;
    int longest_score = 0;
    for (std::pair<std::string,std::pair<int,int>> a : this->game_wins_losses)
    {
        int curr_name_len = a.first.length();
        if (curr_name_len > longest_name)
        {
            longest_name = curr_name_len;
        }
    }
    longest_name++;
    
    std::cout << "\n  name" << std::string(abs(longest_name - 4) , ' ') << "| wins - losses\n";

    for (std::pair<std::string,std::pair<int,int>> a : this->game_wins_losses)
    {
        int curr_name_len = a.first.length();
        std::cout << "| " << a.first << std::string(longest_name - curr_name_len , ' ') <<  "| "
            << a.second.first - a.second.second << "\n";
    }
}


void Score::basket_scores_minus_losses_table()
{
    // Find the longest score & name for preatty output
    int longest_name = 0;
    int longest_score = 0;
    for (std::pair<std::string,std::pair<int,int>> a : this->team_scores_lost)
    {
        int curr_name_len = a.first.length();
        if (curr_name_len > longest_name)
        {
            longest_name = curr_name_len;
        }
    }
    longest_name++;
        
    std::cout << "\n  name" << std::string(abs(longest_name - 4) , ' ') << "| scored - lost\n";

    for (std::pair<std::string,std::pair<int,int>> a : this->team_scores_lost)
    {
        int curr_name_len = a.first.length();
        std::cout << "| " << a.first << std::string(longest_name - curr_name_len , ' ') <<  "| "
            << a.second.first - a.second.second << "\n";
    }    
}
