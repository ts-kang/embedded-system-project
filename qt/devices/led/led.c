/* FPGA LED Test Application
File : fpga_test_led.c*/

#include <err.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LED_DEVICE "/dev/fpga_led"

static int data, count, temp;
static int dev = -1;

void led_init() {
	dev = open(LED_DEVICE, O_RDWR);
	if (dev < 0) {
		printf("push switch device open ERROR!!\n");
		close(dev);
		return -1;
	}
}

void led_destroy() {
	close(dev);
}

pthread_t *led_thread(){
     int thr_id;
     int num;
     pthread_t *p_thread = malloc(sizeof(pthread_t));
     thr_id = pthread_create(p_thread, NULL, t_function, (void*)num);
     if(thr_id<0){
        perror("thread create error : ");
        exit(1);
     }
     return &pthread;
}

void *t_function(void *data){
    int i = 10;
    data = 0; count = 0; temp = 0;
    while(i > 0){
        data = temp * 2 + 1;
        if(data==511){
            data = 0;
            temp = 0;
            count++;
            if(count==3)
                break;
        }   
        temp = data;
        write(dev, *data, 1);
        usleep(100000);
    }
    pthread_exit(NULL);
}
  
