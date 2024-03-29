#ifndef COMMERCIALZONEH
#define COMMERCIALZONEH

#include "../CityCell/CityCell.h"
#include <iostream>
using namespace std;

class commercialZone : public CityCell
{
public:
    commercialZone();
    commercialZone(int cellXPos, int cellYPos, char cellIdentifier);

    void setAvailableWorkers(int workers);
    int getAvailableWorkers() const;
    void addAvailableWorkers(int newWorkers);

    void setAvailableGoods(int goods);
    int getAvailableGoods() const;
    void addAvailableGoods(int newGoods);

private:
    int availableWorkers;
    int availableGoods;
};

#endif
