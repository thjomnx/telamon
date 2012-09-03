#include <QtTest/QtTest>
#include <QValidator>

#include "hostaddressvalidator.h"

class HostAddressValidatorTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void runStandard();

private:
    QValidator::State validationWrapper(QString input);

    HostAddressValidator *validator;
};

void HostAddressValidatorTest::initTestCase()
{
    validator = new HostAddressValidator(this);
    validator->setValidatorMode(HostAddressValidator::Ipv6ValidatorMode);
}

void HostAddressValidatorTest::cleanupTestCase()
{
    delete validator;
}

QValidator::State HostAddressValidatorTest::validationWrapper(QString input)
{
    int pos = 0;
    return validator->validate(input, pos);
}

void HostAddressValidatorTest::runStandard()
{
    QCOMPARE(validationWrapper(""), QValidator::Intermediate);
    QCOMPARE(validationWrapper("::"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("::1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:0"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FF01:0:0:0:0:0:0:101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:DB8::8:800:200C:417A"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FF01::101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A:221"), QValidator::Invalid);
    QCOMPARE(validationWrapper("FF01::101::2"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80::217:f2ff:fe07:ed62"), QValidator::Acceptable);

    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1C0:ABCD:0876"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("3ffe:0b00:0000:0000:0001:0000:0000:000a"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FF02:0000:0000:0000:0000:0000:0000:0001"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0001"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0000"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("02001:0000:1234:0000:0000:C1C0:ABCD:0876"), QValidator::Invalid);        // Extra 0 not allowed
    QCOMPARE(validationWrapper("2001:0000:1234:0000:00001:C1C0:ABCD:0876"), QValidator::Invalid);        // Extra 0 not allowed
    QCOMPARE(validationWrapper(" 2001:0000:1234:0000:0000:C1C0:ABCD:0876"), QValidator::Invalid);        // Leading space
    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1C0:ABCD:0876 "), QValidator::Invalid);        // Trailing space
    QCOMPARE(validationWrapper(" 2001:0000:1234:0000:0000:C1C0:ABCD:0876  "), QValidator::Invalid);      // Leading and trailing space
    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1C0:ABCD:0876  0"), QValidator::Invalid);      // Junk after valid address
    QCOMPARE(validationWrapper("2001:0000:1234: 0000:0000:C1C0:ABCD:0876"), QValidator::Invalid);        // Internal space

    QCOMPARE(validationWrapper("1111:2222:3333:4444:5555:6666:1.2.3.4"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1C0:ABCD:127.0.0.1"), QValidator::Acceptable);
}

QTEST_MAIN(HostAddressValidatorTest)
#include "hostaddressvalidatortest.moc"
