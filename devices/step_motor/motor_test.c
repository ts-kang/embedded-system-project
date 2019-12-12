#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>

#define MAX_BUTTON 9
#define MOTOR_ATTRIBUTE_ERROR_RANGE 4
#define FPGA_STEP_MOTOR_DEVICE "/dev/fpga_step_motor"

unsigned char quit = 0;

void usage(char* dev_info);
void init_motor(int* dev2);
void close_motor(int* dev2);
void user_signal1(int sig){

	quit = 1;

}

int main(void){


	int i;
	int dev;
	int buff_size;
	int dev2;
	int str_size;

	int motor_action;
	int motor_direction;
	int motor_speed;

	unsigned char motor_state[3];

	unsigned char push_sw_buff[MAX_BUTTON];

	dev= open("/dev/fpga_push_switch", O_RDWR);

	if(dev < 0){
		printf("Push Switch Open Error\n");
		close(dev);
		return 1;
	}
	init_motor(&dev2);
	(void)signal(SIGINT, user_signal1);

	buff_size = sizeof(push_sw_buff);
	printf("Press ctrl+c to quit.\n");

	while(!quit){

		usleep(400000);
		read(dev, &push_sw_buff, buff_size);

		for(i=0; i<MAX_BUTTON;i++){
		
			if(push_sw_buff[1]==1){
				// 돌아라 스텝모터여
				motor_state[0]=1;
			        motor_state[1]=0;
		       		motor_state[2]=250;	       
				
				write(dev2,motor_state,3);
			}

			if(push_sw_buff[2]==1){
				// 멈춰라 스텝모터여	
				motor_state[0]=0;
                                motor_state[1]=0;
                                motor_state[2]=0;
				
				write(dev2, motor_state, 3);
			}

			printf("[%d] ", push_sw_buff[i]);
		
			if((i+1)%3==0){
				printf("\n");
			}
		}
		printf("---------------\n");
	}
	close(dev);
	close(dev2);
}
void init_motor(int* dev2){

	*dev2 = open(FPGA_STEP_MOTOR_DEVICE,O_WRONLY);
	if(*dev2 < 0){
                  printf("Push Switch Open Error\n");
                 close(*dev2);
        	exit(0);     
	}



}
