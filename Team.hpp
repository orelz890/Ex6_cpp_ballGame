#include <string>

class Team
{
private:
    std::string name;
    double skill_level;
public:
    Team(std::string& name, double skill);
    Team(const Team& other);
    Team();
    ~Team();

    Team& operator=(const Team& other);
    bool operator==(const Team& other);
    bool operator!=(const Team& other);
    bool operator>(const Team& other);
    bool operator<(const Team& other);

    std::string get_name();
    double get_skill_lvl();
};
