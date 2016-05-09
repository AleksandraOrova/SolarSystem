#ifndef TIMEHOURSSECONDS_H
#define TIMEHOURSSECONDS_H

/**
 * @brief Класс, для хранения времени и перевода в разные единицы
 */
// todo дописать noexcept для методов, не генерирующих исключение
class Time
{
public:
    Time(const double seconds, const double hours, const double days, const double years);

    /**
     * @brief Переводит величину времени из секунд в часы
     */
    double fromSecondstoHours() const; // noexcept

    /**
     * @brief Переводит величину времени из секунд в дни
     */
    double fromSecondstoDays() const; // noexcept

    /**
     * @brief Переводит величину времени из секунд в года
     */
    double fromSecondstoYears() const; // noexcept

    /**
     * @brief Переводит величину времени из дней в часы
     */
    double fromDaysToHours() const; // noexcept

    /**
     * @brief Переводит величину времени из дней в секунды
     */
    double fromDaysToSeconds() const; // noexcept

    /**
     * @brief Переводит величину времени из дней в года
     */
    double fromDaysToYears() const; // noexcept

private:

    double second;
    double hour;
    double day;
    double year;
};

#endif // TIMEHOURSSECONDS_H
