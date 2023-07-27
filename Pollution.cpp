#include "Pollution.h"
#include "CityNode.h"
#include <iostream>
#include <vector>
#include <string>

//-----------------------------------------------------------------------------------
// void main
//  Arguments:
//      cityGrid: passed by reference to manipulate the actual 2d vector of nodes 
//      rowLength: specifies the max number of rows in the cityGrid
//      columnLength: specifies the max number of columns in the cityGrid
//  Returns:
//      just manipulates the cityGrid
//  Purpose:
//      Manipulates cityGrid to adjust current pollution in the nodes 
//------------------------------------------------------------------------------------

void Pollution::main(vector<vector<CityNode>>& cityGrid, int rowLength, int columnLength)
{
 
  int pollutionPass = 0;

  for (int y = 0; y < columnLength; y++)
  {
    for (int x = 0; x < rowLength; x++)
    {
      if (x >= 0 && x < rowLength && y >= 0 && y < columnLength && cityGrid[y][x].getType() == 'I' && cityGrid[y][x].getCurrentPopulation() < 4)
      {
        if (cityGrid[y][x].getCurrentPopulation() < 1)
        {
          cityGrid[y][x].setCurrentPollution(0);           
        }
        else if (cityGrid[y][x].getCurrentPopulation() == 1)
        {
          cityGrid[y][x].setCurrentPollution(1);            
        }
        else if (cityGrid[y][x].getCurrentPopulation() == 2)
        {
          cityGrid[y][x].setCurrentPollution(2);           
        }
        else
          cityGrid[y][x].setCurrentPollution(3);
      }
    }
  }

  while (pollutionPass < 3)
  {
    for (int y = 0; y < columnLength; y++)
    {
      for (int x = 0; x < rowLength; x++)
      {
          checkAdjacentPollution(cityGrid, x, y, rowLength, columnLength);
      }
    }
    pollutionPass++;
  }
}

//-----------------------------------------------------------------------------------
// int checkAdjacentPollution
//  Arguments:
//      cityGrid: passed by reference to make final pollution changes to 2d vector of nodes 
//      x: provides x coordinate current node being manipulated
//      y: provides y coordinate current node being manipulated
//      row: specifies the max number of rows in the cityGrid
//      column: specifies the max number of columns in the cityGrid
//  Returns:
//      nothing, changes by reference
//  Purpose:
//      Checks what the adjacent pollution is, and if the pollution - 1 is greater than
//      the current pollution, change the current pollution to the adjancent - 1
//------------------------------------------------------------------------------------

void Pollution::checkAdjacentPollution(vector<vector<CityNode>>& cityGrid, int x, int y, int row, int column)
{
 
  //Each of these conditionals checks what the pollution of the node is
  //then checks to see if its own pollution is greater than adjacent - 1
  //If less then, takes the adjacent - 1 pollution, otherwise keeps it's own
  //Each cluster is checking either internal nodes or specific special cases

  if (y-1 >= 0 && y+1 < column && x-1 >= 0 && x+1 < row) //internal nodes
  {
    if ((cityGrid[y-1][x-1].getCurrentPollution() - 1) > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x-1].getCurrentPollution() - 1);

    if ((cityGrid[y-1][x].getCurrentPollution() - 1) > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x].getCurrentPollution() - 1);

    if ((cityGrid[y-1][x+1].getCurrentPollution() - 1) > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x+1].getCurrentPollution() - 1);

    if ((cityGrid[y][x-1].getCurrentPollution() - 1) > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x-1].getCurrentPollution() - 1);

    if ((cityGrid[y][x+1].getCurrentPollution() - 1) > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x+1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x-1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x].getCurrentPollution() - 1);

    if (cityGrid[y+1][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x+1].getCurrentPollution() - 1);
  }

  else if (y == 0 && x == 0) //top left corner
  {
    if (cityGrid[y][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x+1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x].getCurrentPollution() - 1);

    if (cityGrid[y+1][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x+1].getCurrentPollution() - 1);
  }

  else if (y == 0 && x == row - 1) //top right corner
  {
    if (cityGrid[y][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x-1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x-1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x].getCurrentPollution() - 1);
  }

  else if (y == column-1 && x == 0) //bottom left corner
  {
    if (cityGrid[y-1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x].getCurrentPollution() - 1);

    if (cityGrid[y-1][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x+1].getCurrentPollution() - 1);

    if (cityGrid[y][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x+1].getCurrentPollution() - 1);
  }
  else if (y == column-1 && x == row-1) //Bottom right corner
  {
    if (cityGrid[y-1][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x-1].getCurrentPollution() - 1);

    if (cityGrid[y-1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x].getCurrentPollution() - 1);

    if (cityGrid[y][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x-1].getCurrentPollution() - 1);
  }

  else if (y == 0 && x-1 >= 0 && x+1 < row) //Top row
  {
    if (cityGrid[y][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x-1].getCurrentPollution() - 1);

    if (cityGrid[y][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x+1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x-1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x].getCurrentPollution() - 1);

    if (cityGrid[y+1][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x+1].getCurrentPollution() - 1);
  }

  else if (y == column-1 && x-1 >= 0 && x+1 < row) //bottom row
  {
    if (cityGrid[y-1][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x-1].getCurrentPollution() - 1);

    if (cityGrid[y-1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x].getCurrentPollution() - 1);

    if (cityGrid[y-1][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x+1].getCurrentPollution() - 1);

    if (cityGrid[y][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x-1].getCurrentPollution() - 1);

    if (cityGrid[y][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x+1].getCurrentPollution() - 1);
  }

  else if (y-1 >= 0 && y+1 < column && x == 0) //left column
  {
    if (cityGrid[y-1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x].getCurrentPollution() - 1);

    if (cityGrid[y-1][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x+1].getCurrentPollution() - 1);

    if (cityGrid[y][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x+1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x].getCurrentPollution() - 1);

    if (cityGrid[y+1][x+1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x+1].getCurrentPollution() - 1);
  }

  else if (y-1 >= 0 && y+1 < column && x == row-1) //right column
  {
    if (cityGrid[y-1][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x-1].getCurrentPollution() - 1);

    if (cityGrid[y-1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y-1][x].getCurrentPollution() - 1);

    if (cityGrid[y][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y][x-1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x-1].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x-1].getCurrentPollution() - 1);

    if (cityGrid[y+1][x].getCurrentPollution() - 1 > cityGrid[y][x].getCurrentPollution())
      cityGrid[y][x].setCurrentPollution(cityGrid[y+1][x].getCurrentPollution() - 1);
  }
}