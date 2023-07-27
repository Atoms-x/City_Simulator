#include "Update.h"
#include <vector>
#include <iostream>
#include <string>

//-----------------------------------------------------------------------------------
// void updateMap
//  Arguments:
//      cityGrid: passed by reference to manipulate the 2d vector of nodes
//      futureWorkers: passed by reference, used to set the current worker count for the 
//                     next turn
//      currentWorkers: passed by reference, receives the end of turn count of workers
//      row: specifies the max number of rows in the cityGrid
//      column: specifies the max number of columns in the cityGrid
//  Returns:
//      Nothing explicitly, but cityGrid, futureWorkers, and currentWorkers are passed  
//      by reference, so modifies outside the scope of this Function/Class
//  Purpose:
//      Updates the stats of the city, in the nodes and outside of the nodes
//------------------------------------------------------------------------------------

void Update::updateMap(vector<vector<CityNode>> &cityGrid, int &futureWorkers, int &currentWorkers, int &futureGoods, int &currentGoods, int rowLength, int columnLength)
{
  currentWorkers = futureWorkers;
  currentGoods = futureGoods;
  
  for(int y = 0; y < columnLength; y++)
  {
    for(int x = 0; x < rowLength; x++)
    {
      if (x >= 0 && x < rowLength && y >= 0 && y < columnLength)
      {
        cityGrid[y][x].setCurrentPopulation(cityGrid[y][x].getFuturePopulation());
      }
    }
  }
}

//-----------------------------------------------------------------------------------
// void displayMap
//  Arguments:
//      cityGrid: passed by value to check into the 2d vector for data
//      refreshRate: Determines the amount of times the map will be displayed and on 
//                   on what turn
//      timeStep: The current turn
//      currentWorkers: The current amount of workers available
//      goods: The current amount of goods available
//  Returns:
//      Nothing/Displays to console only
//  Purpose:
//      Displays to console the current time step, available workers, and 
//      available goods. It then displays the current state of the city.
//------------------------------------------------------------------------------------

void Update::displayMap(vector<vector<CityNode>> cityGrid, int refreshRate, int timeStep, int currentWorkers, int goods) const
{
  cout << "\nTime Step: " << timeStep << endl;
  cout << "Available Workers " << currentWorkers << " Available Goods " << goods << endl;
  
  //Displays only if it is the first turn, a refresh rate of 1, or
  //if it is one off from the refresh rate (since it displays on one, next will
  //whatever the refresh rate added to that is)
  if (refreshRate == 1 || timeStep % refreshRate == 1 || timeStep ==1) 
  {
    for (int a = 0; a <= cityGrid.at(0).size()*2+1; a++) //for loop that creates the top line
      cout << "-";
    
    cout << endl;

    for (int i = 0; i < cityGrid.size(); i++) // for loop that goes through all the columns 
    {
      cout << "|";

      for (int j = 0; j < cityGrid[i].size(); j++) // for loop that goes through all the rows
      {
        if (cityGrid[i][j].getCurrentPopulation() == 0)
          cout << cityGrid[i][j].getType() << " ";  //prints out the City Map
        
        else
          cout << cityGrid[i][j].getCurrentPopulation() << " ";  //prints out the City Map
      }
      cout << "|"<< endl;
    }

    for (int a = 0; a <= cityGrid.at(0).size()*2+1; a++) //for loop that creates the bottom line
      cout << "-";
    
    cout << endl;
  }
}