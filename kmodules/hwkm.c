#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>

#define MSG "Hello World From Kernel Module!\n"

// The structure pointing to the proc file
struct proc_dir_entry *proc_file;

// The read callback function
ssize_t proc_file_read(struct file *file, char __user *ubuf,
                       size_t count, loff_t *ppos)
{
    // int copied = 0;
    // if (*ppos > 0)
    // {
    //     return 0;
    // }
    /* SPB NOTE: cannot write to user space ubuf like this, this crashed */
    // copied = sprintf(ubuf, "Hello World From Kernel Module!\n");
    // *ppos = copied;
    // return copied;
    return simple_read_from_buffer(ubuf, count, ppos, MSG, strlen(MSG));
}

const struct proc_ops proc_file_fops = 
{
    //.owner = THIS_MODULE,
    .proc_read = proc_file_read
};

// The module initialization callback
static int __init hwkm_init(void)
{
    proc_file = proc_create("hwkm", 0, NULL, &proc_file_fops);
    if (!proc_file)
    {
        return -ENOMEM;
    }
    printk("Hello World module is loaded.\n");
    return 0;
}

// The module exit callback
static void __exit hkwm_exit(void)
{
    proc_remove(proc_file);
    printk("Goodbye World!\n");
}

// Defining module callbacks
MODULE_LICENSE("GPL");
module_init(hwkm_init);
module_exit(hkwm_exit);
