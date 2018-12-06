/***************************************************************
 * Utility Functions:
 * 1.Random Int: takes two ints as a range and returns a
 *	random number between them; if one integer is given,
 *	the range is between 0 and b.
 *
 * 2.Clear Page: called without parameters to clear the 
 *	standard ouput and move the cursor to 1,1 between prints 
 *	in linux systems.
 *
 * 3.GetInt: gets and validates an integer value between 
 *	two values, a and b, or less than b. Added getIntNoError
 *	to not return a message, but move back to input space.
 *
 * 4.moveCursor: moves the terminal cursor to row x, column y.
 *
 * 5. getFloat
 **************************************************************/
#include <stdlib.h> //1.srand,rand,
#include <time.h> //1.time,
#include <iostream> //2.cout,
#include <string>
#include <cctype>


/****************
 * 1.Random Int
 * *************/
int randInt(int a, int b)
{
	   //srand(time(NULL));
	   return rand() % b + a;
}
int randInt(int b)
{
	   srand(time(NULL));
	   return rand() % b;
}

/*****************
 * 2.Clear Page
 * **************/
void clearPage()
{
	   std::cout << "\033[2J\033[1;1H";
}

/*************
 * 3.Get Int
 * **********/
int getInt(int a)
{
	   int number;
	   std::cin >> number;
	   while(std::cin.fail())
	   {
		   std::cin.sync();
		   std::cin.clear();
		   std::cin.ignore(256,'\n');
		   std::cout << "Invalid input: Please enter an integer.";
		   std::cin >> number;
	   }
	   while(number < 0 || number > a)
	   {
		   std::cin.sync();
		   std::cin.clear();
		   std::cin.ignore(256,'\n');
		   std::cout << "Invalid input: Please enter an integer between 0 and " 
			   << a << " :";
		   std::cin >> number;
	   }
	   std::cin.clear();
	   return number;
}

int getInt()
{
	   int number;
	   std::cin >> number; 
	   while(std::cin.fail())
	   {
		   std::cin.sync();
		   std::cin.clear();
		   std::cin.ignore(256,'\n');
		   std::cout << "Invalid input: Please enter an integer.";
		   std::cin >> number;
	   }
	   while(number < 1)
	   {
		   std::cin.sync();
		   std::cin.clear();
		   std::cin.ignore(256,'\n');
		   std::cout << "Invalid input: Please enter an integer greater than 0";
		   std::cin >> number;
	   }
	   std::cin.clear();
	   return number;
}

/****************
 * 4. moveCursor
 * *************/
//void moveCursor(int x, int y)
//{
//	printf("\033[%d;%dH", x, y);
//	fflush(stdout);
//}
/*****************/

/*int getIntNoMove(int x, int y)
{
	int number;
	std::cin >> number;
	while(std::cin.fail())
	{
		std::cin.sync();
		std::cin.clear();
		std::cin.ignore(256, '\n');
		moveCursor(x,y);
		std::cin >> number;
	}
	while(number <= 1)
	{
		std::cin.sync();
		std::cin.clear();
		std::cin.ignore(256,'\n');
		moveCursor(x,y);
		std::cin >> number;
	}
	std::cin.clear();
	return number;
}
*/
int getInt(int a, int b)
{
	   int number;
	   std::cin >> number;
	   while(std::cin.fail())
	   {
		   std::cin.sync();
		   std::cin.clear();
		   std::cin.ignore(256,'\n');
		   std::cout << "Invalid input: Please enter an integer.";
		   std::cin >> number;
	   }
	   while(number < a || number > b)
	   {
		   std::cin.sync();
		   std::cin.clear();
		   std::cin.ignore(256,'\n');
		   std::cout << "Invalid input: Please enter an integer between " << a 
			   << " and " << b << " :";
		   std::cin >> number;
	   }
	   std::cin.clear();
	   return number;
}

/**************
 * 5. getFloat
 * ***********/
float getFloat()
{
	float number;
	std::cin >> number;
	while(std::cin.fail())
	{
		std::cin.sync();
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cout << "Invalid input: Please enter a float value.";
		std::cin >> number;
	}
	std::cin.clear();
	return number;
}

