#include "./ResidentialCell/residentialZone.h"
#include "./ResidentialCell/residentialZone.cpp"
#include "./IndustrialCell/IndustrialZone.h"
#include "./IndustrialCell/IndustrialZone.cpp"
#include "./CommercialCell/commercialZone.h"
#include "./CommercialCell/commercialZone.cpp"
#include "./OtherCells/OtherCells.h"
#include "./OtherCells/OtherCells.cpp"
#include "./CityCell/CityCell.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// This fn still needs to have regionChar & RegionObj likely passed as arguments to avoid errors since they are only
// declared in main() and not globally.
// Also still needs logic such as addPopulation(), addavailableWorkers(), and addavailableGoods() with arguments etc when necessary
// Since I can't compile rn I am not sure if the for loops are completely correct once logic is added,
// but there are no other syntax errors in vscode.
// Leaving it commented out for now until it is finished

int availableWorkers;
int availableGoods;

void checkAdjacent(vector<CityCell> &currRegionObj, int currX, int currY, unsigned int index);

int main()
{
    vector<vector<char>> regionChar(8, vector<char>(8, 0));
    vector<CityCell> regionObj;
    ifstream fin;
    string line;
    string modLine;
    char cell;
    int rowCount = 0;
    string fileName;
    ifstream ConfigFile;
    string regionLayoutFilename;
    int timeLimit;
    int refreshRate;

    /*
    fin.open("region1.csv"); //Hard coded region1.csv read
    if (fin.fail())
    {
        cout << "unable to open input file" << endl;
        exit(EXIT_FAILURE);
    }

    while (!fin.eof())
    {
        getline(fin, line);

        for (int j = 0; j < line.length(); j++)
        {
            cell = line.at(j);
            if (cell != ',')
            {
                regionChar[rowCount].push_back(cell);
            }
        }
        rowCount++;
    }
    fin.close();
    */

    cout << "Please input the config file name." << endl;
    cin >> fileName;
    ConfigFile.open(fileName);

    if (ConfigFile.fail())
    {
        cout << "unable to open config file" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Config Loaded Successfully" << endl;
    }

    // These loops hopefully converts the config file lines to strings
    // and then separates everything after the ":" by using it as a key, and stores the info after as a value
    // Not sure if it will work

    while (!ConfigFile.eof())
    {
        getline(ConfigFile, line);
        istringstream iss(line);
        string key, value;
        if (getline(iss, key, ':') && getline(iss, value))
        {
            if (key == "Region Layout")
            {
                regionLayoutFilename = value;
            }
            else if (key == "Time Limit")
            {
                timeLimit = stoi(value);
            }
            else if (key == "Refresh Rate")
            {
                refreshRate = stoi(value);
            }
            else
            {
                regionLayoutFilename = "region1.csv";
                timeLimit = 20;
                refreshRate = 1;
            }
        }
    }

    ConfigFile.close();

    cout << "Region Layout Filename: " << regionLayoutFilename << endl;
    cout << "Time Limit: " << timeLimit << endl;
    cout << "Refresh Rate: " << refreshRate << endl;

    fin.open(regionLayoutFilename); // Hard coded region1.csv read
    if (fin.fail())
    {
        cout << "unable to open input file" << endl;
        exit(EXIT_FAILURE);
    }

    while (!fin.eof())
    {
        getline(fin, line);

        for (unsigned int j = 0; j < line.length(); j++)
        {
            cell = line.at(j);
            if (cell != ',')
            {
                regionChar[rowCount].push_back(cell);
            }
        }
        rowCount++;
    }
    fin.close();

    for (unsigned int i = 0; i < regionChar.size(); i++) // print region file character array
    {
        for (unsigned int j = 0; j < regionChar[i].size(); j++)
        {
            cout << regionChar[i][j] << " ";
        }
        cout << endl;
    }

    for (unsigned int i = 0; i < regionChar.size(); i++) // print region file character array
    {
        for (unsigned int j = 0; j < regionChar[i].size(); j++)
        {
            if (regionChar[i][j] == 'R')
            {
                residentialZone cityObj = residentialZone(j, i, regionChar[i][j]);
                regionObj.push_back(cityObj);
            }
            else if (regionChar[i][j] == 'I')
            {
                IndustrialZone cityObj = IndustrialZone(j, i, regionChar[i][j]);
                regionObj.push_back(cityObj);
            }
            else if (regionChar[i][j] == 'C')
            {
                commercialZone cityObj = commercialZone(j, i, regionChar[i][j]);
                regionObj.push_back(cityObj);
            }
            else if (regionChar[i][j] == 'P' || regionChar[i][j] == 'T' || regionChar[i][j] == '#' || regionChar[i][j] == '-' || regionChar[i][j] == ' ')
            {
                OtherCell cityObj = OtherCell(j, i, regionChar[i][j]);
                regionObj.push_back(cityObj);
            }
        }
    }

    /*for (unsigned int i = 0; i < regionObj.size(); i++) // print region objects vector and internal values for debugging
    {
        cout << regionObj.at(i).getIdentifier() << ", ";
        cout << "X position: " << regionObj.at(i).getPos_x() << ", ";
        cout << "Y position: " << regionObj.at(i).getPos_y() << ", ";
        cout << "Population: " << regionObj.at(i).getPopulation() << ", ";
        cout << "Pollution: " << regionObj.at(i).getPollution() << ", ";
        cout << "Cell Type: " << regionObj.at(i).getCellType();
        cout << endl;
    }*/

    for (int timeStep = 0; timeStep < timeLimit; timeStep++)
    {
        for (unsigned int k = 0; k < regionObj.size(); k++)
        {
            vector<CityCell> adjCells;
            int currX = regionObj.at(k).getPos_x();
            int currY = regionObj.at(k).getPos_y();

            //cout << "Looking at cell: (" << currX << ", " << currY << ")" << endl;

            if (currX != 8) // If not left most col
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k - 1));
            }

            if (currX != 15) // If not right most col
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k + 1));
            }

            if (currY != 0) // If not top row
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k - 8));
            }

            if (currY != 7) // If not bottom row
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k + 8));
            }

            if (currX != 8 && currY != 0) // If not top left corner
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k - 9));
            }

            if (currX != 8 && currY != 7) // If not top right corner
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k + 7));
            }

            if (currX != 15 && currY != 0) // If not bottom left corner
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k - 7));
            }

            if (currX != 15 && currY != 7) // If not bottom right corner
            {
                //cout << "Cell Found" << endl;
                adjCells.push_back(regionObj.at(k + 9));
            }

            //cout << "For Cell (" << currX << ", " << currY << ") found " << adjCells.size() << " Cells: ";
            for (unsigned int adjCount = 0; adjCount < adjCells.size(); adjCount++)
            {
                //cout << adjCells.at(adjCount).getCellType() << ", ";
            }
            //cout << "Moving to tests" << endl << endl;

            for (unsigned int i = 0; i < adjCells.size(); i++)
            {

                if (regionObj.at(k).getCellType() == "Residential")
                {
                    // Logic for residential cell
                    for (unsigned int j = 0; j < adjCells.size(); j++)
                    {
                        if (adjCells.at(j).getIdentifier() == 'T' || adjCells.at(j).getIdentifier() == '#') // Look for Power Line
                        {
                            if (regionObj.at(k).getPopulation() == 0)
                            {
                                //cout << "Adding population to index " << k << endl;
                                regionObj.at(k).addPopulation(1);
                                //cout << "New Population = " << regionObj.at(k).getPopulation() << endl;
                            }
                        }
                        else if (adjCells.at(j).getCellType() == "Residential" && regionObj.at(k).getPopulation() == 0) // Look for other residential cell
                        {
                            //cout << "Adding population to index " << k << endl;
                            regionObj.at(k).addPopulation(1);
                            //cout << "New Population = " << regionObj.at(k).getPopulation() << endl;
                        }
                        else if (adjCells.at(j).getCellType() == "Residential" && regionObj.at(k).getPopulation() >= 1 && regionObj.at(k).getPopulation() <= 4) // look for other cells if requirements met
                        {
                            if (regionObj.at(k).getPopulation() == 1) // increase population if 2 or more cells have pop > 1
                            {
                                int counter = 0;
                                for (unsigned int l = 0; l < adjCells.size(); l++)
                                {
                                    if (adjCells.at(j).getPopulation() == 1)
                                    {
                                        counter++;
                                    }
                                }
                                if (counter >= 2)
                                {
                                    //cout << "Adding population to index " << k << endl;
                                    regionObj.at(k).addPopulation(1);
                                    //cout << "New Population = " << regionObj.at(k).getPopulation() << endl;
                                }
                            }
                            else if (regionObj.at(k).getPopulation() == 2) // increase population if 2 or more cells have pop > 2
                            {
                                int counter = 0;
                                for (unsigned int l = 0; l < adjCells.size(); l++)
                                {
                                    if (adjCells.at(j).getPopulation() == 2)
                                    {
                                        counter++;
                                    }
                                }
                                if (counter >= 2)
                                {
                                    //cout << "Adding population to index " << k << endl;
                                    regionObj.at(k).addPopulation(1);
                                    //cout << "New Population = " << regionObj.at(k).getPopulation() << endl;
                                }
                            }
                            else if (regionObj.at(k).getPopulation() == 3) // increase population if 2 or more cells have pop > 3
                            {
                                int counter = 0;
                                for (unsigned int l = 0; l < adjCells.size(); l++)
                                {
                                    if (adjCells.at(j).getPopulation() == 3)
                                    {
                                        counter++;
                                    }
                                }
                                if (counter >= 2)
                                {
                                    //cout << "Adding population to index " << k << endl;
                                    regionObj.at(k).addPopulation(1);
                                    //cout << "New Population = " << regionObj.at(k).getPopulation() << endl;
                                }
                            }
                            else if (regionObj.at(k).getPopulation() == 4) // increase population if 2 or more cells have pop > 4
                            {
                                int counter = 0;
                                for (unsigned int l = 0; l < adjCells.size(); l++)
                                {
                                    if (adjCells.at(j).getPopulation() == 4)
                                    {
                                        counter++;
                                    }
                                }
                                if (counter >= 2)
                                {
                                    //cout << "Adding population to index " << k << endl;
                                    regionObj.at(k).addPopulation(1);
                                    //cout << "New Population = " << regionObj.at(k).getPopulation() << endl;
                                }
                            }
                        }
                    }
                }

                if (regionObj.at(k).getCellType() == "Industrial")
                {
                    // Logic for industrial cell
                }

                if (regionObj.at(k).getCellType() == "Commercial")
                {
                    // Logic for commercial cell
                }
            }
        }

        int index = 0;
        for (unsigned int i = 8; i < regionChar.size(); i++)
        {
            for (unsigned int j = 0; j < regionChar[i].size(); j++)
            {
                char newChar = regionObj.at(index).getIdentifier();
                regionChar[i][j] = newChar;
                index++;
            }
            cout << endl;
        }
        cout << "Current Timestep: " << timeStep + 1 << endl;
        for (unsigned int i = 0; i < regionChar.size(); i++) // print region file character array
        {
            for (unsigned int j = 0; j < regionChar[i].size(); j++)
            {
                cout << regionChar[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}