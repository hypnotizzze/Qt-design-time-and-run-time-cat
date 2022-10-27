#include "run_time.h"

Run_Time::Run_Time(QWidget *parent) : QMainWindow(parent)
{
}

Run_Time::~Run_Time()
{
  delete label;
  delete bar;
}

void Run_Time::initialization()
{
  QSettings set(":/config.ini", QSettings::IniFormat);
  set.setIniCodec("UTF-8");
  QRect src = QApplication::screens().at(0)->geometry();
  int height = src.height();
  int width = src.width();
  this->setGeometry(width/4, height/4, width/2, height/2);
  label = new QLabel(this);
  this->label->setGeometry(0, 0, this->width(), this->height());
  set.beginGroup("Section1");
  QPixmap mypix(set.value("img_path").toString());
  mypix = mypix.scaled(this->width(), this->height(), Qt::KeepAspectRatio);
  label->setPixmap(mypix);
  timer_id_1=startTimer(set.value("widget_timer").toInt());
  state_of_time=0;
  times[0]=set.value("times_0").toInt();
  times[1]=set.value("times_1").toInt();
  times[2]=set.value("times_2").toInt();
  times[3]=set.value("times_3").toInt();
  times[4]=set.value("times_4").toInt();
  status[0]=set.value("status_0").toString();
  status[1]=set.value("status_1").toString();
  status[2]=set.value("status_2").toString();
  status[3]=set.value("status_3").toString();
  status[4]=set.value("status_4").toString();
  timer_id_2=startTimer(times[0]);
  set.endGroup();
  qDebug() << status[0];
  bar = new QStatusBar(this);
  this->bar->showMessage(status[0]);
  bar->setStyleSheet("QStatusBar{background:rgba(0,0,0,128);color:red;font-weight:bold;font-size:20px;}");
  this->setStatusBar(bar);
}

void Run_Time::timerEvent(QTimerEvent *event)
{
  if (event->timerId() == timer_id_1)
    {
      this->close();
    }
  else if(event->timerId() == timer_id_2)
    {
      if(state_of_time == 4) {
        state_of_time = 0;
        bar->showMessage(status[state_of_time]);
        timer_id_2 = startTimer(times[state_of_time]);
      }
      else {
        state_of_time++;
        bar->showMessage(status[state_of_time]);
        timer_id_2 = startTimer(times[state_of_time]);
      }
    }
}

void Run_Time::mousePressEvent(QMouseEvent *event)
{
  this->close();
}
