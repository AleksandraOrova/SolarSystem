#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "solarsystem.h"
//TODO math.h -> cmath
#include <math.h>
//TODO remove using namespace
using namespace std;
//TODO Документировать doxygen ом 
class Application
{
    //TODO поменять местами private и public
    //TODO const
    //TODO noexcept
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
  //Бесконечной петли?
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
