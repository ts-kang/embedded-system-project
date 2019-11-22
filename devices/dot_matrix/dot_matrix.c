#include <devices/dot_matrix.h>
#include <fcntl.h>
#include <err.h>

#define DEV_PATH	"/dev/fpga_dot"
#define ROWS		10
#define COLS		7

static int dev = -1;
static uint8_t scr[ROWS];

void dot_matrix_init()
{
	dev = open(DEV_PATH, O_WRONLY);
	if (dev < 0)
		errx(1, DEV_PATH ": device open failed");
}

void dot_matrix_destroy()
{
	close(dev);
}
