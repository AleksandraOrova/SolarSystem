#ifndef TIMEHOURSSECONDS_H
#define TIMEHOURSSECONDS_H


class TimeHoursSeconds
{
private:
    float second;
    float hour;
    float day;
    float year;
public:
    TimeHoursSeconds(float s, float h, float d, float y);
    float fromStoHours();
    float fromStoDays();
    float fromStoYears();
    float fromDaysToH();
    float fromDaysToS();
    float fromDaysToY();
};

#endif // TIMEHOURSSECONDS_H
