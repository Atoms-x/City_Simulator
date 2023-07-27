//***************************************************************
// Chet Lockwood
// Last Update: 21 MAY 2020
// Title: City Growth Simulator
// Description: Simulates the growth of a city under a specified model
//***************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

#include "CitySetup.h"
#include "CityNode.h"
#include "Residential.h"
#include "Industrial.h"
#include "Commercial.h"
#include "Pollution.h"
#include "Update.h"
#include "Final.h"

using namespace std;

//Function prototype for reading the 2d vector of chars to a 2d vector of nodes
void transfer (vector<vector<CityNode>> &, CitySetup, int, int); 

//MAIN FUNCTION --------------------------------------------------------------------
int main()
{
  int refresh = 0;
  int turns = 0;
  int turnsCheck = 1;
  int rows = 0;
  int columns = 0;
  int futureWorkers = 0;
  int currentWorkers = 0;
  int futureGoods = 0;
  int currentGoods = 0;
  int changes = 0;
  
  CitySetup setup;
  setup.main(setup); //reads the config.txt and region file into a 2d vector of chars

  refresh = setup.GetRefresh(); //Setting the refresh rate for display
  turns = setup.GetTime(); //Setting the max number of turns
  rows = setup.getRow()/setup.getColumn(); //Calculates the row length
  columns = setup.getColumn(); //Calculates the column length

  //Instantiates the 2d vector of nodes
  vector<vector<CityNode>> cityGrid(columns, vector<CityNode> (rows)); 

  //Transfers the data from the 2d vector of chars to one of objects
  transfer(cityGrid, setup, rows, columns); 

  Residential r;
  Commercial Com;
  Industrial ind;
  Pollution p;
  
  Update u;

  //This increments the turn counter, maninpulates the city (grows it), updates the 
  //data for the city and displays city and data to console according to refresh rate
  //checks if max turn has been reached or if there are no changes within the city
  do
  {
    changes = 0;
    changes = r.main(cityGrid, futureWorkers, rows, columns);
    changes += Com.main(cityGrid, futureWorkers, currentWorkers, futureGoods, rows, columns);
    changes += ind.main(cityGrid, futureWorkers, currentWorkers, futureGoods, rows, columns);

    if(turnsCheck <= turns && changes != 0)
    {
      u.updateMap(cityGrid, futureWorkers, currentWorkers,futureGoods, currentGoods, rows, columns);
      u.displayMap(cityGrid, refresh, turnsCheck, currentWorkers, currentGoods);
    }

    turnsCheck++;

  } while (turnsCheck <= turns && changes != 0);

  p.main(cityGrid, rows, columns);

  Final f;  //f.finish will call the final state and analysis before ending the sim
  f.finish(cityGrid, refresh, turnsCheck, currentWorkers, currentGoods);

  return 0;
}

//FUNCTIONS -------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// void transfer
//  Arguments:
//      cityGrid: passed by reference to manipulate the actual 2d vector of nodes 
//      setup: the 2d vector of chars to set the node type in cityGrid
//      rows: specifies the max number of rows in the cityGrid
//      columns: specifies the max number of columns in the cityGrid
//  Returns:
//      Nothing explicitly, but cityGrid is passed by reference, so modifies outside 
//      the scope of this Function
//  Purpose:
//      Sets the node types for the 2d vector of nodes cityGrid
//------------------------------------------------------------------------------------

void transfer (vector<vector<CityNode>> &cityGrid, CitySetup setup, int rows, int columns)
{
  vector<vector<char>> CityMap = setup.GetCity();
  
  for (int i = 0; i < columns; i++) // for loop that goes through all the columns 
	{
		for (int j = 0; j < rows; j++) // for loop that goes through all the rows
			cityGrid[i][j].setType(CityMap[i][j]);
  }
}