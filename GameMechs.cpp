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
}

GameMechs::GameMechs(int boardX, int boardY){
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

//clean
void GameMechs::clearInput(){input = 0;}

void GameMechs::generateFood(objPos blockOff)//for iteration 2B
{
    int x_candidate;
    int y_candidate;
    char symbol;
    int flag_same;
    

    
    do
    {
        flag_same = 0;
        x_candidate = (rand() % (getBoardSizeX()-2))+1;
        y_candidate = (rand() % (getBoardSizeY()-2))+1;
        symbol = (rand() % (94))+33;


        if (symbol == blockOff.symbol || symbol == ' ')
        {
            flag_same = 1;
        }
    
        if (x_candidate == blockOff.x && y_candidate == blockOff.y)
        {
            flag_same = 1;
            break;
        }
        
        
    }while (flag_same);

    foodPos.x = x_candidate;
    foodPos.y = y_candidate;
    foodPos.symbol = symbol;
}

/*void GameMechs::generateFood(objPosArrayList* blockOff) //This is for the array object one
{
    int x_candidate;
    int y_candidate;
    char symbol;
    int k;
    int flag_same;
    objPos returnPos;

    
    do
    {
        flag_same = 0;
        x_candidate = (rand() % (getBoardSizeX()-2))+1;
        y_candidate = (rand() % (getBoardSizeY()-2))+1;
        symbol = (rand() % (94))+33;

        blockOff->getHeadElement(returnPos);

        if (symbol == returnPos.symbol)
        {
            flag_same = 1;
        }
    
        for(k = 0;k < blockOff->getSize();k++)
        {
            blockOff->getElement(returnPos,k);
            if (x_candidate == returnPos.x && y_candidate == returnPos.y)
            {
                flag_same = 1;
                break
            }
        }
        
    }while (flag_same);

    foodPos.x = x_candidate;
    foodPos.y = y_candidate;
    foodPos.symbol = symbol;
    
};
*/

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}


