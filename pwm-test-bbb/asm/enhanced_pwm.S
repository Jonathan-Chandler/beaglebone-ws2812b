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
	.file	"enhanced_pwm.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"TBCTL  \000"
	.align	2
.LC1:
	.ascii	"TBSTS  \000"
	.align	2
.LC2:
	.ascii	"TBPHSHR\000"
	.align	2
.LC3:
	.ascii	"TBPHS  \000"
	.align	2
.LC4:
	.ascii	"TBCNT  \000"
	.align	2
.LC5:
	.ascii	"TBPRD  \000"
	.align	2
.LC6:
	.ascii	"FILL0  \000"
	.align	2
.LC7:
	.ascii	"CMPCTL \000"
	.align	2
.LC8:
	.ascii	"CMPAHR \000"
	.align	2
.LC9:
	.ascii	"CMPA   \000"
	.align	2
.LC10:
	.ascii	"CMPB   \000"
	.align	2
.LC11:
	.ascii	"AQCTLA \000"
	.align	2
.LC12:
	.ascii	"AQCTLB \000"
	.align	2
.LC13:
	.ascii	"AQSFRC \000"
	.align	2
.LC14:
	.ascii	"AQCSFRC\000"
	.align	2
.LC15:
	.ascii	"DBCTL  \000"
	.align	2
.LC16:
	.ascii	"DBRED  \000"
	.align	2
.LC17:
	.ascii	"DBFED  \000"
	.align	2
.LC18:
	.ascii	"TZSEL  \000"
	.align	2
.LC19:
	.ascii	"FILL1  \000"
	.align	2
.LC20:
	.ascii	"TZCTL  \000"
	.align	2
.LC21:
	.ascii	"TZEINT \000"
	.align	2
.LC22:
	.ascii	"TZFLG  \000"
	.align	2
.LC23:
	.ascii	"TZCLR  \000"
	.align	2
.LC24:
	.ascii	"TZFRC  \000"
	.align	2
.LC25:
	.ascii	"ETSEL  \000"
	.align	2
.LC26:
	.ascii	"ETPS   \000"
	.align	2
.LC27:
	.ascii	"ETFLG  \000"
	.align	2
.LC28:
	.ascii	"ETCLR  \000"
	.align	2
.LC29:
	.ascii	"ETFRC  \000"
	.align	2
.LC30:
	.ascii	"PCCTL  \000"
	.section	.data.rel.local,"aw"
	.align	2
	.type	epwm_reg_name, %object
	.size	epwm_reg_name, 124
epwm_reg_name:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	.LC7
	.word	.LC8
	.word	.LC9
	.word	.LC10
	.word	.LC11
	.word	.LC12
	.word	.LC13
	.word	.LC14
	.word	.LC15
	.word	.LC16
	.word	.LC17
	.word	.LC18
	.word	.LC19
	.word	.LC20
	.word	.LC21
	.word	.LC22
	.word	.LC23
	.word	.LC24
	.word	.LC25
	.word	.LC26
	.word	.LC27
	.word	.LC28
	.word	.LC29
	.word	.LC30
	.section	.rodata
	.align	2
.LC31:
	.ascii	"------------------------------------------------EPW"
	.ascii	"M DBG----------------------------------------------"
	.ascii	"---\000"
	.align	2
.LC32:
	.ascii	"%s: %04X\012\000"
	.align	2
.LC33:
	.ascii	"&EPWM->TBCTL - 0x%X\012\000"
	.align	2
.LC34:
	.ascii	"&EPWM->CMPB - 0x%X\012\000"
	.align	2
.LC35:
	.ascii	"&EPWM->PCCTL - 0x%X\012\000"
	.align	2
.LC36:
	.ascii	"EPWM->TBCTL.FREE_SOFT != TB_FS_FREE - 0x%X\012\000"
	.align	2
.LC37:
	.ascii	"EPWM->TBCTL.PHSDIR != TB_UP - 0x%X\012\000"
	.align	2
.LC38:
	.ascii	"EPWM->TBCTL.CLKDIV != TB_DIV1 - 0x%X\012\000"
	.align	2
.LC39:
	.ascii	"EPWM->TBCTL.HSPCLKDIV != TB_DIV1 - 0x%X\012\000"
	.align	2
.LC40:
	.ascii	"EPWM->TBCTL.SYNCOSEL != TB_SYNC_DISABLE - 0x%X\012\000"
	.align	2
.LC41:
	.ascii	"EPWM->TBCTL.PRDLD != TB_IMMEDIATE - 0x%X\012\000"
	.align	2
.LC42:
	.ascii	"EPWM->TBCTL.PHSEN != TB_DISABLE - 0x%X\012\000"
	.align	2
.LC43:
	.ascii	"EPWM->TBCTL.CTRMODE != TB_COUNT_UP - 0x%X\012\000"
	.align	2
.LC44:
	.ascii	"EPWM->TBPRD: %X\012\000"
	.align	2
.LC45:
	.ascii	"EPWM->TBCNT: %X\012\000"
	.align	2
.LC46:
	.ascii	"EPWM->PCCTL.CHPEN: %X\012\000"
	.align	2
.LC47:
	.ascii	"EPWM->CMPCTL.LOADBMODE: %X\012\000"
	.align	2
.LC48:
	.ascii	"EPWM->AQCTLB.CBU: %X\012\000"
	.align	2
.LC49:
	.ascii	"EPWM->AQCTLB.ZRO: %X\012\000"
	.align	2
.LC50:
	.ascii	"EPWM->AQCSFRC: %X\012\000"
	.align	2
.LC51:
	.ascii	"EPWM->ETPS.INTPRD: %X\012\000"
	.align	2
.LC52:
	.ascii	"EPWM->CMPB: %X\012\000"
	.align	2
.LC53:
	.ascii	"---------------------------------------------------"
	.ascii	"---------------------------------------------------"
	.ascii	"---\000"
	.text
	.align	2
	.global	epwm_debug
	.arch armv7-a
	.arch_extension sec
	.syntax unified
	.arm
	.fpu vfpv3
	.type	epwm_debug, %function
epwm_debug:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	ldr	r3, [fp, #-16]
	str	r3, [fp, #-8]
	ldr	r3, .L21
.LPIC0:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L2
.L3:
	ldr	r3, .L21+4
.LPIC1:
	add	r3, pc, r3
	ldr	r2, [fp, #-12]
	ldr	r1, [r3, r2, lsl #2]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #1
	ldr	r2, [fp, #-8]
	add	r3, r2, r3
	ldrh	r3, [r3]
	mov	r2, r3
	ldr	r3, .L21+8
.LPIC2:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L2:
	ldr	r3, [fp, #-12]
	cmp	r3, #30
	bls	.L3
	ldr	r3, [fp, #-16]
	mov	r1, r3
	ldr	r3, .L21+12
.LPIC3:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	add	r3, r3, #20
	mov	r1, r3
	ldr	r3, .L21+16
.LPIC4:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	add	r3, r3, #60
	mov	r1, r3
	ldr	r3, .L21+20
.LPIC5:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #1]	@ zero_extendqisi2
	bic	r3, r3, #63
	uxtb	r3, r3
	cmp	r3, #128
	beq	.L4
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #1]
	ubfx	r3, r3, #6, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+24
.LPIC6:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L4:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #1]	@ zero_extendqisi2
	and	r3, r3, #32
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L5
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #1]
	ubfx	r3, r3, #5, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+28
.LPIC7:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L5:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #1]	@ zero_extendqisi2
	and	r3, r3, #28
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L6
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #1]
	ubfx	r3, r3, #2, #3
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+32
.LPIC8:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L6:
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3]
	and	r3, r3, #896
	uxth	r3, r3
	cmp	r3, #0
	beq	.L7
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3]	@ movhi
	ubfx	r3, r3, #7, #3
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+36
.LPIC9:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L7:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]	@ zero_extendqisi2
	and	r3, r3, #48
	uxtb	r3, r3
	cmp	r3, #48
	beq	.L8
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]
	ubfx	r3, r3, #4, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+40
.LPIC10:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L8:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]	@ zero_extendqisi2
	and	r3, r3, #8
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L9
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]
	ubfx	r3, r3, #3, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+44
.LPIC11:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L9:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]	@ zero_extendqisi2
	and	r3, r3, #4
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L10
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]
	ubfx	r3, r3, #2, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+48
.LPIC12:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L10:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]	@ zero_extendqisi2
	and	r3, r3, #3
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L11
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3]
	ubfx	r3, r3, #0, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+52
.LPIC13:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L11:
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #10]
	cmp	r3, #125
	beq	.L12
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #10]
	mov	r1, r3
	ldr	r3, .L21+56
.LPIC14:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L12:
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #8]
	cmp	r3, #0
	beq	.L13
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #8]
	mov	r1, r3
	ldr	r3, .L21+60
.LPIC15:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L13:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #60]	@ zero_extendqisi2
	and	r3, r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L14
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #60]
	ubfx	r3, r3, #0, #1
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+64
.LPIC16:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L14:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #14]	@ zero_extendqisi2
	and	r3, r3, #12
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L15
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #14]
	ubfx	r3, r3, #2, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+68
.LPIC17:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L15:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #25]	@ zero_extendqisi2
	and	r3, r3, #3
	uxtb	r3, r3
	cmp	r3, #1
	beq	.L16
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #25]
	ubfx	r3, r3, #0, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+72
.LPIC18:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L16:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #24]	@ zero_extendqisi2
	and	r3, r3, #3
	uxtb	r3, r3
	cmp	r3, #2
	beq	.L17
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #24]
	ubfx	r3, r3, #0, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+76
.LPIC19:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L17:
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #28]
	cmp	r3, #0
	beq	.L18
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #28]
	mov	r1, r3
	ldr	r3, .L21+80
.LPIC20:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L18:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #52]	@ zero_extendqisi2
	and	r3, r3, #3
	uxtb	r3, r3
	cmp	r3, #1
	beq	.L19
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #52]
	ubfx	r3, r3, #0, #2
	uxtb	r3, r3
	mov	r1, r3
	ldr	r3, .L21+84
.LPIC21:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L19:
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #20]
	cmp	r3, #90
	beq	.L20
	ldr	r3, [fp, #-16]
	ldrh	r3, [r3, #20]
	mov	r1, r3
	ldr	r3, .L21+88
.LPIC22:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
.L20:
	ldr	r3, .L21+92
.LPIC23:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L22:
	.align	2
.L21:
	.word	.LC31-(.LPIC0+8)
	.word	epwm_reg_name-(.LPIC1+8)
	.word	.LC32-(.LPIC2+8)
	.word	.LC33-(.LPIC3+8)
	.word	.LC34-(.LPIC4+8)
	.word	.LC35-(.LPIC5+8)
	.word	.LC36-(.LPIC6+8)
	.word	.LC37-(.LPIC7+8)
	.word	.LC38-(.LPIC8+8)
	.word	.LC39-(.LPIC9+8)
	.word	.LC40-(.LPIC10+8)
	.word	.LC41-(.LPIC11+8)
	.word	.LC42-(.LPIC12+8)
	.word	.LC43-(.LPIC13+8)
	.word	.LC44-(.LPIC14+8)
	.word	.LC45-(.LPIC15+8)
	.word	.LC46-(.LPIC16+8)
	.word	.LC47-(.LPIC17+8)
	.word	.LC48-(.LPIC18+8)
	.word	.LC49-(.LPIC19+8)
	.word	.LC50-(.LPIC20+8)
	.word	.LC51-(.LPIC21+8)
	.word	.LC52-(.LPIC22+8)
	.word	.LC53-(.LPIC23+8)
	.size	epwm_debug, .-epwm_debug
	.align	2
	.global	epwm_test_size
	.syntax unified
	.arm
	.fpu vfpv3
	.type	epwm_test_size, %function
epwm_test_size:
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
	.size	epwm_test_size, .-epwm_test_size
	.section	.rodata
	.align	2
.LC54:
	.ascii	"src/enhanced_pwm.c\000"
	.align	2
.LC55:
	.ascii	"%s::%d::%s::LOG::\000"
	.align	2
.LC56:
	.ascii	"EPWM mapped to address %p\012\000"
	.text
	.align	2
	.global	epwm_init
	.syntax unified
	.arm
	.fpu vfpv3
	.type	epwm_init, %function
epwm_init:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	bl	epwm_test_size(PLT)
	mov	r3, r0
	cmp	r3, #0
	bge	.L26
	mov	r3, #0
	b	.L27
.L26:
	ldr	r3, [fp, #-16]
	add	r3, r3, #512
	str	r3, [fp, #-8]
	ldr	r3, .L28
.LPIC24:
	add	r3, pc, r3
	mov	r2, #126
	ldr	r1, .L28+4
.LPIC25:
	add	r1, pc, r1
	ldr	r0, .L28+8
.LPIC26:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r1, [fp, #-8]
	ldr	r3, .L28+12
.LPIC27:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
.L27:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L29:
	.align	2
.L28:
	.word	__func__.2-(.LPIC24+8)
	.word	.LC54-(.LPIC25+8)
	.word	.LC55-(.LPIC26+8)
	.word	.LC56-(.LPIC27+8)
	.size	epwm_init, .-epwm_init
	.section	.rodata
	.align	2
.LC57:
	.ascii	"EPWM was null\000"
	.text
	.align	2
	.global	epwm_destroy
	.syntax unified
	.arm
	.fpu vfpv3
	.type	epwm_destroy, %function
epwm_destroy:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L31
	ldr	r3, .L33
.LPIC28:
	add	r3, pc, r3
	mov	r2, #135
	ldr	r1, .L33+4
.LPIC29:
	add	r1, pc, r1
	ldr	r0, .L33+8
.LPIC30:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L33+12
.LPIC31:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L32
.L31:
	mov	r3, #0
.L32:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L34:
	.align	2
.L33:
	.word	__func__.1-(.LPIC28+8)
	.word	.LC54-(.LPIC29+8)
	.word	.LC55-(.LPIC30+8)
	.word	.LC57-(.LPIC31+8)
	.size	epwm_destroy, .-epwm_destroy
	.section	.rodata
	.align	2
.LC58:
	.ascii	"test: EPWM->TBCTL: %04X\012\000"
	.align	2
.LC59:
	.ascii	"test: shadow_epwm.TBCTL: %04X\012\000"
	.align	2
.LC60:
	.ascii	"tbcnt = %u\012\000"
	.align	2
.LC61:
	.ascii	"timeout_count = %d\012\000"
	.text
	.align	2
	.global	epwm_configure
	.syntax unified
	.arm
	.fpu vfpv3
	.type	epwm_configure, %function
epwm_configure:
	@ args = 0, pretend = 0, frame = 96
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #96
	str	r0, [fp, #-96]
	ldr	r2, .L48
.LPIC46:
	add	r2, pc, r2
	ldr	r3, .L48+4
	ldr	r3, [r2, r3]
	ldr	r3, [r3]
	str	r3, [fp, #-8]
	mov	r3, #0
	mov	r3, #0
	strb	r3, [fp, #-89]
	mov	r3, #0
	str	r3, [fp, #-80]
	sub	r3, fp, #72
	str	r3, [fp, #-76]
	sub	r3, fp, #72
	mov	r2, #62
	mov	r1, #0
	mov	r0, r3
	bl	memset(PLT)
	ldr	r3, [fp, #-96]
	cmp	r3, #0
	bne	.L36
	ldr	r3, .L48+8
.LPIC32:
	add	r3, pc, r3
	mov	r2, #156
	ldr	r1, .L48+12
.LPIC33:
	add	r1, pc, r1
	ldr	r0, .L48+16
.LPIC34:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L48+20
.LPIC35:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L46
.L36:
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #1]
	mov	r1, #2
	bfi	r3, r1, #6, #2
	strb	r3, [r2, #1]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #1]
	orr	r3, r3, #32
	strb	r3, [r2, #1]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #1]
	bfc	r3, #2, #3
	strb	r3, [r2, #1]
	ldr	r2, [fp, #-96]
	ldrh	r3, [r2]	@ movhi
	bfc	r3, #7, #3
	strh	r3, [r2]	@ movhi
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2]
	orr	r3, r3, #64
	strb	r3, [r2]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2]
	orr	r3, r3, #48
	strb	r3, [r2]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2]
	orr	r3, r3, #8
	strb	r3, [r2]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2]
	bfc	r3, #2, #1
	strb	r3, [r2]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2]
	bfc	r3, #0, #2
	strb	r3, [r2]
	ldr	r3, [fp, #-96]
	ldrh	r3, [r3]
	mov	r1, r3
	ldr	r3, .L48+24
.LPIC36:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldrb	r3, [fp, #-71]
	mov	r2, #2
	bfi	r3, r2, #6, #2
	strb	r3, [fp, #-71]
	ldrb	r3, [fp, #-71]
	orr	r3, r3, #32
	strb	r3, [fp, #-71]
	ldrb	r3, [fp, #-71]
	bfc	r3, #2, #3
	strb	r3, [fp, #-71]
	ldrh	r3, [fp, #-72]	@ movhi
	bfc	r3, #7, #3
	strh	r3, [fp, #-72]	@ movhi
	ldrb	r3, [fp, #-72]
	orr	r3, r3, #64
	strb	r3, [fp, #-72]
	ldrb	r3, [fp, #-72]
	orr	r3, r3, #48
	strb	r3, [fp, #-72]
	ldrb	r3, [fp, #-72]
	orr	r3, r3, #8
	strb	r3, [fp, #-72]
	ldrb	r3, [fp, #-72]
	bfc	r3, #2, #1
	strb	r3, [fp, #-72]
	ldrb	r3, [fp, #-72]
	bfc	r3, #0, #2
	strb	r3, [fp, #-72]
	ldr	r3, [fp, #-76]
	ldrh	r3, [r3]
	mov	r1, r3
	ldr	r3, .L48+28
.LPIC37:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldrh	r2, [fp, #-72]
	ldr	r3, [fp, #-96]
	strh	r2, [r3]	@ unaligned
	ldr	r3, [fp, #-96]
	mov	r2, #125
	strh	r2, [r3, #10]	@ movhi
	ldr	r3, [fp, #-96]
	mov	r2, #0
	strh	r2, [r3, #8]	@ movhi
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #60]
	orr	r3, r3, #1
	strb	r3, [r2, #60]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #14]
	bfc	r3, #2, #2
	strb	r3, [r2, #14]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #25]
	mov	r1, #1
	bfi	r3, r1, #0, #2
	strb	r3, [r2, #25]
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #24]
	mov	r1, #2
	bfi	r3, r1, #0, #2
	strb	r3, [r2, #24]
	ldr	r3, [fp, #-96]
	mov	r2, #0
	strh	r2, [r3, #28]	@ movhi
	ldr	r2, [fp, #-96]
	ldrb	r3, [r2, #52]
	mov	r1, #1
	bfi	r3, r1, #0, #2
	strb	r3, [r2, #52]
	ldr	r3, [fp, #-96]
	mov	r2, #0
	strh	r2, [r3, #20]	@ movhi
	mov	r3, #0
	str	r3, [fp, #-88]
	b	.L38
.L45:
	ldr	r3, [fp, #-96]
	mov	r2, #1
	strh	r2, [r3, #56]	@ movhi
	ldr	r3, [fp, #-96]
	mov	r2, #90
	strh	r2, [r3, #20]	@ movhi
	b	.L39
.L44:
	mov	r3, #0
	str	r3, [fp, #-84]
	b	.L40
.L42:
	ldr	r3, [fp, #-84]
	cmp	r3, #49
	ble	.L41
	mov	r3, #1
	strb	r3, [fp, #-89]
	ldr	r3, [fp, #-80]
	add	r3, r3, #1
	str	r3, [fp, #-80]
.L41:
	ldr	r3, [fp, #-84]
	add	r3, r3, #1
	str	r3, [fp, #-84]
.L40:
	ldr	r3, [fp, #-84]
	cmp	r3, #50
	ble	.L42
.L39:
	ldr	r3, [fp, #-96]
	ldrb	r3, [r3, #15]	@ zero_extendqisi2
	and	r3, r3, #2
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L43
	ldrb	r3, [fp, #-89]
	eor	r3, r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L44
.L43:
	ldr	r3, .L48+32
.LPIC38:
	add	r3, pc, r3
	mov	r2, #226
	ldr	r1, .L48+36
.LPIC39:
	add	r1, pc, r1
	ldr	r0, .L48+40
.LPIC40:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-96]
	ldrh	r3, [r3, #8]
	mov	r1, r3
	ldr	r3, .L48+44
.LPIC41:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r3, #0
	strb	r3, [fp, #-89]
	ldr	r3, [fp, #-88]
	add	r3, r3, #1
	str	r3, [fp, #-88]
.L38:
	ldr	r3, [fp, #-88]
	cmp	r3, #49
	ble	.L45
	ldr	r3, .L48+48
.LPIC42:
	add	r3, pc, r3
	mov	r2, #230
	ldr	r1, .L48+52
.LPIC43:
	add	r1, pc, r1
	ldr	r0, .L48+56
.LPIC44:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r1, [fp, #-80]
	ldr	r3, .L48+60
.LPIC45:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r3, #0
.L46:
	ldr	r1, .L48+64
.LPIC47:
	add	r1, pc, r1
	ldr	r2, .L48+4
	ldr	r2, [r1, r2]
	ldr	r1, [r2]
	ldr	r2, [fp, #-8]
	eors	r1, r2, r1
	mov	r2, #0
	beq	.L47
	bl	__stack_chk_fail(PLT)
.L47:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L49:
	.align	2
.L48:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC46+8)
	.word	__stack_chk_guard(GOT)
	.word	__func__.0-(.LPIC32+8)
	.word	.LC54-(.LPIC33+8)
	.word	.LC55-(.LPIC34+8)
	.word	.LC57-(.LPIC35+8)
	.word	.LC58-(.LPIC36+8)
	.word	.LC59-(.LPIC37+8)
	.word	__func__.0-(.LPIC38+8)
	.word	.LC54-(.LPIC39+8)
	.word	.LC55-(.LPIC40+8)
	.word	.LC60-(.LPIC41+8)
	.word	__func__.0-(.LPIC42+8)
	.word	.LC54-(.LPIC43+8)
	.word	.LC55-(.LPIC44+8)
	.word	.LC61-(.LPIC45+8)
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC47+8)
	.size	epwm_configure, .-epwm_configure
	.section	.rodata
	.align	2
	.type	__func__.2, %object
	.size	__func__.2, 10
__func__.2:
	.ascii	"epwm_init\000"
	.align	2
	.type	__func__.1, %object
	.size	__func__.1, 13
__func__.1:
	.ascii	"epwm_destroy\000"
	.align	2
	.type	__func__.0, %object
	.size	__func__.0, 15
__func__.0:
	.ascii	"epwm_configure\000"
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621"
	.section	.note.GNU-stack,"",%progbits
