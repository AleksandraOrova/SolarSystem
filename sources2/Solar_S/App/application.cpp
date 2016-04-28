#include "application.h"

Application::Application(){
    system = new SolarSystem(8);
    system->addPlanet(new Planet("Меркурий", 3.302 * pow(10,23),  57910000000, 0.3f,  0), 0);
    system->addPlanet(new Planet("Венера",   4.8685 * pow(10,24), 108200000000, 0.4f,  0), 1);
    system->addPlanet(new Planet("Земля",    5.973  * pow(10,24), 149600000000, 0.5f,  0), 2);
    system->addPlanet(new Planet("Марс",     6.4185 * pow(10,23), 227900000000, 0.45f, 0), 3);
    system->addPlanet(new Planet("Юпитер",   1.8986 * pow(10,27), 778500000000, 0.8f,  0), 4);
    system->addPlanet(new Planet("Сатурн",   5.6846 * pow(10,26), 1433000000000, 0.7f, 0), 5);
    system->addPlanet(new Planet("Уран",     8.6832 * pow(10,25), 2877000000000, 0.6f, 0), 6);
    system->addPlanet(new Planet("Нептун",   1.0243 * pow(10,26), 4503000000000, 0.6f, 0), 7);
    /*
    cout << system << "\n";
    system.step(4);
    cout << system << "\n";
    */
}

void Application::run()
{
    printMainMenu();
    int choice;
    while((choice = getChoice()) != 0)
        processChoice(choice);
    printMainMenu();

}

void Application::printMainMenu()
{
    cout << "\n"
            "Симулятор звездной системы" << endl
         << "1. Показать таблицу с данными по всей системе" << endl
         << "2. Сдвинуть на дельту по времени" << endl
         << "3. Открыть таблицу для сравнения" << endl
         << "4. Открыть таблицу со всеми данными"
         << "0. Exit" << endl
         << ">>> ";
}

void Application::printPlanets()
{
    cout << "\n"
            "Список планет" << endl
         << "1. Меркурий" << endl
         << "2. Венера" << endl
         << "3. Земля" << endl
         << "4. Марс" << endl
         << "5. Юпитер" << endl
         << "6. Сатурн" << endl
         << "7. Уран" << endl
         << "8. Нептун" << endl
         << ">>> ";
}

int Application::getPlanet(){
    int planetChoise;
    cin >> planetChoise;
    return planetChoise;
}

/*void Application::planetInfo(int planetChoise){
    switch (planetChoise)
    {
    case 1:
        out << "Меркурий" << planet.name << endl;
        out << "Масса: " << planet.mass << " кг" << endl;
        out << "Расстояние до солнца " << planet.RS/1000 << " км" << endl;
        out << "Угловая скорость " << planet.angularVelocity() << " рад/с" << endl;
        out << "Период обращения вокруг солнца " << planet.periodAroundSun().fromStoYears() << " земной год/с" << endl;
        out << "Текущий положение " << planet.theta << " рад" << endl;
        break;
    case 2:
        int tmp;
        cout << "Введите дельту времени ";
        cin >> tmp;
        system->step((double)tmp);
        cout << tmp << "\n";
        printMainMenu();
        break;
    case 3:

        break;
    case 4:
        cout << *system << "\n";
        printMainMenu();
        break;
    default:
        cout << "Error! Invalid number." << endl;
        printMainMenu();
        break;
    }
}
*/

void Application::planetMenu(){
}

int Application::getChoice()
{
    int userInput;
    cin >> userInput;
    return userInput;
}

void Application::processChoice(int choice)
{
    switch (choice)
    {
    case 0:

        break;
    case 1:
        printPlanets();
        break;
    case 2:
        int tmp;
        cout << "Введите дельту времени ";
        cin >> tmp;
        system->step((double)tmp);
        cout << tmp << "\n";
        printMainMenu();
        break;
    case 3:

        break;
    case 4:
        cout << *system << "\n";
        printMainMenu();
        break;
    default:
        cout << "Error! Invalid number." << endl;
        printMainMenu();
        break;
    }
}
