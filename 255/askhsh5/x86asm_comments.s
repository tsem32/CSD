# -----------------------------------
# Program x86asm.s
# Compute and print the sum 0+...+N
# -----------------------------------

	.section .data	# data section
N:	.long 1000	    # number 1000
S:	.long 0		    # number 0
Msg:	.ascii "The sum from 0 to %d is %d\n\0"


	.section .text	# instruction section
.globl main
main:	
	pushl %ebp	    #  stores the stack frame of the calling function on the stack.
	movl %esp, %ebp	#  takes the current stack pointer and uses it as the frame for the called function

 	# initialize
    movl N, %ebx	# move the address of N to %ebx

 	# compute sum
L1:
	addl %ebx, S	# %ebx <- %ebx + S
	decl %ebx       # &ebx <- &ebx - 1
	cmpl $0, %ebx   # compare %ebx with 0
	jng  L2	    	# if not greater than jump to L2
    movl $L1, %eax	# move the address of L1 to %eax
    jmp *%eax   	# jump to addr in %eax

L2:
	# print result
	pushl S	    	# push S
	pushl N	        # push n
	pushl $Msg  	# push Msg addr
	call printf 	# system call
	popl %eax   	# pop Msg addr
	popl %eax   	# pop N
	popl %eax   	# pop S

	# exit
	movl $0, %eax  	# %eax <- 0
    leave	    	# leave
 	ret             # return 0; (from %eax)
