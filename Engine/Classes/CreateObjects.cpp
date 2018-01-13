#include <iostream>
#include <utility>
#include <vector>
#include <random>
#include <ctime>
#include "../Heads/Object.h"
#include "../Heads/CreateObjects.h"

using namespace std;
Object CreateObjects::objectCreation(std::string prefix, std::string suffix, std::string type, int damage, int defense,
                                     int value) {
    Object object;
    object.objprefix = std::move(prefix);
    object.objsuffix = std::move(suffix);
    object.objtype = std::move(type);
    object.objdamage = damage;
    object.objdefense = defense;
    object.value = value;
    return object;
}
int rollDice(int min, int max) {
    srand(static_cast<unsigned int>((int) time(nullptr)));
    int number = rand() % (max - min) + 1;
    return number;
}
Object CreateObjects::randomObject(int level) {
    Object object;
    vector<string> prefixList = {"Common" , "Rare", "Magic", "Leggendary"};
    vector<string> suffixList = {"Sword", "Mace", "Axe", "Hammer", "Shield"};
    vector<string> typeList = {"common", "rare", "magical", "leggendary"};
    int prefixRandom = rollDice(0, prefixList.size()-1);
    int suffixRandom = rollDice(0, suffixList.size()-1);
    int typeRandom = rollDice(0, typeList.size()-1);
    string prefix = prefixList[prefixRandom];
    string suffix = suffixList[suffixRandom];
    string type = typeList[typeRandom];
    int damage = 1;
    int defense = 1;
    int value = 1;
    int base = 10 * level;
    if (type == "common") {
        if (suffix == "Shield") {
            damage = rollDice(0, 1);
            defense = base + rollDice(10, 20);
        } else {
            damage = base + rollDice(1, 10);
            defense = rollDice(1, 2);
        }
        value = base + rollDice(5, 20);
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
//        cout << "received: [" << prefix << suffix << "]" << endl;
//        cout << "Description:" << endl;
//        cout << "Damage:" << damage << " Defense:" << defense << " Value:" << value << endl;
    } else if (type == "rare") {
        if (suffix == "Shield") {
            damage = rollDice(1, 2);
            defense = base + rollDice(10, 20) + base + rollDice(damage, 20);
        } else {
            damage = base + rollDice(1, 13) + 10;
            defense = rollDice(0, 1);
        }
        value = base + rollDice(1, 30) + 10;
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
//        cout << "You received: [" << prefix << suffix << "]" << endl;
//        cout << "Description:" << endl;
//        cout << "Damage:" << damage << " Defense:" << defense << " Value:" << value << endl;
    } else if (type == "magical") {
        if (suffix == "Shield") {
            damage = rollDice(1, 2);
            defense = base + rollDice(damage, 20);
        } else {
            damage = base + rollDice(damage, 75);
            defense = rollDice(1, 2);
        }
        value = base + rollDice(1, 100);
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
    } else if (type == "Leggendary") {
        if (suffix == "Shield") {
            damage = rollDice(1, 2);
            defense = base + rollDice(1, 110) + 90;
        } else {
            damage = base + rollDice(1, 110) + 90;;
            defense = rollDice(1, 2);
        }
        value = base + rollDice(1, 300) + 90;
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
    }
    return object;
}
CreateObjects::~CreateObjects() = default;

