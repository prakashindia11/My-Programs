#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list"
#include "QMessageBox"
using namespace std;

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

list<int>lst1;
list<int>lst2;
list<int>::iterator ptr;

void MainWindow::on_Bok1_clicked()
{
    int a;

    a = ui->Tlist1->text().toInt();
    lst1.push_back(a);
    this->ui->Tlist1->clear();
}

void MainWindow::on_Bok2_clicked()
{
    int b;

    b = ui->Tlist2->text().toInt();
    lst2.push_back(b);
    this->ui->Tlist2->clear();
}

void MainWindow::on_Bvl1_clicked()
{
    for(ptr=lst1.begin();ptr!=lst1.end();++ptr)
    {
        this->ui->PTvl1->appendPlainText(QString::number(*ptr));
    }
}

void MainWindow::on_Bvl2_clicked()
{
    for(ptr=lst2.begin();ptr!=lst2.end();++ptr)
    {
        this->ui->PTvl2->appendPlainText(QString::number(*ptr));
    }
}

void MainWindow::on_Bsort_clicked()
{
    lst1.sort();

    for(ptr=lst1.begin();ptr!=lst1.end();++ptr)
    {
        this->ui->PTsort->appendPlainText(QString::number(*ptr));
    }
}

void MainWindow::on_Bmerge_clicked()
{
    lst1.merge(lst2);

    for(ptr=lst1.begin();ptr!=lst1.end();++ptr)
    {
        this->ui->PTmerge->appendPlainText(QString::number(*ptr));
    }
}

void MainWindow::on_Breverse_clicked()
{
    lst1.reverse();

    for(ptr=lst1.begin();ptr!=lst1.end();++ptr)
    {
        this->ui->PTreverse->appendPlainText(QString::number(*ptr));
    }
}

void MainWindow::on_Bremove_clicked()
{
    QMessageBox q;

    while(lst1.empty())
    {
        lst1.pop_front();
    }

    while(lst2.empty())
    {
        lst2.pop_front();
    }

    q.setText("List 1 And List 2 are empty.");
    q.exec();
}

void MainWindow::on_Breset_clicked()
{
    ui->PTvl1->clear();
    ui->PTvl2->clear();
    ui->PTsort->clear();
    ui->PTmerge->clear();
    ui->PTreverse->clear();
}
