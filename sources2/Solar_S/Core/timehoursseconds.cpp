#include "timehoursseconds.h"

TimeHoursSeconds::TimeHoursSeconds(double s, double h, double d, double y): second(s), hour(h), day(d), year(y){}

double TimeHoursSeconds::fromStoHours(){
    return (second/60/60);
}

double TimeHoursSeconds::fromStoDays(){
    return (second/60/60/24);
}

double TimeHoursSeconds::fromStoYears(){
    return (second/60/60/24/365);
}

double TimeHoursSeconds::fromDaysToH(){
    return (day*24);
}

double TimeHoursSeconds::fromDaysToS(){
    return (day*24*60*60);
}

double TimeHoursSeconds::fromDaysToY(){
    return (day/365);
}
