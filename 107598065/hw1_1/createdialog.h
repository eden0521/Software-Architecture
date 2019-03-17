#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>
#include <string>
#include <iostream>
using namespace std;

namespace Ui {
class CreateDialog;
}

class CreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDialog(QWidget *parent = nullptr);
    ~CreateDialog();

    QString readLeClassName();
    QString readLeClassDetail();
    QString readLeForWho();
    QString readLePrice();
    QString readLeAttention();
    QString readLeNote();
    void setLeClassName(QString qstr);
    void setLeClassDetail(QString qstr);
    void setLeForWho(QString qstr);
    void setLePrice(QString qstr);
    void setLeAttention(QString qstr);
    void setLeNote(QString qstr);

    QString readLabel(int no);
    void setLabel(int no,QString qstr);

private:
    Ui::CreateDialog *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // CREATEDIALOG_H
