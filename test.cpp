#include "doctest.h"
#include "sources/Game.hpp"
#include "sources/Leauge.hpp"
#include "sources/Schedule.hpp"
#include "sources/Score.hpp"
#include "sources/Team.hpp"
#include "sources/my_iterator.hpp"


#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

TEST_CASE("Good tests"){
    cout << "========================================== Start testing ==========================================\n";

/* ============
    * Init check
    * ============*/
    Leauge* leauge = new Leauge();
    // Team* team;
    std::vector<std::string> names;
    for (auto i = leauge->begin(); i != leauge->end(); ++i)
    {
        cout << "Name:" << i->get_name() <<" Losses: " << i->get_losses() << " winings: " << i->get_wins() << " skill lvl: "<<  i->get_skill_lvl() << "\n";
        // Verify all the names are diffrent
        assert(find(names.begin(), names.end(), i->get_name()) == names.end());
        assert(i->get_losses() == 0 && i->get_wins() == 0 && i->get_skill_lvl() != 0);
    }

    Schedule* schedule = new Schedule(leauge);
    for (int i = 0; i < TEAMS_SIZE; i++)
    {
        assert((*leauge)[i] == (*schedule->get_leauge())[i]);
    }
    assert(schedule->get_games_counter() == 380);
    cout << "There where " << schedule->get_games_counter() << " games\n";
    Score* score = new Score(leauge, schedule);


    SUBCASE("Init check"){
        // Check the iterator
        int j = 0;

        for (auto i = leauge->begin(); i != leauge->end(); ++i)
        {
            std::string n = "Team_";
            n += ('A' + j++);
            CHECK_FALSE((*(*i)) != n);
            CHECK_FALSE((*i).get_skill_lvl() <= 0);
            CHECK_FALSE(i->get_losses() + i->get_wins() <= 0);
        }
        CHECK_NOTHROW(score->wining_table());
        CHECK_NOTHROW(score->basket_scores_minus_losses_table());
        
    }// Init check


    SUBCASE("Bad cases")
    {
        CHECK_THROWS((*leauge)[-1]);
        CHECK_THROWS((*leauge)[20]);
        CHECK_THROWS(score->leading_teams(-1));
        CHECK_THROWS(score->leading_teams(20));

    }


}