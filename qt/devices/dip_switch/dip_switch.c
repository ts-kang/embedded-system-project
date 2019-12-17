#include <devices/dip_switch.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*int main(void)
{
    dip_switch_init();
    (void)signal(SIGINT, user_signal1);
    dip_switch_get();
    dip_switch_destroy();
}
*/

static int dev = -1;

void dip_switch_init(void) {
    dev = open("/dev/fpga_dip_switch", O_RDWR);

    if (dev < 0) {
        printf("Device Open Error\n");
	exit(1);
    }
}

void dip_switch_destroy(void) {
    close(dev);
}

unsigned char dip_switch_get(void)
{
    unsigned char flags;
    read(dev, &flags, 1); //한 비트씩 읽어 메인에 반환

    return flags;
}
