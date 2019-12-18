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
    ui->setFlag->setHidden(true);
    ui->setFlag->setEnabled(false);
    ui->setTime->setHidden(true);
    ui->setTime->setEnabled(false);
    ui->gameStartBt->setHidden(true);
    ui->flagTextBack->setHidden(true);
    ui->timeTextBack->setHidden(true);

    dip_switch_init();
    //step_motor_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// dip switch function
void MainWindow::setFlag()
{
    ui->flagText->setHidden(false);
    ui->timeText->setHidden(false);

    unsigned char temp = dip_switch_get();
    temp = 0b01111111;
    switch(temp){
    case 0b01111111:
        ui->flagText->setText(" 1 ");
        ui->setFlag->setEnabled(true);
        flag = 3;
        break;
    case 0b10111111:
        ui->flagText->setText(" 2 ");
        ui->setFlag->setEnabled(true);
        flag = 9;
        break;
    case 0b11011111:
        ui->flagText->setText(" 3 ");
        ui->setFlag->setEnabled(true);
        flag = 27;
        break;
    default:
        ui->flagText->setText(" Invalid ");
        ui->setFlag->setEnabled(false);
        flag = 0;
    }
}
void MainWindow::setTime()
{

    unsigned char temp = dip_switch_get();
    temp =1;
    switch(temp){
    case 0b11101111:
        ui->timeText->setText(" 5 " );
        ui->setTime->setEnabled(true);
        time = 50000;
        break;
    case 0b11110111:
        ui->timeText->setText(" 3 " );
        ui->setTime->setEnabled(true);
        time = 30000;
        break;
    case 0b11111011:
        ui->timeText->setText(" 1 " );
        ui->setTime->setEnabled(true);
        time = 10000;
        break;
    case 0b11111101:
        ui->timeText->setText(" 0.5 " );
        ui->setTime->setEnabled(true);
        time = 5000;
        break;
    default:
        ui->flagText->setText(" Invalid ");
        ui->setTime->setEnabled(false);
        time = 0;
    }
}

void MainWindow::startGame(){

    //rand
    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    int problem = qrand()%flag + 1;
    int count =0;

    // Set Image
    QString image;
    switch(problem){
    case 1: image = ":/new/prefix1/";
    case 2: image = ":/new/prefix1/";
    case 3: image = ":/new/prefix1/";
    case 4: image = ":/new/prefix1/";
    case 5: image = ":/new/prefix1/";
    case 6: image = ":/new/prefix1/";
    case 7: image = ":/new/prefix1/";
    case 8: image = ":/new/prefix1/";
    case 9: image = ":/new/prefix1/";
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
    // step_motor_run();
    // buzzer_run();
    // camera
}

void MainWindow::fail(){
    // led
    // dot matrix
}

void MainWindow::on_Active_BT_clicked(){

    ui->Active_BT->setVisible(false);
    ui->flagTextBack->setHidden(false);
    ui->timeTextBack->setHidden(false);
    ui->setFlag->setHidden(false);
    ui->setTime->setHidden(false);

    //set background
    QPixmap bg(":/new/prefix1/2.png");
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);
    setPalette(p);

    //for getting dip switch status
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(setFlag()));
    timer->start(100);
}

void MainWindow::on_Close_BT_clicked(){

    dip_switch_destroy();
    //step_motor_destroy();
    this->close();
}

void MainWindow::on_gameStartBt_clicked()
{
    ui->flagText->resize(0,0);

    //ui->flagTextBack->resize(0,0);
    // call funtion startGame
    //startGame();
}

void MainWindow::on_setFlag_clicked(){

    // stop getting flag value
    timer->stop();

    // set Buttons Status
    ui->setFlag->setEnabled(false);
    ui->setTime->setEnabled(true);

    // start getting time
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(setTime()));
    timer->start(100);
}

void MainWindow::on_setTime_clicked(){

    // stop getting time value
    timer->stop();

    // set setTime Button Status
    ui->setTime->setEnabled(false);

    // show StartGame button
    ui->gameStartBt->setVisible(true);
}
