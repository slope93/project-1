# Project 1

Members:
Anthony Carter
Chinyere Okonkwo
Chloe Nguyen
Kyle Leonard
Matthew Lopez

Instructions:
When in the linux machine type the command: make
This will run the make file and create and compile project1.exe there will be no additional flags needed.
An example region file "region1.csv" and config file "config1.txt" are included for examples of file formats.

To run the program after the make has completed, type the command: ./project1.exe
This will execute the program.

You will then be prompted to provide a file name for the config.
Type the name of the file with exact case and extention.
Example: config1.txt
This will read the file and grab the information inside.

# City Cells
This serves as the parent object for the various cell types. It contains variables to hold the x and y coordinates of each cell, the cell's identifier which is a character either a letter/symbol, a blank space, or an integer that represents the cell's population. This allows for additional cell types to be created should there be a need for additional types. By default the simcity uses Residential (R), Commercial (C), and Industrial (I) cells. The remainder of the characters are classified as Other cells for and have no additional functionality.

## Residential [Anthony]

#### Purpose

The residential zone simulates the growth of our residential areas, as well as its interaction with powerline cells. For practicality within our project, the primary function of this zone is to provide workers to the commercial and residential zones, and expanding its own population.

##### Data Storage

We utilized a vector to represent the city grid read in from the config file, with each cell being represented by the characters R,C,I, T, P, #, and -. Each of which corrresponds to Residential, Commericial, Industrial, Powerlines, Powerplants, Powerline over roads, and roads, respecitively. Similarly, like the other zones, we used a vector to store the population/available workers of each residential cell. The use of this data structure made it simple to change/increment elements, as well as added elements to the data structure.

#### Functionality

The functionality of this zone is to increase its population and allocate workers, while adhering to the constraints laid out in the Project 1 document. This includes checking for adjacencies with powerlines when a cell's population is currently 0, and increasing its own population when surrounded by cells with equal or greater population. Also, like the other zones, it serves to generate the output of its population and available workers. These tasks would be accomplished by utilizing functions that update available population/workers, and retrieve population/workers.


## Industrial [Chinyere]
A class called IndustrialZone is created. The class contains private and public specifiers. The private specifiers for the class initializes variables titled availableWorkers and availableGoods.The public specifier contains setter and getter functions for setting and getting workers and goods, respectively. setAvaialableWorkers() is void and reads an integer variable named workers. getAvailableWorkers() is a constant integer function type. addAvailableWorkers() is void, and reads in an integer variable titled newWorkers. This function adds new workers to the cell. The setter and getter functions for setAvailableGoods(), getAvailableGoods(), and addAvailableGoods() have the same functionality as the worker functions described above, but instead for the goods of the city.

## Commercial [Chloe]
A class called commercialZone is created. Within the class is a public and private access specifiers. The public access specifier creates the commericalZone() function and defines the varible types that will be used within the function. These variables include int cellXPos, int cellYPos, and char cellIdentifier. The setters and getters are also included in this section to get and set avaible workers and goods. The private access specifier initializes the int varibles availaeWorkers and availableGoods.

The commercialZone.h file must be included. The commercialZone constructor is used and initializing all the variables that will be used. This holds all the default values of the initialized variables. The second commercialZone constructor assigns the variables accordingly for our purpose. The void commercialZone::setAvailableWorkers(int workers) function and int commercialZone::getAvailableWorkers() const function get and set the availableWorkers variables. The void commercialZone::addAvailableWorkers(int newWorkers) function then adds 1 to the count when necessary.
The void commercialZone::setAvailableGoods(int goods) function and int commercialZone::getAvailableGoods() const function get and set the availableGoods variables. The void commercialZone::addAvailableGoods(int newGoods) function then adds 1 to the count when necessary.



# project-1
