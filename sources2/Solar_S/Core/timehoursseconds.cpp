#include "timehoursseconds.h"

Time::Time(double s, double h, double d, double y): second(s), hour(h), day(d), year(y){}

double Time::fromSecondstoHours(){
    return (second/60/60);
}

double Time::fromSecondstoDays(){
    return (fromSecondstoHours()/24);
}

double Time::fromSecondstoYears(){
    return (fromSecondstoDays()/365);
}

double Time::fromDaysToHours(){
    return (day*24);
}
double Time::fromDaysToSeconds(){
    return (fromDaysToHours()*60*60);
}

double Time::fromDaysToYears(){
    return (day/365);
}
