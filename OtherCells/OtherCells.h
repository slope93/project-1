#ifndef OTHERCELLSH
#define OTHERCELLSH

#include "../CityCell/CityCell.h"
#include <iostream>
using namespace std;

class OtherCell : public CityCell
{
public:
    OtherCell();
    OtherCell(int cellXPos, int cellYPos, char cellIdentifier);

    bool isRoad();
    bool isPowerPlant();
    bool isPowerLine();
    bool isEmpty();

private:
    bool PowerPlant;
    bool powerLine;
    bool Road;
    bool Empty;
};

#endif