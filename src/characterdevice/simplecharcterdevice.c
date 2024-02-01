#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

MODULE_AUTHOR("Prasaanth");
MODULE_DESCRIPTION("An Simple Charatcter dev");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

dev_t dev = MKDEV(254,0);



static int __init new_device__init(void){
    register_chrdev_region(dev, 1, "Prasaanth");
    printk(KERN_INFO "Device registered successfully: MAJOR -> %d MINOR -> %d \n", MAJOR(dev), MINOR(dev));
    printk("Kernal Module loded successfully\n");
    return 0;
}

static void __exit new_device_exit(void){
    unregister_chrdev_region(dev, 1);
    printk("Kernal Module unloded successfully...\n");
}


module_init(new_device__init);
module_exit(new_device_exit);