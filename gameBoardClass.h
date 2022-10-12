#ifndef GAMEBOARDCLASS_H
#define GAMEBOARDCLASS_H
#include <map>
#include <queue>
#include "playerClass.h"

using namespace std;
class GameBoard {
    Dice dice ;
    vector<snakeJumper> snake;
    vector<ladderJumper> ladder;
    queue<Player> nextTurn;
    map<Player, int> currentPos;
    int boardSize;
    public:

    GameBoard(Dice dice, vector<snakeJumper> snake, vector<ladderJumper> ladder, queue<Player> nextTurn, map<Player,int> currentPos, int boardSize) {
        this->dice = dice;
        this->snake = snake;
        this->ladder = ladder;
        this->nextTurn = nextTurn;
        this->currentPos = currentPos;
        this->boardSize = boardSize;
    }

    void playGame() {
        while(nextTurn.size() > 1) {
            Player p = nextTurn.front();
            nextTurn.pop();
            int n = dice.shuffle();
            int tempPos = currentPos[p] + n;
            int nextPos = tempPos;
            if(tempPos == boardSize){
                cout<<"player "<<p.getName()<<" wins";
            } else if(tempPos > boardSize) {
                nextTurn.push(p);
            } else {
                for(int i = 0 ; i < snake.size(); i++) {
                    if(snake[i].startPos == tempPos) {
                        nextPos = snake[i].endPos;
                        cout<<"Player "<<p.getName()<<" is bitten by snake and its pos is "<<nextPos;
                    }
                }

                for(int i = 0 ; i < ladder.size(); i++) {
                    if(ladder[i].startPos == tempPos) {
                        nextPos = ladder[i].endPos;
                        cout<<"Player "<<p.getName()<<" is taken ladder and its pos is "<<nextPos;
                    }
                }

                currentPos[p] = nextPos;
                nextTurn.push(p);
            }
        }
    }
};
#endif