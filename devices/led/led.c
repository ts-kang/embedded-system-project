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

int data, count, temp;

void *t_function(void *d){
        int dev = open(LED_DEVICE, O_RDWR);
        int i=10;
        if (dev<0) {
                printf("Device open error : %s\n",LED_DEVICE);
                exit(1);
        }

        data = 0; count = 0; temp = 0;
        while(i > 0){
            data = temp * 2 + 1;
            if(data == 511){
                    data = 0;
                    temp = 0;
                    count++;
                    if(count==3)
                            break;

            }
            temp = data;
            write(dev, &data, 1);
            usleep(100000);
        }
          close(dev);
        pthread_exit(NULL);
}


int main()
{

        int index;
        int status;
        //int a = 127;
        int i = 0, thr_id;
        //int data = 0, count = 0, temp = 0;
        //unsigned char data;
        pthread_t p_thread;
        thr_id = pthread_create(&p_thread, NULL, t_function, (void*)&i);
             if(thr_id < 0){
                perror("thread create error : ");
                exit(0);
        }

        pthread_join(p_thread, (void **)&status);



        /*if(argc!=2) {
                printf("please input the parameter! \n");
                printf("ex)./test_led 7 (0~255)\n");
                return -1;
        }
                if(thr_id < 0){
                perror("thread create error : ");
                exit(0);
        }

        pthread_join(p_thread, (void **)&status);



        /*if(argc!=2) {
                printf("please input the parameter! \n");
                printf("ex)./test_led 7 (0~255)\n");
                return -1;
        }
              
       
        data = atoi(argv[1]);
        if((data<0)||(data>0xff))
        {
                printf("Invalid range!\n");
        exit(1);
    }*/

   /*
    retval=write(dev,&data,1);  
    if(retval<0) {
        printf("Write Error!\n");
        return -1;
    }*/
   //write(dev, &a,1);
    //printf("%d\n",data);
    //sleep(1);
        //write(dev, &a, 1);
    //data=0;
    /*retval=read(dev,&data,1);
    if(retval<0) {
        printf("Read Error!\n");
                                      
        return -1;
    }*/
    //printf("Current LED Value : 0x%x\n",data);

    printf("\n");

    return(0);
}
     