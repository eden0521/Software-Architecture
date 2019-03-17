#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

#include "file_io.h"
#include "btn_event.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void iniSignalSlots();
    void closeEvent(QCloseEvent *event);
    FileIO * file;
    BtnEvent * btnEvent;

private slots:
    void on_btnShow();
    void on_btnCreate();
    void on_btnDelete();
    void on_btnEdit();
};

#endif // MAINWINDOW_H
