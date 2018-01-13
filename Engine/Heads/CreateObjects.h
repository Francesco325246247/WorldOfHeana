

#ifndef UNTITLED2_CREATEOBJECTS_H
#define UNTITLED2_CREATEOBJECTS_H

#include <iostream>
#include "Object.h"


class CreateObjects {
public:
		Object objectCreation(std::string prefix, std::string suffix, std::string type, int damage, int defense, int value);
	~CreateObjects();
	Object randomObject(int level);
};


#endif //UNTITLED2_CREATEOBJECTS_H
