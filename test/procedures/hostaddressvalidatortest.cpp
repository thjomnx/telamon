#include <QtTest/QtTest>
#include <QValidator>

#include "hostaddressvalidator.h"

class HostAddressValidatorTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_Ipv6_Crumbs();
    void test_Ipv6_Unspecified();
    void test_Ipv6_Loopback();
    void test_Ipv6_Linklocal();
    void test_Ipv6_UniqueLocalUnicast();
    void test_Ipv6_Multicast();
    void test_Ipv6_GlobalUnicast();

private:
    void initIpv4();
    void initIpv6();
    QValidator::State validationWrapper(QString input);

    HostAddressValidator *validator;
};

void HostAddressValidatorTest::initTestCase()
{
    validator = new HostAddressValidator(this);
}

void HostAddressValidatorTest::cleanupTestCase()
{
    delete validator;
}

void HostAddressValidatorTest::initIpv4()
{
    validator->setValidatorMode(HostAddressValidator::Ipv4ValidatorMode);
}

void HostAddressValidatorTest::initIpv6()
{
    validator->setValidatorMode(HostAddressValidator::Ipv6ValidatorMode);
}

QValidator::State HostAddressValidatorTest::validationWrapper(QString input)
{
    int pos = 0;
    QValidator::State result = validator->validate(input, pos);

    return result;
}

void HostAddressValidatorTest::test_Ipv6_Crumbs()
{
    initIpv6();

    QCOMPARE(validationWrapper(""), QValidator::Intermediate);
    QCOMPARE(validationWrapper(":"), QValidator::Intermediate);
}

void HostAddressValidatorTest::test_Ipv6_Unspecified()
{
    initIpv6();

    QCOMPARE(validationWrapper("::"), QValidator::Acceptable);
    QCOMPARE(validationWrapper(":::"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("::0"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("::0:"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("::0:0"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:0"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:0:"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:0:0"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0000"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0000:"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0000::"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0000:0000"), QValidator::Invalid);
}

void HostAddressValidatorTest::test_Ipv6_Loopback()
{
    initIpv6();

    QCOMPARE(validationWrapper("::1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("::1:"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("::1:1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:1:"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0:0:0:0:0:0:0:0:1"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0001"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0001:"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0001::"), QValidator::Invalid);
    QCOMPARE(validationWrapper("0000:0000:0000:0000:0000:0000:0000:0000::0001"), QValidator::Invalid);
}

void HostAddressValidatorTest::test_Ipv6_Linklocal()
{
    initIpv6();

    QCOMPARE(validationWrapper("fe80::"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000::"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000:"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000:0000"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000:0000:"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000:0000:0000"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000:0000:0000:"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000:0000:0000::"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80:0000:0000:0000:0000:0000:0000:0000:0000"), QValidator::Invalid);

    QCOMPARE(validationWrapper("fe80::217:f2ff:fe07:ed62"), QValidator::Acceptable);
}

void HostAddressValidatorTest::test_Ipv6_UniqueLocalUnicast()
{
    initIpv6();
}

void HostAddressValidatorTest::test_Ipv6_Multicast()
{
    initIpv6();

    QCOMPARE(validationWrapper("FF01::101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FF01:0:0:0:0:0:0:101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FF01::101::2"), QValidator::Intermediate);
}

void HostAddressValidatorTest::test_Ipv6_GlobalUnicast()
{
    initIpv6();

    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:DB8::8:800:200C:417A"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A:221"), QValidator::Invalid);

    QCOMPARE(validationWrapper("02001:0000:1234:0000:0000:C1C0:ABCD:0876"), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234:0000:00001:C1C0:ABCD:0876"), QValidator::Invalid);
    QCOMPARE(validationWrapper(" 2001:0000:1234:0000:0000:C1C0:ABCD:0876"), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1C0:ABCD:0876 "), QValidator::Invalid);
    QCOMPARE(validationWrapper(" 2001:0000:1234:0000:0000:C1C0:ABCD:0876  "), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1C0:ABCD:0876  0"), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234: 0000:0000:C1C0:ABCD:0876"), QValidator::Invalid);

    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1C0:ABCD:127.0.0.1"), QValidator::Acceptable);
}

QTEST_MAIN(HostAddressValidatorTest)
#include "hostaddressvalidatortest.moc"
