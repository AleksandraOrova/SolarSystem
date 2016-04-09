#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H
#include "solarsystem.h"

class ConsoleApp
{
public:

    SolarSystem system;

    ConsoleApp();
    ~ConsoleApp();

    void tableOfPlanets();
    void run();

private:
    void loadSystem(char* fileName);
    void printMenu(); // show menu
    void operate(int operationNumber);
    bool isGood(int operationNumber);
    int getInput();
};

#endif // CONSOLEAPP_H
