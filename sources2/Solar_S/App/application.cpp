#include "application.h"

Application::Application(){
    system = new SolarSystem(8);
    system->addPlanet(Planet("Меркурий", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 0);
    system->addPlanet(Planet("Венера",   4.8685 * pow(10,24),  108208930000,         0.0068,  0.4f,  0), 1);
    system->addPlanet(Planet("Земля",    5.973  * pow(10,24),  149598261000,     0.01671123,  0.5f,  0), 2);
    system->addPlanet(Planet("Марс",     6.4185 * pow(10,23),  227943820000,      0.0933941,  0.45f, 0), 3);
    system->addPlanet(Planet("Юпитер",   1.8986 * pow(10,27),  778547200000,       0.048775,  0.8f,  0), 4);
    system->addPlanet(Planet("Сатурн",   5.6846 * pow(10,26), 1433449370000,    0.055723219,  0.7f,  0), 5);
    system->addPlanet(Planet("Уран",     8.6832 * pow(10,25), 2876679082000,    0.044405586, 0.6f,  0), 6);
    system->addPlanet(Planet("Нептун",   1.0243 * pow(10,26), 4503443661000,    0.011214269, 0.6f,  0), 7);

    planetsTable = new bool[8];
    for(int i = 0; i < 8; i++)
        planetsTable[i] = false;
}

Application::~Application(){
    system->~SolarSystem();
}

void Application::run()
{
    printMainMenu();
    processMainMenu();
    std::cout << "END" << std::endl;
}

void Application::printMainMenu()
{
    std::cout << std::endl
         << "Симулятор звездной системы" << std::endl
         << "1. Вывести информацию о планете" << std::endl
         << "2. Открыть таблицу для сравнения" << std::endl
         << "3. Открыть таблицу со всеми данными" << std::endl
         << "0. Выход" << std::endl
         << ">>> ";
}

void Application::processMainMenu()
{
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
                printPlanetMenu();
                processPlanetInfoMenu(menuChoice);
            }
            else
                std::cout << "Некорректный номер планеты";
            break;
            // todo если здесь мы считали некорректный номер, например 10,
            // то приложение начинает вести себя немного неадекватно.
        case 2:
            printTableMenu();
            processTableMenu();
            break;
        case 3:
            std::cout << *system << std::endl;
            break;
        default:
            std::cout << "Ошибка ввода" << std::endl;
            break;
        }
        printMainMenu();
    }
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
    int paremeterChoice;
    while((paremeterChoice = getChoice())!=0){
        switch(paremeterChoice){
        case 1:
            (system->getPlanet(planetId)).printStaticParameters(std::cout);
            break;
        case 2:
            (system->getPlanet(planetId)).printDynamicParameters(std::cout);
            break;
        case 3:
            std::cout << system->getPlanet(planetId);
            break;
        case 4:
            paremeterChoice = getDeltaTime();
            (system->getPlanet(planetId)).printDelta(std::cout, paremeterChoice);
            break;
        case 5:
            (system->getPlanet(planetId)).setLifeTime(0);
            break;
        default:
            break;
        }
        printPlanetMenu();
    }
}

void Application::processTableMenu(){
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

// todo кажется, если я введу не число, а строку, будет плохо... Пусть этот метод занимается обработкой ввода
int Application::getChoice(){
    int userInput;
    while((std::cin >> userInput) && (!std::cin.good())){
        std::cin.clear();
    }
    return userInput;
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
