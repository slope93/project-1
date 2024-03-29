#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H

#include "../CityCell/CityCell.h"
#include <vector>

class IndustrialZone : public CityCell
{
private:
    int availableWorkers;
    int availableGoods;

public:
    IndustrialZone();
    IndustrialZone(int, int, char);

    void setAvailableWorkers(int workers);
    int getAvailableWorkers() const;
    void addAvailableWorkers(int newWorkers);

    void setAvailableGoods(int goods);
    int getAvailableGoods() const;
    void addAvailableGoods(int newGoods);
};
#endif
