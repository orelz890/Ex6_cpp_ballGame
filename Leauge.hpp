
#include "Team.hpp"

const int TEAMS_SIZE = 20;

class Leauge
{
private:
    Team all_teams[TEAMS_SIZE];
    int current_size;
public:
    std::string generate_name();

    Leauge();
    Leauge(Team* teams, const int size);
    Leauge(Team teams[20]);
    ~Leauge();

    Team& operator[](int);

};
