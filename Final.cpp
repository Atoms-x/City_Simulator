#include "Final.h"
#include <vector>
#include <iostream>
#include <string>

//-----------------------------------------------------------------------------------
// void finish
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
//      Displays to console the final region state, final pollution map 
//      including final Residential population, final industrial population,
//      final commercial population, and final total pollution count. It then 
//      prompts the user to examine a specified area of the map (using the coordinates
//      of the top left corner of a box, and the bottom right corner)
//------------------------------------------------------------------------------------

void Final::finish(vector<vector<CityNode>> cityGrid, int refreshRate, int timeStep, int currentWorkers, int goods) const
{
  //The user specified box check variables 
  int minX = 0;
  int minY = 0;
  int maxX = 0;
  int maxY = 0;

  //Counters used to get final totals by stepping through cityGrid
  int totalResPop = 0;
  int totalIndPop = 0;
  int totalComPop = 0;
  int totalPollution = 0;
  
  
  //Display of the final region state ----------------------------------------------
  cout << "\nFinal Region State" << endl;
  
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
  
  
  //Display of the pollution map --------------------------------------------------
  cout << "\nPollution" << endl;

  for (int a = 0; a <= cityGrid.at(0).size()*2+1; a++) //for loop that creates the top line
    cout << "-";
  
  cout << endl;

  for (int i = 0; i < cityGrid.size(); i++) // for loop that goes through all the columns 
  {
    cout << "|";

    for (int j = 0; j < cityGrid[i].size(); j++) // for loop that goes through all the rows
      cout << cityGrid[i][j].getCurrentPollution() << " ";  //prints out the City Map
    
    cout << "|"<< endl;
  }

  for (int a = 0; a <= cityGrid.at(0).size()*2+1; a++) //for loop that creates the bottom line
      cout << "-";
    
    cout << endl;
  
  //Nested for loops to get the final total population counts by stepping through cityGrid
  for(int y = 0; y < cityGrid.size(); y++)
  {
    for(int x = 0; x < cityGrid[1].size(); x++)
    {
      if (cityGrid[y][x].getType() == 'R')
        totalResPop += cityGrid[y][x].getCurrentPopulation();
      if (cityGrid[y][x].getType() == 'I')
        totalIndPop += cityGrid[y][x].getCurrentPopulation();
      if (cityGrid[y][x].getType() == 'C')
        totalComPop += cityGrid[y][x].getCurrentPopulation();
      
      totalPollution += cityGrid[y][x].getCurrentPollution();
    }
  }
  
  //Display of all the final stats
  cout << "\nThe total popluations for the region are:" << endl;
  cout << "Residential: " << totalResPop << endl;
  cout << "Industrial: " << totalIndPop << endl;
  cout << "Commercial: " << totalComPop << endl;
  cout << "The total amount of pollution in the region is " << totalPollution << " units" << endl;

  //Prompt for a user specified area check
  cout << "Please enter the diagonal corners of the area you wish to have more information about. ";
  cout << "(MinX = 0, MinY = 0, MaxX = " << (cityGrid[1].size() - 1) << ", MaxY = " << (cityGrid.size() - 1) << ")"; 

  totalResPop = 0;
  totalIndPop = 0;
  totalComPop = 0;
  totalPollution = 0;

  //input for the user specified area with a simple bounds check to prevent error
  do
  {
    cout << "\nminX: ";
    cin >> minX;
    cout << "minY: ";
    cin >> minY;
    cout << "maxX: ";
    cin >> maxX;
    cout << "maxY: ";
    cin >> maxY;

    if ((minX < 0 || minY < 0) || (minX > maxX || minY > maxY) || (maxX > (cityGrid[1].size() - 1) || maxY > (cityGrid.size() - 1)) || cin.fail())
    {
      cout << "\nINVALID INPUT\n";
      cin.clear(); //clear the stream operator if a non int is input
      cin.ignore(); //ignore any input
      //These are used to prevent the exit of the while loop from a non int input
      minX = 0; 
      minY = 0;
      maxX = -1;
      maxY = -1;
    }
  } while ((minX < 0 || minY < 0) || (minX > maxX || minY > maxY) || (maxX > (cityGrid[1].size() - 1) || maxY > (cityGrid.size() - 1)) | cin.fail());
  
  //Same step through as before, but with user specified mins and maxes
  for(int y = minY; y <= maxY; y++)
  {
    for(int x = minX; x <= maxX; x++)
    {
      if (cityGrid[y][x].getType() == 'R')
        totalResPop += cityGrid[y][x].getCurrentPopulation();
      if (cityGrid[y][x].getType() == 'I')
        totalIndPop += cityGrid[y][x].getCurrentPopulation();
      if (cityGrid[y][x].getType() == 'C')
        totalComPop += cityGrid[y][x].getCurrentPopulation();
      
      totalPollution += cityGrid[y][x].getCurrentPollution();
    }
  }

  //Display of the user specified area data
  cout << "The total populations for the requested area are:" << endl;
  cout << "Residential: " << totalResPop << endl;
  cout << "Industrial: " << totalIndPop << endl;
  cout << "Commercial: " << totalComPop << endl;
  cout << "The total amount of pollution for the requested area is " << totalPollution << " units.";

  cout << "\nSimulation complete" << endl;
}