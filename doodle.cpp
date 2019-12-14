/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 14:11:41 PDT 2016
 * *Description: Doodle class implementation.
 * *********************************************/

#include <iostream>
#include "doodle.hpp"
#include "utils.hpp"

/**********************
 * Doodle Constructor
 * *******************/
Doodle::Doodle(Game* b, int r, int c):Critter(b,r,c)
{
	hunger = 0; //calls the Critter constructor plus initializes hunger variable.
}

Doodle::~Doodle()
{
	//nada
}

/*************
 * getCritter
 * **********/
Species Doodle::getCritter()
{
	return DOODLE;
}

/*******************
 * hasAntNeighbor?
 * ****************/
bool Doodle::hasAntNeighbor()
{
	return bord->hasAntNeighbor(rCoord,cCoord);
}

/*****************
 * isAntNeighbor
 * **************/
bool Doodle::isAntNeighbor(Direction d)
{
	switch(d) {
		case UP: if(bord->whatCritter(rCoord-1,cCoord)==ANT)
				    return true;
			    break;
		case DOWN: if(bord->whatCritter(rCoord+1,cCoord)==ANT)
					 return true;
				 break;
		case LEFT: if(bord->whatCritter(rCoord, cCoord-1)==ANT)
					 return true;
				 break;
		case RIGHT: if(bord->whatCritter(rCoord,cCoord+1)==ANT)
					  return true;
				  break; }
	return false;
}

/**************
 * doodleBreed
 * ***********/
void Doodle::breed()
{
	if(aliveFor==8 && hasEmptyNeighbor())
		while(aliveFor==8)
		{
			Direction d = static_cast<Direction>(randInt(1,4));
			if(isOpenNeighbor(d))
			{
				newCritter(d);
				aliveFor = 0;
			}
		}
}

/**************
 * doodleMove
 * ***********/
void Doodle::move()
{
	if(hasAntNeighbor()) //doodle will preferentially move towards eating an ant.
	{
		while(hasMoved==false)
		{
			Direction d = static_cast<Direction>(randInt(1,4));
			if(isAntNeighbor(d))
			{
				moveThisCritter(d);
				aliveFor++;
				hasMoved = true;
				hunger = 0;
			}
		}
	}
	else if(hasEmptyNeighbor())
		while(hasMoved==false)
		{
			Direction d = static_cast<Direction>(randInt(1,4));
			if(isOpenNeighbor(d))
			{
				moveThisCritter(d);
				aliveFor++;
				hunger++;
				hasMoved = true;
			}
		}
}

void Doodle::starve()
{
	if(hunger==4)
		bord->setCritter(EMPTY, rCoord, cCoord);
}
