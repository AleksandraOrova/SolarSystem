#include <QString>
#include <QtTest>
/// Мало тестов.
/// А те, что есть не доделаны
/// В частности, нет тестов, которые показали бы, что есть большие утечки памяти
//TODO добавить тестов
#include "planet.h"
#include "solarsystem.h"
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
    /*double gravitationalForce();
    double angularVelocity();
    double velocity();
    double angularPosition();
    double varAngularPosition();
    TimeHoursSeconds periodAroundSun();
    void addPlanet();
    void step();*/
};

TestTest::TestTest(){
}

void TestTest::fromStoHours(){
    TimeHoursSeconds tmp(7200, 0, 0, 0); // 2 часа = 7200 секунд
    QCOMPARE(tmp.fromStoHours(), 2.0f);
}

void TestTest::fromStoDays(){
    TimeHoursSeconds tmp(172800, 0, 0, 0); // 2 дня = 48 часов = 172800 секунд
    QCOMPARE(tmp.fromStoDays(), 2.0f);
}

void TestTest::fromStoYears(){
    TimeHoursSeconds tmp(63072000, 0, 0, 0); // 2 года = 730 дней = 17520 часов = 63072000 секунд
    QCOMPARE(tmp.fromStoYears(), 2.0f);
}

void TestTest::fromDaysToH(){
    TimeHoursSeconds tmp(0, 0, 2, 0); // 2 дня = 48 часов
    QCOMPARE(tmp.fromDaysToH(), 48.0f);
}

void TestTest::fromDaysToS(){
    TimeHoursSeconds tmp(0, 0, 2, 0); // 2 дня = 48 часов = 172800 секунд
    QCOMPARE(tmp.fromDaysToS(), 172800.0f);
}

void TestTest::fromDaysToY(){
    TimeHoursSeconds tmp(0, 0, 730, 0); // 2 года = 730 дней
    QCOMPARE(tmp.fromDaysToY(), 2.0f);
}
//TODO доделать тесты
//Planet::Planet(string name, double mass, double RS, double radius, double theta)
/*
double TestTest::gravitationalForce(){

}

double TestTest::angularVelocity(){

}

double TestTest::velocity(){

}

double TestTest::angularPosition(){

}

double TestTest::varAngularPosition(){

}

TimeHoursSeconds TestTest::periodAroundSun(){

}

//

void TestTest::addPlanet(){

}


void TestTest::step(){

}
*/

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
