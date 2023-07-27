#ifndef POLLUTION_H
#define POLLUTION_H

#include <string>
#include <iostream>
#include <vector>
#include "CityNode.h"

using namespace std;

class Pollution
{
  public:
    void main(vector<vector<CityNode>>&, int, int);
    void checkAdjacentPollution(vector<vector<CityNode>>&, int, int, int, int);
};
#endif