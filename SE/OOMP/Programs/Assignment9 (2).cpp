Name : Prakash Iyer
Class : SE A
Roll No : 138

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

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

class Television
{
        private :

        int model_no,screen_size,price;

        public :

        void initialize()
        {
            model_no = 0;
            screen_size = 0;
            price = 0;
        }

        friend MainWindow;
};

Television t;

void MainWindow::on_Bsubmit_clicked()
{
    QMessageBox q;

    t.model_no = ui->Tmodelno->text().toInt();
    t.screen_size = ui->Tscreensize->text().toInt();
    t.price = ui->Tprice->text().toInt();

    try
        {
            if(t.screen_size<12 || t.screen_size>70)
            {
                throw 1;
            }

            if(t.price<0 || t.price>5000)
            {
                throw 2;
            }

            if(t.model_no>9999)
            {
                throw 3;
            }
        }
        catch(int n)
        {
            if(n==1)
            {
                t.initialize();
                q.setText("Screen size should be between 12 to 70 inches");
                q.exec();
            }
            else if(n==2)
            {
                t.initialize();
                q.setText("Price should be less than $5000.");
                q.exec();
            }
            else if(n==3)
            {
                t.initialize();
                q.setText("Model number should be less than 5 digits.");
                q.exec();
            }
        }
}

void MainWindow::on_Bdisplay_clicked()
{
        QString display;

        display.append("Model No : "+QString ::number(t.model_no));
        display.append("\nScreen Size : "+QString ::number(t.screen_size));
        display.append("\nPrice : "+QString ::number(t.screen_size));
        ui->plainTextEdit->appendPlainText(display);
}

void MainWindow::on_Breset_clicked()
{
        ui->Tmodelno->clear();
        ui->Tscreensize->clear();
        ui->Tprice->clear();
        ui->plainTextEdit->clear();
}
