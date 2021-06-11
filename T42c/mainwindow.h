#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

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
    void on_pushButton_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_f1_clicked();

    void on_pushButton_all_3_clicked();

    void on_pushButton_all_clicked();

    void on_Year_actionTriggered(int action);

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_actionTriggered(int action);

    void on_checkBox_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db; // объект базы данных
    QSqlQuery* query;  // указатель на запос
    QSqlTableModel* model; // указатель на таблиу данных
};

#endif // MAINWINDOW_H
