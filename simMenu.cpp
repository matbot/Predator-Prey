/**************************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 13:44:02 PDT 2016 
 * *Description: This function provides a user
 * input interface, initializes objects, and
 * calls the runBoard that creates the simulation.
 * ***********************************************/
#include <iostream>
#include <unistd.h>
#include "utils.hpp"
#include "game.hpp"
#include "critter.hpp"

using std::cout;
using std::cin;
using std::endl;

/************
 * simMenu
 * *********/
void simMenu()
{
	clearPage();
	usleep(50000);
	cout << "Welcome the Mathew McDade's Predator(\u24E7 )-Prey(\u204E) Simulation" << endl << endl;
	usleep(100000);

	cout << "Would you like to see the default simulation or make a custom simulation(for EXTRACREDIT)?" << endl;
	int choice = 0;
	while(choice!=3)
	{
	cout << "1. Default Simulation" << endl;
	cout << "2. Custom Simulation" << endl;
	cout << "3. Quit" << endl << endl;
	usleep(75000);

	cout << "Please make your selection:" << endl;
	choice = getInt(1,3);

	switch(choice) {
		case 1:{ cout << "How many turns would you like the default simulation to run?" << endl;
			   int turnChoice = getInt();
			   Game g(turnChoice);
			   g.runBoard();
			   break;}
		case 2:{ usleep(100000);
			   clearPage();
			   cout << "Custom Simulation" << endl;
			   cout << "How many turns would you like the custom simulation to run?" << endl;
			   int turnChoice = getInt();
			   cout << "How many rows should the simulation board have?" << endl;
			   cout << "NOTE: Row and Column choices over 40 may cause some simulation stuttering." << endl;
			   int rowChoice = getInt();
			   cout << "How many columns should the simulation board have?" << endl;
			   int columnChoice = getInt();
			   cout << "How many ants should the simulation have?" << endl;
			   int antChoice = getInt(1,(rowChoice*columnChoice)*.8);
			   cout << "How many doodlebugs should the simulation have?" << endl;
			   int doodleChoice = getInt(1,(rowChoice*columnChoice)-(antChoice+1));

			   Game g(turnChoice, rowChoice, columnChoice, antChoice, doodleChoice);
			   g.runBoard();
			   break; }
		case 3: return;
			   }
	}
}


