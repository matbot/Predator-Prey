/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 14:20:18 PDT 2016 
 * *Description: Main method.
 * Not much here. More inside.
 * *********************************************/
#include <iostream>
#include <stdlib.h>
#include "game.hpp"
#include "critter.hpp"
#include "simMenu.hpp"

int main()
{
	srand(time(NULL)); //moved rand seed here to make calls to rand provide more random values
	simMenu();		//without long time delays.
	return 0;
}
