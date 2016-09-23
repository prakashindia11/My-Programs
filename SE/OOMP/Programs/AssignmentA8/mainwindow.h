#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    


private slots:
    void on_bsubmit_clicked();
    
    void on_bdisplay_clicked();

    void on_breset_clicked();

    void on_bsearch_clicked();

    void on_ptdisplay_destroyed();
    
    void on_bdelete_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
