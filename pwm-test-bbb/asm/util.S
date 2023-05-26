	.cpu cortex-a8
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"util.c"
	.text
	.align	2
	.global	msleep
	.arch armv7-a
	.arch_extension sec
	.syntax unified
	.arm
	.fpu vfpv3
	.type	msleep, %function
msleep:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	str	r0, [fp, #-24]
	ldr	r2, .L8
.LPIC0:
	add	r2, pc, r2
	ldr	r3, .L8+4
	ldr	r3, [r2, r3]
	ldr	r3, [r3]
	str	r3, [fp, #-8]
	mov	r3, #0
	ldr	r3, [fp, #-24]
	cmp	r3, #0
	bge	.L2
	bl	__errno_location(PLT)
	mov	r3, r0
	mov	r2, #22
	str	r2, [r3]
	mvn	r3, #0
	b	.L6
.L2:
	ldr	r2, [fp, #-24]
	movw	r3, #19923
	movt	r3, 4194
	smull	r1, r3, r3, r2
	asr	r1, r3, #6
	asr	r3, r2, #31
	sub	r3, r1, r3
	str	r3, [fp, #-16]
	ldr	r2, [fp, #-24]
	movw	r3, #19923
	movt	r3, 4194
	smull	r1, r3, r3, r2
	asr	r1, r3, #6
	asr	r3, r2, #31
	sub	r3, r1, r3
	mov	r1, #1000
	mul	r3, r1, r3
	sub	r3, r2, r3
	movw	r2, #16960
	movt	r2, 15
	mul	r3, r2, r3
	str	r3, [fp, #-12]
.L5:
	sub	r2, fp, #16
	sub	r3, fp, #16
	mov	r1, r2
	mov	r0, r3
	bl	nanosleep(PLT)
	str	r0, [fp, #-20]
	ldr	r3, [fp, #-20]
	cmp	r3, #0
	beq	.L4
	bl	__errno_location(PLT)
	mov	r3, r0
	ldr	r3, [r3]
	cmp	r3, #4
	beq	.L5
.L4:
	ldr	r3, [fp, #-20]
.L6:
	ldr	r1, .L8+8
.LPIC1:
	add	r1, pc, r1
	ldr	r2, .L8+4
	ldr	r2, [r1, r2]
	ldr	r1, [r2]
	ldr	r2, [fp, #-8]
	eors	r1, r2, r1
	mov	r2, #0
	beq	.L7
	bl	__stack_chk_fail(PLT)
.L7:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L9:
	.align	2
.L8:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC0+8)
	.word	__stack_chk_guard(GOT)
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC1+8)
	.size	msleep, .-msleep
	.align	2
	.global	reverse_8bit
	.syntax unified
	.arm
	.fpu vfpv3
	.type	reverse_8bit, %function
reverse_8bit:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L11
.L13:
	mov	r2, #128
	ldr	r3, [fp, #-12]
	asr	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	and	r3, r3, r2
	cmp	r3, #0
	beq	.L12
	mov	r2, #1
	ldr	r3, [fp, #-12]
	lsl	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-8]
	orr	r3, r3, r2
	str	r3, [fp, #-8]
.L12:
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L11:
	ldr	r3, [fp, #-12]
	cmp	r3, #7
	bls	.L13
	ldr	r3, [fp, #-8]
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	reverse_8bit, .-reverse_8bit
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621"
	.section	.note.GNU-stack,"",%progbits
