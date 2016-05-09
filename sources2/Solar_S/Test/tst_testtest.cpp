#include <QString>
#include <QtTest>
#include "planet.h"
#include "solarsystem.h"
#include "timehoursseconds.h"

// todo нужно больше тестов. Тестируется всего один класс.
// todo еще нужны функциональные тесты. Для них можно сделать отдельный проект.
class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();

private Q_SLOTS:
    void fromSecondstoHours();
    void fromSecondstoDays();
    void fromSecondstoYears();
    void fromDaysToHours();
    void fromDaysToSeconds();
    void fromDaysToYears();
};

TestTest::TestTest(){
}

void TestTest::fromSecondstoHours(){
    Time tmp(7200, 0, 0, 0); // 2 часа = 7200 секунд
    QCOMPARE(tmp.fromSecondstoHours(), 2.0f);
}

void TestTest::fromSecondstoDays(){
    Time tmp(172800, 0, 0, 0); // 2 дня = 48 часов = 172800 секунд
    QCOMPARE(tmp.fromSecondstoDays(), 2.0f);
}

void TestTest::fromSecondstoYears(){
    Time tmp(63072000, 0, 0, 0); // 2 года = 730 дней = 17520 часов = 63072000 секунд
    QCOMPARE(tmp.fromSecondstoYears(), 2.0f);
}

void TestTest::fromDaysToHours(){
    Time tmp(0, 0, 2, 0); // 2 дня = 48 часов
    QCOMPARE(tmp.fromDaysToHours(), 48.0f);
}

void TestTest::fromDaysToSeconds(){
    Time tmp(0, 0, 2, 0); // 2 дня = 48 часов = 172800 секунд
    QCOMPARE(tmp.fromDaysToSeconds(), 172800.0f);
}

void TestTest::fromDaysToYears(){
    Time tmp(0, 0, 730, 0); // 2 года = 730 дней
    QCOMPARE(tmp.fromDaysToYears(), 2.0f);
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
