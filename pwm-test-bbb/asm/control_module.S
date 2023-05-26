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
	.file	"control_module.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"src/control_module.c\000"
	.align	2
.LC1:
	.ascii	"%s::%d::%s::ERROR::\000"
	.align	2
.LC2:
	.ascii	"Fail to allocate CONTROL\000"
	.align	2
.LC3:
	.ascii	"Receive NULL control_base_addr\000"
	.align	2
.LC4:
	.ascii	"%s::%d::%s::LOG::\000"
	.align	2
.LC5:
	.ascii	"CONTROL base_addr = %p\012\000"
	.align	2
.LC6:
	.ascii	"CONTROL pin_addr = %p\012\000"
	.align	2
.LC7:
	.ascii	"CONTROL pwm_addr = %p\012\000"
	.text
	.align	2
	.global	control_init
	.arch armv7-a
	.arch_extension sec
	.syntax unified
	.arm
	.fpu vfpv3
	.type	control_init, %function
control_init:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r0, #16
	bl	malloc(PLT)
	mov	r3, r0
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	bne	.L2
	ldr	r3, .L8
.LPIC0:
	add	r3, pc, r3
	mov	r2, #17
	ldr	r1, .L8+4
.LPIC1:
	add	r1, pc, r1
	ldr	r0, .L8+8
.LPIC2:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L8+12
.LPIC3:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mov	r3, #0
	b	.L3
.L2:
	mov	r1, #0
	movt	r1, 17633
	ldr	r0, [fp, #-16]
	bl	mem_mgr_get_map(PLT)
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L4
	ldr	r3, .L8+16
.LPIC4:
	add	r3, pc, r3
	mov	r2, #23
	ldr	r1, .L8+20
.LPIC5:
	add	r1, pc, r1
	ldr	r0, .L8+24
.LPIC6:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L8+28
.LPIC7:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	nop
.L5:
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	beq	.L6
	b	.L7
.L4:
	ldr	r3, [fp, #-12]
	ldr	r2, [fp, #-8]
	str	r2, [r3, #4]
	ldr	r3, [fp, #-8]
	add	r3, r3, #2080
	add	r3, r3, #4
	mov	r2, r3
	ldr	r3, [fp, #-12]
	str	r2, [r3, #8]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1632
	add	r3, r3, #4
	mov	r2, r3
	ldr	r3, [fp, #-12]
	str	r2, [r3, #12]
	ldr	r3, .L8+32
.LPIC8:
	add	r3, pc, r3
	mov	r2, #31
	ldr	r1, .L8+36
.LPIC9:
	add	r1, pc, r1
	ldr	r0, .L8+40
.LPIC10:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #4]
	mov	r1, r3
	ldr	r3, .L8+44
.LPIC11:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L8+48
.LPIC12:
	add	r3, pc, r3
	mov	r2, #32
	ldr	r1, .L8+52
.LPIC13:
	add	r1, pc, r1
	ldr	r0, .L8+56
.LPIC14:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #8]
	mov	r1, r3
	ldr	r3, .L8+60
.LPIC15:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L8+64
.LPIC16:
	add	r3, pc, r3
	mov	r2, #33
	ldr	r1, .L8+68
.LPIC17:
	add	r1, pc, r1
	ldr	r0, .L8+72
.LPIC18:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #12]
	mov	r1, r3
	ldr	r3, .L8+76
.LPIC19:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	b	.L3
.L7:
	ldr	r0, [fp, #-12]
	bl	free(PLT)
.L6:
	mov	r3, #0
.L3:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L9:
	.align	2
.L8:
	.word	__func__.3-(.LPIC0+8)
	.word	.LC0-(.LPIC1+8)
	.word	.LC1-(.LPIC2+8)
	.word	.LC2-(.LPIC3+8)
	.word	__func__.3-(.LPIC4+8)
	.word	.LC0-(.LPIC5+8)
	.word	.LC1-(.LPIC6+8)
	.word	.LC3-(.LPIC7+8)
	.word	__func__.3-(.LPIC8+8)
	.word	.LC0-(.LPIC9+8)
	.word	.LC4-(.LPIC10+8)
	.word	.LC5-(.LPIC11+8)
	.word	__func__.3-(.LPIC12+8)
	.word	.LC0-(.LPIC13+8)
	.word	.LC4-(.LPIC14+8)
	.word	.LC6-(.LPIC15+8)
	.word	__func__.3-(.LPIC16+8)
	.word	.LC0-(.LPIC17+8)
	.word	.LC4-(.LPIC18+8)
	.word	.LC7-(.LPIC19+8)
	.size	control_init, .-control_init
	.section	.rodata
	.align	2
.LC8:
	.ascii	"CONTROL was null\000"
	.text
	.align	2
	.global	control_destroy
	.syntax unified
	.arm
	.fpu vfpv3
	.type	control_destroy, %function
control_destroy:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L11
	ldr	r3, .L13
.LPIC20:
	add	r3, pc, r3
	mov	r2, #48
	ldr	r1, .L13+4
.LPIC21:
	add	r1, pc, r1
	ldr	r0, .L13+8
.LPIC22:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L13+12
.LPIC23:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L12
.L11:
	ldr	r0, [fp, #-8]
	bl	free(PLT)
	mov	r3, #0
.L12:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L14:
	.align	2
.L13:
	.word	__func__.2-(.LPIC20+8)
	.word	.LC0-(.LPIC21+8)
	.word	.LC4-(.LPIC22+8)
	.word	.LC8-(.LPIC23+8)
	.size	control_destroy, .-control_destroy
	.section	.rodata
	.align	2
.LC9:
	.ascii	"GPMC_AD9       \000"
	.align	2
.LC10:
	.ascii	"LCD_DATA22     \000"
	.align	2
.LC11:
	.ascii	"MMC1_DAT1      \000"
	.align	2
.LC12:
	.ascii	"MMC2_DAT5      \000"
	.align	2
.LC13:
	.ascii	"EHRPWM2B       \000"
	.align	2
.LC14:
	.ascii	"PR1_MII0_COL   \000"
	.align	2
.LC15:
	.ascii	"INVALID        \000"
	.align	2
.LC16:
	.ascii	"GPIO_0_23      \000"
	.section	.data.rel.local,"aw"
	.align	2
	.type	P8_13_MODE_NAMES, %object
	.size	P8_13_MODE_NAMES, 32
P8_13_MODE_NAMES:
	.word	.LC9
	.word	.LC10
	.word	.LC11
	.word	.LC12
	.word	.LC13
	.word	.LC14
	.word	.LC15
	.word	.LC16
	.section	.rodata
	.align	2
.LC17:
	.ascii	"NULL CONTROL\000"
	.align	2
.LC18:
	.ascii	"------------------------------------------------CTR"
	.ascii	"L  DBG---------------------------------------------"
	.ascii	"---\000"
	.align	2
.LC19:
	.ascii	"PIN: %X\012\000"
	.align	2
.LC20:
	.ascii	"SLOW\000"
	.align	2
.LC21:
	.ascii	"FAST\000"
	.align	2
.LC22:
	.ascii	"PIN SLEW:       %s\012\000"
	.align	2
.LC23:
	.ascii	"INPUT\000"
	.align	2
.LC24:
	.ascii	"OUTPUT\000"
	.align	2
.LC25:
	.ascii	"PIN RX ACTIVE:  %s\012\000"
	.align	2
.LC26:
	.ascii	"PULL UP\000"
	.align	2
.LC27:
	.ascii	"PULL DOWN\000"
	.align	2
.LC28:
	.ascii	"PIN PU TYPESEL: %s\012\000"
	.align	2
.LC29:
	.ascii	"ENABLED\000"
	.align	2
.LC30:
	.ascii	"DISABLED\000"
	.align	2
.LC31:
	.ascii	"PIN PU/PD EN:   %s\012\000"
	.align	2
.LC32:
	.ascii	"PIN MODE_SEL:   %d\012\000"
	.align	2
.LC33:
	.ascii	"PIN MODE NAME:  %s\012\000"
	.align	2
.LC34:
	.ascii	"PWM: %X\012\000"
	.align	2
.LC35:
	.ascii	"PWM 0 TBCLK: %s\012\000"
	.align	2
.LC36:
	.ascii	"PWM 1 TBCLK: %s\012\000"
	.align	2
.LC37:
	.ascii	"PWM 2 TBCLK: %s\012\000"
	.align	2
.LC38:
	.ascii	"---------------------------------------------------"
	.ascii	"---------------------------------------------------"
	.ascii	"---\000"
	.text
	.align	2
	.global	control_debug
	.syntax unified
	.arm
	.fpu vfpv3
	.type	control_debug, %function
control_debug:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L16
	ldr	r3, .L32
.LPIC24:
	add	r3, pc, r3
	mov	r2, #73
	ldr	r1, .L32+4
.LPIC25:
	add	r1, pc, r1
	ldr	r0, .L32+8
.LPIC26:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L32+12
.LPIC27:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	b	.L15
.L16:
	ldr	r3, .L32+16
.LPIC28:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #4]
	mov	r1, r3
	ldr	r3, .L32+20
.LPIC29:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	mov	r1, r3
	ldr	r3, .L32+24
.LPIC30:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	mov	r1, r3
	ldr	r3, .L32+28
.LPIC31:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r0, #10
	bl	putchar(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, .L32+32
.LPIC32:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r3, r3, #64
	cmp	r3, #0
	beq	.L18
	ldr	r3, .L32+36
.LPIC33:
	add	r3, pc, r3
	b	.L19
.L18:
	ldr	r3, .L32+40
.LPIC34:
	add	r3, pc, r3
.L19:
	mov	r1, r3
	ldr	r3, .L32+44
.LPIC35:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r3, r3, #32
	cmp	r3, #0
	beq	.L20
	ldr	r3, .L32+48
.LPIC36:
	add	r3, pc, r3
	b	.L21
.L20:
	ldr	r3, .L32+52
.LPIC37:
	add	r3, pc, r3
.L21:
	mov	r1, r3
	ldr	r3, .L32+56
.LPIC38:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r3, r3, #16
	cmp	r3, #0
	beq	.L22
	ldr	r3, .L32+60
.LPIC39:
	add	r3, pc, r3
	b	.L23
.L22:
	ldr	r3, .L32+64
.LPIC40:
	add	r3, pc, r3
.L23:
	mov	r1, r3
	ldr	r3, .L32+68
.LPIC41:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r3, r3, #8
	cmp	r3, #0
	beq	.L24
	ldr	r3, .L32+72
.LPIC42:
	add	r3, pc, r3
	b	.L25
.L24:
	ldr	r3, .L32+76
.LPIC43:
	add	r3, pc, r3
.L25:
	mov	r1, r3
	ldr	r3, .L32+80
.LPIC44:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r3, r3, #7
	mov	r1, r3
	ldr	r3, .L32+84
.LPIC45:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r2, r3, #7
	ldr	r3, .L32+88
.LPIC46:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L32+92
.LPIC47:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r0, #10
	bl	putchar(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, .L32+96
.LPIC48:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	and	r3, r3, #1
	cmp	r3, #0
	beq	.L26
	ldr	r3, .L32+100
.LPIC49:
	add	r3, pc, r3
	b	.L27
.L26:
	ldr	r3, .L32+104
.LPIC50:
	add	r3, pc, r3
.L27:
	mov	r1, r3
	ldr	r3, .L32+108
.LPIC51:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	and	r3, r3, #2
	cmp	r3, #0
	beq	.L28
	ldr	r3, .L32+112
.LPIC52:
	add	r3, pc, r3
	b	.L29
.L28:
	ldr	r3, .L32+116
.LPIC53:
	add	r3, pc, r3
.L29:
	mov	r1, r3
	ldr	r3, .L32+120
.LPIC54:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	and	r3, r3, #4
	cmp	r3, #0
	beq	.L30
	ldr	r3, .L32+124
.LPIC55:
	add	r3, pc, r3
	b	.L31
.L30:
	ldr	r3, .L32+128
.LPIC56:
	add	r3, pc, r3
.L31:
	mov	r1, r3
	ldr	r3, .L32+132
.LPIC57:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L32+136
.LPIC58:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
.L15:
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L33:
	.align	2
.L32:
	.word	__func__.1-(.LPIC24+8)
	.word	.LC0-(.LPIC25+8)
	.word	.LC1-(.LPIC26+8)
	.word	.LC17-(.LPIC27+8)
	.word	.LC18-(.LPIC28+8)
	.word	.LC5-(.LPIC29+8)
	.word	.LC6-(.LPIC30+8)
	.word	.LC7-(.LPIC31+8)
	.word	.LC19-(.LPIC32+8)
	.word	.LC20-(.LPIC33+8)
	.word	.LC21-(.LPIC34+8)
	.word	.LC22-(.LPIC35+8)
	.word	.LC23-(.LPIC36+8)
	.word	.LC24-(.LPIC37+8)
	.word	.LC25-(.LPIC38+8)
	.word	.LC26-(.LPIC39+8)
	.word	.LC27-(.LPIC40+8)
	.word	.LC28-(.LPIC41+8)
	.word	.LC29-(.LPIC42+8)
	.word	.LC30-(.LPIC43+8)
	.word	.LC31-(.LPIC44+8)
	.word	.LC32-(.LPIC45+8)
	.word	P8_13_MODE_NAMES-(.LPIC46+8)
	.word	.LC33-(.LPIC47+8)
	.word	.LC34-(.LPIC48+8)
	.word	.LC29-(.LPIC49+8)
	.word	.LC30-(.LPIC50+8)
	.word	.LC35-(.LPIC51+8)
	.word	.LC29-(.LPIC52+8)
	.word	.LC30-(.LPIC53+8)
	.word	.LC36-(.LPIC54+8)
	.word	.LC29-(.LPIC55+8)
	.word	.LC30-(.LPIC56+8)
	.word	.LC37-(.LPIC57+8)
	.word	.LC38-(.LPIC58+8)
	.size	control_debug, .-control_debug
	.align	2
	.global	control_configure
	.syntax unified
	.arm
	.fpu vfpv3
	.type	control_configure, %function
control_configure:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L35
	ldr	r3, .L37
.LPIC59:
	add	r3, pc, r3
	mov	r2, #101
	ldr	r1, .L37+4
.LPIC60:
	add	r1, pc, r1
	ldr	r0, .L37+8
.LPIC61:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L37+12
.LPIC62:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L36
.L35:
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	mov	r2, #4
	str	r2, [r3]
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	mov	r2, #7
	str	r2, [r3]
	mov	r3, #0
.L36:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L38:
	.align	2
.L37:
	.word	__func__.0-(.LPIC59+8)
	.word	.LC0-(.LPIC60+8)
	.word	.LC1-(.LPIC61+8)
	.word	.LC17-(.LPIC62+8)
	.size	control_configure, .-control_configure
	.section	.rodata
	.align	2
	.type	__func__.3, %object
	.size	__func__.3, 13
__func__.3:
	.ascii	"control_init\000"
	.align	2
	.type	__func__.2, %object
	.size	__func__.2, 16
__func__.2:
	.ascii	"control_destroy\000"
	.align	2
	.type	__func__.1, %object
	.size	__func__.1, 14
__func__.1:
	.ascii	"control_debug\000"
	.align	2
	.type	__func__.0, %object
	.size	__func__.0, 18
__func__.0:
	.ascii	"control_configure\000"
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621"
	.section	.note.GNU-stack,"",%progbits
