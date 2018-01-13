cmake_minimum_required(VERSION 3.9)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

add_executable(untitled2 main.cpp Engine/Heads/Subjects.h Engine/Classes/Engine.cpp Engine/Heads/Engine.h Engine/Heads/Object.h Engine/Classes/CreateObjects.cpp Engine/Heads/CreateObjects.h Engine/Classes/CreateSubjects.cpp Engine/Heads/CreateSubjects.h Locations/Adventures/Adventures_In_The_Bouldermash/Bouldersmash.cpp Locations/Adventures/Adventures_In_The_Bouldermash/Bouldersmash.h Engine/Classes/loadScript.cpp Engine/Heads/loadScript.h Engine/Classes/fight.cpp Engine/Heads/fight.h)
