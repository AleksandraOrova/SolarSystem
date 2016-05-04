#ifndef TIMEHOURSSECONDS_H
#define TIMEHOURSSECONDS_H

class Time
{
public:

//Когда функция не генерирует исключений, классно приписывать модификатор noexcept.
//почему это классно, объясняется в Мейерс "Эффективный и современный c++ 11 и 14"

//TODO добавить noexcept ко всем функциям, которые не генерируют исключений.

//TODO добавить const к аргументам функций, где только возможно.

    Time(double seconds, double hours, double days, double years);

    //TODO добавить const ко всем функциям, которые не изменяют объект.

    double fromSecondstoHours();
    /**
     * @brief fromSecondstoDays
     * @return
     */

    double fromSecondstoDays();
    /**
     * @brief fromSecondstoYears
     * @return
     */

    double fromSecondstoYears();
    /**
     * @brief fromDaysToHours
     * @return
     */

    double fromDaysToHours();
    /**
     * @brief fromDaysToSeconds
     * @return
     */

    double fromDaysToSeconds();
    /**
     * @brief fromDaysToYears
     * @return
     */

    double fromDaysToYears();

private:

    double second;
    double hour;
    double day;
    double year;
};

#endif // TIMEHOURSSECONDS_H
