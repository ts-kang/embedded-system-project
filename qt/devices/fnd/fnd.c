/* FPGA FND Test Application
File : fpga_test_fnd.c*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <err.h>

#define FND_DEVICE "/dev/fpga_fnd"

void fnd_init() {
	dev = open(LED_DEVICE, O_RDWR);
	if (dev < 0) {
		printf("push switch device open ERROR!!\n");
		close(dev);
		return -1;
	}
}

void fnd_destroy() {
	close(dev);
}

void *fnd_thread(void *data){
       int* num = (int*)data;
        int i = *num;

        

        unsigned char str[5] = {1,1,1,1};
  
        while(i>=0){
               sprintf(str, "%d",i);
                write(dev,str,4);
                i--;
                usleep(1000);
        }
        pthread_exit(NULL);
}