#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "solarsystem.h"
#include <cmath>

/**
 * @brief Класс для работы консольного приложения
 */

class Application
{

public:

    /**
     * @brief Конструктор по умолчанию
     */
    Application();

    /**
     * @brief Печать главного меню
     *
     */
    void printMainMenu();

    /**
     * @brief Считывание выбора пользователя
     * @return
     */
    int getChoice();

    /**
     * @brief Обработка главного меню
     * @param choice
     */
    void processMainMenu(int choice);

    /**
     * @brief Запуск работы консольного приложения
     */
    void run();

    /**
     * @brief Вывод списка планет
     */
    void printPlanets();

    /**
     * @brief Печать меню работы с планетой
     */
    void printPlanetMenu();

    /**
     * @brief Печать информации о планетах
     */
    void printInfoTable();

    /**
     * @brief Печать таблицы сравнения планет
     */
    void printTableMenu();

    /**
     * @brief Запуск меню для работы с таблицей сравнения планет
     */
    void processTableMenu();

    /**
     * @brief Запуск работы меню с информацией о планете
     * @param planetId
     */
    void processPlanetInfoMenu(int planetId);

    /**
     * @brief Считать дельту по времени с клавиатуры
     * @return
     */
    int getDeltaTime();
private:

    /**
     * @brief Солнечная система
     */
    SolarSystem* system;

    /**
     * @brief Массив флагов планет для вывода в сравнении
     */
    bool* planetsTable;
};

#endif // APPLICATION_H
