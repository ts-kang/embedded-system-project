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
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t *fnd_thread(int num){
      int thr_id;
      pthread_t *p_thread = malloc(sizeof(pthread_t));
      thr_id = pthread_create(p_thread,NULL,t_function,(void *)num);
      if(thr_id < 0){
         perror("thread create error : ");
         exit(1);
     }  
     return &pthread_t;
}
 
void *t_function(void *data){
    int i = (int)data;

    unsigned char str[5] = {1, 1, 1, 1};
    while(i>=0){
        sprintf(str, "%d",i);
        write(dev,str,4);
        i--;
        usleep(1000);
    }
    pthread_exit(NULL);
}