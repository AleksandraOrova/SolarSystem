#include"solarSystem.h"

void ConsoleApp::menu()
{
    int number_in_menu;

    cout << "Choose what you want to know:" << endl
         << "1. Information about all plnets in Solarsystem" << endl
         << "0. Exit" << endl;

    cin >> number_in_menu;

    if (cin.good())
    {
        switch (number_in_menu)
        {
            case 0:
                break;
        case 1:
           // table_of_planets();
            cout << endl;
            break;
        default:
            cout << "Something goes wrong!" << endl;
            cin.clear();
            cout << endl;
            mainMenu();
            break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl ;
        cin.clear();
        cout << endl;
        mainMenu();
    }
}

