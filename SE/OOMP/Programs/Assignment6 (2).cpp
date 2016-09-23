#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

class Person
{
    private :

        QString name,dob,bg;
        int height,weight,cno;

    public :

        friend MainWindow;
};

Person p[50];
int c=0;
void MainWindow::on_Bsubmit_clicked()
{
    QMessageBox q;

    p[c].name = ui->Tname->text();
    p[c].dob = ui->Tdob->text();
    p[c].bg = ui->Tbg->text();
    p[c].height = ui->Theight->text().toInt();
    p[c].weight = ui->Tweight->text().toInt();
    p[c].cno = ui->Tcontactno->text().toInt();

    c++;

    q.setText("Data submitted successfully.");
    q.exec();

    on_Breset_clicked();
}

void MainWindow::on_Bdisplay_clicked()
{
    int i;
    QString display;

    for(i=0;i<c;i++)
    {
        display.append("Name : "+p[i].name);
        display.append("\nDOB : "+p[i].dob);
        display.append("\nBlood Group : "+p[i].bg);
        display.append("\nHeight : "+QString::number(p[i].height));
        display.append("\nWeight : "+QString::number(p[i].weight));
        display.append("\nContact No : "+QString::number(p[i].cno)+"\n\n");

        ui->PT->appendPlainText(display);
    }
}

void MainWindow::on_Breset_clicked()
{
    ui->Tname->clear();
    ui->Tdob->clear();
    ui->Tbg->clear();
    ui->Theight->clear();
    ui->Tweight->clear();
    ui->Tcontactno->clear();
    ui->PT->clear();;
}