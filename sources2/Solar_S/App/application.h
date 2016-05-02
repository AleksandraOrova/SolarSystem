#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "solarsystem.h"
#include <math.h>
using namespace std;

class Application
{
private:
    SolarSystem* system;
    bool* planetsTable;
public:
    Application();
    /**
     * @brief Display main menu
     */
  void printMainMenu(); // метод печатающий основное меню
  int getChoice(); // обработка ввода с клавиатуры
  void processMainMenu(int choice); // обработка ввода, вывод команд в соответствии с меню
  void run(); // запуск бесконечной петли приложения
  void printPlanets();
  void printPlanetMenu();
  void printInfoTable();
  void printTableMenu();
  void processTableMenu();
  void processPlanetInfoMenu(int planetId);
  int getPlanet();
  int getDeltaTime();
};

#endif // APPLICATION_H
