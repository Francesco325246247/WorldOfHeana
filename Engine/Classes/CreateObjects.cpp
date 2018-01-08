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
Object CreateObjects::randomObject() {
    Object object;
    vector<string> prefixList = {"Common ", "Rare ", "Magic ", "Leggendary "};
    vector<string> suffixList = {"Sword", "Mace", "Axe", "Hammer"};
    vector<string> typeList = {"common", "rare", "magical", "Leggendary"};
    int prefixRandom = rollDice(0, prefixList.size());
    int suffixRandom = rollDice(0, suffixList.size());
    int typeRandom = rollDice(0, typeList.size());
    string prefix = prefixList[prefixRandom];
    string suffix = suffixList[suffixRandom];
    string type = typeList[typeRandom];
    int damage = 1;
    int defense = 1;
    int value = 1;
    if (type == "common") {
        damage = rollDice(1, 10);
        defense = rollDice(1, 10);
        value = rollDice(5, 20);
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
        cout << "You received: [" << prefix << suffix << "]" << endl;
        cout << "Description:" << endl;
        cout << "Damage:" << damage << " Defense:" << defense << " Value:" << value << endl;
    } else if (type == "rare") {
        damage = rollDice(1, 13)+10;
        defense = rollDice(1, 13)+ rollDice(damage,13);
        value = rollDice(1, 30)+10;
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
        cout << "You received: [" << prefix << suffix << "]" << endl;
        cout << "Description:" << endl;
        cout << "Damage:" << damage << " Defense:" << defense << " Value:" << value << endl;
    } else if (type == "magical") {
        damage = rollDice(1, 75);
        defense = rollDice(1, 75)+rollDice(damage,75);
        value = rollDice(1, 100);
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
        cout << "You received: [" << prefix << suffix << "]" << endl;
        cout << "Description:" << endl;
        cout << "Damage:" << damage << " Defense:" << defense << " Value:" << value << endl;
    } else if (type == "Leggendary") {
        damage = rollDice(1, 110)+90;
        defense = rollDice(1, 110)+90+rollDice(damage,110);
        value = rollDice(1, 300)+90;
        object.objprefix = prefix;
        object.objsuffix = suffix;
        object.objtype = type;
        object.objdamage = damage;
        object.objdefense = defense;
        object.value = value;
        cout << "You received: [" << prefix << suffix << "]" << endl;
        cout << "Description:" << endl;
        cout << "Damage:" << damage << " Defense:" << defense << " Value:" << value << endl;
    }
    return object;
}
CreateObjects::~CreateObjects() = default;

