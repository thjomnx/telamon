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
    QCOMPARE(validationWrapper(""), QValidator::Intermediate);                                    // Empty string
    QCOMPARE(validationWrapper("::"), QValidator::Acceptable);                                    // Loopback, compressed, non-routable
    QCOMPARE(validationWrapper("::1"), QValidator::Acceptable);                                   // Unspecified, compressed, non-routable
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:1"), QValidator::Acceptable);                       // Loopback, full
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:0"), QValidator::Acceptable);                       // Unspecified, full
    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A"), QValidator::Acceptable);          // Unicast, full
    QCOMPARE(validationWrapper("FF01:0:0:0:0:0:0:101"), QValidator::Acceptable);                  // Multicast, full
    QCOMPARE(validationWrapper("2001:DB8::8:800:200C:417A"), QValidator::Acceptable);             // Unicast, compressed
    QCOMPARE(validationWrapper("FF01::101"), QValidator::Acceptable);                             // Multicast, compressed
    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A:221"), QValidator::Invalid);         // Unicast, full
    QCOMPARE(validationWrapper("FF01::101::2"), QValidator::Invalid);                             // Multicast, compressed
    QCOMPARE(validationWrapper("fe80::217:f2ff:fe07:ed62"), QValidator::Acceptable);              // Local link, compressed, lowercase
}

QTEST_MAIN(HostAddressValidatorTest)
#include "hostaddressvalidatortest.moc"
