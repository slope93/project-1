#include "residentialZone.h"

residentialZone::residentialZone()
{
    xPos = 0;
    yPos = 0;
    population = 0;
    identifier = ' ';
    availableWorkers = 0;
}

residentialZone::residentialZone(int cellXPos, int cellYPos, char cellIdentifier)
{
    xPos = cellXPos;
    yPos = cellYPos;
    population = 0;
    identifier = cellIdentifier;
    availableWorkers = 0;
    cellType = "Residential";
}

// Setters and getters

void residentialZone::setAvailableWorkers(int workers)
{
    availableWorkers = workers;
}

int residentialZone::getAvailableWorkers() const
{
    return availableWorkers;
}

void residentialZone::addAvailableWorkers(int newWorkers)
{
    availableWorkers += newWorkers;
}
