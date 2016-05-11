#ifndef TIMEHOURSSECONDS_H
#define TIMEHOURSSECONDS_H

/**
 * @brief Класс, для хранения времени и перевода в разные единицы
 */

class Time
{
public:
    Time(const double s, const double h, const double d, const double y): second(s), hour(h), day(d), year(y){}

    /**
     * @brief Переводит величину времени из секунд в часы
     */
    double fromSecondstoHours() const noexcept { return (second/60/60); }

    /**
     * @brief Переводит величину времени из секунд в дни
     */
    double fromSecondstoDays() const noexcept { return (fromSecondstoHours()/24); }

    /**
     * @brief Переводит величину времени из секунд в года
     */
    double fromSecondstoYears() const noexcept { return (fromSecondstoDays()/365); }

    /**
     * @brief Переводит величину времени из дней в часы
     */
    double fromDaysToHours() const noexcept { return (day*24); }

    /**
     * @brief Переводит величину времени из дней в секунды
     */
    double fromDaysToSeconds() const noexcept { return (fromDaysToHours()*60*60); }

    /**
     * @brief Переводит величину времени из дней в года
     */
    double fromDaysToYears() const noexcept { return (day/365); }

private:

    double second;
    double hour;
    double day;
    double year;
};

#endif // TIMEHOURSSECONDS_H
