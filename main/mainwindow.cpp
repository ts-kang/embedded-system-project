#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->timeText->setHidden(true);
    ui->flagText->setHidden(true);
   // unsigned char level;
    ui->gameStartBt->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// dip switch function
void MainWindow::update()
{
    ui->flagText->setHidden(false);
    ui->timeText->setHidden(false);
    // level get_dip();

    switch(level){
    case 17:
        ui->flagText->setText(" TEST ");
    case 33:
    case 65:
    case 129:
    case 18:
    case 34:
    case 66:
    case 130:
    case 20:
    case 36:
    case 68:
    case 132:
    default:
    }
}

/*void MainWindow::startGame(int level){

    // rand
    // level
    // background

    // push switch

    // if
    // success
    // fail
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
*/
void MainWindow::on_Active_BT_toggled()
{
    ui->Active_BT->setHidden(true);
    QPixmap bg(":/new/prefix1/2.png");
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);
    //setAutoFillBackground(true);
    setPalette(p);
    ui->gameStartBt->setHidden(false);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

void MainWindow::on_Close_BT_clicked()
{
    this->close();
}

void MainWindow::on_gameStartBt_clicked()
{
    timer->stop();
    //SLOT(startGame());
}
