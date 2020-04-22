/*  
 *  hello-4.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>     /* Needef for the macros */
#define DRIVER_AUTHOR	"Ken Wang <ken@xpire0215.org>"
#define DRIVER_DESC	"A sample driver"

static int __init hello_4_init(void)
{
	printk(KERN_INFO "Hello world 4\n");
	return 0;
}

static void __exit hello_4_exit(void)
{
	printk(KERN_INFO "Goodbye world 4\n");
}

module_init(hello_4_init);
module_exit(hello_4_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE("testdevice");
