#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>     	/* Needef for the macros */
#include <linux/netdevice.h>

struct net_device *dev;

static int __init list_devices_init(void)
{
	read_lock(&dev_base_lock);
	dev = first_net_device(&init_net);

	while (dev) {
		printk(KERN_INFO "found [%s]\n", dev->name);
		dev = next_net_device(dev);
	}

	read_unlock(&dev_base_lock);
        return 0;
}

static void __exit list_devices_exit(void)
{
        printk(KERN_INFO "Goodbye world 1.\n");
}

module_init(list_devices_init);
module_exit(list_devices_exit);

