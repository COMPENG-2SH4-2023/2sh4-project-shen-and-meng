#include "GameMechs.h"

GameMechs::GameMechs(){
    input=0;
    exitFlag=0;
    loseFlag=0;
    winFlag=0;
    delay = 100000; 
    key_up = 'w';key_left = 'a';key_down = 's';key_right = 'd'; //wasd
    
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
//GameMechs::~GameMechs(){}// do you need a destructor?/

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
void generateFood(objPos blockOff){
    int i=0,j=0;
    
    for(i=0;i<characters_size;i++){
        int regenerate=0,temp_col=0,temp_row=0;
        char temp_char='\0';
        do{
            regenerate=0;//assume no need to regenerate, and generate a set of col row char
            temp_col=1+rand() % (right_bound-1),temp_row = 1+rand() % (bottom_bound-1);  
            if(i<num_Target){temp_char=*(Goal_str+(rand()%12));}//pick num_Target of characters from goal str
            else{temp_char=(rand()%86)+40;}  //generate num_fakeTarget of char from （ to } 
         //check
            for(j=0;j<i;j++){
                if(((temp_char==characters[j]->symbol)||(temp_col==player->col&&temp_row==player->row))||(temp_col==characters[j]->col&&temp_row==characters[j]->row)){regenerate=1;}  //avoid overlaping and repeting 
            }  
        }while(regenerate);  //regenerate col and row if current one is not usable

        characters[i]->col = temp_col;  //set the col row char if usable
        characters[i]->row = temp_row;
        characters[i]->symbol=temp_char;
    }
    
}
/*
void GameMechs::assignStr(char str[],const char Temp_str[],int size){
    for(int i=0;i<size;i++){str[i]=Temp_str[i];}
}
*/
//clean
void GameMechs::clearInput(){input = 0;}


