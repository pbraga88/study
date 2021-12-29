#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

char tasklet_data[] = "Utilizando uma string, mas tambem pode ser um ponteiro para uma estrutura";

/* Tasklet handle, que apenas imprime os dados */
void tasklet_work(unsigned long data)
{
	printk("%s\n", (char *)data); // (char *) is used this way to print the value of data. In other words,
								  // 'unsigned long' is converted to char
}

DECLARE_TASKLET(my_tasklet, tasklet_work, (unsigned long) tasklet_data); // In the same way as previous
								  // stated, 'tasklet_data' is converted to 'unsigned long'

static int __init my_init(void)
{
	/*
	 * Schedule the handler.
	 * Tasklet are also scheduled from interrupt handler
	 */
	tasklet_schedule(&my_tasklet);
	return 0;
}

void my_exit(void)
{
	tasklet_kill(&my_tasklet);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("John Madieu <john.madieu@gmail.com>");
MODULE_LICENSE("GPL");