#ifndef TIMEHOURSSECONDS_H
#define TIMEHOURSSECONDS_H

/**
 * @brief Класс, для хранения времени и перевода в разные единицы
 */

class Time
{
public:
    Time(const double seconds, const double hours, const double days, const double years);

    double fromSecondstoHours() const noexcept;
    /**
     * @brief Переводит величину времени из секунд в часы
     */

    double fromSecondstoDays() const noexcept;
    /**
     * @brief Переводит величину времени из секунд в дни
     */

    double fromSecondstoYears() const noexcept;
    /**
     * @brief Переводит величину времени из секунд в года
     */

    double fromDaysToHours() const noexcept;
    /**
     * @brief Переводит величину времени из дней в часы
     */

    double fromDaysToSeconds() const noexcept;
    /**
     * @brief Переводит величину времени из дней в секунды
     */

    double fromDaysToYears() const noexcept;
    /**
     * @brief Переводит величину времени из дней в года
     */

private:

    double second;
    double hour;
    double day;
    double year;
};

#endif // TIMEHOURSSECONDS_H
