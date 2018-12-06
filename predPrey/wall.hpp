/*************************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 14:15:42 PDT 2016
 * *Description: Wall class header.
 * Created border object as a derived class of
 * Critter to differenctiate from NULL in all
 * functions that assess the space around a 
 * given critter derived object. This prevents
 * methods being called on NULL border objects.
 * Not sure about this convention of using a 
 * derived class in this way, but it works.
 * *********************************************/

#ifndef MMCD_WALL_HPP
#define MMCD_WALL_HPP

#include "critter.hpp"

class Wall: public Critter
{
private:
public:
	Wall(Game*,int,int);
	~Wall();
	Species getCritter();
};
#endif
