#include<iostream>
#include<vector>
#include "diceClass.h"
#include "jumperClass.h"
#include "gameBoardClass.h"
#include "playerClass.h"

int main() {
    cout<<"bhushan**************************************************************";
    Player p1 = Player("sudhanshu", 1);
    Player p2 = Player("tanya", 2);
    vector<Player> player;
    player.push_back(p1);
    player.push_back(p2);

    snakeJumper snake1(10,2);
    snakeJumper snake2 = snakeJumper(99,12);
    vector<snakeJumper> snakes;
    snakes.push_back(snake1);
    snakes.push_back(snake2);

    ladderJumper ladder1 = ladderJumper(5,25);
    ladderJumper ladder2 = ladderJumper(40,89);
    vector<ladderJumper> ladders;
    ladders.push_back(ladder1);
    ladders.push_back(ladder2);

    Dice dice = Dice(1);
    map<Player,int> currentPos;
    currentPos[p1] = 0;
    currentPos[p2] = 0;

    queue<Player> nextTurn;
    nextTurn.push(p1);
    nextTurn.push(p2);
    GameBoard gb = GameBoard(dice,snakes,ladders,nextTurn,currentPos,100);
    gb.playGame();
    
    return 0;
}