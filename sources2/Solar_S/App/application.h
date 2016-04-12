#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "solarsystem.h"
using namespace std;

class Application
{
private:
    SolarSystem* system;
public:
    Application();
    /**
     * @brief Display main menu
     */
  void planetMenu(); // пока пустой метод
  void printMainMenu(); // метод печатающий основное меню
  int getChoice(); // обработка ввода с клавиатуры
  void processChoice(int choice); // обработка ввода, вывод команд в соответствии с меню
  void run(); // запуск бесконечной петли приложения
};

#endif // APPLICATION_H
