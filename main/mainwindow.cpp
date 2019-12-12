#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->Dip_1->setValue(0);
    QPixmap bg(":/prefix1/1.png");
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);
    //setAutoFillBackground(true);
    setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this.close();
}
