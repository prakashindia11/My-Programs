#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "PersonDB.cpp"

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

void MainWindow::on_bAddNewPerson_clicked()
{

    //All Fields Are Blank
    if(this->ui->tfName->text().length()==0 || this->ui->tfDob->text().length()==0 ||
            this->ui->tfHeight->text().length()==0 || this->ui->tfWeight->text().length()==0)
    {
        QMessageBox::warning(NULL,QString("Error"),QString("Fill All The Details"));
    }
    else{

    PersonPtr = new PersonDB();
    PersonPtr->sName=this->ui->tfName->text().toStdString();
    PersonPtr->sDob=this->ui->tfDob->text().toStdString();
    PersonPtr->iWeight=this->ui->tfWeight->text().toInt();
    PersonPtr->iHeight=this->ui->tfHeight->text().toInt();

    ltPerson.push_back(PersonPtr);


    this->ui->tfName->setText("");
    this->ui->tfDob->setText("");
    this->ui->tfWeight->setText("");
    this->ui->tfHeight->setText("");

    QMessageBox qmAdded;
    qmAdded.setText("Added");
    qmAdded.show();
        }
}



void MainWindow::on_bShowPersonDatabase_clicked()
{
    ui->taPersonList->clear();
    QString qsName,qsDob,qsWeight,qsHeight;
    for(itPerson = ltPerson.begin(); itPerson != ltPerson.end(); itPerson++)
    {
        qsName = QString::fromStdString((*itPerson)->sName);
        qsDob = QString::fromStdString((*itPerson)->sDob);
        qsWeight = QString::number((*itPerson)->iWeight);
        qsHeight = QString::number((*itPerson)->iHeight);

        this->ui->taPersonList->appendPlainText(qsName+"\t\t"+qsDob+"\t\t"+qsWeight+"\t\t"+qsHeight);
    }
}
