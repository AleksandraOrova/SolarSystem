#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "solarsystem.h"
#include "juperos.h"
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
     * @brief Деструктор по умолчанию
     */
    ~Application();

    /**
     * @brief Запуск работы консольного приложения
     */
    void run();
    /**
     * @brief Считывание выбора пользователя
     * @return
     */
    int getChoice();

    void printPickMenu();
    void processPickPlanet();

    /**
     * @brief Печать главного меню
     *
     */
    void printSystemMainMenu();
    /**
     * @brief Обработка главного меню
     * @param choice
     */
    void processSystemMainMenu();

    void printJuperosMainMenu();
    void processJuperosMainMenu();

    /**
     * @brief Вывод списка планет
     */
    void printPlanets();

    void printSatellites();
    void printJuperosSatelliteInfoMenu();
    void processJuperosSatelliteInfoMenu(int satelliteId);

    void printJuperosTableMenu();
    void processJuperosTableMenu();
    void printJuperosInfoTable();

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
    Juperos* juperos;

    /**
     * @brief Массив флагов планет для вывода в сравнении
     */
    bool* planetsTable;
    bool* satellitesTable;
};

#endif // APPLICATION_H
