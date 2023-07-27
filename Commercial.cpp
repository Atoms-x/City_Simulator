#include "Commercial.h"
#include "CityNode.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>

//-----------------------------------------------------------------------------------
// int main
//  Arguments:
//      cityGrid: passed by reference to manipulate the actual 2d vector of nodes 
//      futureWorkers: passed by reference to increment with population increase
//                     and a holding variable for making changes at the end of turn
//      currentWorkers: passed by reference to decrement after pop of 'C' increases
//      currentGoods (acutally futureGoods): passed by reference to decrement after pop increase
//      rowLength: specifies the max number of rows in the cityGrid
//      columnLength: specifies the max number of columns in the cityGrid
//  Returns:
//      changes: Used to indicate if any changes have occured, ultimately for creating a
//               condition that will end the simulation (no changes)
//  Purpose:
//      Manipulates cityGrid to adjust commercial population, available worker
//      count, and available goods based on a set of rules. This will provide the 
//      conditions for the othe classes to draw from and alter the city.
//------------------------------------------------------------------------------------

int Commercial::main(vector<vector<CityNode>>& cityGrid, int& futureWorkers, int& currentWorkers,int& currentGoods, int rowLength, int columnLength)
{
    int popChange = 1;
    int changes = 0;
    set<int> grow;
  
    for (int y = 0; y < columnLength; y++)
    {
        for (int x = 0; x < rowLength; x++)
        {
            if (x >= 0 && x < rowLength && y >= 0 && y < columnLength && cityGrid[y][x].getType() == 'C' && cityGrid[y][x].getCurrentPopulation() < 2)
            {
                if (cityGrid[y][x].getCurrentPopulation() < 1)
                {
                    if (checkForPowerline(cityGrid, x, y, rowLength, columnLength) && currentWorkers >= 1 && currentGoods >= 1)
                    {
                      cityGrid[y][x].setPriority(determinePriority(cityGrid, x, y, rowLength, columnLength));
                      grow.insert(cityGrid[y][x].getPriority());
                    }
                    else if (checkAdjacentPopulation(cityGrid, x, y, rowLength, columnLength) >= 1 && currentWorkers >= 1 && currentGoods >= 1)
                    {
                      cityGrid[y][x].setPriority(determinePriority(cityGrid, x, y, rowLength, columnLength));
                      grow.insert(cityGrid[y][x].getPriority());
                    }
                }
                else if (cityGrid[y][x].getCurrentPopulation() == 1)
                {
                    if (checkAdjacentPopulation(cityGrid, x, y, rowLength, columnLength) >= 2 && currentWorkers >= 1 && currentGoods >= 1)
                    {
                      cityGrid[y][x].setPriority(determinePriority(cityGrid, x, y, rowLength, columnLength));
                      grow.insert(cityGrid[y][x].getPriority());
                    }
                }
    	      }
        }
    }

    for (auto it = grow.rbegin(); it != grow.rend(); it++)
    {
      for (int y = 0; y < columnLength; y++)
      {
        for (int x = 0; x < rowLength; x++)
        {
          if (x >= 0 && x < rowLength && y >= 0 && y < columnLength && cityGrid[y][x].getType() == 'C' && cityGrid[y][x].getCurrentPopulation() < 2 && currentWorkers >= 1 && currentGoods >= 1)
          {
            if ((*it) == cityGrid[y][x].getPriority())
            {
              cityGrid[y][x].setFuturePopulation(popChange);
              futureWorkers-=1;
              currentWorkers-=1;
              currentGoods-=1;
              changes++;
            }
          }
        }
      }
    }
   
    return changes;
}

//-----------------------------------------------------------------------------------
// bool checkForPowerline
//  Arguments:
//      cityGrid: passed by value to make checks into the 2d vector of nodes 
//      x: provides x coordinate current node being manipulated
//      y: provides y coordinate current node being manipulated
//      row: specifies the max number of rows in the cityGrid
//      column: specifies the max number of columns in the cityGrid
//  Returns:
//      true: returns true if the node being checked is type 'T' or '#'
//      false: returns false if not type 'T' or '#'
//  Purpose:
//      Checks if any adjacent nodes are power lines
//------------------------------------------------------------------------------------

bool Commercial::checkForPowerline(vector<vector<CityNode>> cityGrid, int x, int y, int row, int column)
{

    //Each of these conditionals checks what the type of the node is
    //then either returns true or false, depending on whether it's a power line
    //or not. Each cluster is checking either internal nodes or specific special cases

    if (y - 1 >= 0 && y + 1 < column && x - 1 >= 0 && x + 1 < row) //interior nodes
    {
        if (cityGrid[y - 1][x - 1].getType() == 'T' || cityGrid[y - 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x].getType() == 'T' || cityGrid[y - 1][x].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x + 1].getType() == 'T' || cityGrid[y - 1][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y][x - 1].getType() == 'T' || cityGrid[y][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y][x + 1].getType() == 'T' || cityGrid[y][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x - 1].getType() == 'T' || cityGrid[y + 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x].getType() == 'T' || cityGrid[y + 1][x].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x + 1].getType() == 'T' || cityGrid[y + 1][x + 1].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y == 0 && x == 0) //top left corner
    {
        if (cityGrid[y][x + 1].getType() == 'T' || cityGrid[y][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x - 1].getType() == 'T' || cityGrid[y + 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x].getType() == 'T' || cityGrid[y + 1][x].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y == 0 && x == row - 1) //top right corner
    {
        if (cityGrid[y][x - 1].getType() == 'T' || cityGrid[y][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x - 1].getType() == 'T' || cityGrid[y + 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x].getType() == 'T' || cityGrid[y + 1][x].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y == column - 1 && x == 0) //bottom left corner
    {
        if (cityGrid[y - 1][x].getType() == 'T' || cityGrid[y - 1][x].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x + 1].getType() == 'T' || cityGrid[y - 1][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y][x + 1].getType() == 'T' || cityGrid[y][x + 1].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y == column - 1 && x == row - 1) //Bottom right corner
    {
        if (cityGrid[y][x - 1].getType() == 'T' || cityGrid[y][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x - 1].getType() == 'T' || cityGrid[y - 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x].getType() == 'T' || cityGrid[y - 1][x].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y == 0 && x - 1 >= 0 && x + 1 < row) //Top row
    {
        if (cityGrid[y][x - 1].getType() == 'T' || cityGrid[y][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y][x + 1].getType() == 'T' || cityGrid[y][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x - 1].getType() == 'T' || cityGrid[y + 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x].getType() == 'T' || cityGrid[y + 1][x].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x + 1].getType() == 'T' || cityGrid[y + 1][x + 1].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y == column - 1 && x - 1 >= 0 && x + 1 < row) //bottom row
    {
        if (cityGrid[y - 1][x - 1].getType() == 'T' || cityGrid[y - 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x].getType() == 'T' || cityGrid[y - 1][x].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x + 1].getType() == 'T' || cityGrid[y - 1][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y][x - 1].getType() == 'T' || cityGrid[y][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y][x + 1].getType() == 'T' || cityGrid[y][x + 1].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y - 1 >= 0 && y + 1 < column && x == 0) //left column
    {
        if (cityGrid[y - 1][x].getType() == 'T' || cityGrid[y - 1][x].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x + 1].getType() == 'T' || cityGrid[y - 1][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y][x + 1].getType() == 'T' || cityGrid[y][x + 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x].getType() == 'T' || cityGrid[y + 1][x].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x + 1].getType() == 'T' || cityGrid[y + 1][x + 1].getType() == '#')
            return true;
        else
            return false;
    }

    else if (y - 1 >= 0 && y + 1 < column && x == row - 1) //right column
    {
        if (cityGrid[y - 1][x - 1].getType() == 'T' || cityGrid[y - 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y - 1][x].getType() == 'T' || cityGrid[y - 1][x].getType() == '#')
            return true;
        else if (cityGrid[y][x - 1].getType() == 'T' || cityGrid[y][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x - 1].getType() == 'T' || cityGrid[y + 1][x - 1].getType() == '#')
            return true;
        else if (cityGrid[y + 1][x].getType() == 'T' || cityGrid[y + 1][x].getType() == '#')
            return true;
        else
            return false;
    }

    else
        return false;
}

//-----------------------------------------------------------------------------------
// int checkAdjacentPopulation
//  Arguments:
//      cityGrid: passed by value to make checks into the 2d vector of nodes 
//      x: provides x coordinate current node being manipulated
//      y: provides y coordinate current node being manipulated
//      row: specifies the max number of rows in the cityGrid
//      column: specifies the max number of columns in the cityGrid
//  Returns:
//      numberOfNodes: specifies how many adjacent nodes there are that have the 
//                     specified amount of population
//  Purpose:
//      Checks how many adjacent nodes have specified population
//------------------------------------------------------------------------------------

int Commercial::checkAdjacentPopulation(vector<vector<CityNode>> cityGrid, int x, int y, int row, int column)
{
    int numberOfNodes = 0; // Counting variable for the number of nodes that have a specified pop
    int popCheck = cityGrid[y][x].getCurrentPopulation(); // Specifies the required pop amount to check

    //Rectifies the condition for zero population nodes, preventing growth of all zero pop nodes
    //in the first turn
    if (popCheck == 0)
        popCheck = 1;

    //Each of these conditionals checks what the population of the node is
    //then increments numberOfNodes to reflect a count that meet, the conditions for growth.
    //Each cluster is checking either internal nodes or specific special cases

    if (y - 1 >= 0 && y + 1 < column && x - 1 >= 0 && x + 1 < row) //internal nodes
    {
        if (cityGrid[y - 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    else if (y == 0 && x == 0) //top left corner
    {
        if (cityGrid[y][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    else if (y == 0 && x == row - 1) //top right corner
    {
        if (cityGrid[y][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    else if (y == column - 1 && x == 0) //bottom left corner
    {
        if (cityGrid[y - 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }
    else if (y == column - 1 && x == row - 1) //Bottom right corner
    {
        if (cityGrid[y - 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    else if (y == 0 && x - 1 >= 0 && x + 1 < row) //Top row
    {
        if (cityGrid[y][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    else if (y == column - 1 && x - 1 >= 0 && x + 1 < row) //bottom row
    {
        if (cityGrid[y - 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    else if (y - 1 >= 0 && y + 1 < column && x == 0) //left column
    {
        if (cityGrid[y - 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x + 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    else if (y - 1 >= 0 && y + 1 < column && x == row - 1) //right column
    {
        if (cityGrid[y - 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y - 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x - 1].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
        if (cityGrid[y + 1][x].getCurrentPopulation() >= popCheck)
            numberOfNodes++;
    }

    return numberOfNodes;
}

//-----------------------------------------------------------------------------------
// int determinePriority
//  Arguments:
//      cityGrid: passed by value to make checks into the 2d vector of nodes 
//      x: provides x coordinate current node being manipulated
//      y: provides y coordinate current node being manipulated
//      row: specifies the max number of rows in the cityGrid
//      column: specifies the max number of columns in the cityGrid
//  Returns:
//      priorityValue: A unique number derived from the differing levels of priority, each 
//                     level adding a dispraportionate amount of value to the variable,creating
//                     non-overlapping ranges of priority for each node
//  Purpose:
//      Creates a number that can be placed into a list of some kind (this program uses a set)
//      to linearly grow nodes in proper order, based upon a set of well defined rules, until
//      the conditions for growth are no longer met.
//------------------------------------------------------------------------------------

int Commercial::determinePriority(vector<vector<CityNode>> cityGrid, int x, int y, int row, int column)
{
    int adjacentPopulationCount = 0;
    int priorityValue = 0; //The value per node for order of growth
    int popCheck = cityGrid[y][x].getCurrentPopulation(); // Specifies the required pop amount to check
    priorityValue = popCheck * 100000;
    //Rectifies the condition for zero population nodes, preventing growth of all zero pop nodes
    //in the first turn
    if (popCheck == 0)
        popCheck = 1;

    //Each of these conditionals checks what the population of the node is
    //then increments numberOfNodes to reflect a count that meet, the conditions for growth.
    //Each cluster is checking either internal nodes or specific special cases

    if (y - 1 >= 0 && y + 1 < column && x - 1 >= 0 && x + 1 < row) //internal nodes
    {
      adjacentPopulationCount += cityGrid[y - 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x + 1].getCurrentPopulation();

      priorityValue += adjacentPopulationCount * 1000;
    }

    else if (y == 0 && x == 0) //top left corner
    {
      adjacentPopulationCount += cityGrid[y][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x + 1].getCurrentPopulation();

      priorityValue += adjacentPopulationCount * 1000;
    }

    else if (y == 0 && x == row - 1) //top right corner
    {
      adjacentPopulationCount += cityGrid[y][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x].getCurrentPopulation();

      priorityValue += adjacentPopulationCount * 1000;
    }

    else if (y == column - 1 && x == 0) //bottom left corner
    {
      adjacentPopulationCount += cityGrid[y - 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x + 1].getCurrentPopulation();
       
      priorityValue += adjacentPopulationCount * 1000;
    }
    else if (y == column - 1 && x == row - 1) //Bottom right corner
    {
      adjacentPopulationCount += cityGrid[y - 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x - 1].getCurrentPopulation();
      
      priorityValue += adjacentPopulationCount * 1000;
    }

    else if (y == 0 && x - 1 >= 0 && x + 1 < row) //Top row
    {
      adjacentPopulationCount += cityGrid[y][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x + 1].getCurrentPopulation();

      priorityValue += adjacentPopulationCount * 1000;
    }

    else if (y == column - 1 && x - 1 >= 0 && x + 1 < row) //bottom row
    { 
      adjacentPopulationCount += cityGrid[y - 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x + 1].getCurrentPopulation();
   
      priorityValue += adjacentPopulationCount * 1000;
    }

    else if (y - 1 >= 0 && y + 1 < column && x == 0) //left column
    {
      adjacentPopulationCount += cityGrid[y - 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x + 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x + 1].getCurrentPopulation();

      priorityValue += adjacentPopulationCount * 1000;
    }

    else if (y - 1 >= 0 && y + 1 < column && x == row - 1) //right column
    {
      adjacentPopulationCount += cityGrid[y - 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y - 1][x].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x - 1].getCurrentPopulation();
      adjacentPopulationCount += cityGrid[y + 1][x].getCurrentPopulation();
  
      priorityValue += adjacentPopulationCount * 1000;
    }

    priorityValue += ((cityGrid.size() - y)*(cityGrid.at(0).size()));
    priorityValue += (cityGrid.at(0).size() - x);

    return priorityValue;
}
