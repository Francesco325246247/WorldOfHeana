#include <iostream>
#include <fstream>
#include "../Heads/loadScript.h"

using namespace std;

loadScript::loadScript(const string &path, Subjects hero) {
    try {
        string line;
        string fulltxt;
        ifstream story;
        story.open(path,std::ifstream::in);
        if (story.is_open()) {
            while (story >> line) {
                if (line == "<newline>") {
                    line = "\n";
                    fulltxt.append(line);
                } else if (line == "<s>") {
                    line = " ";
                    fulltxt.append(line);
                } else if (line == "hero.name") {
                    line = hero.name;
                    fulltxt.append(line);
                } else {
                    fulltxt.append(line);
                }
            }
            story.close();
        } else {
            "Error: file not found.";
        }
       cout<< fulltxt;
        fulltxt.clear();
    }
    catch (const std::invalid_argument &e) {
        cout << "Error: " << &e << endl;
    }
}