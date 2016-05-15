#include "application.h"

Application::Application(){
    system = new SolarSystem(8);
    system->addPlanet(Planet("Меркурий", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 0);
    system->addPlanet(Planet("Венера",   4.8685 * pow(10,24),  108208930000,         0.0068,  0.4f,  0), 1);
    system->addPlanet(Planet("Земля",    5.973  * pow(10,24),  149598261000,     0.01671123,  0.5f,  0), 2);
    system->addPlanet(Planet("Марс",     6.4185 * pow(10,23),  227943820000,      0.0933941,  0.45f, 0), 3);
    system->addPlanet(Planet("Юпитер",   1.8986 * pow(10,27),  778547200000,       0.048775,  0.8f,  0), 4);
    system->addPlanet(Planet("Сатурн",   5.6846 * pow(10,26), 1433449370000,    0.055723219,  0.7f,  0), 5);
    system->addPlanet(Planet("Уран",     8.6832 * pow(10,25), 2876679082000,    0.044405586,  0.6f,  0), 6);
    system->addPlanet(Planet("Нептун",   1.0243 * pow(10,26), 4503443661000,    0.011214269,  0.6f,  0), 7);

    planetsTable = new bool[8];
    for(int i = 0; i < 8; i++)
        planetsTable[i] = false;

    juperos = new Juperos(16);

    //                          название      масса                 больший радиус эксцентриситет радиус начальное положение
    juperos->addPlanet(Planet("1 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 0);
    juperos->addPlanet(Planet("2 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 1);
    juperos->addPlanet(Planet("3 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 2);
    juperos->addPlanet(Planet("4 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 3);
    juperos->addPlanet(Planet("5 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 4);
    juperos->addPlanet(Planet("6 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 5);
    juperos->addPlanet(Planet("7 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 6);
    juperos->addPlanet(Planet("8 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 7);
    juperos->addPlanet(Planet("9 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 8);
    juperos->addPlanet(Planet("10 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 9);
    juperos->addPlanet(Planet("11 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 10);
    juperos->addPlanet(Planet("12 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 11);
    juperos->addPlanet(Planet("13 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 12);
    juperos->addPlanet(Planet("14 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 13);
    juperos->addPlanet(Planet("15 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 14);
    juperos->addPlanet(Planet("16 спутник", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 15);

    satellitesTable = new bool[8];
    for(int i = 0; i < 8; i++)
        satellitesTable[i] = false;

}
Application::~Application(){
    system->~SolarSystem();
}

void Application::run()
{
    processPickPlanet();
    std::cout << "Конец" << std::endl;
}

// todo кажется, если я введу не число, а строку, будет плохо... Пусть этот метод занимается обработкой ввода
int Application::getChoice(){
    int userInput;
    while((std::cin >> userInput) && (!std::cin.good())){
        std::cin.clear();
    }
    return userInput;
}

void Application::printPickMenu(){
    std::cout << std::endl
         << "Выберите вид" << std::endl
         << "1. Система" << std::endl
         << "2. Юпитер" << std::endl
         << "0. Выход" << std::endl
         << ">>> ";
}
void Application::processPickPlanet(){
    printPickMenu();
    int menuChoice;
    while((menuChoice = getChoice()) != 0)
    {
        switch (menuChoice)
        {
        case 0:
            break;
        case 1:
            processSystemMainMenu();
            break;
        case 2:
            processJuperosMainMenu();
            break;
        default:
            std::cout << "Ошибка ввода" << std::endl;
            break;
        }
        printPickMenu();
    }
}

void Application::printSystemMainMenu()
{
    std::cout << std::endl
         << "Симулятор звездной системы" << std::endl
         << "1. Вывести информацию о планете" << std::endl
         << "2. Открыть таблицу для сравнения" << std::endl
         << "3. Открыть таблицу со всеми данными" << std::endl
         << "0. Выход" << std::endl
         << ">>> ";
}
void Application::processSystemMainMenu()
{
    printSystemMainMenu();
    int menuChoice;
    while((menuChoice = getChoice()) != 0)
    {
        switch (menuChoice)
        {
        case 0:
            break;
        case 1:
            printPlanets();
            menuChoice = getChoice();
            if (system->idValid(menuChoice)){
                processPlanetInfoMenu(menuChoice);
            }
            else
                std::cout << "Некорректный номер планеты";
            break;
            // todo если здесь мы считали некорректный номер, например 10,
            // то приложение начинает вести себя немного неадекватно.
        case 2:
            processTableMenu();
            break;
        case 3:
            std::cout << *system << std::endl;
            break;
        default:
            std::cout << "Ошибка ввода" << std::endl;
            break;
        }
        printSystemMainMenu();
    }
}

void Application::printJuperosMainMenu()
{
    std::cout << std::endl
         << "Симулятор Юпитера и спутников" << std::endl
         << "1. Вывести информацию о спутнике" << std::endl
         << "2. Открыть таблицу для сравнения" << std::endl
         << "3. Открыть таблицу со всеми данными" << std::endl
         << "0. Выход" << std::endl
         << ">>> ";
}
void Application::processJuperosMainMenu()
{
    printJuperosMainMenu();
    int menuChoice;
    while((menuChoice = getChoice()) != 0)
    {
        switch (menuChoice)
        {
        case 0:
            break;
        case 1:
            printSatellites();
            menuChoice = getChoice();
            if (juperos->idValid(menuChoice)){
                processJuperosSatelliteInfoMenu(menuChoice);
            }
            else
                std::cout << "Некорректный номер планеты";
            break;
        case 2:
            processJuperosTableMenu();
            break;
        case 3:
            std::cout << *juperos << std::endl;
            break;
        default:
            std::cout << "Ошибка ввода" << std::endl;
            break;
        }
        printJuperosMainMenu();
    }
}


void Application::printJuperosSatelliteInfoMenu(){
    std::cout << std::endl
         << "Выберите действие" << std::endl
         << "1. Вывести статические параметры" << std::endl
         << "2. Вывести динамические параметры" << std::endl
         << "3. Вывести все параметры" << std::endl
         << "4. Сдвинуть планету на дельту" << std::endl
         << "5. Сбросить время" << std::endl
         << "0. Выход" << std::endl
         << ">>> ";
}

void Application::processJuperosSatelliteInfoMenu(int satelliteId){
    printJuperosSatelliteInfoMenu();
    int paremeterChoice;
    while((paremeterChoice = getChoice())!=0){
        switch(paremeterChoice){
        case 1:
            std::cout << std::endl;
            (juperos->getPlanet(satelliteId)).printStaticParameters(std::cout);
            break;
        case 2:
            std::cout << std::endl;
            (juperos->getPlanet(satelliteId)).printDynamicParameters(std::cout);
            break;
        case 3:
            std::cout << std::endl;
            std::cout << juperos->getPlanet(satelliteId);
            break;
        case 4:
            std::cout << std::endl;
            paremeterChoice = getDeltaTime();
            (juperos->getPlanet(satelliteId)).printDelta(std::cout, paremeterChoice);
            break;
        case 5:
            std::cout << std::endl;
            (juperos->getPlanet(satelliteId)).setLifeTime(0);
            break;
        default:
            break;
        }
        printJuperosSatelliteInfoMenu();
    }
}

void Application::printJuperosTableMenu(){
    std::cout << std::endl
         << "Выберите операцию с таблицей" << std::endl
         << "1. Добавить планету для сравнения" << std::endl
         << "2. Убрать планету из таблицы" << std::endl
         << "3. Ввести дельту по времени" << std::endl
         << "4. Вывести таблицу" << std::endl
         << "0. Exit" << std::endl
         << ">>> ";
}

void Application::processJuperosTableMenu(){
    printJuperosTableMenu();
    int tableChoice;
    for(int i = 0 ; i < 8; i++)
        satellitesTable[i] = false;
    while((tableChoice = getChoice())!=0){
        switch(tableChoice){
        case 1:
            printSatellites();
            tableChoice = getChoice();
            if(juperos->idValid(tableChoice))
                satellitesTable[tableChoice-1] = true;
            break;
        case 2:
            printSatellites();
            tableChoice = getChoice();
            if(juperos->idValid(tableChoice))
                satellitesTable[tableChoice-1] = false;
            break;
        case 3:
            tableChoice = getDeltaTime();
            for(int i = 0 ; i < 8; i++)
                if (satellitesTable[i])
                    (juperos->getPlanet(i + 1)).step(tableChoice);
            std::cout << "\n\tДЕЛЬТА " << tableChoice << " секунд" << std::endl;
            printJuperosInfoTable();
            break;
        case 4:
            printJuperosInfoTable();
            break;
        default:
            break;
        }
        printJuperosTableMenu();
    }
}
void Application::printJuperosInfoTable(){
    std::cout << "Спутник         Масса           Расстояние      Период          Текущий угол" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < 8; i++)
        if (satellitesTable[i]){
            (juperos->getPlanet(i + 1)).printShortInfo(std::cout);
        }
    std::cout << "----------------------------------------------------------------------------";
    std::cout << std::endl;

}

void Application::printPlanets()
{
    std::cout << std::endl
         << "Выберите планету" << std::endl
         << "1. Меркурий" << std::endl
         << "2. Венера" << std::endl
         << "3. Земля" << std::endl
         << "4. Марс" << std::endl
         << "5. Юпитер" << std::endl
         << "6. Сатурн" << std::endl
         << "7. Уран" << std::endl
         << "8. Нептун" << std::endl
         << ">>> ";
}

void Application::printSatellites(){
    std::cout << std::endl
         << "Выберите спутник" << std::endl
         << "1. " << std::endl
         << "2. " << std::endl
         << "3. " << std::endl
         << "4. " << std::endl
         << "5. " << std::endl
         << "6. " << std::endl
         << "7. " << std::endl
         << "8. " << std::endl
         << ">>> ";

}

void Application::printPlanetMenu(){
    std::cout << std::endl
         << "Выберите действие" << std::endl
         << "1. Вывести статические параметры" << std::endl
         << "2. Вывести динамические параметры" << std::endl
         << "3. Вывести все параметры" << std::endl
         << "4. Сдвинуть планету на дельту" << std::endl
         << "5. Сбросить время" << std::endl
         << "0. Выход" << std::endl
         << ">>> ";
}

void Application::processPlanetInfoMenu(int planetId){
    printPlanetMenu();
    int paremeterChoice;
    while((paremeterChoice = getChoice())!=0){
        switch(paremeterChoice){
        case 1:
            std::cout << std::endl;
            (system->getPlanet(planetId)).printStaticParameters(std::cout);
            break;
        case 2:
            std::cout << std::endl;
            (system->getPlanet(planetId)).printDynamicParameters(std::cout);
            break;
        case 3:
            std::cout << std::endl;
            std::cout << system->getPlanet(planetId);
            break;
        case 4:
            std::cout << std::endl;
            paremeterChoice = getDeltaTime();
            (system->getPlanet(planetId)).printDelta(std::cout, paremeterChoice);
            break;
        case 5:
            std::cout << std::endl;
            (system->getPlanet(planetId)).setLifeTime(0);
            break;
        default:
            break;
        }
        printPlanetMenu();
    }
}

void Application::processTableMenu(){
    printTableMenu();
    int tableChoice;
    for(int i = 0 ; i < 8; i++)
        planetsTable[i] = false;
    while((tableChoice = getChoice())!=0){
        switch(tableChoice){
        case 1:
            printPlanets();
            tableChoice = getChoice();
            if(system->idValid(tableChoice))
                planetsTable[tableChoice-1] = true;
            break;
        case 2:
            printPlanets();
            tableChoice = getChoice();
            if(system->idValid(tableChoice))
                planetsTable[tableChoice-1] = false;
            break;
        case 3:
            tableChoice = getDeltaTime();
            for(int i = 0 ; i < 8; i++)
                if (planetsTable[i])
                    (system->getPlanet(i + 1)).step(tableChoice);
            std::cout << "\n\tДЕЛЬТА " << tableChoice << " секунд" << std::endl;
            printInfoTable();
            break;
        case 4:
            printInfoTable();
            break;
        default:
            break;
        }
        printTableMenu();
    }
}

void Application::printTableMenu(){
    std::cout << std::endl
         << "Выберите операцию с таблицей" << std::endl
         << "1. Добавить планету для сравнения" << std::endl
         << "2. Убрать планету из таблицы" << std::endl
         << "3. Ввести дельту по времени" << std::endl
         << "4. Вывести таблицу" << std::endl
         << "0. Exit" << std::endl
         << ">>> ";
}

void Application::printInfoTable(){
    std::cout << "Планета         Масса           Расстояние      Период          Текущий угол" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < 8; i++)
        if (planetsTable[i]){
            (system->getPlanet(i + 1)).printShortInfo(std::cout);
        }
    std::cout << "----------------------------------------------------------------------------";
    std::cout << std::endl;
}

int Application::getDeltaTime(){

    int preDelTime;
    int delta = 0;
    std::cout << "Введите дельту времени\n";
    std::cout << "дни ";
    preDelTime = getChoice();
    delta = preDelTime;
    std::cout << "часы ";
    preDelTime = getChoice();
    delta = 24 * delta + preDelTime;
    std::cout << "минуты ";
    preDelTime = getChoice();
    delta = 60 * delta + preDelTime;
    std::cout << "секунды ";
    preDelTime = getChoice();
    delta = 60 * delta + preDelTime;
    return delta;
}
