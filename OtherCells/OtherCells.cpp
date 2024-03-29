#include "OtherCells.h"

OtherCell::OtherCell()
{
    xPos = 0;
    yPos = 0;
    population = 0;
    identifier = ' ';
    PowerPlant = false;
    powerLine = false;
    Road = false;
    Empty = true;
}

OtherCell::OtherCell(int cellXPos, int cellYPos, char cellIdentifier)
{
    xPos = cellXPos;
    yPos = cellYPos;
    population = 0;

    if (cellIdentifier == 'P')
    {
        PowerPlant = true;
        powerLine = false;
        Road = false;
        Empty = false;
        population = 0;
        identifier = cellIdentifier;
        cellType = "Power Plant";
    }
    else if (cellIdentifier == 'T')
    {
        PowerPlant = false;
        powerLine = true;
        Road = false;
        Empty = false;
        population = 0;
        identifier = cellIdentifier;
        cellType = "Power Line";
    }
    else if (cellIdentifier == '#')
    {
        PowerPlant = false;
        powerLine = true;
        Road = true;
        Empty = false;
        population = 0;
        identifier = cellIdentifier;
        cellType = "Power Line Over Road";
    }
    else if (cellIdentifier == '-')
    {
        PowerPlant = false;
        powerLine = false;
        Road = true;
        Empty = false;
        population = 0;
        identifier = cellIdentifier;
        cellType = "Road";
    }
    else
    {
        PowerPlant = false;
        powerLine = false;
        Road = false;
        Empty = true;
        population = 0;
        identifier = ' ';
        cellType = "Empty";
    }
}

bool OtherCell::isRoad()
{
    return Road;
}
bool OtherCell::isPowerPlant()
{
    return PowerPlant;
}
bool OtherCell::isPowerLine()
{
    return powerLine;
}
bool OtherCell::isEmpty()
{
    return Empty;
}