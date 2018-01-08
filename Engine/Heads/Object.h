
#ifndef UNTITLED2_OBJECT_H
#define UNTITLED2_OBJECT_H
#include <iostream>

class Object {
public:
    std::string objprefix;
    std::string objsuffix;
    std::string objtype;
    int objdamage;
    int objdefense;
    int value;
    ~Object() = default;
};
#endif //UNTITLED2_OBJECT_H
