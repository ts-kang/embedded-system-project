#include <devices/push_switch.h>

/* FPGA Push Switch Test Application
File : fpga_test_push.c*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>
#include <signal.h>

#define MAX_BUTTON 9
unsigned char quit = 0;
static int dev = -1;

void user_signal1(int sig)
{
	quit = 1;
}

void push_switch_init(); //device open
void push_switch_destroy(); //device close
void push_switch_run(); //device movinggg

int main() //최종 메인에 리턴은 true, false
{
	push_switch_init();
	(void)signal(SIGINT, user_signal1);

	while (!quit) {
		push_switch_run();
	}
	push_switch_destroy();
}

void push_switch_init() {
	dev = open("/dev/fpga_push_switch", O_RDWR);
	if (dev < 0) {
		printf("push switch device open ERROR!!\n");
		close(dev);
		return -1;
	}
}

void push_switch_destroy() {
	close(dev);
}

void push_switch_run() {
	int i, j, k;
	int buff_size;
	int flag_num = 3; //받게 될 깃발의 갯수 (메인으로부터 받게 되겠지!!)

	unsigned char push_sw_buff[MAX_BUTTON];
	int *flag_stat; //누른 푸시 스위치의 상태를 저장하는 배열 (올리고 0, 가만히 1, 내리면 2)
					//메인에서 오는 문제와 비교하게 되겠지 얘랑

	buff_size = sizeof(push_sw_buff);
	flag_stat = (int*)malloc(sizeof(int)*flag_num);

	usleep(400000);
	read(dev, &push_sw_buff, buff_size);

	for (i = 0; i < flag_num; i++) { //상태 배열 초기화
		flag_stat[i] = -1;
	}

	j = 0, k = 0;
	for (i = 0; i < MAX_BUTTON; i++) { //상태 배열 채워넣기
		if (push_sw_buff[i] != 0) {
			j++;
			flag_stat[k] = i % 3;
		}
		if (i % 3 == 2) {
			k++;
		}
	}

	if (j > 0) { //눌렸을 때만 배열 출력
		for (i = 0; i < flag_num; i++) { //상태 배열 출력
			printf("[%d] ", flag_stat[i]);
		}
		printf("\n");
		for (i = 0; i < MAX_BUTTON; i++) {
			printf("[%d] ", push_sw_buff[i]);
		}
		printf("\n=========================================\n");
	}
}
