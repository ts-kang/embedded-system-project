#include <linux/module.h>
#include <linux/kernel.h>

static int __init init_module(void)
{

}

static int __exit exit_module(void)
{

}

module_init(init_module);
module_exit(exit_module);

MODULE_LICENSE("GPL");
