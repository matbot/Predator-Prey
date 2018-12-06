/*********************************************
 * *Author: Mathew McDade
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
