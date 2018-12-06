/*********************************************
 * *Author: Mathew McDade
 * *Date:	Sat Oct 29 14:19:23 PDT 2016
 * *Description: Wall class impl.
 * *********************************************/
#include "wall.hpp"

/***************
 * constructor
 * ************/
Wall::Wall(Game* b, int r, int c):Critter(b,r,c)
{
	//
}

Wall::~Wall()
{
	//definietly nothing
}

Species Wall::getCritter()
{
	return WALL;
}


