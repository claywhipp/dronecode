	.arch armv5te
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"rtGetInf.c"
	.global	__aeabi_f2d
	.text
	.align	2
	.global	rtGetInf
	.type	rtGetInf, %function
rtGetInf:
	.fnstart
.LFB0:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	.save {fp, lr}
.LCFI0:
	.setfp fp, sp, #4
	add	fp, sp, #4
.LCFI1:
	.pad #24
	sub	sp, sp, #24
.LCFI2:
	mov	r3, #64
	str	r3, [fp, #-16]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [fp, #-12]
	ldr	r3, [fp, #-16]
	cmp	r3, #32
	bne	.L2
	bl	rtGetInfF(PLT)
	mov	r3, r0
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-12]
	b	.L3
.L2:
	ldr	r3, .L5
	str	r3, [fp, #-24]
	mov	r3, #0
	str	r3, [fp, #-28]
	ldrd	r2, [fp, #-28]
	strd	r2, [fp, #-12]
.L3:
	ldrd	r2, [fp, #-12]
	mov	r0, r2
	mov	r1, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.L6:
	.align	2
.L5:
	.word	2146435072
.LFE0:
	.fnend
	.size	rtGetInf, .-rtGetInf
	.align	2
	.global	rtGetInfF
	.type	rtGetInfF, %function
rtGetInfF:
	.fnstart
.LFB1:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI3:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI4:
	.pad #12
	sub	sp, sp, #12
.LCFI5:
	ldr	r3, .L9
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-8]	@ float
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L10:
	.align	2
.L9:
	.word	2139095040
.LFE1:
	.fnend
	.size	rtGetInfF, .-rtGetInfF
	.align	2
	.global	rtGetMinusInf
	.type	rtGetMinusInf, %function
rtGetMinusInf:
	.fnstart
.LFB2:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	.save {fp, lr}
.LCFI6:
	.setfp fp, sp, #4
	add	fp, sp, #4
.LCFI7:
	.pad #24
	sub	sp, sp, #24
.LCFI8:
	mov	r3, #64
	str	r3, [fp, #-16]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [fp, #-12]
	ldr	r3, [fp, #-16]
	cmp	r3, #32
	bne	.L12
	bl	rtGetMinusInfF(PLT)
	mov	r3, r0
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-12]
	b	.L13
.L12:
	ldr	r3, .L15
	str	r3, [fp, #-24]
	mov	r3, #0
	str	r3, [fp, #-28]
	ldrd	r2, [fp, #-28]
	strd	r2, [fp, #-12]
.L13:
	ldrd	r2, [fp, #-12]
	mov	r0, r2
	mov	r1, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.L16:
	.align	2
.L15:
	.word	-1048576
.LFE2:
	.fnend
	.size	rtGetMinusInf, .-rtGetMinusInf
	.align	2
	.global	rtGetMinusInfF
	.type	rtGetMinusInfF, %function
rtGetMinusInfF:
	.fnstart
.LFB3:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI9:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI10:
	.pad #12
	sub	sp, sp, #12
.LCFI11:
	ldr	r3, .L19
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-8]	@ float
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L20:
	.align	2
.L19:
	.word	-8388608
.LFE3:
	.fnend
	.size	rtGetMinusInfF, .-rtGetMinusInfF
	.ident	"GCC: (Sourcery G++ Lite 2009q3-67) 4.4.1"
	.section	.note.GNU-stack,"",%progbits
