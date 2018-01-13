#include <iostream>
#include <fstream>
#include <vector>
#include "../Heads/Engine.h"
#include "../Heads/CreateObjects.h"
#include "../../Locations/Adventures/Adventures_In_The_Bouldermash/Bouldersmash.h"
#include "../Heads/CreateSubjects.h"
#include "../Heads/loadScript.h"

using namespace std;
void Engine::saveGame(Subjects hero) {
    ofstream output_hero;
    ofstream output_bag;
    ofstream equipped;
    try {
        output_hero.open("../Save/save.txt", std::ifstream::in );
        output_bag.open("../Save/saveBag.txt", std::ifstream::in );
        equipped.open("../Save/equipped.txt", std::ifstream::in );
        if (output_hero.is_open()) {
            output_hero << hero.name << endl;
            output_hero << hero.gender << endl;
            output_hero << hero.race << endl;
            output_hero << hero.classe << endl;
            output_hero << hero.type << endl;
            if (hero.level * hero.experience % 100 > 0) {
                hero.level += 1;
                hero.health = (hero.health) + hero.level + 6;
                hero.mana = (hero.mana) + hero.level + 7;
                hero.experience = 1;
                cout << "Congratulation you level up!\n";
            }
            output_hero << hero.level << endl;
            output_hero << hero.health << endl;
            output_hero << hero.mana << endl;
            output_hero << hero.money << endl;
            output_hero << hero.experience << endl;
        }
        output_hero.flush();
        output_hero.close();
        if (output_bag.is_open()) {
            for (auto &it : hero.bag) {
                output_bag << "\n";
                output_bag << it.objprefix << " " << it.objsuffix << endl;
                output_bag << it.objtype << endl;
                output_bag << it.objdamage << endl;
                output_bag << it.objdefense << endl;
                output_bag << it.value;
                output_bag << "\n";
            }
            output_bag.flush();
            output_bag.close();
        }
        if (equipped.is_open()) {
            for (auto &it : hero.equipped) {
                equipped << "\n";
                equipped << it.objprefix << " " << it.objsuffix << endl;
                equipped << it.objtype << endl;
                equipped << it.objdamage << endl;
                equipped << it.objdefense << endl;
                equipped << it.value;
                equipped << "\n";
            }
            equipped.flush();
            equipped.close();
        }
    }
    catch (std::ifstream::failure &e) {
        std::cerr << "Exception opening/reading/closing file\n";
    }
}
Subjects Engine::loadGame() {
    Subjects hero;
    Object obj;
    CreateSubjects subjects;
    CreateObjects build;
    ifstream input_heroInfo;
    ifstream input_bag;
    ifstream equipped;
    try {
        input_heroInfo.open("../Save/save.txt", std::ifstream::in);
        input_bag.open("../Save/saveBag.txt", std::ifstream::in);
        equipped.open("../Save/equipped.txt", std::ifstream::in);
        if (input_heroInfo.is_open()) {
            string name, gender, race, classe, type;
            int health, mana, level, money, experience;
            while (input_heroInfo >> name >> gender >> race >> classe >> type >> level >> health >> mana >> money
                                  >> experience) {
                hero = subjects.subjectCreation(name, gender, race, classe, type, level, health, mana, money,
                                                experience);
            }
            input_heroInfo.close();
        }
        if (input_bag.is_open()) {
            string objprefix, objsuffix;
            string objtype;
            int objdamage, objdefense, objvalue;
            while (input_bag >> objprefix >> objsuffix >> objtype >> objdamage >> objdefense >> objvalue) {
                obj = build.objectCreation(objprefix, objsuffix, objtype, objdamage, objdefense, objvalue);
                hero.bag.push_back(obj);
            }
            input_bag.close();
        }
        if (equipped.is_open()) {
            string equiobjprefix, equiobjsuffix;
            string equiobjtype;
            int equiobjdamage, equiobjdefense, equiobjvalue;
            while (equipped >> equiobjprefix >> equiobjsuffix >> equiobjtype >> equiobjdamage >> equiobjdefense >> equiobjvalue) {
                obj = build.objectCreation(equiobjprefix, equiobjsuffix, equiobjtype, equiobjdamage, equiobjdefense, equiobjvalue);
                hero.equipped.push_back(obj);
            }
            input_bag.close();
        }
    }
    catch (const std::invalid_argument &e) {
        cout << "Error: " << &e << endl;
    }
    return hero;
}
void Engine::infoHero() {
    Subjects hero;
    hero = loadGame();
    cout << "------------- " << "hero's details" << " -------------" << endl;
    cout << "Name: " << hero.name << endl;
    cout << "Geder: " << hero.gender << endl;
    cout << "Race: " << hero.race << endl;
    cout << "Class: " << hero.classe << endl;
    cout << "Level: " << hero.level << endl;
    cout << "Health: " << hero.health << endl;
    cout << "Mana: " << hero.mana << endl;
    cout << "Golds: " << hero.money << endl;
    cout << "Experinece: " << hero.experience << endl;
    cout << "############# " << "hero's bag" << " #############" << endl;
    for (auto &it : hero.bag) {
        string prefix = it.objprefix;
        string suffix = it.objsuffix;
        string type = it.objtype;
        int damage = it.objdamage;
        int defense = it.objdefense;
        int value = it.value;
        cout << prefix << "-" << suffix << ":" << endl;
        cout << "   -Type: " << type << endl;
        cout << "   -Damage: " << damage << endl;
        cout << "   -Defense: " << defense << endl;
        cout << "   -Value: " << value << endl;
        cout << "---------------------" << endl;
    }
    cout << "######################################\n" << endl;
}
bool Engine::mainMenu() {
    while (cin) {
        int answer = 0;
        cout << "Choose your action:" << endl;
        cout << "1 . Travel" << endl;
        cout << "2 . Info hero " << endl;
        cout << "3 . Exit the Game" << endl;
        cin >> answer;
        if (answer == 1) {
            travelMenu();
        } else if (answer == 2) {
            infoHero();
        } else if (answer == 3) {
            Subjects hero = loadGame();
            saveGame(hero);
            cout << hero.name
                 << " do not forget to come back to find out which is the reason behind the mass memory lapse that has affected everyone on Heana"
                 << endl;
            exit(0);
        } else {
            continue;
        }
    }
}
void Engine::travelMenu() {
    while (cin) {
        int answer;
        cout << "Where do you want to go?" << endl;
        cout << "1 . (Instance) Adventure in the Bouldersmash " << endl;
        cout << "2 . return to the main menu" << endl;
        cin >> answer;
        if (answer == 1) {
            Bouldersmash bouldersmash;
            bouldersmash.makeInstance();
        } else if (answer == 2) {
            mainMenu();
        } else {
            continue;
        }
    }
}
void Engine::createPersonage() {
    Subjects hero;
    string name;
    string gender;
    string race;
    string classe;
    string type = "hero";
    loadScript("../intro1.txt_ready.txt", hero);
    cout << "\nLibrarian: who are you exactly?\n";
    cout << "My name is ... " << endl;
    cin >> name;
    hero.name = name;
    cout << "mmm ... my gender? " << endl;
    cin >> gender;
    hero.gender = gender;
    cout << "I am a proud ... (race)" << endl;
    cin >> race;
    hero.race = race;
    cout << "I always wanted to be a ..." << endl;
    cin >> classe;
    hero.classe = classe;
    hero.type = type;
    loadScript("../intro2.txt_ready.txt", hero);
    CreateObjects sword;
    CreateObjects shield;
    CreateObjects placeholder;
    Object drop1 = sword.objectCreation("Rusty", "dagger", "common", 7, 0, 1);
    Object drop2 = shield.objectCreation("Small", "Shield", "common", 0, 50, 1);
    Object drop3 = placeholder.randomObject(1);
    hero.equipped.push_back(drop1);
    hero.equipped.push_back(drop2);
    hero.bag.push_back(drop3);
    saveGame(hero);
}
void Engine::intro() {
    string answer;
    cout << "Welcome in the magic world of Heana house of Humans, Elfves, Orcs, Dwarfs and other magic beasts.\n";
    cout << "Book one: Time lapses\n";
    cout << "Do you want to create a new personage or continue? new or continue" << endl;
    cin >> answer;
    if (answer == "new") {
        createPersonage();
    } else if (answer == "continue") {
        loadGame();
        mainMenu();
    } else {
        intro();
    }
}
Engine::~Engine() = default;


