#include<iostream>
#include "application.h"
using namespace std;

int main(){
    Application app;
    app.run();
    //(new Application())->run();
    //TODO: найти информацию про текущее положение планет
    //TODO: дописать функционал меню
    //TODO: дописать поведение планет - переопределить методы stepBy() в соответствии с законами движения
    //TODO: посмотреть в каких системах координат возможна обработка координат планет
    //TODO: работа с файловой системой
    return 0;
}
