#ifndef FORM_H
#define FORM_H

#include <QScreen>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QStatusBar>
#include <QMainWindow>

namespace Ui {
class Form;
}

class Form : public QMainWindow
{
    Q_OBJECT
    
  public:
    explicit Form(QWidget *parent = nullptr);
    void initialization();
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent * event);
    ~Form();
    
  private:
    Ui::Form *ui;
    int timer_id_1, timer_id_2, times[5], state_of_time;
    QString status[5];
    QStatusBar *bar;
};

#endif // FORM_H
