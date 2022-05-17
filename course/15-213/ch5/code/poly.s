	.file	"poly.c"
	.text
	.p2align 4
	.globl	poly
	.type	poly, @function
poly:
.LFB0:
	.cfi_startproc
	endbr64
	cvttsd2siq	(%rdi), %rdx
	cvttsd2siq	%xmm0, %rax
	testq	%rsi, %rsi
	jle	.L2
	leaq	8(%rdi), %rcx
	leaq	8(%rdi,%rsi,8), %rsi
	.p2align 4,,10
	.p2align 3
.L3:
	pxor	%xmm1, %xmm1
	movsd	(%rcx), %xmm3
	pxor	%xmm2, %xmm2
	addq	$8, %rcx
	cvtsi2sdq	%rax, %xmm1
	cvtsi2sdq	%rdx, %xmm2
	mulsd	%xmm1, %xmm3
	mulsd	%xmm0, %xmm1
	addsd	%xmm3, %xmm2
	cvttsd2siq	%xmm1, %rax
	cvttsd2siq	%xmm2, %rdx
	cmpq	%rcx, %rsi
	jne	.L3
.L2:
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	poly, .-poly
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
