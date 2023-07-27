#ifndef CITYNODE_H
#define CITYNODE_H

#include <iostream>

using namespace std;

class CityNode
{
  private:
    int priority;
    char type;
    int currentPopulation;
    int currentPollution;
    int futurePopulation;
    int futurePollution;
  public:
    CityNode()
    {
      priority = 0;
      type = 'X';
      currentPopulation = 0;
      currentPollution = 0;
      futurePopulation = 0;
      futurePollution = 0;
    }
    
    CityNode(char t)
    {
      priority = 0;
      type = t;
      currentPopulation = 0;
      currentPollution = 0;
      futurePopulation = 0;
      futurePollution = 0;
    }
    
    void setPriority(int p)
      { priority = p; }
    int getPriority() const
      { return priority; }
    
    void setType(char t)
      { type = t; }
    char getType() const
      { return type; }

    void setCurrentPopulation(int p)
      { currentPopulation = p; }
    int getCurrentPopulation() const
      { return currentPopulation; }
    void setFuturePopulation(int pf)
      { futurePopulation += pf; }
    int getFuturePopulation() const
      { return futurePopulation; }

    void setCurrentPollution(int po)
      { currentPollution = po; }
    int getCurrentPollution() const
      { return currentPollution; }
    void setFuturePollution(int pof)
      { futurePollution += pof; }
    int getFuturePollution() const
      { return futurePollution; }

    //Overloading < operator in order to properly insert into a set for growing by
    //the ruleset and taking into account nodes that share multiple priorities
    bool operator< (const CityNode &right) const
      { return priority < right.priority;}
};
#endif