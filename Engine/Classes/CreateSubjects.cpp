#include <utility>
#include "../Heads/CreateSubjects.h"

using namespace std;
Subjects CreateSubjects::subjectCreation(string name, string gender, string race, string classe, string type, int level,
                                         int health, int mana, int money, int experience) {
    Subjects subjects;
    subjects.name = std::move(name);
    subjects.gender = std::move(gender);
    subjects.race = std::move(race);
    subjects.classe = std::move(classe);
    subjects.type = std::move(type);
    subjects.level = level;
    subjects.health = health;
    subjects.mana = mana;
    subjects.money = money;
    subjects.experience = experience;
    return subjects;
}
CreateSubjects::~CreateSubjects() {
}
