#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/workqueue.h>

static DECLARE_WAIT_QUEUE_HEAD(my_wq);
static int condition = 0;

/* Declare a work queue */
static struct work_struct wrk;

static void work_handler(struct work_struct *work)
{
	printk("Waitqueue module handler %s\n", __FUNCTION__);
	msleep(5000);
	printk("Wake up the sleeping module\n");
	condition = 1;

	/* The wakr up routine is called. Note that the var condition above was set to '1'. */
	wake_up_interruptible(&my_wq);
}

static int __init my_init(void)
{
	printk("Wait queue example\n");

	/* Initialize and schedule it to wait for the interrupt */
	INIT_WORK(&wrk, work_handler);
	schedule_work(&wrk);

	/* Wait for the interrupt event. Note that, to wake up, the condition must be different from '0'. */
	printk("Going to sleep %s\n", __FUNCTION__);
	wait_event_interruptible(my_wq, condition != 0 );

	pr_info("woken up by the work job\n");
	return 0;
}

void my_exit(void)
{
	printk("waitqueue example cleanup\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("John Madieu <john.madieu@foobar.com>");
MODULE_LICENSE("GPL");