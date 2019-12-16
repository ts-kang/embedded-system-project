#include <devices/dip_switch.h>

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>
#include <signal.h>

unsigned char quit = 0;
static int dev = -1;

void user_signal1(int sig)
{
	quit = 1;
}

void dip_switch_init(); //device open
void dip_switch_destroy(); //device close
unsigned char dip_switch_get(); //device return flag, time

/*int main(void)
{
	dip_switch_init();
	(void)signal(SIGINT, user_signal1);

	dip_switch_get();
	dip_switch_destroy();
}
*/

void dip_switch_init() {
	dev = open("/dev/fpga_dip_switch", O_RDWR);

	if (dev < 0) {
		printf("Device Open Error\n");
		close(dev);
		return -1;
	}
}

void dip_switch_destroy() {
	close(dev);
}

unsigned char dip_switch_get()
{
	unsigned char flags;
	read(dev, &flags, 1); //한 비트씩 읽어 메인에 반환

	return flags;
}
