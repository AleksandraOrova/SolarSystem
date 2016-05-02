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
  void planetTableMenu(); // пока пустой метод
  void printMainMenu(); // метод печатающий основное меню
  int getChoice(); // обработка ввода с клавиатуры
  void processChoice(int choice); // обработка ввода, вывод команд в соответствии с меню
  void run(); // запуск бесконечной петли приложения
  void printPlanets();
  void parameterType();
  void printInfoTable();
  void printTableMenu();
  int getPlanet();
  int getDeltaTime();
};

#endif // APPLICATION_H
