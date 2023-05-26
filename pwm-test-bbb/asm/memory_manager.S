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
	.file	"memory_manager.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"src/memory_manager.c\000"
	.align	2
.LC1:
	.ascii	"%s::%d::%s::ERROR::\000"
	.align	2
.LC2:
	.ascii	"Fail to allocate memory manager\000"
	.align	2
.LC3:
	.ascii	"/dev/mem\000"
	.align	2
.LC4:
	.ascii	"Fail to open /dev/mem\000"
	.align	2
.LC5:
	.ascii	"%s::%d::%s::LOG::\000"
	.align	2
.LC6:
	.ascii	"Open devmem file descriptor: %d\012\000"
	.text
	.align	2
	.global	mem_mgr_init
	.arch armv7-a
	.arch_extension sec
	.syntax unified
	.arm
	.fpu vfpv3
	.type	mem_mgr_init, %function
mem_mgr_init:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r0, #208
	bl	malloc(PLT)
	mov	r3, r0
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L2
	ldr	r3, .L8
.LPIC0:
	add	r3, pc, r3
	mov	r2, #15
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
	movw	r1, #4098
	movt	r1, 16
	ldr	r3, .L8+16
.LPIC4:
	add	r3, pc, r3
	mov	r0, r3
	bl	open(PLT)
	mov	r2, r0
	ldr	r3, [fp, #-8]
	str	r2, [r3]
	ldr	r3, [fp, #-8]
	ldr	r3, [r3]
	cmp	r3, #0
	bge	.L4
	ldr	r3, .L8+20
.LPIC5:
	add	r3, pc, r3
	mov	r2, #22
	ldr	r1, .L8+24
.LPIC6:
	add	r1, pc, r1
	ldr	r0, .L8+28
.LPIC7:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L8+32
.LPIC8:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	nop
.L5:
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	beq	.L6
	b	.L7
.L4:
	ldr	r3, .L8+36
.LPIC9:
	add	r3, pc, r3
	mov	r2, #25
	ldr	r1, .L8+40
.LPIC10:
	add	r1, pc, r1
	ldr	r0, .L8+44
.LPIC11:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, .L8+48
.LPIC12:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-8]
	mov	r2, #0
	str	r2, [r3, #4]
	ldr	r3, [fp, #-8]
	add	r3, r3, #8
	mov	r2, #200
	mov	r1, #0
	mov	r0, r3
	bl	memset(PLT)
	ldr	r3, [fp, #-8]
	b	.L3
.L7:
	ldr	r0, [fp, #-8]
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
	.word	__func__.2-(.LPIC0+8)
	.word	.LC0-(.LPIC1+8)
	.word	.LC1-(.LPIC2+8)
	.word	.LC2-(.LPIC3+8)
	.word	.LC3-(.LPIC4+8)
	.word	__func__.2-(.LPIC5+8)
	.word	.LC0-(.LPIC6+8)
	.word	.LC1-(.LPIC7+8)
	.word	.LC4-(.LPIC8+8)
	.word	__func__.2-(.LPIC9+8)
	.word	.LC0-(.LPIC10+8)
	.word	.LC5-(.LPIC11+8)
	.word	.LC6-(.LPIC12+8)
	.size	mem_mgr_init, .-mem_mgr_init
	.section	.rodata
	.align	2
.LC7:
	.ascii	"NULL mem_mgr\000"
	.align	2
.LC8:
	.ascii	"Unmap address at index %d: %p\012\000"
	.align	2
.LC9:
	.ascii	"Fail to unmap address at index %d: %p\012\000"
	.align	2
.LC10:
	.ascii	"Closing devmem file descriptor: %d\012\000"
	.align	2
.LC11:
	.ascii	"Fail to close file descriptor\000"
	.text
	.align	2
	.global	mem_mgr_destroy
	.syntax unified
	.arm
	.fpu vfpv3
	.type	mem_mgr_destroy, %function
mem_mgr_destroy:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-16]
	cmp	r3, #0
	bne	.L11
	ldr	r3, .L17
.LPIC13:
	add	r3, pc, r3
	mov	r2, #46
	ldr	r1, .L17+4
.LPIC14:
	add	r1, pc, r1
	ldr	r0, .L17+8
.LPIC15:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L17+12
.LPIC16:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	b	.L12
.L11:
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L13
.L15:
	ldr	r3, .L17+16
.LPIC17:
	add	r3, pc, r3
	mov	r2, #52
	ldr	r1, .L17+20
.LPIC18:
	add	r1, pc, r1
	ldr	r0, .L17+24
.LPIC19:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-12]
	add	r2, r2, #2
	ldr	r3, [r3, r2, lsl #2]
	mov	r2, r3
	ldr	r1, [fp, #-12]
	ldr	r3, .L17+28
.LPIC20:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-12]
	add	r2, r2, #2
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, #4096
	mov	r0, r3
	bl	munmap(PLT)
	mov	r3, r0
	cmn	r3, #1
	bne	.L14
	ldr	r3, .L17+32
.LPIC21:
	add	r3, pc, r3
	mov	r2, #55
	ldr	r1, .L17+36
.LPIC22:
	add	r1, pc, r1
	ldr	r0, .L17+40
.LPIC23:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-12]
	add	r2, r2, #2
	ldr	r3, [r3, r2, lsl #2]
	mov	r2, r3
	ldr	r1, [fp, #-12]
	ldr	r3, .L17+44
.LPIC24:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mvn	r3, #0
	str	r3, [fp, #-8]
.L14:
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L13:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	ldr	r2, [fp, #-12]
	cmp	r2, r3
	blt	.L15
	ldr	r3, .L17+48
.LPIC25:
	add	r3, pc, r3
	mov	r2, #60
	ldr	r1, .L17+52
.LPIC26:
	add	r1, pc, r1
	ldr	r0, .L17+56
.LPIC27:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, .L17+60
.LPIC28:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldr	r3, [r3]
	mov	r0, r3
	bl	close(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L16
	ldr	r3, .L17+64
.LPIC29:
	add	r3, pc, r3
	mov	r2, #63
	ldr	r1, .L17+68
.LPIC30:
	add	r1, pc, r1
	ldr	r0, .L17+72
.LPIC31:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L17+76
.LPIC32:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mvn	r3, #0
	str	r3, [fp, #-8]
.L16:
	ldr	r0, [fp, #-16]
	bl	free(PLT)
	ldr	r3, [fp, #-8]
.L12:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L18:
	.align	2
.L17:
	.word	__func__.1-(.LPIC13+8)
	.word	.LC0-(.LPIC14+8)
	.word	.LC1-(.LPIC15+8)
	.word	.LC7-(.LPIC16+8)
	.word	__func__.1-(.LPIC17+8)
	.word	.LC0-(.LPIC18+8)
	.word	.LC5-(.LPIC19+8)
	.word	.LC8-(.LPIC20+8)
	.word	__func__.1-(.LPIC21+8)
	.word	.LC0-(.LPIC22+8)
	.word	.LC1-(.LPIC23+8)
	.word	.LC9-(.LPIC24+8)
	.word	__func__.1-(.LPIC25+8)
	.word	.LC0-(.LPIC26+8)
	.word	.LC5-(.LPIC27+8)
	.word	.LC10-(.LPIC28+8)
	.word	__func__.1-(.LPIC29+8)
	.word	.LC0-(.LPIC30+8)
	.word	.LC1-(.LPIC31+8)
	.word	.LC11-(.LPIC32+8)
	.size	mem_mgr_destroy, .-mem_mgr_destroy
	.section	.rodata
	.align	2
.LC12:
	.ascii	"NULL target_addr\000"
	.align	2
.LC13:
	.ascii	"mem_mgr devmem file descriptor is not valid (%d)\012"
	.ascii	"\000"
	.align	2
.LC14:
	.ascii	"Allocating more than %d addresses\012\000"
	.align	2
.LC15:
	.ascii	"Fail to get memory map for target 0x%08lX\012\000"
	.align	2
.LC16:
	.ascii	"Add map for target address 0x%08lX - index %d mappe"
	.ascii	"d addr: %p\012\000"
	.text
	.align	2
	.global	mem_mgr_get_map
	.syntax unified
	.arm
	.fpu vfpv3
	.type	mem_mgr_get_map, %function
mem_mgr_get_map:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	ldr	r3, [fp, #-16]
	cmp	r3, #0
	bne	.L20
	ldr	r3, .L26
.LPIC33:
	add	r3, pc, r3
	mov	r2, #77
	ldr	r1, .L26+4
.LPIC34:
	add	r1, pc, r1
	ldr	r0, .L26+8
.LPIC35:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L26+12
.LPIC36:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mov	r3, #0
	b	.L21
.L20:
	ldr	r3, [fp, #-20]
	cmp	r3, #0
	bne	.L22
	ldr	r3, .L26+16
.LPIC37:
	add	r3, pc, r3
	mov	r2, #83
	ldr	r1, .L26+20
.LPIC38:
	add	r1, pc, r1
	ldr	r0, .L26+24
.LPIC39:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, .L26+28
.LPIC40:
	add	r3, pc, r3
	mov	r0, r3
	bl	puts(PLT)
	mov	r3, #0
	b	.L21
.L22:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3]
	cmp	r3, #0
	bge	.L23
	ldr	r3, .L26+32
.LPIC41:
	add	r3, pc, r3
	mov	r2, #89
	ldr	r1, .L26+36
.LPIC42:
	add	r1, pc, r1
	ldr	r0, .L26+40
.LPIC43:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r3, .L26+44
.LPIC44:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r3, #0
	b	.L21
.L23:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	cmp	r3, #49
	ble	.L24
	ldr	r3, .L26+48
.LPIC45:
	add	r3, pc, r3
	mov	r2, #95
	ldr	r1, .L26+52
.LPIC46:
	add	r1, pc, r1
	ldr	r0, .L26+56
.LPIC47:
	add	r0, pc, r0
	bl	printf(PLT)
	mov	r1, #50
	ldr	r3, .L26+60
.LPIC48:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r3, #0
	b	.L21
.L24:
	ldr	r3, [fp, #-16]
	ldr	r2, [r3]
	ldr	r3, [fp, #-20]
	bic	r3, r3, #4080
	bic	r3, r3, #15
	str	r3, [sp, #4]
	str	r2, [sp]
	mov	r3, #1
	mov	r2, #3
	mov	r1, #4096
	mov	r0, #0
	bl	mmap(PLT)
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmn	r3, #1
	bne	.L25
	ldr	r3, .L26+64
.LPIC49:
	add	r3, pc, r3
	mov	r2, #102
	ldr	r1, .L26+68
.LPIC50:
	add	r1, pc, r1
	ldr	r0, .L26+72
.LPIC51:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-20]
	bic	r3, r3, #4080
	bic	r3, r3, #15
	mov	r1, r3
	ldr	r3, .L26+76
.LPIC52:
	add	r3, pc, r3
	mov	r0, r3
	bl	printf(PLT)
	mov	r3, #0
	b	.L21
.L25:
	ldr	r3, [fp, #-16]
	ldr	r2, [r3, #4]
	ldr	r3, [fp, #-16]
	add	r2, r2, #2
	ldr	r1, [fp, #-8]
	str	r1, [r3, r2, lsl #2]
	ldr	r3, .L26+80
.LPIC53:
	add	r3, pc, r3
	mov	r2, #108
	ldr	r1, .L26+84
.LPIC54:
	add	r1, pc, r1
	ldr	r0, .L26+88
.LPIC55:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-20]
	bic	r1, r3, #4080
	bic	r1, r1, #15
	ldr	r3, [fp, #-16]
	ldr	r0, [r3, #4]
	ldr	r3, [fp, #-16]
	ldr	r2, [r3, #4]
	ldr	r3, [fp, #-16]
	add	r2, r2, #2
	ldr	r3, [r3, r2, lsl #2]
	mov	r2, r0
	ldr	r0, .L26+92
.LPIC56:
	add	r0, pc, r0
	bl	printf(PLT)
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	add	r2, r3, #1
	ldr	r3, [fp, #-16]
	str	r2, [r3, #4]
	ldr	r3, [fp, #-20]
	ubfx	r3, r3, #0, #12
	ldr	r2, [fp, #-8]
	add	r3, r2, r3
.L21:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L27:
	.align	2
.L26:
	.word	__func__.0-(.LPIC33+8)
	.word	.LC0-(.LPIC34+8)
	.word	.LC1-(.LPIC35+8)
	.word	.LC7-(.LPIC36+8)
	.word	__func__.0-(.LPIC37+8)
	.word	.LC0-(.LPIC38+8)
	.word	.LC1-(.LPIC39+8)
	.word	.LC12-(.LPIC40+8)
	.word	__func__.0-(.LPIC41+8)
	.word	.LC0-(.LPIC42+8)
	.word	.LC1-(.LPIC43+8)
	.word	.LC13-(.LPIC44+8)
	.word	__func__.0-(.LPIC45+8)
	.word	.LC0-(.LPIC46+8)
	.word	.LC1-(.LPIC47+8)
	.word	.LC14-(.LPIC48+8)
	.word	__func__.0-(.LPIC49+8)
	.word	.LC0-(.LPIC50+8)
	.word	.LC1-(.LPIC51+8)
	.word	.LC15-(.LPIC52+8)
	.word	__func__.0-(.LPIC53+8)
	.word	.LC0-(.LPIC54+8)
	.word	.LC5-(.LPIC55+8)
	.word	.LC16-(.LPIC56+8)
	.size	mem_mgr_get_map, .-mem_mgr_get_map
	.section	.rodata
	.align	2
	.type	__func__.2, %object
	.size	__func__.2, 13
__func__.2:
	.ascii	"mem_mgr_init\000"
	.align	2
	.type	__func__.1, %object
	.size	__func__.1, 16
__func__.1:
	.ascii	"mem_mgr_destroy\000"
	.align	2
	.type	__func__.0, %object
	.size	__func__.0, 16
__func__.0:
	.ascii	"mem_mgr_get_map\000"
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621"
	.section	.note.GNU-stack,"",%progbits
