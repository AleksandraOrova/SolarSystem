#include "application.h"

Application::Application(){
    system = new SolarSystem(8);
    system->addPlanet(new Planet("Меркурий", 4,  1, 22, 1234), 0);
    system->addPlanet(new Planet("Венера",   2,  2, 21, 412),  1);
    system->addPlanet(new Planet("Земля",    3,  3, 23, 1123), 2);
    system->addPlanet(new Planet("Марс",     1,  4, 24, 1123), 3);
    system->addPlanet(new Planet("Юпитер",   7,  5, 24, 1423), 4);
    system->addPlanet(new Planet("Сатурн",   8,  6, 25, 123),  5);
    system->addPlanet(new Planet("Уран",     23, 7, 26, 11),   6);
    system->addPlanet(new Planet("Нептун",   24, 8, 26, 14),   7);
    /*
    cout << system << "\n";
    system.step(4);
    cout << system << "\n";
    */
}

void Application::printMainMenu()
{
    cout << "Симулятор звездной системы" << endl
         << "1. Показать список планет" << endl
         << "2. Сдвинуть планеты на дельту по времени" << endl
         << "3. " << endl
         << "0. Exit" << endl
         << ">>> ";
}

void Application::planetMenu()
{

}

int Application::getChoice()
{
    int tmp;
    cin >> tmp;
    return tmp;
}
void Application::processChoice(int choice)
{
    switch (choice)
    {
    case 0:

        break;
    case 1:
        cout << *system << "\n";
        break;
    case 2:
        int tmp;
        cout << "Введите дельту времени ";
        cin >> tmp;
        system->step(tmp);
        break;
    default:
        cout << "Error! Invalid number." << endl;
        printMainMenu();
        break;
    }
}

void Application::run()
{
    printMainMenu();
    int choice;
    while((choice = getChoice()) != 0)
        processChoice(choice);

}
