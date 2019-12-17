#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>
extern "C" {
#include <devices/dip_switch.h>
#include <devices/step_motor.h>
}


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Active_BT_toggled();
     void update();
    void on_Close_BT_clicked();
    void on_gameStartBt_clicked();
    void startGame();
    void on_setFlag_clicked();
    void success();
    void fail();


private:
    Ui::MainWindow *ui;
    QMessageBox msgBox;
    QTimer *timer ;
    unsigned char flag, time;

};

#endif // MAINWINDOW_H
