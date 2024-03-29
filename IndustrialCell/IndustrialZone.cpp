#include "IndustrialZone.h"

IndustrialZone::IndustrialZone()
{
    xPos = 0;
    yPos = 0;
    population = 0;
    pollution = 0;
    identifier = ' ';
    availableGoods = 0;
    availableWorkers = 0;
}

IndustrialZone::IndustrialZone(int cellXPos, int cellYPos, char cellIdentifier)
{
    xPos = cellXPos;
    yPos = cellYPos;
    population = 0;
    pollution = 0;
    identifier = cellIdentifier;
    availableGoods = 0;
    availableWorkers = 0;
    cellType = "Industrial";
}

// Setters and getters

void IndustrialZone::setAvailableWorkers(int workers)
{
    availableWorkers = workers;
}

int IndustrialZone::getAvailableWorkers() const
{
    return availableWorkers;
}

void IndustrialZone::addAvailableWorkers(int newWorkers)
{
    availableWorkers += newWorkers;
}

void IndustrialZone::setAvailableGoods(int goods)
{
    availableGoods = goods;
}

int IndustrialZone::getAvailableGoods() const
{
    return availableGoods;
}

void IndustrialZone::addAvailableGoods(int newGoods)
{
    availableGoods += newGoods;
}
// Need to setup calculateAdjacentPopulation
