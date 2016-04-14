#include <QString>
#include <QtTest>
#include "timehoursseconds.h"

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();

private Q_SLOTS:
    void fromStoHours();
    void fromStoDays();
    void fromStoYears();
    void fromDaysToH();
    void fromDaysToS();
    void fromDaysToY();
};

// TimeHoursSeconds::TimeHoursSeconds(float s, float h, float d, float y): second(s), hour(h), day(d), year(y){}

TestTest::TestTest(){
}

void TestTest::fromStoHours()
{
    TimeHoursSeconds tmp(7200, 0, 0, 0); // 2 часа = 7200 секунд
    QCOMPARE(tmp.fromStoHours(), 2.0f);
}

void TestTest::fromStoDays()
{
    TimeHoursSeconds tmp(172800, 0, 0, 0); // 2 дня = 48 часов = 172800 секунд
    QCOMPARE(tmp.fromStoDays(), 2.0f);
}

void TestTest::fromStoYears()
{
    TimeHoursSeconds tmp(63072000, 0, 0, 0); // 2 года = 730 дней = 17520 часов = 63072000 секунд
    QCOMPARE(tmp.fromStoYears(), 2.0f);
}

void TestTest::fromDaysToH()
{
    TimeHoursSeconds tmp(0, 0, 2, 0); // 2 дня = 48 часов
    QCOMPARE(tmp.fromDaysToH(), 48.0f);
}

void TestTest::fromDaysToS()
{
    TimeHoursSeconds tmp(0, 0, 2, 0); // 2 дня = 48 часов = 172800 секунд
    QCOMPARE(tmp.fromDaysToS(), 172800.0f);
}

void TestTest::fromDaysToY()
{
    TimeHoursSeconds tmp(0, 0, 730, 0); // 2 года = 730 дней
    QCOMPARE(tmp.fromDaysToY(), 2.0f);
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
