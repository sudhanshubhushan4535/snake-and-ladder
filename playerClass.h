#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

using namespace std;
class Player {
    string name;
    int id;
    
    public:
    Player(string name, int id) {
        this->name = name;
        this->id = id;
    }

    string getName() {
        return name;
    }
};
#endif