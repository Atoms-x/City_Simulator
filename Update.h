#ifndef UPDATE_H
#define UPDATE_H

#include <string>
#include <iostream>
#include <vector>
#include "CityNode.h"


using namespace std;

class Update
{
  public:
    void updateMap(vector<vector<CityNode>> &, int &,int &, int&, int&, int, int);
    void displayMap(vector<vector<CityNode>>, int, int, int, int) const;
};
#endif