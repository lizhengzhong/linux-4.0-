/*
 *a simple char device driver: globalmem with mutex
 *
 * */

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define GLOBALMEM_SIZE 0x1000
#define MEM_CLEAR 0x1
#define GLOBALMEM_MAJOR 230

static int globalmem_major = GLOBALMEM_MAJOR;
//this is pass parameter
module_param(globalmem_major, int, S_IRUGO);

struct globalmem_dev {
	struct cdev cdev;
	unsigned char mem[GLOBALMEM_SIZE];
	struct mutex mutex;
};

struct globalmem_dev *globalmem_devp;

static int globalmem_open(struct inode  *inode, struct file *filp)
{
	filp->private_data = globalmem_devp;
	return 0;
}







