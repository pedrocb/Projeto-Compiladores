	.text
	.file	"test.ll"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	movl	$0, -4(%rsp)
	movl	$3, -8(%rsp)
	movl	$4, -8(%rsp)
	xorl	%eax, %eax
	retq
.Ltmp0:
	.size	main, .Ltmp0-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
