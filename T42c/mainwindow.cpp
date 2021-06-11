#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        m_db = QSqlDatabase::addDatabase("QSQLITE"); //соединение объекта базы данных
                                        // с СУБД
        m_db.setDatabaseName("myDB3");  //определение имени базы данных
        query = new QSqlQuery(m_db); // создание объекта для запроса
        if(!m_db.open()) // проверка на ошибку при открытии или создании базы данных
            throw "can't open database";
        if(!m_db.tables().contains("GAME")) // если в базе не существует таблица  Person,
        { //то создание таблицы  Person и заполнение данными
            query->clear(); // очистка запроса
      query->exec("CREATE TABLE GAME (ID INTEGER PRIMARY KEY, Name VARCHAR, Year INTEGER, parts integer);");  // исполнение запроса на добавление записи
            query->clear();
            query->exec("INSERT INTO GAME (ID,Name,Year, parts) VALUES (1,'PUBG', 2000, 1);");
            query->clear();
            query->exec("INSERT INTO GAME (ID,Name,Year,parts) VALUES (2,'CS-Go', 2003, 2);");
            query->clear();
            query->exec("INSERT INTO GAME (ID,Name,Year,parts) VALUES (3,'Rust',2014,1 );");
            query->clear();
            query->exec("INSERT INTO GAME (ID,Name,Year, parts) VALUES (4,'dota', 2011, 1);");
        }
        model = new QSqlTableModel(this,m_db); // создание
                                      // редактируемой модели базы данных
            model->setTable("GAME"); // создание модели таблицы  Person

            model->select(); // заполнение модели данными
            model->setEditStrategy(QSqlTableModel::OnFieldChange); // выбор стратегии
                            //  сохранения изменений в базе данных
                            //- сохранение происходит при переходе к другому полю
            ui->table->setModel(model); // соединение модели
                            // и ее табличного представления в форме
        }

        MainWindow::~MainWindow()
        {
            delete ui;
               delete query;
               delete model;
           }

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit_name->text().isEmpty()||ui->lineEdit_age->text().isEmpty()||ui->lineEdit_id->text().isEmpty()||ui->lineEdit_parts->text().isEmpty() )
            return;
        QString id = ui->lineEdit_id->text();
        QString name = ui->lineEdit_name->text();
        QString age = ui->lineEdit_age->text();
        QString parts= ui->lineEdit_parts->text();
        QString buf = tr("INSERT INTO GAME (ID,Name,Year,Parts) VALUES (")+id+tr(",'")+name+tr("',")+age+tr(",")+parts+tr(");");

        query->clear();
        query->exec(buf);
        model->select();

}

void MainWindow::on_pushButton_del_clicked()
{
    if(ui->lineEdit_name->text().isEmpty()||ui->lineEdit_age->text().isEmpty()||ui->lineEdit_id->text().isEmpty()||ui->lineEdit_parts->text().isEmpty() )
            return;
    QString id = ui->lineEdit_id_2->text();
    QString name = ui->lineEdit_id_2->text();
    QString age = ui->lineEdit_id_2->text();
    QString parts= ui->lineEdit_id_2->text();
    QString buf = tr("DELETE FROM GAME WHERE ID=")+id+tr(";");

    query->clear();
    query->exec(buf);
    model->select();
}

void MainWindow::on_pushButton_f1_clicked()
{
    model->setFilter("Year>2001");
    model->select();
    ui->table->setModel(model);
}

void MainWindow::on_pushButton_all_3_clicked()
{
    model->setFilter("Year<2001");
    model->select();
    ui->table->setModel(model);
}

void MainWindow::on_pushButton_all_clicked()
{
    model->setFilter("");
    model->select();
    ui->table->setModel(model);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    switch(value)
    {
    case 0:
    {
        model ->setFilter("Year<1950");
        model ->select();
        ui->table->setModel(model);
        break;
    }
    case 1: {
        model ->setFilter ("Year<2029");
        model->select();
        ui->table->setModel(model);
        break;
    }

    case 2: {
        model->setFilter("");
        model->select();
        ui->table->setModel(model);
        break;
    }
    default: {
        model->setFilter("");
        break;
        }
    }
}

