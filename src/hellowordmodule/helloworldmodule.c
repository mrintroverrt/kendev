#include<linux/module.h>
#include<linux/init.h>

MODULE_AUTHOR("Prasaanth");
MODULE_DESCRIPTION("An Simple hello world module in LKM");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");


int init_module(void){
    pr_info("Hello world\n");
    return 0;
}

void cleanup_module(void){
    pr_info("Bye");
}