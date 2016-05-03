#ifndef TIMEHOURSSECONDS_H
#define TIMEHOURSSECONDS_H

//TODO задокументировать Doxygen'ом
class TimeHoursSeconds
{
private:
//Пышкин на лекциях говорил, что классно сначала объявлять public функции (интерфейс класса, функции доступа к данным)
//А после них уже private функции и данные.
//Это можно аргументировать тем, что удобно видеть пользователю класса сначала то, что можно будет ему использовать, а
//не то, что закрыто.
//TODO поменять местами public и private.
    double second;
    double hour;
    double day;
    double year;
public:
//чтобы понять, что такое s, h, d и y, надо смотреть на данные класса. Посмотрев только на интерфейс, что будет делать пользователь,
//понять ничего нельзя.
//TODO дать нормальные названия переменным в констукторе
    TimeHoursSeconds(double s, double h, double d, double y);
    double fromStoHours();
    double fromStoDays();
    double fromStoYears();
    double fromDaysToH();
    double fromDaysToS();
    double fromDaysToY();
};

#endif // TIMEHOURSSECONDS_H
