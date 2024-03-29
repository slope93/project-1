#ifndef CITYCELLH
#define CITYCELLH

#include <string>
using namespace std;

class CityCell
{
public:
    CityCell();
    CityCell(int cellXPos, int cellYPos, char cellIdentifier);

    void setPos_x(int inputXPos);             // manually set cell x coordinate
    void setPos_y(int inputYPos);             // manually set cell y coordinate
    void setIdentifier(char inputIdentifier); // manually set cell identifier
    void addPopulation(int newPop);           // add value to population
    void addPollution(int newPol);            // add value to pollution

    int getPos_x();       // returns the cell x pos
    int getPos_y();       // returns the cell y pos
    char getIdentifier(); // returns cell char identifier
    int getPopulation();  // returns current cell population
    int getPollution();   // returns current cell pollution
    string getCellType(); // returns the cell type

    bool isRoad();
    bool isPowerPlant();
    bool isPowerLine();
    bool isEmpty();

protected:
    int xPos;
    int yPos;
    int population;
    int pollution;
    char identifier;
    string cellType;
};

#endif
