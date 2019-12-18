#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <err.h>
#include <pthread.h>
static int dev = -1;
void fnd_init(){
    dev = open("/dev/fpga_fnd",O_RDWR);
    if(dev < 0)
        printf("Asdfa");
}

void *t_function(void *data){
    int i = *(int *)data;

    unsigned char str[5] = {1, 1, 1, 1};
    while(i>=0){
        sprintf(str, "%d",i);
        write(dev,str,4);
        i--;
       usleep(1000);
    }
    pthread_exit(NULL);
}
void fnd_destroy(){      
    close(dev);
}
pthread_t *fnd_thread(int num){
    int thr_id;
    pthread_t *p_thread = malloc(sizeof(pthread_t));
    thr_id = pthread_create(p_thread,NULL,t_function,(void *)&num);
    if(thr_id < 0){
        perror("thread create error : ");
        exit(1);
    }

    return p_thread;
}


 
void main(){
 
    fnd_init();
    fnd_thread(5000);
    fnd_destroy();
}
