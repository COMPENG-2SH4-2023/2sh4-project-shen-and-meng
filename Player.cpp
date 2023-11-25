#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(10,5,'@');
}



Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic     
    if (myDir == STOP)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyLeft())
        {
            myDir = LEFT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyRight())
        {
            myDir = RIGHT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyUp())
        {
            myDir = UP;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyDown())
        {
            myDir = DOWN;
        }
        else
        {
            myDir = STOP;
        }
    }
    if (myDir == UP)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyLeft())
        {
            myDir = LEFT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyRight())
        {
            myDir = RIGHT;
        }
        else
        {
            myDir = UP;
        }
    }
    else if (myDir == DOWN)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyLeft())
        {
            myDir = LEFT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyRight())
        {
            myDir = RIGHT;
        }
        else
        {
            myDir = DOWN;
        }
    }
    else if (myDir == LEFT)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyUp())
        {
            myDir = UP;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyDown())
        {
            myDir = DOWN;
        }
        else
        {
            myDir = LEFT;
        }
    }
    else if (myDir == RIGHT)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyUp())
        {
            myDir = UP;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyDown())
        {
            myDir = DOWN;
        }
        else
        {
            myDir = RIGHT;
        }
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if (myDir == UP)
    {
        playerPos.y -= 1;
    }
    else if (myDir == DOWN)
    {
        playerPos.y += 1;
    }
    else if (myDir == LEFT)
    {
        playerPos.x -= 1;
    }
    else if (myDir == RIGHT)
    {
        playerPos.x += 1;
    }
    if (playerPos.x == mainGameMechsRef->getBoardSizeX()-1)
    {
        playerPos.x = 1;
    }
    else if (playerPos.x == 0)
    {
        playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
    }
    else if (playerPos.y == mainGameMechsRef->getBoardSizeY()-1)
    {
        playerPos.y = 1;
    }
    else if (playerPos.y == 0)
    {
        playerPos.y = mainGameMechsRef->getBoardSizeY()-2;
    }

}

