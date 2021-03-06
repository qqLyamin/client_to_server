#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>

logIn::logIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logIn)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(this->width(), this->height());

    setWindowFlags(Qt::CustomizeWindowHint      /*|
                   Qt::WindowTitleHint          |
                   Qt::WindowMinimizeButtonHint |
                   Qt::WindowMaximizeButtonHint |
                   Qt::WindowCloseButtonHint    |
                   Qt::WindowSystemMenuHint     |
                   Qt::WindowContextHelpButtonHint */);
    this->setAttribute(Qt::WA_CustomWhatsThis);
}

logIn::~logIn()
{
    delete ui;
}

void logIn::accept()
{
    if (ui->lineEdit_name->text() != "" && ui->lineEdit_password->text() != "") {
        QString name = QString(ui->lineEdit_name->text());
        QString pw = QString(ui->lineEdit_password->text());

        emit checkClient(name, pw);
    }
}

void logIn::login_ok()
{
    emit login_ok_signal();
    this->close();
}

void logIn::login_no()
{
    QMessageBox msg;
    msg.setText("Wrong!");
    msg.exec();
    emit wrongLogin();
}

void logIn::on_buttonBox_rejected()
{
    emit return_to_entry();
    this->close();
}
