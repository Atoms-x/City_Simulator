#ifndef CITYSETUP_H
#define CITYSETUP_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CitySetup
{
private:

	vector <vector <char> > CityMap; //the 2D vector that stores all the elements
	int Refresh;
  int Time;
  int row = 0;
  int column = 0;

public:
  void main(CitySetup &);
	void CityGrid(string Filename, CitySetup &); // gets the city and removes the commas and stores it

	int GetTime(); // retrieves the time
	int GetRefresh(); // retrieves the refresh rate
  int getRow() const
    { return row; }
  int getColumn() const
    { return column; }
	vector<vector<char>> GetCity(); // retrieves the city grid

	void SetTime(int ti); // sets the time
	void SetRefresh(int re); // sets the refresh rate

  void incRow()
    { row++; }
  void incColumn()
    { column++; }
    
	void SetCity(vector<vector<char>> input); // sets the city grid
};
#endif