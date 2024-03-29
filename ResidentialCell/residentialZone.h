#ifndef RESIDENTIALZONE_H
#define RESIDENTIALZONE_H

#include "../CityCell/CityCell.h"
#include <vector>

class residentialZone : public CityCell
{
private:
    int availableWorkers;

public:
    // constructors
    residentialZone();
    residentialZone(int, int, char);

    void setAvailableWorkers(int workers);
    int getAvailableWorkers() const;
    void addAvailableWorkers(int newWorkers);
};
#endif
