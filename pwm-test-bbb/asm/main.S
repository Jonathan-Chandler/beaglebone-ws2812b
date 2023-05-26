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
	.file	"main.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Exit\000"
	.align	2
.LC1:
	.ascii	"Error\000"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arch_extension sec
	.syntax unified
	.arm
	.fpu vfpv3
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #32
	str	r0, [fp, #-32]
	str	r1, [fp, #-36]
	mov	r3, #0
	str	r3, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-8]
	mov	r3, #0
	str	r3, [fp, #-24]
	mov	r3, #0
	str	r3, [fp, #-20]
	mov	r3, #0
	str	r3, [fp, #-16]
	bl	mem_mgr_init(PLT)
	str	r0, [fp, #-12]
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	bne	.L2
	mvn	r3, #0
	b	.L3
.L2:
	ldr	r0, [fp, #-12]
	bl	prcm_init(PLT)
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	beq	.L9
	ldr	r0, [fp, #-8]
	bl	prcm_start_all(PLT)
	ldr	r0, [fp, #-8]
	bl	prcm_debug(PLT)
	ldr	r0, [fp, #-12]
	bl	control_init(PLT)
	str	r0, [fp, #-24]
	ldr	r3, [fp, #-24]
	cmp	r3, #0
	beq	.L10
	ldr	r0, [fp, #-24]
	bl	control_configure(PLT)
	ldr	r0, [fp, #-24]
	bl	control_debug(PLT)
	ldr	r0, [fp, #-12]
	bl	pwmss_init(PLT)
	str	r0, [fp, #-20]
	ldr	r3, [fp, #-20]
	cmp	r3, #0
	beq	.L11
	ldr	r0, [fp, #-20]
	bl	pwmss_debug(PLT)
	ldr	r0, [fp, #-20]
	bl	epwm_init(PLT)
	str	r0, [fp, #-16]
	ldr	r3, [fp, #-16]
	cmp	r3, #0
	beq	.L12
	ldr	r0, [fp, #-16]
	bl	epwm_debug(PLT)
	ldr	r0, [fp, #-20]
	bl	pwmss_configure(PLT)
	ldr	r0, [fp, #-16]
	bl	epwm_configure(PLT)
	ldr	r0, [fp, #-20]
	bl	pwmss_debug(PLT)
	ldr	r0, [fp, #-16]
	bl	epwm_debug(PLT)
	ldr	r0, [fp, #-16]
	bl	epwm_destroy(PLT)
	ldr	r0, [fp, #-20]
	bl	pwmss_destroy(PLT)
	ldr	r0, [fp, #-8]
	bl	prcm_destroy(PLT)
	ldr	r0, [fp, #-24]
	bl	control_destroy(PLT)
	ldr	r0, [fp, #-12]
	bl	mem_mgr_destroy(PLT)
	ldr	r3, .L13
.LPIC0:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mov	r3, #0
	b	.L3
.L9:
	nop
	b	.L5
.L10:
	nop
	b	.L5
.L11:
	nop
	b	.L5
.L12:
	nop
.L5:
	ldr	r0, [fp, #-16]
	bl	epwm_destroy(PLT)
	ldr	r0, [fp, #-20]
	bl	pwmss_destroy(PLT)
	ldr	r0, [fp, #-24]
	bl	control_destroy(PLT)
	ldr	r0, [fp, #-8]
	bl	prcm_destroy(PLT)
	ldr	r0, [fp, #-12]
	bl	mem_mgr_destroy(PLT)
	ldr	r3, .L13+4
.LPIC1:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
.L3:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L14:
	.align	2
.L13:
	.word	.LC0-(.LPIC0+8)
	.word	.LC1-(.LPIC1+8)
	.size	main, .-main
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621"
	.section	.note.GNU-stack,"",%progbits
