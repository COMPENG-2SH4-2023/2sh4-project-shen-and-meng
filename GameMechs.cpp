#include "GameMechs.h"

GameMechs::GameMechs(){
    input=0;
    exitFlag=0;
    loseflag=0;
    delay = 100000; 
    key_up = 87;key_left = 65;key_down = 83;key_right = 68;

    boardSizeX=30;
    boardSizeY=15;

    score=0;
}

GameMechs::GameMechs(int boardX, int boardY){
    input=0;
    exitFlag=0;
    loseflag=0;
    delay = 100000; 
    key_up = 87;key_left = 65;key_down = 83;key_right = 68;
    score=0;

    boardSizeX=boardX;
    boardSizeY=boardY;
}

// do you need a destructor?


//getters
bool GameMechs::getExitFlagStatus(){return exitFlag;}
bool GameMechs::getLoseFlagStatus(){return loseflag;}

char GameMechs::getInput(){return input;}
//char GameMechs::getKeys(){return input;}

int GameMechs::getDelay(){return delay;}
int GameMechs::getScore(){return score;}

int GameMechs::getBoardSizeX(){return boardSizeX;}
int GameMechs::getBoardSizeY(){return boardSizeY;}

//setters

void GameMechs::setExitTrue(){exitFlag=1;}
void GameMechs::setLoseTrue(){loseflag=1;}

void GameMechs::setInput(char this_input){input = this_input;}
// char GameMechs::setKeys(int a,int b,int c,int d){
//     key_up = a;key_left = b;key_down = c;key_right = d;
// }

int GameMechs::setDelay(int d){delay=d;}
int GameMechs::increment(int i;){score+=i;}

//clean
void GameMechs::clearInput(){input = 0;}


