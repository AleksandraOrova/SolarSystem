#include "timehoursseconds.h"

TimeHoursSeconds::TimeHoursSeconds(float s, float h, float d, float y): second(s), hour(h), day(d), year(y){}

float TimeHoursSeconds::fromStoHours(){
    return (second/60/60);
}

float TimeHoursSeconds::fromStoDays(){
    return (second/60/60/24);
}

float TimeHoursSeconds::fromStoYears(){
    return (second/60/60/24/365);
}

float TimeHoursSeconds::fromDaysToH(){
    return (day*24);
}

float TimeHoursSeconds::fromDaysToS(){
    return (day*24*60*60);
}

float TimeHoursSeconds::fromDaysToY(){
    return (day/365);
}
