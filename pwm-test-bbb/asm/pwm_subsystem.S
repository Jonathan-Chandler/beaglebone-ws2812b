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
	.file	"pwm_subsystem.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"IDVER    \000"
	.align	2
.LC1:
	.ascii	"SYSCONFIG\000"
	.align	2
.LC2:
	.ascii	"CLKCONFIG\000"
	.align	2
.LC3:
	.ascii	"CLKSTATUS\000"
	.section	.data.rel.local,"aw"
	.align	2
	.type	pwmss_reg_name, %object
	.size	pwmss_reg_name, 16
pwmss_reg_name:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.section	.rodata
	.align	2
.LC4:
	.ascii	"------------------------------------------------PWM"
	.ascii	"SS DBG---------------------------------------------"
	.ascii	"---\000"
	.align	2
.LC5:
	.ascii	"%s: %08X\012\000"
	.align	2
.LC6:
	.ascii	"---------------------------------------------------"
	.ascii	"---------------------------------------------------"
	.ascii	"---\000"
	.text
	.align	2
	.global	pwmss_debug
	.arch armv7-a
	.arch_extension sec
	.syntax unified
	.arm
	.fpu vfpv3
	.type	pwmss_debug, %function
pwmss_debug:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	ldr	r3, [fp, #-16]
	str	r3, [fp, #-8]
	ldr	r3, .L4
.LPIC0:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L2
.L3:
	ldr	r3, .L4+4
.LPIC1:
	add	r3, pc, r3
	ldr	r2, [fp, #-12]
	ldr	r1, [r3, r2, lsl #2]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-8]
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r2, r3
	ldr	r3, .L4+8
.LPIC2:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L2:
	ldr	r3, [fp, #-12]
	cmp	r3, #3
	bls	.L3
	ldr	r3, .L4+12
.LPIC3:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L5:
	.align	2
.L4:
	.word	.LC4-(.LPIC0+8)
	.word	pwmss_reg_name-(.LPIC1+8)
	.word	.LC5-(.LPIC2+8)
	.word	.LC6-(.LPIC3+8)
	.size	pwmss_debug, .-pwmss_debug
	.align	2
	.global	pwmss_test_size
	.syntax unified
	.arm
	.fpu vfpv3
	.type	pwmss_test_size, %function
pwmss_test_size:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	mov	r3, #0
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	pwmss_test_size, .-pwmss_test_size
	.section	.rodata
	.align	2
.LC7:
	.ascii	"src/pwm_subsystem.c\000"
	.align	2
.LC8:
	.ascii	"%s::%d::%s::LOG::\000"
	.align	2
.LC9:
	.ascii	"PWMSS mapped to address %p\012\000"
	.text
	.align	2
	.global	pwmss_init
	.syntax unified
	.arm
	.fpu vfpv3
	.type	pwmss_init, %function
pwmss_init:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r3, #16384
	movt	r3, 18480
	str	r3, [fp, #-12]
	bl	pwmss_test_size(PLT)
	mov	r3, r0
	cmp	r3, #0
	bge	.L9
	mov	r3, #0
	b	.L10
.L9:
	ldr	r1, [fp, #-12]
	ldr	r0, [fp, #-16]
	bl	mem_mgr_get_map(PLT)
	str	r0, [fp, #-8]
	ldr	r3, .L11
.LPIC4:
	add	r3, pc, r3
	mov	r2, #46
	ldr	r1, .L11+4
.LPIC5:
	add	r1, pc, r1
	ldr	r0, .L11+8
.LPIC6:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r1, [fp, #-8]
	ldr	r3, .L11+12
.LPIC7:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
.L10:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L12:
	.align	2
.L11:
	.word	__func__.2-(.LPIC4+8)
	.word	.LC7-(.LPIC5+8)
	.word	.LC8-(.LPIC6+8)
	.word	.LC9-(.LPIC7+8)
	.size	pwmss_init, .-pwmss_init
	.section	.rodata
	.align	2
.LC10:
	.ascii	"PWMSS was null\000"
	.text
	.align	2
	.global	pwmss_destroy
	.syntax unified
	.arm
	.fpu vfpv3
	.type	pwmss_destroy, %function
pwmss_destroy:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L14
	ldr	r3, .L16
.LPIC8:
	add	r3, pc, r3
	mov	r2, #55
	ldr	r1, .L16+4
.LPIC9:
	add	r1, pc, r1
	ldr	r0, .L16+8
.LPIC10:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L16+12
.LPIC11:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L15
.L14:
	mov	r3, #0
.L15:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L17:
	.align	2
.L16:
	.word	__func__.1-(.LPIC8+8)
	.word	.LC7-(.LPIC9+8)
	.word	.LC8-(.LPIC10+8)
	.word	.LC10-(.LPIC11+8)
	.size	pwmss_destroy, .-pwmss_destroy
	.section	.rodata
	.align	2
.LC11:
	.ascii	"PWMSS->SYSCONFIG.STANDBYMODE: %X\012\000"
	.align	2
.LC12:
	.ascii	"PWMSS->SYSCONFIG.IDLEMODE: %X\012\000"
	.align	2
.LC13:
	.ascii	"PWMSS->SYSCONFIG.FREEMU: %X\012\000"
	.align	2
.LC14:
	.ascii	"PWMSS->SYSCONFIG.SOFTRESET: %X\012\000"
	.align	2
.LC15:
	.ascii	"PWMSS->CLKCONFIG.eCAPCLK_EN: %X\012\000"
	.align	2
.LC16:
	.ascii	"PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ: %X\012\000"
	.align	2
.LC17:
	.ascii	"PWMSS->CLKCONFIG.eQEPCLK_EN: %X\012\000"
	.align	2
.LC18:
	.ascii	"PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ: %X\012\000"
	.align	2
.LC19:
	.ascii	"PWMSS->CLKCONFIG.ePWMCLK_EN: %X\012\000"
	.align	2
.LC20:
	.ascii	"PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ: %X\012\000"
	.text
	.align	2
	.global	pwmss_configure
	.syntax unified
	.arm
	.fpu vfpv3
	.type	pwmss_configure, %function
pwmss_configure:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L19
	ldr	r3, .L31
.LPIC12:
	add	r3, pc, r3
	mov	r2, #68
	ldr	r1, .L31+4
.LPIC13:
	add	r1, pc, r1
	ldr	r0, .L31+8
.LPIC14:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L31+12
.LPIC15:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L20
.L19:
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #4]
	mov	r1, #2
	bfi	r3, r1, #4, #2
	strb	r3, [r2, #4]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #4]
	mov	r1, #2
	bfi	r3, r1, #2, #2
	strb	r3, [r2, #4]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #4]
	orr	r3, r3, #2
	strb	r3, [r2, #4]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #4]
	bfc	r3, #0, #1
	strb	r3, [r2, #4]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #8]
	bfc	r3, #0, #1
	strb	r3, [r2, #8]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #8]
	orr	r3, r3, #2
	strb	r3, [r2, #8]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #8]
	bfc	r3, #4, #1
	strb	r3, [r2, #8]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #8]
	orr	r3, r3, #32
	strb	r3, [r2, #8]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #9]
	orr	r3, r3, #1
	strb	r3, [r2, #9]
	ldr	r2, [fp, #-8]
	ldrb	r3, [r2, #9]
	bfc	r3, #1, #1
	strb	r3, [r2, #9]
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]	@ zero_extendqisi2
	and	r3, r3, #48
	uxtb	r3, r3
	cmp	r3, #32
	beq	.L21
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]
	ubfx	r3, r3, #4, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+16
.LPIC16:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L21:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]	@ zero_extendqisi2
	and	r3, r3, #12
	uxtb	r3, r3
	cmp	r3, #8
	beq	.L22
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]
	ubfx	r3, r3, #2, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+20
.LPIC17:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L22:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]	@ zero_extendqisi2
	and	r3, r3, #2
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L23
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]
	ubfx	r3, r3, #1, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+24
.LPIC18:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L23:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]	@ zero_extendqisi2
	and	r3, r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L24
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #4]
	ubfx	r3, r3, #0, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+28
.LPIC19:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L24:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]	@ zero_extendqisi2
	and	r3, r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L25
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]
	ubfx	r3, r3, #0, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+32
.LPIC20:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L25:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]	@ zero_extendqisi2
	and	r3, r3, #2
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L26
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]
	ubfx	r3, r3, #1, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+36
.LPIC21:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L26:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]	@ zero_extendqisi2
	and	r3, r3, #16
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L27
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]
	ubfx	r3, r3, #4, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+40
.LPIC22:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L27:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]	@ zero_extendqisi2
	and	r3, r3, #32
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L28
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #8]
	ubfx	r3, r3, #5, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+44
.LPIC23:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L28:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #9]	@ zero_extendqisi2
	and	r3, r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L29
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #9]
	ubfx	r3, r3, #0, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+48
.LPIC24:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L29:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #9]	@ zero_extendqisi2
	and	r3, r3, #2
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L30
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #9]
	ubfx	r3, r3, #1, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L31+52
.LPIC25:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L30:
	mov	r3, #0
.L20:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L32:
	.align	2
.L31:
	.word	__func__.0-(.LPIC12+8)
	.word	.LC7-(.LPIC13+8)
	.word	.LC8-(.LPIC14+8)
	.word	.LC10-(.LPIC15+8)
	.word	.LC11-(.LPIC16+8)
	.word	.LC12-(.LPIC17+8)
	.word	.LC13-(.LPIC18+8)
	.word	.LC14-(.LPIC19+8)
	.word	.LC15-(.LPIC20+8)
	.word	.LC16-(.LPIC21+8)
	.word	.LC17-(.LPIC22+8)
	.word	.LC18-(.LPIC23+8)
	.word	.LC19-(.LPIC24+8)
	.word	.LC20-(.LPIC25+8)
	.size	pwmss_configure, .-pwmss_configure
	.section	.rodata
	.align	2
	.type	__func__.2, %object
	.size	__func__.2, 11
__func__.2:
	.ascii	"pwmss_init\000"
	.align	2
	.type	__func__.1, %object
	.size	__func__.1, 14
__func__.1:
	.ascii	"pwmss_destroy\000"
	.align	2
	.type	__func__.0, %object
	.size	__func__.0, 16
__func__.0:
	.ascii	"pwmss_configure\000"
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621"
	.section	.note.GNU-stack,"",%progbits
