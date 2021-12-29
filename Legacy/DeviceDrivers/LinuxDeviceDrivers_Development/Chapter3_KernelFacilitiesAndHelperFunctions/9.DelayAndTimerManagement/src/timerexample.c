#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

static struct timer_list my_timer;

void my_timer_callback(unsigned long data)
{
	/* '__FUNCTION__' é uma variável de referência à essa função (my_timer_callback) 
	 * jiffies é a unidade de medida de tempo do kernel  
	 *'ld': long unsigned int
	 */
	printk("%s called (%ld).\n ", __FUNCTION__, jiffies);
}

static int __init my_init(void)
{
	/* Variável que irá receber o que retorna de 'mod_timer()'*/
	int retval; 

	printk("Timer module loaded\n");

	/* Setup do timer passando:
	 * 	a minha instância 'my_timer' da estrutura;
	 *	a função 'my_timer_allback()' que é minha função de callback;
	 *	data = 0 pois tal campo é opcional.
	 */
	setup_timer(&my_timer, my_timer_callback, 0);
	
	printk("Setup timer to fire in 3000ms (%ld)\n", jiffies);

	/* Aqui é configurado o timer do módulo, que é o tempo de espea até que a callback 
	 * seja disparada. É passado:
	 * a minha instância da estrutura 'my_timer';
	 * o tempo atual em 'jiffies', mais o tempo para que a callback seja executada com 
	 * a função 'msecs_to_jiffies()'.
	 */
	retval = mod_timer(&my_timer, jiffies + msecs_to_jiffies(3000));
	if (retval)
		printk("Timer firing failed\n");

	return 0;
}

static void my_exit(void)
{
	int retval;
	
	/* Aqui, a minha instância 'my_timer' do timer e excluida*/
	retval = del_timer(&my_timer);
	
	/* Is timer still active (1) or not (0)*/
	if (retval)
		printk("The timer is still in use...\n");

	pr_info("Timer module unloaded");	
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("Paulo Simplício <paulo.braga1388@gmail.com>");
MODULE_DESCRIPTION("Standard timer example");
MODULE_LICENSE("GPL");