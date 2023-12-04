#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        objPosArrayList* foodBucket;
        objPos foodPos;
        //control
        char input;
        bool exitFlag;
        bool loseFlag;
        bool winFlag;
        int delay;
        char key_up,key_left,key_down,key_right;
        int key_quit;
        
        
        int duration;
        int effect;
        int bonus;
        //bord
        int boardSizeX;
        int boardSizeY;

        //info
        int score;
        int step_moved;
    

    public:
    //initializer
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
    //getter
        //flags
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        bool getwinFlagStatus();

        //input
        char getInput();

        //keys
        char getKeyUp();
        char getKeyLeft();
        char getKeyDown();
        char getKeyRight();

        //info
        int getDelay();
        int getScore();

        int getEffect();
        int getDuration();
        int getBonus();

        int getBoardSizeX();
        int getBoardSizeY();

        void getFoodPos(objPos &returnPos);
        objPosArrayList* getfoodlist();

        


    //setter
        //data
        void setExitTrue();
        void setLoseTrue();
        void setWinTrue();
        void incrementScore(int d);
        
        void setInput(char this_input);

        void setKeys(char a,char b,char c,char d);
        
        //game setting
        void setDelay(int d);
        void setEffect(int d);
        void setDuration(int d);
        void setBonus(int d);

        //food
        void generateFood(objPosArrayList* blockOff);//For iteration 3
        //void generateFood(objPosArrayList* blockOffList);//For iteration 2

        //void assignStr(char str[],const char Temp_str2[],int size);
    //clean
        void clearInput();

        
      

};

#endif