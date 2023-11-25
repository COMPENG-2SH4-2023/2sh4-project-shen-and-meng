#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
using namespace std;


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
    Mech=new GameMechs;
    Player_obj = new Player(Mech);

    MacUILib_init();
    MacUILib_clearScreen();

    
    
}

void GetInput(void){
   if(MacUILib_hasChar()){Mech->setInput(char(MacUILib_getChar()));}
}

void RunLogic(void){
    
    if(Mech->getInput() != 0){  // if not null character
        if(Mech->getInput()==32){Mech->setExitTrue();}  //exit if cmd is "space" 
        if(Mech->getInput()=='m'){Mech->setWinTrue();}
        
        Player_obj->updatePlayerDir();
        
        //
        //else if(input>=49&&input<=53){num_Target = (input-48);}   //changging the nummber of Target by entering number 1-5
        //else if(input==43||input==45){g_temp=input-44;if((delay+g_temp)<150000&&(delay+g_temp)>5000){delay+=g_temp*5000;g_temp=0;}} //modify speed        
        //
        /*
        else if(abs(Mech->getInput()-direction)>5){  //if the input isn't oppsit to current direction
            if(input==key_up){step=-1;direction=input;}  //change to coresponding moving direction and update the moving direction 
            else if(input==key_down){step=1;direction=input;}
            else if(input==key_left){step=-1;direction=input;}
            else if(input==key_right){step=1;direction=input;}   
        }  
        */
        Mech->clearInput();  //reset the input
    }
    
    Player_obj->movePlayer();
    

    

}

void DrawScreen(void){
    MacUILib_clearScreen();    
    //cout<<(Mech->upperBoard[]);
    objPos A;
    Player_obj->getPlayerPos(A);
    bool printed=0;
    for (int row=0;row<(Mech->getBoardSizeY());row++){
        for (int col=0;col<(Mech->getBoardSizeX());col++){
            if ((row == 0 || row == (Mech->getBoardSizeY()-1 ))|| (col == 0 || col == (Mech->getBoardSizeX()-1))){
                MacUILib_printf("#");
            }
            else if(row == A.y && col == A.x)
            {
                MacUILib_printf("%c",A.symbol);
            }
            else{
               
                    MacUILib_printf(" ");
                
            }
            printed = 0;
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void){
    MacUILib_Delay(Mech->getDelay()); 
}


void CleanUp(void){
    MacUILib_clearScreen(); 

    delete Mech;
    delete Player_obj;

    MacUILib_uninit();

}
