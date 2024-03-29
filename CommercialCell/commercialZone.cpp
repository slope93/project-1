#include "commercialZone.h"

commercialZone::commercialZone()
{
    xPos = 0;
    yPos = 0;
    population = 0;
    pollution = 0;
    identifier = ' ';
    availableGoods = 0;
    availableWorkers = 0;
}

commercialZone::commercialZone(int cellXPos, int cellYPos, char cellIdentifier)
{
    xPos = cellXPos;
    yPos = cellYPos;
    population = 0;
    pollution = 0;
    identifier = cellIdentifier;
    availableGoods = 0;
    availableWorkers = 0;
    cellType = "Commercial";
}

// Setters and getters

void commercialZone::setAvailableWorkers(int workers)
{
    availableWorkers = workers;
}

int commercialZone::getAvailableWorkers() const
{
    return availableWorkers;
}

void commercialZone::addAvailableWorkers(int newWorkers)
{
    availableWorkers += newWorkers;
}

void commercialZone::setAvailableGoods(int goods)
{
    availableGoods = goods;
}

int commercialZone::getAvailableGoods() const
{
    return availableGoods;
}

void commercialZone::addAvailableGoods(int newGoods)
{
    availableGoods += newGoods;
}
// Need to setup calculateAdjacentPopulation
