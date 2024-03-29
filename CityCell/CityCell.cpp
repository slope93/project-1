#include <iostream>
#include "CityCell.h"

CityCell::CityCell()
{
    xPos = 0;
    yPos = 0;
    population = 0;
    pollution = 0;
    identifier = ' ';
}

CityCell::CityCell(int cellXPos, int cellYPos, char cellIdentifier)
{
    xPos = cellXPos;
    yPos = cellYPos;
    population = 0;
    pollution = 0;
    identifier = cellIdentifier;
}

void CityCell::setPos_x(int inputXPos)
{
    xPos = inputXPos;
}

void CityCell::setPos_y(int inputYPos)
{
    yPos = inputYPos;
}

void CityCell::setIdentifier(char inputIdentifier)
{
    identifier = inputIdentifier;
}

void CityCell::addPopulation(int newPop)
{
    population += newPop;
}

void CityCell::addPollution(int newPol)
{
    pollution += newPol;
}

int CityCell::getPos_x()
{
    return xPos;
}

int CityCell::getPos_y()
{
    return yPos;
}

int CityCell::getPopulation()
{
    return population;
}

int CityCell::getPollution()
{
    return pollution;
}

char CityCell::getIdentifier()
{
    if (population > 0)
    {
        return '0' + population;
    }
    else
    {
        return identifier;
    }
}

string CityCell::getCellType()
{
    return cellType;
}