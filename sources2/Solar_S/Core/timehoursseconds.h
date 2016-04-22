#ifndef TIMEHOURSSECONDS_H
#define TIMEHOURSSECONDS_H


class TimeHoursSeconds
{
private:
    double second;
    double hour;
    double day;
    double year;
public:
    TimeHoursSeconds(double s, double h, double d, double y);
    double fromStoHours();
    double fromStoDays();
    double fromStoYears();
    double fromDaysToH();
    double fromDaysToS();
    double fromDaysToY();
};

#endif // TIMEHOURSSECONDS_H
