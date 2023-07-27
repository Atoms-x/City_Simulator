#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <string>
#include <iostream>
#include <vector>
#include "CityNode.h"

using namespace std;

class Residential
{
  public:
    int main(vector<vector<CityNode>> &, int &, int, int);
    bool checkForPowerline(vector<vector<CityNode>>, int, int, int, int);
    int checkAdjacentPopulation(vector<vector<CityNode>>, int, int, int, int);
};
#endif