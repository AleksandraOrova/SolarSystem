#include "timehoursseconds.h"

Time::Time(const double s, const double h, const double d, const double y): second(s), hour(h), day(d), year(y){}

double Time::fromSecondstoHours() const noexcept{
    return (second/60/60);
}

double Time::fromSecondstoDays() const noexcept{
    return (fromSecondstoHours()/24);
}

double Time::fromSecondstoYears() const noexcept{
    return (fromSecondstoDays()/365);
}

double Time::fromDaysToHours() const noexcept{
    return (day*24);
}
double Time::fromDaysToSeconds() const noexcept{
    return (fromDaysToHours()*60*60);
}

double Time::fromDaysToYears() const noexcept{
    return (day/365);
}
