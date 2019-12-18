#include <devices/step_motor.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


/*
void main(){
    int dev = 0;
    unsigned char motor_state[3];
    step_motor_init(&dev);
    step_motor_run(motor_state, &dev);
    (void)signal(SIGINT, user_signal1);
    while(!quit){
        }
    step_motor_stop(motor_state, &dev);
    step_motor_destroy(&dev);
}
*/

static int dev = -1
static unsigned char motor_state_stop[3] = {0, 0, 0};
static unsigned char motor_state_run[3] = {1, 0, 250};

void step_motor_stop(){
        write(dev, motor_state_stop, 3);

}

void step_motor_run(){
    write(dev, motor_state_run, 3);
}
void step_motor_destroy(){
    close(dev);
}

void step_motor_init(){
     dev = open("/dev/fpga_step_motor",O_RDWR);
        if(dev < 0){
                printf("/dev/fpga_step_motor: Device Open Error\n");
        exit(1);
    }
}
