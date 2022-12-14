#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QString>
#include <ostream>
#include <QDebug>
#include <string>
#include <QMessageBox>
#define max 100

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Valoresmotor_clicked()
{
    QString arr[5];
    QStringList lista, lista2;
    //QFile f("/home/alse/Documents/lab_final/datos.txt");
    //QFile f("/home/alse/Documents/lab_final/datos1.txt");
    QFile f("/home/alse/Documents/lab_final/datos2.txt");
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout<<"Open failed"<<endl;
    }
    QTextStream txtInput(&f);
    QString lineStr, lineStr2;
    if (!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();

        int cont = 0;
        lista = lineStr.split(";");
        for (cont = 0; cont < 5; cont++)
        {
            lineStr2 = lista[cont];
            lista2 = lineStr2.split(":");
            foreach(QString item, lista2)
            {
                arr[cont]=item;
            }
            ui->Velocidad->setText(arr[0]);
            ui->Frecuencia->setText(arr[1]);
            ui->Voltaje->setText(arr[2]);
            ui->Temp->setText(arr[3]);
            ui->Time->setText(arr[4]);
        }

        //velocidad
        if (1710<arr[0].toInt() && arr[0].toInt()<1890)
        {
            QPalette p = ui->Velocidad->palette();
            p.setColor(QPalette::Base, Qt::green);
            p.setColor(QPalette::Text, Qt::black);
            ui->Velocidad->setPalette(p);
        }
        else
        {
            QPalette p1 = ui->Velocidad->palette();
            p1.setColor(QPalette::Base, Qt::red);
            p1.setColor(QPalette::Text, Qt::black);
            ui->Velocidad->setPalette(p1);
        }
        //frecuencia
        if (57<arr[1].toInt() && arr[1].toInt()<63)
        {
            QPalette p = ui->Frecuencia->palette();
            p.setColor(QPalette::Base, Qt::green);
            p.setColor(QPalette::Text, Qt::black);
            ui->Frecuencia->setPalette(p);
        }
        else
        {
            QPalette p1 = ui->Frecuencia->palette();
            p1.setColor(QPalette::Base, Qt::red);
            p1.setColor(QPalette::Text, Qt::black);
            ui->Frecuencia->setPalette(p1);
        }
        //voltaje
        if (209<arr[2].toInt() && arr[2].toInt()<231)
        {
            QPalette p = ui->Voltaje->palette();
            p.setColor(QPalette::Base, Qt::green);
            p.setColor(QPalette::Text, Qt::black);
            ui->Voltaje->setPalette(p);
        }
        else
        {
            QPalette p1 = ui->Voltaje->palette();
            p1.setColor(QPalette::Base, Qt::red);
            p1.setColor(QPalette::Text, Qt::black);
            ui->Voltaje->setPalette(p1);
        }
        //temperatura
        if (57<arr[3].toInt() && arr[3].toInt()<63)
        {
            QPalette p = ui->Temp->palette();
            p.setColor(QPalette::Base, Qt::green);
            p.setColor(QPalette::Text, Qt::black);
            ui->Temp->setPalette(p);
        }
        else
        {
            QPalette p1 = ui->Temp->palette();
            p1.setColor(QPalette::Base, Qt::red);
            p1.setColor(QPalette::Text, Qt::black);
            ui->Temp->setPalette(p1);
        }
    }
    f.close();
}

void MainWindow::on_Valores_Referencia_clicked()
{

    int cont = 0;

    ui->VALORESTABLE->setColumnCount(4);

    QStringList headers1={"VELOCIDAD","FRECUENCIA","VOLTAJE","TEMPERATURA"};
    ui->VALORESTABLE->setHorizontalHeaderLabels(headers1);

    ui->VALORESTABLE->setRowCount(4);

    QStringList headers2={"VALOR_REF","TOLERANCIA","VALOR_MAX","VALOR_MIN"};
    ui->VALORESTABLE->setVerticalHeaderLabels(headers2);

    QString arr1[16]={"1800","60 HZ","220 V","60°C","5%","5%","10%","5%","1890","63 HZ","231 V","63°C","1710","57 HZ","209 V","57°C"};

    for (int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            ui->VALORESTABLE->setItem( row, col,new QTableWidgetItem (arr1[cont]));
            cont++;
        }

    }
}

void MainWindow::on_VALORESTABLE_cellChanged(){}
void MainWindow::on_Velocidad_textChanged(){}
void MainWindow::on_Frecuencia_textChanged(){}
void MainWindow::on_Voltaje_textChanged(){}
void MainWindow::on_Temp_textChanged(){}
void MainWindow::on_Time_textChanged(){}

