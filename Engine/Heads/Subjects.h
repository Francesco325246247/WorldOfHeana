

#ifndef UNTITLED2_SUBJECTS_H
#define UNTITLED2_SUBJECTS_H
#include <vector>
#include <string>
#include "Object.h"

class Subjects {
public:
    int level = 1;
    int health = 100;
    int mana = 50;
    int money = 1;
    int experience = 1;
    std::string name;
    std::string gender;
    std::string race;
    std::string classe;
    std::string type;
    std::vector <Object> bag{};
    //std::vector <int> spells {};
    std::vector <Object> equipped{};
    ~Subjects() = default;

};



#endif //UNTITLED2_SUBJECTS_H
