#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "solarsystem.h"
#include <cmath>

class Application
{
    //TODO const
    //TODO noexcept

public:
    Application();
    /**
     * @brief Display main menu
     *
     */
    void printMainMenu();
    /**
     * @brief getChoice
     * @return
     */
    int getChoice();
    /**
     * @brief processMainMenu
     * @param choice
     */
    void processMainMenu(int choice);
    /**
     * @brief run
     */
    void run();
    /**
     * @brief printPlanets
     */
    void printPlanets();
    /**
     * @brief printPlanetMenu
     */
    void printPlanetMenu();
    /**
     * @brief printInfoTable
     */
    void printInfoTable();
    /**
     * @brief printTableMenu
     */
    void printTableMenu();
    /**
     * @brief processTableMenu
     */
    void processTableMenu();
    /**
     * @brief processPlanetInfoMenu
     * @param planetId
     */
    void processPlanetInfoMenu(int planetId);
    /**
     * @brief getPlanet
     * @return
     */
    int getPlanet();
    /**
     * @brief getDeltaTime
     * @return
     */
    void Application::viewMenu();
    /**
     * @brief getDeltaTime
     * @return
     */
    int getDeltaTime();
private:
    SolarSystem* system;
    /**
     * @brief planetsTable
     */
    bool* planetsTable;
};

#endif // APPLICATION_H
