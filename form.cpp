#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Form)
{
  ui->setupUi(this);
  times[0]=times[1]=times[2]=times[3]=times[4]=3000;
  state_of_time=0;
  status[0]="Это рыжий кот";
  status[1]="Его зовут Винсент";
  status[2]="Он сидит в раковине";
  status[3]="Он не испытывает чувство вины";
  status[4]="Винсент хочет пить!";
}

Form::~Form()
{
  delete ui;
}

void Form::initialization()
{
  bar = new QStatusBar(this);
  this->bar->showMessage(status[0]);
  bar->setStyleSheet("QStatusBar{background:rgba(0,0,0,128);color:red;font-weight:bold;font-size:20px;}");
  this->setStatusBar(bar);
  timer_id_1 = startTimer(25000);
  timer_id_2 = startTimer(times[state_of_time]);
  QRect src = QApplication::screens().at(0)->geometry();
  int height = src.height();
  int width = src.width();
  this->setGeometry(width/4, height/4, width/2, height/2);
  this->ui->label->setGeometry(0, 0, this->width(), this->height());
  QPixmap mypix(":/Vinc.png");  
  mypix = mypix.scaled(this->width(), this->height(), Qt::KeepAspectRatio);
  ui->label->setPixmap(mypix);
}

void Form::timerEvent(QTimerEvent *event)
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

void Form::mousePressEvent(QMouseEvent * event)
{
  this->close();
}
