#include "timehoursseconds.h"

TimeHoursSeconds::TimeHoursSeconds(double s, double h, double d, double y): second(s), hour(h), day(d), year(y){}

double TimeHoursSeconds::fromStoHours(){
    return (second/60/60);
}

//по Фаулеру, если одно выражение встречается в двух методах одного класса, то это дублирование.
//если заменить second/60/60/24 на fromSecondsToHours()/24, то будет понятнее. И дублирования не будет.
//TODO устранить дублирование
double TimeHoursSeconds::fromStoDays(){
    return (second/60/60/24);
}

//TODO устранить дублирование
double TimeHoursSeconds::fromStoYears(){
    return (second/60/60/24/365);
}

double TimeHoursSeconds::fromDaysToH(){
    return (day*24);
}
//TODO устранить дублирование
double TimeHoursSeconds::fromDaysToS(){
    return (day*24*60*60);
}

double TimeHoursSeconds::fromDaysToY(){
    return (day/365);
}
