#ifndef UNTITLED2_INSTANCES_H
#define UNTITLED2_INSTANCES_H
#include "Subjects.h"
class Subjects;
class Engine {
public:
		void createPersonage();
		void saveGame(Subjects hero);
		Subjects loadGame();
		void infoHero();
		void travelMenu();
		void intro();
		bool mainMenu();
		~Engine();
};
#endif //UNTITLED2_INSTANCES_H
