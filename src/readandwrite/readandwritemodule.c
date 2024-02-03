#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_AUTHOR("Prasaanth");
MODULE_DESCRIPTION("A Basic read and write module");
MODULE_LICENSE("GPL");

#define DEVICE_NAME "simple_charcter_device"
#define BUFF_SIZE 1024

static char device_buffer[BUFF_SIZE];
static int major_number;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    ssize_t bytes_read = 0;

    if (*offset >= BUFF_SIZE) {
        return 0;
    }

    bytes_read = min(length, (size_t)(BUFF_SIZE - *offset));
    
    // Copy data from device buffer to user space
    if (copy_to_user(buffer, device_buffer + *offset, bytes_read) != 0) {
        return -EFAULT;
    }

    *offset += bytes_read;

    return bytes_read;
}

static ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    ssize_t bytes_written = 0;

    if (*offset >= BUFF_SIZE) {
        return -ENOSPC;
    }

    bytes_written = min((ssize_t)length, (ssize_t)(BUFF_SIZE - *offset));

    // Copy data from user space to device buffer
    if (copy_from_user(device_buffer + *offset, buffer, bytes_written) != 0) {
        return -EFAULT;
    }

    *offset += bytes_written;

    return bytes_written;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

static int __init char_device_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);

    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }

    printk(KERN_INFO "Registered character device with major number %d\n", major_number);
    return 0;
}

static void __exit char_device_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Unregistered character device\n");
}

module_init(char_device_init);
module_exit(char_device_exit);
