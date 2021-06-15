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
    void on_pushButton_0_clicked();
    void numbers ();
    void on_pushButton_dot_clicked();
    void operatioms();
    void on_pushButton_znak_clicked();
    void on_pushButton_clean_clicked();
    void on_pushButtonrovno_clicked();
    void mathoperations();

    void on_pushButton_dele_2_clicked();


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
