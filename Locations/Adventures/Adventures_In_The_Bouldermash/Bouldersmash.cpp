#include <iostream>
#include "Bouldersmash.h"
#include "../../../Engine/Heads/Engine.h"
#include "../../../Engine/Heads/CreateSubjects.h"
#include "../../../Engine/Heads/CreateObjects.h"
#include "../../../Engine/Heads/loadScript.h"

using namespace std;

void save(Subjects hero) {
    Engine save;
    save.saveGame(hero);
}
void Bouldersmash::makeInstance() {
    Engine load;
    Subjects hero;
    CreateObjects sword;
    CreateSubjects Mugdul;
    hero = load.loadGame();
    Subjects foe = Mugdul.subjectCreation("Mugdul", "Male", "orc", "Thief", "foe", 5, 200, 300, 200, 100);
    loadScript loadScriptl("../Locations/Adventures/Adventures_In_The_Bouldermash/bouldermash.txt_ready.txt",hero);
    Object drop2 = sword.randomObject();
    hero.bag.push_back(drop2);
    hero.money += foe.money;
    hero.experience += foe.experience;
    cout << endl;
    cout << foe.money << " golds collected\n";
    save(hero);
}
Bouldersmash::~Bouldersmash() = default;
