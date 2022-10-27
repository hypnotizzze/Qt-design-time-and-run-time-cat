#ifndef RUN_TIME_H
#define RUN_TIME_H

#include <QScreen>
#include <QLabel>
#include <QTimer>
#include <QTimerEvent>
#include <QSettings>
#include <QVariant>
#include <QApplication>
#include <QStatusBar>
#include <QMainWindow>
#include <QtDebug>

class Run_Time : public QMainWindow
{
    Q_OBJECT
    
  public:
    explicit Run_Time(QWidget *parent = nullptr);
    void initialization();
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent * event);
    ~Run_Time();
    
  private:
    int timer_id_1, timer_id_2, times[5], state_of_time;
    QLabel *label;
    QString status[5];
    QStatusBar *bar;
};

#endif // RUN_TIME_H
