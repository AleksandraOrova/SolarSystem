#include "consoleapp.h"
#include <iostream>

using namespace std;

ConsoleApp::ConsoleApp()
{

}

void ConsoleApp::tableOfPlanets()
{

}

ConsoleApp::~ConsoleApp()
{

}

void ConsoleApp::printMenu()
{
    cout << "Choose what you want to know:" << endl
         << "1. Information about all plnets in Solarsystem" << endl
         << "0. Exit" << endl;
}

int ConsoleApp::getInput()
{
    int number_in_menu;
    cin >> number_in_menu;
    return number_in_menu;
}

bool ConsoleApp::isGood(int operationNumber){
    return (operationNumber >= 0 && operationNumber <=1);
}

void ConsoleApp::operate(int operationNumber)
{
    if (isGood(operationNumber)){
        switch (operationNumber)
        {
            case 0:
                break;
            case 1:
               // tableOfPlanets();
                cout << endl;
                break;
            default:
                cout << "Something goes wrong!" << endl;
                cin.clear();
                cout << endl;
                printMenu();
                break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl ;
        cin.clear();
        cout << endl;
        printMenu();
    }

}

void ConsoleApp::run(){
    while(true){
        printMenu();
        int tmp = getInput();
        if (tmp == 0)
            break;
        operate(tmp);

    }
}
