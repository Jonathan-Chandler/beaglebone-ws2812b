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
	.file	"prcm.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"FUNC       \000"
	.align	2
.LC1:
	.ascii	"TRANSITION \000"
	.align	2
.LC2:
	.ascii	"IDLE       \000"
	.align	2
.LC3:
	.ascii	"DISABLE    \000"
	.section	.data.rel.local,"aw"
	.align	2
	.type	cm_per_idlest, %object
	.size	cm_per_idlest, 16
cm_per_idlest:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.section	.rodata
	.align	2
.LC4:
	.ascii	"RESERVED   \000"
	.align	2
.LC5:
	.ascii	"ENABLE     \000"
	.align	2
.LC6:
	.ascii	"RESERVED2  \000"
	.section	.data.rel.local
	.align	2
	.type	cm_per_mode, %object
	.size	cm_per_mode, 16
cm_per_mode:
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.section	.rodata
	.align	2
.LC7:
	.ascii	"src/prcm.c\000"
	.align	2
.LC8:
	.ascii	"%s::%d::%s::ERROR::\000"
	.align	2
.LC9:
	.ascii	"NULL PRCM\000"
	.align	2
.LC10:
	.ascii	"------------------------------------------------CTR"
	.ascii	"L  DBG---------------------------------------------"
	.ascii	"---\000"
	.align	2
.LC11:
	.ascii	"PRCM cm_per_base addr = %p\012\000"
	.align	2
.LC12:
	.ascii	"PRCM epwmss0 addr = %p\012\000"
	.align	2
.LC13:
	.ascii	"PRCM epwmss1 addr = %p\012\000"
	.align	2
.LC14:
	.ascii	"PRCM epwmss2 addr = %p\012\000"
	.align	2
.LC15:
	.ascii	"PRCM pru_icss_clkstctrl addr = %p\012\000"
	.align	2
.LC16:
	.ascii	"CM_PER_EPWMSS0_CLKCTRL IDLEST: %s\012\000"
	.align	2
.LC17:
	.ascii	"CM_PER_EPWMSS0_CLKCTRL MODULEMODE: %s\012\000"
	.align	2
.LC18:
	.ascii	"CM_PER_EPWMSS1_CLKCTRL IDLEST: %s\012\000"
	.align	2
.LC19:
	.ascii	"CM_PER_EPWMSS1_CLKCTRL MODULEMODE: %s\012\000"
	.align	2
.LC20:
	.ascii	"CM_PER_EPWMSS2_CLKCTRL IDLEST: %s\012\000"
	.align	2
.LC21:
	.ascii	"CM_PER_EPWMSS2_CLKCTRL MODULEMODE: %s\012\000"
	.align	2
.LC22:
	.ascii	"Standby\000"
	.align	2
.LC23:
	.ascii	"Func\000"
	.align	2
.LC24:
	.ascii	"CM_PER_PRU_ICSS_CLKCTRL STBYST: %s\012\000"
	.align	2
.LC25:
	.ascii	"CM_PER_PRU_ICSS_CLKCTRL IDLEST: %s\012\000"
	.align	2
.LC26:
	.ascii	"CM_PER_PRU_ICSS_CLKCTRL MODULEMODE: %s\012\000"
	.align	2
.LC27:
	.ascii	"---------------------------------------------------"
	.ascii	"---------------------------------------------------"
	.ascii	"---\000"
	.text
	.align	2
	.global	prcm_debug
	.arch armv7-a
	.arch_extension sec
	.syntax unified
	.arm
	.fpu vfpv3
	.type	prcm_debug, %function
prcm_debug:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L2
	ldr	r3, .L6
.LPIC0:
	add	r3, pc, r3
	mov	r2, #27
	ldr	r1, .L6+4
.LPIC1:
	add	r1, pc, r1
	ldr	r0, .L6+8
.LPIC2:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L6+12
.LPIC3:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	b	.L1
.L2:
	ldr	r3, .L6+16
.LPIC4:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, .L6+20
.LPIC5:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #4]
	mov	r1, r3
	ldr	r3, .L6+24
.LPIC6:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	mov	r1, r3
	ldr	r3, .L6+28
.LPIC7:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	mov	r1, r3
	ldr	r3, .L6+32
.LPIC8:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #16]
	mov	r1, r3
	ldr	r3, .L6+36
.LPIC9:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r0, #10
	bl	putchar(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #4]
	ldr	r3, [r3]
	lsr	r3, r3, #16
	and	r2, r3, #3
	ldr	r3, .L6+40
.LPIC10:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+44
.LPIC11:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #4]
	ldr	r3, [r3]
	and	r2, r3, #3
	ldr	r3, .L6+48
.LPIC12:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+52
.LPIC13:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	lsr	r3, r3, #16
	and	r2, r3, #3
	ldr	r3, .L6+56
.LPIC14:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+60
.LPIC15:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r2, r3, #3
	ldr	r3, .L6+64
.LPIC16:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+68
.LPIC17:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	lsr	r3, r3, #16
	and	r2, r3, #3
	ldr	r3, .L6+72
.LPIC18:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+76
.LPIC19:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	and	r2, r3, #3
	ldr	r3, .L6+80
.LPIC20:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+84
.LPIC21:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r0, #10
	bl	putchar(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #16]
	ldr	r3, [r3]
	and	r3, r3, #262144
	cmp	r3, #0
	beq	.L4
	ldr	r3, .L6+88
.LPIC22:
	add	r3, pc, r3
	b	.L5
.L4:
	ldr	r3, .L6+92
.LPIC23:
	add	r3, pc, r3
.L5:
	mov	r1, r3
	ldr	r3, .L6+96
.LPIC24:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #16]
	ldr	r3, [r3]
	lsr	r3, r3, #16
	and	r2, r3, #3
	ldr	r3, .L6+100
.LPIC25:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+104
.LPIC26:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #16]
	ldr	r3, [r3]
	and	r2, r3, #3
	ldr	r3, .L6+108
.LPIC27:
	add	r3, pc, r3
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r3, .L6+112
.LPIC28:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L6+116
.LPIC29:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
.L1:
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L7:
	.align	2
.L6:
	.word	__func__.4-(.LPIC0+8)
	.word	.LC7-(.LPIC1+8)
	.word	.LC8-(.LPIC2+8)
	.word	.LC9-(.LPIC3+8)
	.word	.LC10-(.LPIC4+8)
	.word	.LC11-(.LPIC5+8)
	.word	.LC12-(.LPIC6+8)
	.word	.LC13-(.LPIC7+8)
	.word	.LC14-(.LPIC8+8)
	.word	.LC15-(.LPIC9+8)
	.word	cm_per_idlest-(.LPIC10+8)
	.word	.LC16-(.LPIC11+8)
	.word	cm_per_mode-(.LPIC12+8)
	.word	.LC17-(.LPIC13+8)
	.word	cm_per_idlest-(.LPIC14+8)
	.word	.LC18-(.LPIC15+8)
	.word	cm_per_mode-(.LPIC16+8)
	.word	.LC19-(.LPIC17+8)
	.word	cm_per_idlest-(.LPIC18+8)
	.word	.LC20-(.LPIC19+8)
	.word	cm_per_mode-(.LPIC20+8)
	.word	.LC21-(.LPIC21+8)
	.word	.LC22-(.LPIC22+8)
	.word	.LC23-(.LPIC23+8)
	.word	.LC24-(.LPIC24+8)
	.word	cm_per_mode-(.LPIC25+8)
	.word	.LC25-(.LPIC26+8)
	.word	cm_per_mode-(.LPIC27+8)
	.word	.LC26-(.LPIC28+8)
	.word	.LC27-(.LPIC29+8)
	.size	prcm_debug, .-prcm_debug
	.section	.rodata
	.align	2
.LC28:
	.ascii	"Fail to allocate PRCM\000"
	.align	2
.LC29:
	.ascii	"Receive NULL cm_per_base\000"
	.align	2
.LC30:
	.ascii	"%s::%d::%s::LOG::\000"
	.align	2
.LC31:
	.ascii	"PRCM cm_per_base = %p\012\000"
	.align	2
.LC32:
	.ascii	"PRCM cm_per_epwmss0 = %p\012\000"
	.align	2
.LC33:
	.ascii	"PRCM cm_per_epwmss1 = %p\012\000"
	.align	2
.LC34:
	.ascii	"PRCM cm_per_epwmss2 = %p\012\000"
	.align	2
.LC35:
	.ascii	"PRCM cm_per_pru_icss = %p\012\000"
	.text
	.align	2
	.global	prcm_init
	.syntax unified
	.arm
	.fpu vfpv3
	.type	prcm_init, %function
prcm_init:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r0, #20
	bl	malloc(PLT)
	mov	r3, r0
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	bne	.L9
	ldr	r3, .L15
.LPIC30:
	add	r3, pc, r3
	mov	r2, #59
	ldr	r1, .L15+4
.LPIC31:
	add	r1, pc, r1
	ldr	r0, .L15+8
.LPIC32:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L15+12
.LPIC33:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mov	r3, #0
	b	.L10
.L9:
	mov	r1, #0
	movt	r1, 17632
	ldr	r0, [fp, #-16]
	bl	mem_mgr_get_map(PLT)
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L11
	ldr	r3, .L15+16
.LPIC34:
	add	r3, pc, r3
	mov	r2, #65
	ldr	r1, .L15+20
.LPIC35:
	add	r1, pc, r1
	ldr	r0, .L15+24
.LPIC36:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L15+28
.LPIC37:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	nop
.L12:
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	beq	.L13
	b	.L14
.L11:
	ldr	r3, [fp, #-12]
	ldr	r2, [fp, #-8]
	str	r2, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #212
	mov	r2, r3
	ldr	r3, [fp, #-12]
	str	r2, [r3, #4]
	ldr	r3, [fp, #-8]
	add	r3, r3, #204
	mov	r2, r3
	ldr	r3, [fp, #-12]
	str	r2, [r3, #8]
	ldr	r3, [fp, #-8]
	add	r3, r3, #216
	mov	r2, r3
	ldr	r3, [fp, #-12]
	str	r2, [r3, #12]
	ldr	r3, [fp, #-8]
	add	r3, r3, #232
	mov	r2, r3
	ldr	r3, [fp, #-12]
	str	r2, [r3, #16]
	ldr	r3, .L15+32
.LPIC38:
	add	r3, pc, r3
	mov	r2, #75
	ldr	r1, .L15+36
.LPIC39:
	add	r1, pc, r1
	ldr	r0, .L15+40
.LPIC40:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, .L15+44
.LPIC41:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L15+48
.LPIC42:
	add	r3, pc, r3
	mov	r2, #76
	ldr	r1, .L15+52
.LPIC43:
	add	r1, pc, r1
	ldr	r0, .L15+56
.LPIC44:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #4]
	mov	r1, r3
	ldr	r3, .L15+60
.LPIC45:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L15+64
.LPIC46:
	add	r3, pc, r3
	mov	r2, #77
	ldr	r1, .L15+68
.LPIC47:
	add	r1, pc, r1
	ldr	r0, .L15+72
.LPIC48:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #8]
	mov	r1, r3
	ldr	r3, .L15+76
.LPIC49:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L15+80
.LPIC50:
	add	r3, pc, r3
	mov	r2, #78
	ldr	r1, .L15+84
.LPIC51:
	add	r1, pc, r1
	ldr	r0, .L15+88
.LPIC52:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #12]
	mov	r1, r3
	ldr	r3, .L15+92
.LPIC53:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, .L15+96
.LPIC54:
	add	r3, pc, r3
	mov	r2, #79
	ldr	r1, .L15+100
.LPIC55:
	add	r1, pc, r1
	ldr	r0, .L15+104
.LPIC56:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #16]
	mov	r1, r3
	ldr	r3, .L15+108
.LPIC57:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	b	.L10
.L14:
	ldr	r0, [fp, #-12]
	bl	free(PLT)
.L13:
	mov	r3, #0
.L10:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L16:
	.align	2
.L15:
	.word	__func__.3-(.LPIC30+8)
	.word	.LC7-(.LPIC31+8)
	.word	.LC8-(.LPIC32+8)
	.word	.LC28-(.LPIC33+8)
	.word	__func__.3-(.LPIC34+8)
	.word	.LC7-(.LPIC35+8)
	.word	.LC8-(.LPIC36+8)
	.word	.LC29-(.LPIC37+8)
	.word	__func__.3-(.LPIC38+8)
	.word	.LC7-(.LPIC39+8)
	.word	.LC30-(.LPIC40+8)
	.word	.LC31-(.LPIC41+8)
	.word	__func__.3-(.LPIC42+8)
	.word	.LC7-(.LPIC43+8)
	.word	.LC30-(.LPIC44+8)
	.word	.LC32-(.LPIC45+8)
	.word	__func__.3-(.LPIC46+8)
	.word	.LC7-(.LPIC47+8)
	.word	.LC30-(.LPIC48+8)
	.word	.LC33-(.LPIC49+8)
	.word	__func__.3-(.LPIC50+8)
	.word	.LC7-(.LPIC51+8)
	.word	.LC30-(.LPIC52+8)
	.word	.LC34-(.LPIC53+8)
	.word	__func__.3-(.LPIC54+8)
	.word	.LC7-(.LPIC55+8)
	.word	.LC30-(.LPIC56+8)
	.word	.LC35-(.LPIC57+8)
	.size	prcm_init, .-prcm_init
	.section	.rodata
	.align	2
.LC36:
	.ascii	"PRCM was null\000"
	.text
	.align	2
	.global	prcm_destroy
	.syntax unified
	.arm
	.fpu vfpv3
	.type	prcm_destroy, %function
prcm_destroy:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L18
	ldr	r3, .L20
.LPIC58:
	add	r3, pc, r3
	mov	r2, #94
	ldr	r1, .L20+4
.LPIC59:
	add	r1, pc, r1
	ldr	r0, .L20+8
.LPIC60:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L20+12
.LPIC61:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L19
.L18:
	ldr	r0, [fp, #-8]
	bl	free(PLT)
	mov	r3, #0
.L19:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L21:
	.align	2
.L20:
	.word	__func__.2-(.LPIC58+8)
	.word	.LC7-(.LPIC59+8)
	.word	.LC30-(.LPIC60+8)
	.word	.LC36-(.LPIC61+8)
	.size	prcm_destroy, .-prcm_destroy
	.align	2
	.global	prcm_start_all
	.syntax unified
	.arm
	.fpu vfpv3
	.type	prcm_start_all, %function
prcm_start_all:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	ldr	r0, [fp, #-16]
	bl	prcm_start_epwmss(PLT)
	str	r0, [fp, #-8]
	ldr	r0, [fp, #-16]
	bl	prcm_start_pru_icss(PLT)
	mov	r2, r0
	ldr	r3, [fp, #-8]
	orr	r3, r3, r2
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-8]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
	.size	prcm_start_all, .-prcm_start_all
	.section	.rodata
	.align	2
.LC37:
	.ascii	"Fail to enable cm_per_epwmss0\000"
	.align	2
.LC38:
	.ascii	"Fail to enable cm_per_epwmss1\000"
	.align	2
.LC39:
	.ascii	"Fail to enable cm_per_epwmss2\000"
	.text
	.align	2
	.global	prcm_start_epwmss
	.syntax unified
	.arm
	.fpu vfpv3
	.type	prcm_start_epwmss, %function
prcm_start_epwmss:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L25
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	mov	r2, #2
	str	r2, [r3]
.L25:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L26
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #8]
	mov	r2, #2
	str	r2, [r3]
.L26:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L27
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #12]
	mov	r2, #2
	str	r2, [r3]
.L27:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L28
	ldr	r3, .L32
.LPIC62:
	add	r3, pc, r3
	mov	r2, #128
	ldr	r1, .L32+4
.LPIC63:
	add	r1, pc, r1
	ldr	r0, .L32+8
.LPIC64:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L32+12
.LPIC65:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	str	r3, [fp, #-8]
.L28:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #8]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L29
	ldr	r3, .L32+16
.LPIC66:
	add	r3, pc, r3
	mov	r2, #134
	ldr	r1, .L32+20
.LPIC67:
	add	r1, pc, r1
	ldr	r0, .L32+24
.LPIC68:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L32+28
.LPIC69:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	str	r3, [fp, #-8]
.L29:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #12]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L30
	ldr	r3, .L32+32
.LPIC70:
	add	r3, pc, r3
	mov	r2, #140
	ldr	r1, .L32+36
.LPIC71:
	add	r1, pc, r1
	ldr	r0, .L32+40
.LPIC72:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L32+44
.LPIC73:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	str	r3, [fp, #-8]
.L30:
	ldr	r3, [fp, #-8]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L33:
	.align	2
.L32:
	.word	__func__.1-(.LPIC62+8)
	.word	.LC7-(.LPIC63+8)
	.word	.LC8-(.LPIC64+8)
	.word	.LC37-(.LPIC65+8)
	.word	__func__.1-(.LPIC66+8)
	.word	.LC7-(.LPIC67+8)
	.word	.LC8-(.LPIC68+8)
	.word	.LC38-(.LPIC69+8)
	.word	__func__.1-(.LPIC70+8)
	.word	.LC7-(.LPIC71+8)
	.word	.LC8-(.LPIC72+8)
	.word	.LC39-(.LPIC73+8)
	.size	prcm_start_epwmss, .-prcm_start_epwmss
	.section	.rodata
	.align	2
.LC40:
	.ascii	"Fail to enable cm_per_pru_icss_clkstctrl\000"
	.text
	.align	2
	.global	prcm_start_pru_icss
	.syntax unified
	.arm
	.fpu vfpv3
	.type	prcm_start_pru_icss, %function
prcm_start_pru_icss:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #16]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L35
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #16]
	mov	r2, #2
	str	r2, [r3]
.L35:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #16]
	ldr	r3, [r3]
	and	r3, r3, #3
	cmp	r3, #2
	beq	.L36
	ldr	r3, .L38
.LPIC74:
	add	r3, pc, r3
	mov	r2, #156
	ldr	r1, .L38+4
.LPIC75:
	add	r1, pc, r1
	ldr	r0, .L38+8
.LPIC76:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L38+12
.LPIC77:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	str	r3, [fp, #-8]
.L36:
	ldr	r3, [fp, #-8]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L39:
	.align	2
.L38:
	.word	__func__.0-(.LPIC74+8)
	.word	.LC7-(.LPIC75+8)
	.word	.LC8-(.LPIC76+8)
	.word	.LC40-(.LPIC77+8)
	.size	prcm_start_pru_icss, .-prcm_start_pru_icss
	.section	.rodata
	.align	2
	.type	__func__.4, %object
	.size	__func__.4, 11
__func__.4:
	.ascii	"prcm_debug\000"
	.align	2
	.type	__func__.3, %object
	.size	__func__.3, 10
__func__.3:
	.ascii	"prcm_init\000"
	.align	2
	.type	__func__.2, %object
	.size	__func__.2, 13
__func__.2:
	.ascii	"prcm_destroy\000"
	.align	2
	.type	__func__.1, %object
	.size	__func__.1, 18
__func__.1:
	.ascii	"prcm_start_epwmss\000"
	.align	2
	.type	__func__.0, %object
	.size	__func__.0, 20
__func__.0:
	.ascii	"prcm_start_pru_icss\000"
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621"
	.section	.note.GNU-stack,"",%progbits
