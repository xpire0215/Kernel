/*  
 *  hello-5.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/moduleparam.h>	/* Needed by module_param */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h> 	/* Needef for the macros */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ken Wang <ken@xpire0215.org>");
MODULE_DESCRIPTION("A sample driver");
MODULE_SUPPORTED_DEVICE("testdevice");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "string";

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");

module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");

module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");

module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

static int myintArray[5] = {-1, -1, -1, -1, -1};
static int arr_argc = 0;

module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");

static int __init hello_5_init(void)
{
	printk(KERN_INFO "Hello, world 5\n=============\n");
	printk(KERN_INFO "myshort is a short integer: %hd\n", myshort);
	printk(KERN_INFO "myint is an integer: %d\n", myint);
	printk(KERN_INFO "mylong is a long integer: %ld\n", mylong);
	printk(KERN_INFO "mystring is a string: %s\n", mystring);

	int i;
	for (i = 0; i < (sizeof myintArray / sizeof(int)); i++) 
	{
		printk(KERN_INFO "myintArray[%d] = %d\n", i, myintArray[i]);
	}
	
	printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
	return 0;
}

static void __exit hello_5_exit(void)
{
	printk(KERN_INFO "Goodbye world 5\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);


