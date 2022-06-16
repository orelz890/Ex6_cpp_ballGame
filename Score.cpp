#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include "Score.hpp"

Score::Score()
{
    this->leauge = new Leauge();
    this->schedule = new Schedule(*leauge);
    this->longest_losses_series = 0;
    this->longest_wins_series = 0;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        this->game_wins_losses[(*this->leauge)[i].get_name()] = {0,0};
    }
    
    for (int  round = 0; round < 2; round++)
    {    
        for (int i = 0; i < TEAMS_SIZE; i++)
        {
            for (int j = i + 1; j < TEAMS_SIZE; j++)
            {
                // Create the current 2 teams game
                std::pair<int,std::string> key;
                std::pair<int, std::pair<int,std::string>> key2;
                key = {i, this->schedule->get_oponnent(round, i,j)};
                key2 = {0, key};
                this->games_schedule.at(key2) = new Game(&((*this->leauge)[i]), &((*this->leauge)[j]), (int)(55 + rand()%45), (int)(50 + rand()%50));
                
                // Update the scores
                Team* winningTeam = &(this->games_schedule.at(key2)->winning_team());
                Team* lossingTeam = &(this->games_schedule.at(key2)->lossing_team());
                winningTeam->inc_wins();
                lossingTeam->inc_losses();
                int current_winning_team_wins = this->game_wins_losses[winningTeam->get_name()].first + 1;
                this->game_wins_losses[winningTeam->get_name()] = {current_winning_team_wins, 0};
                if (current_winning_team_wins > this->longest_wins_series)
                {
                    this->longest_wins_series = current_winning_team_wins;
                }
                int current_lossing_team_losses = this->game_wins_losses[winningTeam->get_name()].second + 1;
                this->game_wins_losses[winningTeam->get_name()] = {0, current_lossing_team_losses};
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
    delete this->leauge;
    delete this->schedule;
}


int Score::longest_wins_in_a_row()
{
    return this->longest_wins_series;
}


int Score::longest_losses_in_a_row()
{
    return longest_losses_series;
}


int Score::teams_with_more_wins()
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


void Score::leading_teams(const int num)
{
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


void Score::wining_table()               // not finished
{
    int longest_name = 0;
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        int current_name_len = (*this->leauge)[i].get_name().length();
        if (current_name_len > longest_name)
        {
            longest_name = current_name_len;
        }
    }
    longest_name++;
    
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        std::cout << "| " << (*this->leauge)[i].get_name() << "| ";
    }
    
}


void basket_scores_minus_losses_table();

