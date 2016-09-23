Name : 
Class : SE A
Roll No : 


#include "mainwindow.h"
#include "ui_mainwindow.h"

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

class student
{
    protected :

    QString name,subject,rollno;

    friend MainWindow;
};

class studentinfo : public student
{
    private :

    QString subcode,imarks,emarks;

    public :

    friend MainWindow;
};

studentinfo s[50];
int i=0;
int count=0;
QString srollno,drollno,erollno;

void MainWindow::on_bsubmit_clicked()
{
    QString display;

    s[i].name=ui->tname->text();
    s[i].rollno=ui->trollno->text();
    s[i].subject=ui->tsubject->text();
    s[i].subcode=ui->tsubcode->text();
    s[i].imarks=ui->timarks->text();
    s[i].emarks=ui->temarks->text();

    ui->tname->clear();
    ui->trollno->clear();
    ui->tsubject->clear();
    ui->tsubcode->clear();
    ui->timarks->clear();
    ui->temarks->clear();

    ui->ptdisplay->clear();
    display.append("Record submitted successfully.");
    ui->ptdisplay->appendPlainText(display);

    i++;
    count++;
}

void MainWindow::on_bdisplay_clicked()
{
    QString display;
    ui->ptdisplay->clear();
    for(i=0;i<count;i++)
    {
        display.append("Name : "+s[i].name+"\n");
        display.append("Roll No : "+s[i].rollno+"\n");
        display.append("Subject : "+s[i].subject+"\n");
        display.append("Subject Code : "+s[i].subcode+"\n");
        display.append("Internal Marks : "+s[i].imarks+"\n");
        display.append("External Marks : "+s[i].emarks+"\n\n");

        ui->ptdisplay->appendPlainText(display);
    }
}

void MainWindow::on_breset_clicked()
{
    ui->tname->clear();
    ui->trollno->clear();
    ui->tsubject->clear();
    ui->tsubcode->clear();
    ui->timarks->clear();
    ui->temarks->clear();
    ui->ptdisplay->clear();
    ui->drollno->clear();
    ui->srollno->clear();
    ui->erollno->clear();
}


void MainWindow::on_bsearch_clicked()
{
    QString display;

    ui->ptdisplay->clear();
    srollno = ui->srollno->text();

    if(count==0)
    {
        display.append("Record not found");
        ui->ptdisplay->appendPlainText(display);
    }

    for(i=0;i<count;i++)
    {
        if(srollno==s[i].rollno)
        {

            display.append("Name : "+s[i].name+"\n");
            display.append("Roll No : "+s[i].rollno+"\n");
            display.append("Subject : "+s[i].subject+"\n");
            display.append("Subject Code : "+s[i].subcode+"\n");
            display.append("Internal Marks : "+s[i].imarks+"\n");
            display.append("External Marks : "+s[i].emarks+"\n\n");

            ui->ptdisplay->appendPlainText(display);

            break;
        }
    }
}

void MainWindow::on_bdelete_clicked()
{
    QString display;
    int j;

    ui->ptdisplay->clear();
    drollno=ui->drollno->text();

    for(i=0;i<count;i++)
    {
        if(drollno==s[i].rollno)
        {
            for(j=0;j<count;j++)
            {
                s[j]=s[j+1];
            }

            display.append("Record of roll no "+drollno+" deleted successfully.");
            ui->ptdisplay->appendPlainText(display);

            break;
        }
    }

    count--;
}

void MainWindow::on_bedit_clicked()
{
    QString display;

    ui->ptdisplay->clear();
    erollno = ui->erollno->text();

    if(count==0)
    {
        display.append("Record not found");
        ui->ptdisplay->appendPlainText(display);
    }

    for(i=0;i<count;i++)
    {
        if(erollno==s[i].rollno)
        {
            ui->ptdisplay->clear();

            ui->tname->setText(s[i].name);
            ui->trollno->setText(s[i].rollno);
            ui->tsubject->setText(s[i].subject);
            ui->tsubcode->setText(s[i].subcode);
            ui->timarks->setText(s[i].imarks);
            ui->temarks->setText(s[i].emarks);

            display.append("Please edit the given data and click submit.");
            ui->ptdisplay->appendPlainText(display);
            count--;
            break;
        }
    }
}
