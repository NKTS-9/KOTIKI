#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

#define PI 3.14

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->pushButtonpro,SIGNAL(clicked()),this,SLOT(operatioms()));
    connect(ui->pushButton_znak,SIGNAL(clicked()),this,SLOT(operatioms()));
    connect(ui->pushButton_dele,SIGNAL(clicked()),this,SLOT(mathoperations()));
    connect(ui->pushButtonumno,SIGNAL(clicked()),this,SLOT(mathoperations()));
    connect(ui->pushButtonplus,SIGNAL(clicked()),this,SLOT(mathoperations()));
    connect(ui->pushButtonminus,SIGNAL(clicked()),this,SLOT(mathoperations()));
    connect(ui->pushButtontg,SIGNAL(clicked()),this,SLOT(mathoperations()));
    connect(ui->pushButtonstep,SIGNAL(clicked()),this,SLOT(mathoperations()));
    connect(ui->pushButtonstepExp,SIGNAL(clicked()),this,SLOT(mathoperations()));
    connect(ui->pushButtonsteplog,SIGNAL(clicked()),this,SLOT(mathoperations()));

    ui->pushButton_dele->setCheckable(true);
    ui->pushButtonumno->setCheckable(true);
    ui->pushButtonplus->setCheckable(true);
    ui->pushButtonminus->setCheckable(true);
    ui->pushButtontg->setCheckable(true);
    ui->pushButtonstep->setCheckable(true);
    ui->pushButtonstepExp->setCheckable(true);
    ui->pushButtonsteplog->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::numbers()
{
    QPushButton *button = (QPushButton *) sender();

    double all_numbers;
    QString new_lable;

    all_numbers = (ui->result->text() + button->text()).toDouble();
    new_lable = QString::number(all_numbers, 'g', 15);
    ui->result->setText (new_lable);//тк нельзя вывести переменную - мы создаем строку которой присваиваем значение
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result->text().contains('.')))
    ui->result->setText (ui->result->text() + ".");
}
void MainWindow::operatioms()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    QString new_lable;

    if(button->text() == "+/-") {
    all_numbers = (ui->result->text()).toDouble();
    all_numbers = all_numbers * -1;
    new_lable = QString::number(all_numbers, 'g', 15);
    ui->result->setText (new_lable);//тк нельзя вывести переменную - мы создаем строку которой присваиваем значение
    }
    else if (button->text() == "%") {
        all_numbers = (ui->result->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->result->setText (new_lable);
}

}

void MainWindow::mathoperations()
{
     QPushButton *button = (QPushButton *) sender();


     num_first = ui->result->text().toDouble();
     ui->result->setText("");

     button->setChecked(true);


}

void MainWindow::on_pushButton_clean_clicked()
{
        ui->pushButtonumno->setChecked(false);
        ui->pushButton_dele->setChecked(false);
        ui->pushButtonplus->setChecked(false);
        ui->pushButtonminus->setChecked(false);

        ui->result->setText("0");
}

void MainWindow::on_pushButtonrovno_clicked()
{
    double lableNumber, num_second;
    QString new_lable;

    num_second = ui->result->text().toDouble();

        if(ui->pushButtonplus->isChecked()) {
            lableNumber = num_first + num_second;
            new_lable = QString::number(lableNumber, 'g', 15);

            ui->result->setText (new_lable);
            ui->pushButtonplus->setChecked(false);
    }
        else if(ui->pushButtonminus->isChecked()) {
            lableNumber = num_first - num_second;
            new_lable = QString::number(lableNumber, 'g', 15);

            ui->result->setText (new_lable);
            ui->pushButtonminus->setChecked(false);
    }
        else if(ui->pushButton_dele->isChecked()) {
            if (num_second == 0) {ui->result->setText("Otkazano");}
            else {
            lableNumber = num_first / num_second;
            new_lable = QString::number(lableNumber, 'g', 15);

            ui->result->setText (new_lable);
            }
            ui->pushButton_dele->setChecked(false);

    }   else if(ui->pushButtonumno->isChecked()) {
            lableNumber = num_first * num_second;
            new_lable = QString::number(lableNumber, 'g', 15);

            ui->result->setText (new_lable);
            ui->pushButtonumno->setChecked(false);

    }
        else if(ui->pushButtontg->isChecked()) {
                    lableNumber = tan(num_first * PI/180);
                    new_lable = QString::number(lableNumber, 'g', 15);

                    ui->result->setText (new_lable);
                    ui->pushButtontg->setChecked(false);

            }
        else if(ui->pushButtonstep->isChecked()) {
                    lableNumber = pow (num_first, num_second);
                    new_lable = QString::number(lableNumber, 'g', 15);

                    ui->result->setText (new_lable);
                    ui->pushButtontg->setChecked(false);

            }
        else if(ui->pushButtonstepExp->isChecked()) {
                    lableNumber = exp(num_first);
                    new_lable = QString::number(lableNumber, 'g', 15);

                    ui->result->setText (new_lable);
                    ui->pushButtonstepExp->setChecked(false);

            }
        else if(ui->pushButtonsteplog->isChecked()) {
                    lableNumber = log(num_first);
                    new_lable = QString::number(lableNumber, 'g', 15);

                    ui->result->setText (new_lable);
                    ui->pushButtonsteplog->setChecked(false);

            }
}

int n=1;

void MainWindow::on_pushButton_znak_clicked()
{
    if (n==1) { ui->pushButton_znak->setStyleSheet("background-color:green"); n++;}
        else{ if (n==2) {ui->pushButton_znak->setStyleSheet("background-color:blue"); n++;}
        else{ if (n==3) {ui->pushButton_znak->setStyleSheet("background-color:violet"); n++;}
        else{ if (n==4) {ui->pushButton_znak->setStyleSheet("background-color:grey"); n++;}
        else{ if (n==5) {ui->pushButton_znak->setStyleSheet("background-color:pink"); n++;}
        else{ if (n==6) {ui->pushButton_znak->setStyleSheet("background-color:light lue"); n++;}
        else{ if (n==7) {ui->pushButton_znak->setStyleSheet("background-color:yellow"); n++;}
        else{ if (n==8) {ui->pushButton_znak->setStyleSheet("background-color:"); n++;}
        else{ if (n==9) {ui->pushButton_znak->setStyleSheet("background-color:brown"); n++;}
        else{ if (n==10) {ui->pushButton_znak->setStyleSheet("background-color:orange"); n++;}
        else{ if (n==11) {ui->pushButton_znak->setStyleSheet("background-color:white"); n++;}
        else{ if (n==12) {ui->pushButton_znak->setStyleSheet("background-color:purple"); n=1;}}}}}}}}}}}}}




void MainWindow::on_pushButton_0_clicked()
{
   }


