#ifndef UNTITLED2_CREATESUBJECTS_H
#define UNTITLED2_CREATESUBJECTS_H


#include "Subjects.h"

class CreateSubjects {
public:
    Subjects
    subjectCreation(std::string name, std::string gender, std::string race, std::string classe, std::string type, int level,
                    int health, int mana, int money, int experience);
    ~CreateSubjects();
};


#endif //UNTITLED2_CREATESUBJECTS_H
