#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

MODULE_AUTHOR("Prasaanth");
MODULE_DESCRIPTION("An Dynamic Character device allocation");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

dev_t dynamicdev = 0;

static int __init inital_dynamic(void){
    if((alloc_chrdev_region(&dynamicdev,0,1,"Prasaanthdynamic")) < 0){
        printk("Can't able to allocate dynamic character device\n");
        return -1;
    }
    printk("MAJOR : %d MINOR : %d ",MAJOR(dynamicdev),MINOR(dynamicdev));
    printk("Dynamic Character Kernal module loaded successfully");
    return 0;
}


static void __exit exit_dynamic(void){
    unregister_chrdev_region(dynamicdev,1);
    printk("Dynamic Character Kernal module unloaded successfully");
}

module_init(inital_dynamic);
module_exit(exit_dynamic);