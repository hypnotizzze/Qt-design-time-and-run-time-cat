#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  forma_1 = new Form;
  forma_2 = new Run_Time;  
}

MainWindow::~MainWindow()
{
  delete forma_1;
  delete forma_2;
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  forma_1->initialization();
  forma_1->show();
}

void MainWindow::on_pushButton_2_clicked()
{
  forma_2->initialization();
  forma_2->show();
}
