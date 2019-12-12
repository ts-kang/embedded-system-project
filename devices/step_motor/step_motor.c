#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>

#define MOTOR_ATTRIBUTE_ERROR_RANGE 4
#define FPGA_STEP_MOTOR_DEVICE "/dev/fpga_step_motor"
unsigned char quit = 0;

void step_motor_init(int* dev);
void step_motor_destroy(int* dev2);
void step_motor_run(unsigned char* motor_state, int* dev);
void step_motor_stop(unsigned char* motor_state, int* dev);
void user_signal1(int sig){
	quit = 1;
}
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
void step_motor_stop(unsigned char * motor_state, int* dev){
	motor_state[0] = 0;
        motor_state[1]= 0;
        motor_state[2] = 0;
        write(*dev, motor_state, 3);

}

void step_motor_run(unsigned char * motor_state, int* dev){
	motor_state[0] = 1;
	motor_state[1] = 0;
	motor_state[2] = 250;
	write(*dev, motor_state, 3);
}
void step_motor_destroy(int * dev){
	close(*dev);
}

void step_motor_init(int* dev){
	 *dev = open(FPGA_STEP_MOTOR_DEVICE,O_WRONLY);
        if(*dev < 0){
                printf("Push Switch Open Error\n");
		close(*dev);
		exit(0);
	}
}

