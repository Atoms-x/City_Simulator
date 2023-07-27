#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <string>
#include <iostream>
#include <vector>
#include "CityNode.h"

using namespace std;

class Commercial
{
  public:
    int main(vector<vector<CityNode>>&, int&, int&, int&, int, int);
    bool checkForPowerline(vector<vector<CityNode>>, int, int, int, int);
    int checkAdjacentPopulation(vector<vector<CityNode>>, int, int, int, int);
    int determinePriority(vector<vector<CityNode>>, int, int, int, int);
};
#endif