#ifndef JUMPERCLASS_H
#define JUMPERCLASS_H

using namespace std;
class Jumper {

    public:
    int startPos;
    int endPos;
    
    Jumper(int startPos, int endPos) {
        this->startPos = startPos;
        this->endPos = endPos;
    }

    virtual  bool validate() = 0 ;
};

class snakeJumper : public Jumper {
    public:
    snakeJumper(int x, int y):Jumper(x,y){};

    bool validate() {
        cout << "snake";
    }
};

class ladderJumper : public Jumper {
    public:
    ladderJumper(int x, int y) : Jumper(x,y){};

    bool validate() {
        cout << "ladder";
    }
};

#endif