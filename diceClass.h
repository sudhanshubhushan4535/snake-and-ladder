#ifndef DICECLASS_H
#define DICECLASS_H

class Dice {
    int numberOfDice;
    
    public:
    Dice(){}
    Dice(int numberOfDice) {
        this->numberOfDice = numberOfDice;
    }

    int shuffle() {
        return rand()%6 + 1;
    }
};

#endif
