#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "form.h"
#include "run_time.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
  private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();
    
  private:
    Ui::MainWindow *ui;
    Form *forma_1;
    Run_Time *forma_2;
};
#endif // MAINWINDOW_H
