#include "timehoursseconds.h"

// а здесь вы все-таки используйте список инициализаци...
// todo сделать все методы inline и удалить файл
Time::Time(const double s, const double h, const double d, const double y): second(s), hour(h), day(d), year(y){}

double Time::fromSecondstoHours() const{
    return (second/60/60);
}

double Time::fromSecondstoDays() const{
    return (fromSecondstoHours()/24);
}

double Time::fromSecondstoYears() const{
    return (fromSecondstoDays()/365);
}

double Time::fromDaysToHours() const{
    return (day*24);
}

double Time::fromDaysToSeconds() const{
    return (fromDaysToHours()*60*60);
}

double Time::fromDaysToYears() const{
    return (day/365);
}
