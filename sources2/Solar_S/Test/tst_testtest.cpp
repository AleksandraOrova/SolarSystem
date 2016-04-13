#include <QString>
#include <QtTest>
#include "timehoursseconds.h"

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();

private Q_SLOTS:
    void addPlanet();
};

TestTest::TestTest(){
}

void TestTest::addPlanet()
{
    TimeHoursSeconds tmp(7200, 0, 0, 0);
    QCOMPARE(tmp.fromStoHours(), 2.0f);
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
