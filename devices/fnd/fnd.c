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

void *t_function(void *data){
        int dev = open(FND_DEVICE, O_RDWR);
        if (dev < 0)
                errx(1, FND_DEVICE ": device open error\n");
        int* difficulty = (int*)data;
        int i = 0;


        if(*difficulty == 3){
                i = 7000;
        }else if(*difficulty == 2){
                i = 5000;
        }else if(*difficulty == 1){
                i = 3000;

        };

        //i = 0xff;



        //i = 0;

        unsigned char str[5] = {1,1,1,1};
        //sprintf(str, "%.3f", sec);


        while(i>=0){
//              fprintf(stdout, "%d\n", i);
                //write(dev,&i,4);
                sprintf(str, "%d",i);
                write(dev,str,4);
                i--;
                usleep(1000);
        }
        close(dev);
        pthread_exit(NULL);
}

int main(){
        int i;
        int status;
        int thr_id;
        int str_size;
        int difficulty = 3;

        pthread_t p_thread;
        thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&difficulty);

        if(thr_id < 0){
                perror("thread create error : ");
                exit(0);
        }

        pthread_join(p_thread, (void **)&status);

        //printf("when it clear!\n");

//      memset(data,0,sizeof(data));

        /*if(argc!=2) {
                printf("please input the parameter! \n");
                printf("ex)./test_led 1234\n");
                return -1;
        }

    str_size=(strlen(argv[1]));
    if(str_size>MAX_DIGIT)
    {
        printf("Warning! 4 Digit number only!\n");
        str_size=MAX_DIGIT;
    }

    for(i=0;i<str_size;i++)
    {
        if((argv[1][i]<0x30)||(argv[1][i])>0x39) {
            printf("Error! Invalid Value!\n");
            return -1;
        }
        data[i]=argv[1][i]-0x30;
    }*/


    /*if (dev<0) {
        printf("Device open error : %s\n",FND_DEVICE);
        exit(1);
    }*/

//      sleep(1);

//      read(dev,&data,4);
        /*if(retval<0) {
                printf("Read Error!\n");
                return -1;
        }*/

//      printf("Current FND Value : ");
//      for(i=0;i<str_size;i++) 
//              printf("0x%x ",data[i]);
        printf("\n");


        return(0);
}
                                   