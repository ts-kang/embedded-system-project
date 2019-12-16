#include <devices/led.h>
#include <fcntl.h>
#include <err.h>

#define DEV_PATH	"/dev/fpga_led"

static int dev = -1;

void led_init()
{
	dev = open(DEV_PATH, O_WRONLY);
	if (dev < 0)
		errx(1, DEV_PATH ": device open failed");
}

void led_destroy()
{
	close(dev);
}
