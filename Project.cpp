#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "time.h"
using namespace std;

//create class
GameMechs* Mech;
Player* Player_obj;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!(Mech->getExitFlagStatus()))  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void){
    MacUILib_init();
    MacUILib_clearScreen();
    srand(time(NULL));

    //class
    Mech=new GameMechs;
    Player_obj = new Player(Mech);
    
    objPosArrayList* PlayerList;
    //assign value
    PlayerList=Player_obj->getPlayerList();
    Mech->generateFood(PlayerList);
    
}

void GetInput(void){
   if(MacUILib_hasChar()){Mech->setInput(char(MacUILib_getChar()));}
}

void RunLogic(void){
    
    if(Mech->getInput() != 0){  // if not null character
        if(Mech->getInput()==32){Mech->setExitTrue();}  //exit if cmd is "space" 
        if(Mech->getInput()=='m'){Mech->setWinTrue();}
        
        Player_obj->updatePlayerDir();
        Mech->clearInput();  //reset the input
    }
    
    Player_obj->movePlayer();
    if(Player_obj->checkSelfCollision())
    {
    Mech->setExitTrue();
    }
    
}

void DrawScreen(void){
    MacUILib_clearScreen(); 
    
    
    //temp storage  
    int score = Mech->getScore();
    //print to PosArray storing body
    objPosArrayList* PlayerList;
    objPos Bodypos;
    objPos FoodPos;
    Bodypos = objPos();
    FoodPos = objPos();
    //assign value
    PlayerList=Player_obj->getPlayerList();
    
    if(Player_obj->checkFoodConsumption())
    {
    Mech->generateFood(PlayerList);
    Mech->incrementScore();
    }
    Mech->getFoodPos(FoodPos);

    //values
    int body = PlayerList->getSize();
    bool printed=0;
    //int start = 0;
    for (int row=0;row<(Mech->getBoardSizeY());row++){
        for (int col=0;col<(Mech->getBoardSizeX());col++){
            if ((row == 0 || row == (Mech->getBoardSizeY()-1 ))|| (col == 0 || col == (Mech->getBoardSizeX()-1))){
                MacUILib_printf("#");
            }

            //print inside board
            else{
                //print food
                if(row == FoodPos.y && col == FoodPos.x){
                    MacUILib_printf("%c",FoodPos.symbol);
                    printed=1;
                }
                
                //print body
                else if(body!=0){
                    for(int i=0;i<body;i++){
                        PlayerList->getElement(Bodypos,i);//check through the body list 
                        if(row == Bodypos.y && col == Bodypos.x){
                            MacUILib_printf("%c",Bodypos.symbol);
                            printed=1;
                            break;
                        }
                    }
                }
                //print space
                if(!printed){
                    MacUILib_printf(" ");  
                }
                printed = 0;
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d\n",score);
}

void LoopDelay(void){
    MacUILib_Delay(Mech->getDelay()); 
}


void CleanUp(void){
    //MacUILib_clearScreen(); 

    delete Mech;
    delete Player_obj;

    MacUILib_uninit();

}
