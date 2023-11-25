#include "GameMechs.h"

GameMechs::GameMechs(){
    input=0;
    exitFlag=0;
    loseFlag=0;
    winFlag=0;
    delay = 100000; 
    key_up = 87;key_left = 65;key_down = 83;key_right = 68; //WASD
    
    key_quit=32; //space

    score=0;
    step_moved=0;

    boardSizeX=30;
    boardSizeY=15;
    //assignStr(upperBoard,"################################\n",32);
}

GameMechs::GameMechs(int boardX, int boardY){
    // input=0;
    // exitFlag=0;
    // loseflag=0;
    // delay = 100000; 
    // key_up = 87;key_left = 65;key_down = 83;key_right = 68;
    // key_quit=' ';
    // score=0;
    GameMechs();

    boardSizeX=boardX;
    boardSizeY=boardY;
}

// do you need a destructor?


//getters
bool GameMechs::getExitFlagStatus(){return exitFlag;}
bool GameMechs::getLoseFlagStatus(){return loseFlag;}
bool GameMechs::getwinFlagStatus(){return winFlag;}

char GameMechs::getInput(){return input;}


char GameMechs::getKeyUp(){return key_up;}
char GameMechs::getKeyLeft(){return key_left;}
char GameMechs::getKeyDown(){return key_down;}
char GameMechs::getKeyRight(){return key_right;}


int GameMechs::getDelay(){return delay;}
int GameMechs::getScore(){return score;}

int GameMechs::getBoardSizeX(){return boardSizeX;}
int GameMechs::getBoardSizeY(){return boardSizeY;}

//setters
void GameMechs::setExitTrue(){exitFlag=1;}
void GameMechs::setLoseTrue(){loseFlag=1;}
void GameMechs::setWinTrue(){winFlag=1;}

void GameMechs::setInput(char this_input){input=this_input;}

void GameMechs::setKeys(char a,char b,char c,char d){ //
    key_up=a;key_left=b;key_down=c;key_right=d;
}

void GameMechs::setDelay(int d){delay=d;}
void GameMechs::scoreIncrement(int i){score+=i;}
/*
void GameMechs::assignStr(char str[],const char Temp_str[],int size){
    for(int i=0;i<size;i++){str[i]=Temp_str[i];}
}
*/
//clean
void GameMechs::clearInput(){input = 0;}


