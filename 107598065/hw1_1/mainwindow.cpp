#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniSignalSlots();

    vector<vector<string>> vecData = file->fileInput("data.txt");
    btnEvent->iniTable(ui,vecData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniSignalSlots()
{
    connect(ui->btnShow,SIGNAL(clicked()),this,SLOT(on_btnShow()));
    connect(ui->btnCreate,SIGNAL(clicked()),this,SLOT(on_btnCreate()));
    connect(ui->btnDelete,SIGNAL(clicked()),this,SLOT(on_btnDelete()));
    connect(ui->btnEdit,SIGNAL(clicked()),this,SLOT(on_btnEdit()));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    btnEvent->btnCloseEvent(event,this,ui,file);
}

void MainWindow::on_btnShow()
{
    btnEvent->btnShow(this,ui);
}

void MainWindow::on_btnCreate()
{
    btnEvent->btnCreate(this,ui);
}

void MainWindow::on_btnDelete()
{
    btnEvent->btnDelete(this,ui);
}

void MainWindow::on_btnEdit()
{
    btnEvent->btnEdit(this,ui);
}

