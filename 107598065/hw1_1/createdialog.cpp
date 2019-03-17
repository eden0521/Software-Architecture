#include "createdialog.h"
#include "ui_createdialog.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QString>

#include <string>
#include <iostream>
using namespace std;

CreateDialog::CreateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
}

CreateDialog::~CreateDialog()
{
    delete ui;
}

void CreateDialog::closeEvent(QCloseEvent *event)
{
    QString qstr = ui->leClassName->text();
    string str = string((const char *)qstr.toLocal8Bit());
    if(str.compare("") == 0){
        QMessageBox::StandardButton button;
        button = QMessageBox::warning(this, tr("新增失敗"),
            QString(tr("課程名稱為必填欄位!")),
            QMessageBox::Yes);
        if (button == QMessageBox::Yes) {
            event->ignore();
        }
    }
}

QString CreateDialog::readLabel(int no)
{
    QString qstr;
    switch (no) {
        case 0:
            qstr = ui->leClassName->text();
            return qstr;
        case 1:
            qstr = ui->leClassDetail->text();
            return qstr;
        case 2:
            qstr = ui->leForWho->text();
            return qstr;
        case 3:
            qstr = ui->lePrice->text();
            return qstr;
        case 4:
            qstr = ui->leAttention->text();
            return qstr;
        case 5:
            qstr = ui->leNote->text();
            return qstr;
        default:
            break;
    }
}

void CreateDialog::setLabel(int no, QString qstr)
{
    switch (no) {
        case 0:
            ui->leClassName->setText(qstr);
            break;
        case 1:
            ui->leClassDetail->setText(qstr);
            break;
        case 2:
            ui->leForWho->setText(qstr);
            break;
        case 3:
            ui->lePrice->setText(qstr);
            break;
        case 4:
            ui->leAttention->setText(qstr);
            break;
        case 5:
            ui->leNote->setText(qstr);
            break;
    }
}

QString CreateDialog::readLeClassName()
{
    QString qstr = ui->leClassName->text();
    return qstr;
}
QString CreateDialog::readLeClassDetail()
{
    QString qstr = ui->leClassDetail->text();
    return qstr;
}
QString CreateDialog::readLeForWho()
{
    QString qstr = ui->leForWho->text();
    return qstr;
}
QString CreateDialog::readLePrice()
{
    QString qstr = ui->lePrice->text();
    return qstr;
}
QString CreateDialog::readLeAttention()
{
    QString qstr = ui->leAttention->text();
    return qstr;
}
QString CreateDialog::readLeNote()
{
    QString qstr = ui->leNote->text();
    return qstr;
}

void CreateDialog::setLeClassName(QString qstr)
{
    ui->leClassName->setText(qstr);
}
void CreateDialog::setLeClassDetail(QString qstr)
{
    ui->leClassDetail->setText(qstr);
}
void CreateDialog::setLeForWho(QString qstr)
{
    ui->leForWho->setText(qstr);
}
void CreateDialog::setLePrice(QString qstr)
{
    ui->lePrice->setText(qstr);
}
void CreateDialog::setLeAttention(QString qstr)
{
    ui->leAttention->setText(qstr);
}
void CreateDialog::setLeNote(QString qstr)
{
    ui->leNote->setText(qstr);
}


