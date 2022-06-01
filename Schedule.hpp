#include <map>
#include "Leauge.hpp"

class Schedule
{
private:
    std::map<std::pair<int, std::string>, std::string> games_schedule;

public:
    Schedule(Leauge& l);
    ~Schedule();

    std::string get_oponnent(int round , std::string& team);
};
