#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>

#define FPGA_DIP_SWITCH_DEVICE "/dev/fpga_dip_switch"
#define MOTOR_ATTRIBUTE_ERROR_RANGE 4
#define FPGA_STEP_MOTOR_DEVICE "/dev/fpga_step_motor"

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

private:
    Ui::MainWindow *ui;
    int dev_dip, dev_step, dev_led, dev_push;
    unsigned char dip_sw_buff;
    QMessageBox msgBox;
    int motor_action;
    int motor_direction;
    int motor_speed;
    unsigned char motor_state[3];
    QTimer *timer ;
};

#endif // MAINWINDOW_H
