#include <iostream>
#include <ctime>
#include "../Heads/fight.h"
#include "../Heads/Engine.h"
#include "../Heads/CreateObjects.h"

using namespace std;
void save(Subjects hero) {
    Engine save;
    save.saveGame(hero);
}
int rollFightDice(int min, int max) {
    srand(static_cast<unsigned int>((int) time(nullptr)));
    int number = rand() % (max - min) + 1;
    return number;
}
void fightLog(int turn, int attack, int defense, int fight, Subjects attacking, Subjects defending) {
    cout << "\n---------------------Turn: " << turn << " ------------------------------" << endl;
    cout << defending.name << " has " << defending.health << " health left." << endl;
    cout << attacking.name << " has " << attacking.health << " health left." << endl;
    cout << attacking.name << " is now attacking ... " << endl;
    cout << attacking.name << " roll the attack dices, attacking for " << attack << " base damages" << endl;
    cout << defending.name << " roll the defensive dices, absorbing " << defense << " base damages" << endl;
    cout << defending.name << " receive " << fight << " total calculated damage. " << endl;
    cout << defending.name << " has " << defending.health << " health left." << endl;
}
fight fight::skirmish(Subjects hero, Subjects foe) {
    CreateObjects objects;
    Object foeWeapon1 = objects.randomObject(foe.level);
    Object foeWeapon2 = objects.objectCreation("common","Shield","rare",1,foe.level*20,200);
    foe.equipped.push_back(foeWeapon1);
    foe.equipped.push_back(foeWeapon2);
    int turns = 0;
    int herohearth = hero.health;
    while (hero.health > 0 && foe.health > 0) {
        int quickness = rollFightDice(1, 100);
        if (quickness % 2 == 0) {
            int attack = foe.equipped[0].objdamage;
            string magicSpell;
            cout << "\ncWrite roll to roll the dices\n";
            cin >> magicSpell;
            cout << "\nYour skin start shining of an unnatural light ...\n";
            cin.clear();
            int defense = hero.equipped[1].objdefense;
            int fight = (attack * rollFightDice(1, 7)) - (defense * rollFightDice(1, 6));
            if (fight < 0) {
                fight = 0;
            }
            hero.health -= fight;
            fightLog(turns, attack, defense, fight, foe, hero);
            turns += 1;
        } else if (quickness % 2 != 0) {
            int attack = hero.equipped[0].objdamage;
            string magicSpell;
            cout << "\ncast a spell to power your attack\n";
            cin >> magicSpell;
            cout << "\nYour weapon become hot like the lava ... \n";
            cin.clear();
            int defense = foe.equipped[1].objdefense;
            int fight = (attack * rollFightDice(1, 7)) - (defense * rollFightDice(1, 6));
            if (fight < 0) {
                fight = 0;
            }
            foe.health -= fight;
            fightLog(turns, attack, defense, fight, hero, foe);
            turns += 1;
        } else if (turns % 2 == 0) {
            int attack = foe.equipped[0].objdamage;
            string magicSpell;
            cout << "\ncast a  defensive spell on yourself\n";
            cin >> magicSpell;
            cout << "\nYour skin start shining of an unnatural light ...\n";
            cin.clear();
            int defense = hero.equipped[1].objdefense;
            int fight = (attack * rollFightDice(1, 7)) - (defense * rollFightDice(1, 6));
            if (fight < 0) {
                fight = 0;
            }
            hero.health -= fight;
            fightLog(turns, attack, defense, fight, foe, hero);
            turns += 1;
        } else {
            int attack = hero.equipped[0].objdamage;
            string magicSpell;
            cout << "\ncast a spell to power your attack\n";
            cin >> magicSpell;
            cout << "\nYour weapon become hot like the lava ... \n";
            cin.clear();
            int defense = foe.equipped[1].objdefense;
            int fight = (attack * rollFightDice(1, 7)) - (defense * rollFightDice(1, 6));
            if (fight < 0) {
                fight = 0;
            }
            foe.health -= fight;
            fightLog(turns, attack, defense, fight, hero, foe);
            turns += 1;
        }
    }
    if (foe.health <= 0) {
        cout << "\nCongratulation you defeated " << foe.name;
        CreateObjects sword;
        Object drop = sword.randomObject(hero.level);
        hero.bag.push_back(drop);
        hero.money += foe.money + rollFightDice(0, foe.level);
        hero.experience += foe.experience;
        cout << "You collected " << drop.objprefix << "-" << drop.objsuffix << endl;
        cout << "Experience accumulated: " << foe.experience << endl;
        cout << foe.money + rollFightDice(0, foe.level) << " golds collected.\n" << endl;
    } else {
        int experienceLost = hero.experience -= foe.experience;
        hero.experience -= experienceLost;
        cout << "\nYou unfortunately got heavily injured and you have being defeated" << endl;
        cout << "You lost " << experienceLost << " experience: " << endl;
    }
    hero.health = herohearth;
    save(hero);
}