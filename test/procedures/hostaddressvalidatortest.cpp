/*
 * This file is part of 'telamon'.
 *
 *    'telamon' is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    'telamon' is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with 'telamon'. If not, see <http://www.gnu.org/licenses/>.
 */

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
    void test_Ipv6_Ipv4Suffix();
    void test_Ipv6_Junk();

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
}

void HostAddressValidatorTest::test_Ipv6_UniqueLocalUnicast()
{
    initIpv6();

    QCOMPARE(validationWrapper("FC00::101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FC00:0:0:0:0:0:0:101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FC00::101::2"), QValidator::Intermediate);

    QCOMPARE(validationWrapper("fc00::101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("fc00:0:0:0:0:0:0:101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("fc00::101::2"), QValidator::Intermediate);
}

void HostAddressValidatorTest::test_Ipv6_Multicast()
{
    initIpv6();

    QCOMPARE(validationWrapper("FF01::101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FF01:0:0:0:0:0:0:101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("FF01::101::2"), QValidator::Intermediate);

    QCOMPARE(validationWrapper("ff01::101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("ff01:0:0:0:0:0:0:101"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("ff01::101::2"), QValidator::Intermediate);
}

void HostAddressValidatorTest::test_Ipv6_GlobalUnicast()
{
    initIpv6();

    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:DB8::8:800:200C:417A"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:DB8:0:0:8:800:200C:417A:221"), QValidator::Invalid);

    QCOMPARE(validationWrapper("2001:db8:0:0:8:800:200c:417a"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:db8::8:800:200c:417a"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("2001:db8:0:0:8:800:200c:417a:221"), QValidator::Invalid);
}

void HostAddressValidatorTest::test_Ipv6_Ipv4Suffix()
{
    QCOMPARE(validationWrapper("::0.0.0.1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("::127.0.0.1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("::abcd:127.0.0.1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("::1234:5678:127.0.0.1"), QValidator::Acceptable);
    QCOMPARE(validationWrapper("fe80::127.0.0.1"), QValidator::Acceptable);

    QCOMPARE(validationWrapper("::0.0.0."), QValidator::Intermediate);
    QCOMPARE(validationWrapper("::127.0..1"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("::abcd:127..0.1"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("::1234:5678:.0.0.1"), QValidator::Intermediate);
    QCOMPARE(validationWrapper("ff01::127."), QValidator::Intermediate);
}

void HostAddressValidatorTest::test_Ipv6_Junk()
{
    initIpv6();

    QCOMPARE(validationWrapper("fe80::^"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::°"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::!"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::\""), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::²"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::³"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::§"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::$"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::%"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::&"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::/"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::("), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::)"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::["), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::]"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::{"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::}"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::\\"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::="), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::?"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::´"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::`"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::#"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::'"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::+"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::*"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::~"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::;"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::,"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::_"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::-"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::."), QValidator::Intermediate);
    QCOMPARE(validationWrapper("fe80::ä"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::ö"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::ü"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::ß"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::<"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::>"), QValidator::Invalid);
    QCOMPARE(validationWrapper("fe80::|"), QValidator::Invalid);

    QCOMPARE(validationWrapper("ddki:"), QValidator::Invalid);
    QCOMPARE(validationWrapper("123m"), QValidator::Invalid);
    QCOMPARE(validationWrapper("k4:6fi:"), QValidator::Invalid);
    QCOMPARE(validationWrapper("12345"), QValidator::Invalid);
    QCOMPARE(validationWrapper("1:2:3:4:5:6:7:8:9"), QValidator::Invalid);

    QCOMPARE(validationWrapper("02001:0000:1234:0000:0000:C1C0:ABCD:0876"), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234:0000:00001:c1c0:abcd:0876"), QValidator::Invalid);
    QCOMPARE(validationWrapper(" 2001:0000:1234:0000:0000:C1c0:aBcD:0876"), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:c1C0:AbCd:0876 "), QValidator::Invalid);
    QCOMPARE(validationWrapper(" 2001:0000:1234:0000:0000:C1C0:abcD:0876  "), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234:0000:0000:C1c0:aBcd:0876  0"), QValidator::Invalid);
    QCOMPARE(validationWrapper("2001:0000:1234: 0000:0000:c1c0:ABcD:0876"), QValidator::Invalid);
}

QTEST_MAIN(HostAddressValidatorTest)
#include "hostaddressvalidatortest.moc"
