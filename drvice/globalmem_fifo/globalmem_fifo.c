/*
 *
 * a simple char device driver: globalfifo
 *
 * */


#include <linux/module.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/poll.h>

#define GLOBALFIFO_SIZE 0x1000
#define FIFO_CLEAR 0x1

#define GLOBALFIFO_MAJOR 231

static int globalfifo_major = GLOBALFIFO_MAJOR;
module_param(globalfifo_major, int, S_IRUGO);

struct globalfifo_dev {
	struct cdev cdev;
	unsigned int  currend_len;
	unsigned char mem[GLOBALFIFO_SIZE];
	struct mutex mutex;
	wait_queue_head_t r_wait;
	wait_queue_head_t w_wait;
};

struct globalfifo_dev *globalfifo_devp;

static int globalfifo_open(struct inode *inode, struct file *filp)
{
	filp->private_data = globalfifo_devp;
	return 0;
}

static int globalfifo_release(struct inode *inode, struct file *filp)
{
	return 0;
}

static long globalfifo_ioctl(struct file *filp, unsigned int cmd,
		unsigned long arg)
{
	
}

static unsigned int globalfifo_poll(struct file *filp, poll_table *wait)
{

}

static ssize_t globalfifo_read(struct file *filp, char __user *buf,
		size_t count, loff_t *ppos)
{
	
}

static ssize_t globalfifo_write(struct file *filp, const char __user *buf,
		size_t count, loff_t *ppos)
{
	
}

static const struct file_operations globalfifo_fops = {
	.owner = THIS_MODULE,
	.read = globalfifo_read,
	.write = globalfifo_write,
	.unlocked_ioctl = globalfifo_ioctl,
	.poll = globalfifo_open,
	.release = globalfifo_release,
};

static void globalfifo_setup_cdev(struct globalfifo_dev *dev, int inndex)
{

}

static int __init globalfifo_init(void)
{

}
module_init(globalfifo_init);

static void __exit globalfifo_exit(void)
{

}
module_exit(globalfifo_exit);

MODULE_LICENSE("GPL v2");



