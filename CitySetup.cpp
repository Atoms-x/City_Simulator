#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "CitySetup.h"

using namespace std;

//MAIN --------------------------------------------------------------------------

void CitySetup::main(CitySetup &City)
{
	string file, line;
	ifstream inFile;

	cout << "Beginning simulation" << endl;
	cout << "Please enter the name of the configuration file: ";
	getline(cin, file); // gets the text file

	inFile.open(file); // opens the file

	if (!inFile) //If you can't find the file it will display this message
	{
		cout << "Unable to open the file";
		exit(1);
	}

	getline(inFile, line); //gets the first line of the text file
	int pos = line.find(":"); //finds the semicolon in the line
	string region = line.substr(pos + 1); //stores everything after the colon into the string

	getline(inFile, line); //gets the second line of the text file
	int pos2 = line.find(":"); //finds the semicolon in the line
	string ti = line.substr(pos2 + 1); //stores everything after the colon into the string
	int time = stoi(ti); //turns the string into an int

	getline(inFile, line); //gets the third line of the text file
	int pos3 = line.find(":"); //finds the semicolon in the line
	string re = line.substr(pos3 + 1); //stores everything after the colon into the string
	int refresh = stoi(re); //turns the string into an int

	//Outputs everything from the text files that was stored
	//cout <<"Region Layout: "<< region << endl;
	//cout << "Time Limit: " << time << endl;
	//cout << "Refresh Rate: " << refresh << endl;
	
	City.CityGrid(region, City); // gets the city and removes the commas and stores it in the 2D vector
	City.SetTime(time); //sets the time
	City.SetRefresh(refresh); //sets the refresh rate
}

//CITYGRID -----------------------------------------------------------------------------

void CitySetup::CityGrid(string FileName, CitySetup &City)
{
	string line;			
	ifstream Infile;

	Infile.open(FileName.c_str());

	if (!Infile)
	{
		cout << "Unable to open the file";
		exit(1);
	}
	else
	{
			while (getline(Infile, line))
			{
			  vector<char> grid; //vector to hold the char of elements

			  for (char& c : line) //for loop that will go through the line of the map
			  {
				  if (c != ',') // if statement that will ignore the commas
          {
					  grid.push_back(c); // pushes all the characters into a vector
            City.incRow();
          }
			  }

			  CityMap.push_back(grid); // pushes all the characters into a 2D vector
        City.incColumn();
		  }	
	}
	
  cout<<"Initial Region State" << endl;

	for (int a = 0; a <= CityMap.at(0).size()*2+1; a++) //for loop that creates the top line
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < CityMap.size(); i++) // for loop that goes through all the columns 
	{
		cout << "|";
		for (int j = 0; j < CityMap[i].size(); j++) // for loop that goes through all the rows
		
			cout << CityMap[i][j] << " ";  //prints out the City Map
			cout << "|"<< endl;
		
	}

	for (int a = 0; a <= CityMap.at(0).size()*2+1; a++) //for loop that creates the bottom line
	{
		cout << "-";
	}
	cout << endl;

	Infile.close(); //close the file

	SetCity(CityMap); // sets the map into the vector
}

//OTHER FUNCTIONS -------------------------------------------------------------------------------------

int CitySetup::GetTime() // retrieves the time
{
	return Time;
}

int CitySetup::GetRefresh() // retrieves the refresh rate
{
	return Refresh;
}

vector<vector<char>> CitySetup::GetCity() // retrieves the city grid
{
	return CityMap;
}

void CitySetup::SetTime(int ti) // sets the time
{
	Time = ti;
}

void CitySetup::SetRefresh(int re) //sets the refresh rate
{
	Refresh = re;
}

void CitySetup::SetCity(vector<vector<char>> city) // sets the city grid
{
	CityMap = city;
}