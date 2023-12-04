#include "GameMechs.h"

GameMechs::GameMechs(){
    foodBucket = new objPosArrayList();
    input=0;
    exitFlag=0;
    loseFlag=0;
    winFlag=0;
    delay = 100000; 
    duration = 0;
    effect = 0;
    bonus = 1;
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

GameMechs::~GameMechs()
{
 delete foodBucket;
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

int GameMechs::getEffect(){return effect;}
int GameMechs::getDuration(){return duration;}
int GameMechs::getBonus(){return bonus;}

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
void GameMechs::incrementScore(int d){score+=d;}

void GameMechs::setEffect(int d){effect=d;}
void GameMechs::setDuration(int d){duration+=d;}
void GameMechs::setBonus(int d){bonus=d;}





//clean
void GameMechs::clearInput(){input = 0;}

void GameMechs::generateFood(objPosArrayList* blockOff) //This is for the array object one
{
    int x_candidate;
    int y_candidate;
    char symbol;
    int k;
    int flag_same;
    objPos returnPos;
    int i;
    int j;
    objPos returnfood;

    while(foodBucket->getSize() != 0)
    {
        foodBucket->removeTail();
    }
    for(i = 0;i<2;i++)
    {
        do
        {
            flag_same = 0;
            x_candidate = (rand() % (getBoardSizeX()-2))+1;
            y_candidate = (rand() % (getBoardSizeY()-2))+1;
            symbol = (rand() % (10))+48;

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
                    break;
                }
            }

            for (j = 0; j < i;j++)
            {
                foodBucket->getElement(returnfood,j);
                if (symbol == returnfood.symbol || x_candidate == returnfood.x || y_candidate == returnfood.y)
                {
                    flag_same = 1;
                    break;
                }
            }
            
        }while (flag_same);

        foodPos.x = x_candidate;
        foodPos.y = y_candidate;
        foodPos.symbol = symbol;

        foodBucket->insertHead(foodPos);
    }
    for(i = 2;i<5;i++)
    {
        do
        {
            flag_same = 0;
            x_candidate = (rand() % (getBoardSizeX()-2))+1;
            y_candidate = (rand() % (getBoardSizeY()-2))+1;
            symbol = (rand() % (94))+33;

            blockOff->getHeadElement(returnPos);

            if (symbol <= 57 && symbol >= 48)
            {
                flag_same = 1;
            }
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
                    break;
                }
            }

            for (j = 0; j < i;j++)
            {
                foodBucket->getElement(returnfood,j);
                if (x_candidate == returnfood.x || y_candidate == returnfood.y)
                {
                    flag_same = 1;
                    break;
                }
            }
            
        }while (flag_same);

        foodPos.x = x_candidate;
        foodPos.y = y_candidate;
        foodPos.symbol = symbol;

        foodBucket->insertHead(foodPos);
    }
};



void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}

objPosArrayList* GameMechs::getfoodlist()
{
    return foodBucket;
}

