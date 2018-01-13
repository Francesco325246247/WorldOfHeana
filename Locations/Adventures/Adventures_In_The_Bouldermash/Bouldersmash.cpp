#include <iostream>
#include "Bouldersmash.h"
#include "../../../Engine/Heads/Engine.h"
#include "../../../Engine/Heads/CreateSubjects.h"
#include "../../../Engine/Heads/CreateObjects.h"
#include "../../../Engine/Heads/loadScript.h"
#include "../../../Engine/Heads/fight.h"

using namespace std;
Engine load;
Subjects hero;
fight fight;
void Bouldersmash::makeInstance() {
    hero = load.loadGame();
    CreateSubjects Mugdul;
    Subjects foe = Mugdul.subjectCreation("Mugdul", "Male", "orc", "Thief", "foe", 5, 200, 300, 200, 100);
    loadScript loadScriptl("../Locations/Adventures/Adventures_In_The_Bouldermash/bouldermash.txt_ready.txt", hero);
    fight.skirmish(hero,foe);
}
Bouldersmash::~Bouldersmash() = default;
