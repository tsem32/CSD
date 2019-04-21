#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/uaccess.h>
#include <asm-generic/errno.h>
#include <asm/current.h>
asmlinkage long sys_set_total_computation_time(int pid,unsigned int total_time){
        int pidofprocess;
	struct task_struct* task_struct_of_process;
	//task_struct_of_process=(struct task_struct*)kmalloc(sizeof(struct task_struct),GFP_KERNEL);
	printk("Anastasios Gialamoudis 2910 set_total_computation_time\n");
	printk("pid=%d\n",pid);
		if(pid==(-1)){
	/*change current task*/
	current->total_computation_time=total_time;
	printk("Changed current (pid=%d) process",pid);
	printk("Anastasios Gialamoudis 2910 set_total_computation_done");
	//kfree(task_struct_of_process);
	return 0;
	}
	if(pid>-1){
	for_each_process(task_struct_of_process){
		if(task_struct_of_process->pid==pid){
			printk("Found process with pid=%d",pid);
			task_struct_of_process->total_computation_time=total_time;
			printk("Anastasios Gialamoudis 2910 set_total_computation_done");
	//		kfree(task_struct_of_process);
			return 0;
			}
		}
	/*by here we have reached the end of the task_struct list so no process
	with pid=pid exists*/
	//kfree(task_struct_of_process);
	return EINVAL;
	
	}
   return 1;}
