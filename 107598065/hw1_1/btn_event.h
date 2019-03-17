#ifndef BTN_EVENT_H
#define BTN_EVENT_H

//#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createdialog.h"
#include "file_io.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QInputDialog>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>

class BtnEvent{
public:
    void btnCloseEvent(QCloseEvent *event,QMainWindow *parent,
                       Ui::MainWindow *ui,FileIO *file){
       QMessageBox::StandardButton button;
        button = QMessageBox::question(parent, "關閉程式",
            QString("確定要離開?"),
            QMessageBox::Yes | QMessageBox::No);

        if (button == QMessageBox::No) {
            event->ignore();
        }
        if (button == QMessageBox::Yes) {
            QString qstr = "";
            QTableWidgetItem * cellItem;
            for(int i=0;i<ui->tableClass->rowCount();i++){
                for(int j=0;j<ui->tableClass->columnCount();j++){
                    cellItem = ui->tableClass->item(i,j);
                    if(cellItem->text().length() == 0)
                        qstr += " |@$#|";
                    else
                        qstr += cellItem->text() + "|@$#|" ;
                }
//                cout<<"qstr = "<<string((const char *)qstr.toLocal8Bit())<<endl;
                qstr += "\n";
            }
            string strText = string((const char *)qstr.toLocal8Bit());
            file->fileOutPut("data.txt",strText);
        }
    }

    void btnShow(QMainWindow *parent,Ui::MainWindow *ui){
        QString dlgTitle = "列出所有課程";
        QString qStrClassName = "";
        for(int i=0;i<ui->tableClass->rowCount();i++){
            qStrClassName += ui->tableClass->item(i,0)->text() + "\n";
        }
        QMessageBox::about(parent,dlgTitle,qStrClassName);
    }

    void btnCreate(QMainWindow *parent,Ui::MainWindow *ui){
        CreateDialog * createDialog = new CreateDialog(parent);
        int ret = createDialog->exec();
        //ret==0 is create
        //ret==1 is cancel
        if(ret==0){
            QString strClassName = createDialog->readLeClassName();
            QString strClassDetail = createDialog->readLeClassDetail();
            QString strForWho = createDialog->readLeForWho();
            QString strPrice = createDialog->readLePrice();
            QString strAttention = createDialog->readLeAttention();
            QString strNote = createDialog->readLeNote();
            int rows = ui->tableClass->rowCount();
            ui->tableClass->insertRow(rows);
            createItemsARow(ui,rows,strClassName,strClassDetail,
                            strForWho,strPrice,strAttention,strNote);
        }
        delete createDialog;
    }

    void btnDelete(QMainWindow *parent,Ui::MainWindow *ui){
        int curRow = ui->tableClass->currentRow();
        cout<<"curRow = "<<curRow<<endl;
        if(curRow < 0){
            QString dlgTitle = "錯誤";
            QString strInfo = "請選點選要刪除行";
            QMessageBox::warning(parent,dlgTitle,strInfo);
        }
        else{
            QMessageBox::StandardButton button;
            button = QMessageBox::warning(parent, "刪除提醒",
                QString("確認要刪除?"),
                QMessageBox::Yes | QMessageBox::No);
            if (button == QMessageBox::Yes) {
                ui->tableClass->removeRow(curRow);
            }
        }
    }

    void btnEdit(QMainWindow *parent,Ui::MainWindow *ui){
        QString dlgTitle = "編輯";
        QString txtLabel = "選擇想要編輯的行號";
        int defaultValue = ui->tableClass->currentRow()+1;
        int minValue = 1;
        int maxValue = ui->tableClass->rowCount();
        int stepValue = 1;
        bool ok = false;
        int inputValue = QInputDialog::getInt(parent,dlgTitle,txtLabel,
                                              defaultValue,minValue,maxValue,
                                              stepValue,&ok);
        int setRow = inputValue - 1;
        if(ok){
            CreateDialog * createDialog = new CreateDialog(parent);
            for(int i=0;i<6;i++){
                createDialog->setLabel(i,ui->tableClass->item(setRow,i)->text());
            }

            int ret = createDialog->exec();
            //ret==0 is create
            //ret==1 is cancel
            if(ret==0){
                QString strArray[6];
                for(int i=0;i<6;i++){
                    strArray[i] = createDialog->readLabel(i);
                }
                ui->tableClass->removeRow(setRow);
                ui->tableClass->insertRow(setRow);
                createItemsARow(ui,setRow,strArray[0],strArray[1],
                                strArray[2],strArray[3],strArray[4],strArray[5]);
            }
            delete createDialog;
        }
    }

    void iniTable(Ui::MainWindow *ui,vector<vector<string> > vecData){
        QTableWidgetItem * headerItem;
        QStringList headerText;
        headerText<<"課程名稱"<<"課程說明"<<"適合對象"<<"定價"<<"注意事項"<<"備註";
        ui->tableClass->setColumnCount(headerText.count());
        ui->tableClass->setRowCount(vecData.size());
        for(int i=0;i<ui->tableClass->columnCount();i++){
            headerItem = new QTableWidgetItem(headerText.at(i));
            ui->tableClass->setHorizontalHeaderItem(i,headerItem);
        }
        vector<vector<string>>::iterator itData;
        vector<string>::iterator it;
        int rowCount=0;
        for(itData = vecData.begin();itData != vecData.end();++itData){
            for(int i=0;i<6;i++){
                if((*itData)[i].compare(" ") == 0)
                    (*itData)[i] = "";
            }
            QString strClassName = QString(QString::fromLocal8Bit((*itData)[0].c_str()));
            QString strClassDetail = QString(QString::fromLocal8Bit((*itData)[1].c_str()));
            QString strForWho = QString(QString::fromLocal8Bit((*itData)[2].c_str()));
            QString strPrice = QString(QString::fromLocal8Bit((*itData)[3].c_str()));
            QString strAttention = QString(QString::fromLocal8Bit((*itData)[4].c_str()));
            QString strNote = QString(QString::fromLocal8Bit((*itData)[5].c_str()));
            createItemsARow(ui,rowCount,strClassName,strClassDetail,
                            strForWho,strPrice,strAttention,strNote);
            rowCount++;
        }
    }


private:
    void createItemsARow(Ui::MainWindow *ui,int rowNo, QString className,
                        QString classDetail, QString forWho,
                        QString price, QString attention, QString note){
        QString qstrArr[6] = {className,classDetail,forWho,price,attention,note};
        QTableWidgetItem * item;
        for(int i=0;i<6;i++){
            item = new QTableWidgetItem(qstrArr[i],i);
            ui->tableClass->setItem(rowNo,i,item);
        }

    }
};

#endif // BTN_EVENT_H
