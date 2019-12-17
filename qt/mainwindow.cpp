#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->timeText->setHidden(true);
    ui->flagText->setHidden(true);
    ui->timeText->setHidden(true);
    ui->setFlag->setEnabled(false);
    ui->setTime->setEnabled(false);
    ui->gameStartBt->setHidden(true);

    dip_switch_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// dip switch function
void MainWindow::update()
{
    QString temp;
    ui->flagText->setHidden(false);
    ui->timeText->setHidden(false);

    flag = dip_switch_get();
    temp = (QString)flag;
    ui->flagText->setText(temp);
    /*
    switch(flag){
    case 1:
        ui->flagText->setText(" 1 ");
        ui->setFlag->setEnabled(true);
        break;
    case 0b00000010:
        ui->flagText->setText(" 2 ");
        ui->setFlag->setEnabled(true);
        break;
    case 0b00000100:
        ui->flagText->setText(" 3 ");
        ui->setFlag->setEnabled(true);
        break;
    default:
        ui->flagText->setText(" Check ");
        ui->setFlag->setEnabled(false);
    }
    */
/*
    time = dip_switch_get();

    switch(time){
    case 1:
        ui->timeText->setText(" 5 " );
        ui->setTime->setEnabled(false);
        break;
    case 2:
        ui->timeText->setText(" 3 " );
        ui->setTime->setEnabled(false);
        break;
    case 4:
        ui->timeText->setText(" 1 " );
        ui->setTime->setEnabled(false);
        break;
    case 8:
        ui->timeText->setText(" 0.5 " );
        ui->setTime->setEnabled(false);
        break;
    default:
        ui->flagText->setText(" Check ");
    }

    ui->gameStartBt->setHidden(false);
    */
}

void MainWindow::startGame(){

    // rand
    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    int problem = qrand()%26;

    int count =0;

    // Set Image
    QString image;
    switch(problem){
    case 1: image = "";
    case 2: image = "";
    case 3: image = "";
    case 4: image = "";
    }

    // Show background
    QPixmap bg(image);
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);
    setPalette(p);

    // push switch

    if(count == 5)
        SLOT(success());
    else if(count <5)
        SLOT(fail());
}
void MainWindow::success(){

    // stepMotor Start
    // buzzer
    // camera
}

void MainWindow::fail(){
    // led
    // dot matrix
}

void MainWindow::on_Active_BT_toggled()
{
    ui->Active_BT->setHidden(true);
    QPixmap bg(":/new/prefix1/2.png");
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);
    //setAutoFillBackground(true);
    setPalette(p);
 //   int dev_step;
 //   unsigned char motor_state[3];
 //   step_motor_init(&dev_step);
 //   step_motor_run(motor_state, &dev_step);
    timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

void MainWindow::on_Close_BT_clicked()
{
    dip_switch_destroy();
    this->close();
}

void MainWindow::on_gameStartBt_clicked()
{
    timer->stop();
    SLOT(startGame());
}

void MainWindow::on_setFlag_clicked()
{
    ui->setTime->setEnabled(true);
}
