#include <QtGui>

#include "udpreceiverconfigdialog.h"
#include "ipaddressvalidator.h"

UdpReceiverConfigDialog::UdpReceiverConfigDialog(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setupUi(this);

    initUi();
    makeConnections();
}

UdpReceiverConfigDialog::~UdpReceiverConfigDialog()
{
}

void UdpReceiverConfigDialog::initUi()
{
    buttonBox_OkCancel->button(QDialogButtonBox::Ok)->setEnabled(false);

    QValidator *validator = new IpAddressValidator(this);
    comboBox_Address->setValidator(validator);
}

void UdpReceiverConfigDialog::makeConnections()
{
    connect(buttonBox_OkCancel, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox_OkCancel, SIGNAL(rejected()), this, SLOT(reject()));
}

void UdpReceiverConfigDialog::updateUi()
{
    bool valid = comboBox_Address->lineEdit()->hasAcceptableInput();
    valid &= spinBox_Port->value() > 0 ? true : false;

    buttonBox_OkCancel->button(QDialogButtonBox::Ok)->setEnabled(valid);
}

void UdpReceiverConfigDialog::on_comboBox_Address_editTextChanged()
{
    updateUi();
}

void UdpReceiverConfigDialog::on_spinBox_Port_valueChanged()
{
    updateUi();
}
