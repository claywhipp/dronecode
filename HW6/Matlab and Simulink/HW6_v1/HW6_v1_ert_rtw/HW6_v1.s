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
	.file	"HW6_v1.c"
	.comm	cmd_inport,36,4
	.comm	sensor_inport,2496,8
	.comm	motors_outport,16,4
	.comm	flag_outport,1,1
	.comm	HW6_v1_B,400,8
	.comm	HW6_v1_X,80,8
	.comm	HW6_v1_DW,96,8
	.comm	HW6_v1_Y,20,4
	.comm	HW6_v1_M_,696,8
	.global	HW6_v1_M
	.section	.data.rel.ro,"aw",%progbits
	.align	2
	.type	HW6_v1_M, %object
	.size	HW6_v1_M, 4
HW6_v1_M:
	.word	HW6_v1_M_
	.global	__aeabi_dmul
	.global	__aeabi_dadd
	.text
	.align	2
	.type	rt_ertODEUpdateContinuousStates, %function
rt_ertODEUpdateContinuousStates:
	.fnstart
.LFB0:
	@ args = 0, pretend = 0, frame = 88
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, fp, lr}
	.save {r4, r5, r6, r7, r8, r9, fp, lr}
.LCFI0:
	.setfp fp, sp, #28
	add	fp, sp, #28
.LCFI1:
	.pad #88
	sub	sp, sp, #88
.LCFI2:
	ldr	r4, .L13
.LPIC0:
	add	r4, pc, r4
	str	r0, [fp, #-112]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #124]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3]
	strd	r2, [fp, #-84]
	ldr	r3, [fp, #-112]
	ldrd	r2, [r3, #24]
	strd	r2, [fp, #-76]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #32]
	ldrd	r2, [r3]
	strd	r2, [fp, #-68]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #132]
	ldr	r3, [r3, #0]
	str	r3, [fp, #-60]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #8]
	str	r3, [fp, #-56]
	ldr	r3, [fp, #-56]
	ldr	r3, [r3, #0]
	str	r3, [fp, #-52]
	ldr	r3, [fp, #-56]
	ldr	r3, [r3, #4]
	str	r3, [fp, #-48]
	ldr	r3, [fp, #-56]
	ldr	r3, [r3, #8]
	str	r3, [fp, #-44]
	ldr	r3, [fp, #-56]
	ldr	r3, [r3, #12]
	str	r3, [fp, #-40]
	mov	r3, #10
	str	r3, [fp, #-32]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #0]
	ldr	r3, [fp, #-32]
	mov	r3, r3, asl #3
	ldr	r0, [fp, #-52]
	ldr	r1, [fp, #-60]
	mov	r2, r3
	bl	memcpy(PLT)
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #120]
	ldr	r2, [fp, #-48]
	str	r2, [r3, #0]
	bl	HW6_v1_derivatives(PLT)
	ldr	r3, .L13+4
	add	r3, r4, r3
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-108]
	mov	r3, #0
	str	r3, [fp, #-36]
	b	.L2
.L3:
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-60]
	add	r5, r2, r3
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-52]
	add	r3, r2, r3
	ldrd	r6, [r3]
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-48]
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldrd	r2, [fp, #-108]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [r5]
	ldr	r3, [fp, #-36]
	add	r3, r3, #1
	str	r3, [fp, #-36]
.L2:
	ldr	r2, [fp, #-36]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L3
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #124]
	ldr	r5, [r3, #0]
	ldr	r3, .L13+8
	add	r3, r4, r3
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-84]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [r5]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #120]
	ldr	r2, [fp, #-44]
	str	r2, [r3, #0]
	bl	HW6_v1_step(PLT)
	bl	HW6_v1_derivatives(PLT)
	mov	r3, #0
	str	r3, [fp, #-36]
	b	.L4
.L5:
	ldr	r5, [fp, #-36]
	ldr	r2, [fp, #-36]
	ldr	r3, .L13+4
	add	r3, r4, r3
	add	r2, r2, #3
	mov	r2, r2, asl #3
	add	r3, r2, r3
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mvn	r1, #79
	mov	r0, r5, asl #3
	sub	ip, fp, #28
	add	r0, r0, ip
	add	r1, r0, r1
	strd	r2, [r1]
	ldr	r3, [fp, #-36]
	add	r3, r3, #1
	str	r3, [fp, #-36]
.L4:
	ldr	r3, [fp, #-36]
	cmp	r3, #1
	ble	.L5
	mov	r3, #0
	str	r3, [fp, #-36]
	b	.L6
.L7:
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-60]
	add	r5, r2, r3
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-52]
	add	r3, r2, r3
	ldrd	r6, [r3]
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-48]
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldrd	r2, [fp, #-108]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r8, r2
	mov	r9, r3
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-44]
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldrd	r2, [fp, #-100]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r8
	mov	r1, r9
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [r5]
	ldr	r3, [fp, #-36]
	add	r3, r3, #1
	str	r3, [fp, #-36]
.L6:
	ldr	r2, [fp, #-36]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L7
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #124]
	ldr	r5, [r3, #0]
	ldr	r3, .L13+8
	add	r3, r4, r3
	ldrd	r2, [r3, #8]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-84]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [r5]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #120]
	ldr	r2, [fp, #-40]
	str	r2, [r3, #0]
	bl	HW6_v1_step(PLT)
	bl	HW6_v1_derivatives(PLT)
	mov	r3, #0
	str	r3, [fp, #-36]
	b	.L8
.L9:
	ldr	r5, [fp, #-36]
	ldr	r2, [fp, #-36]
	ldr	r3, .L13+4
	add	r3, r4, r3
	add	r2, r2, #6
	mov	r2, r2, asl #3
	add	r3, r2, r3
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mvn	r1, #79
	mov	r0, r5, asl #3
	sub	ip, fp, #28
	add	r0, r0, ip
	add	r1, r0, r1
	strd	r2, [r1]
	ldr	r3, [fp, #-36]
	add	r3, r3, #1
	str	r3, [fp, #-36]
.L8:
	ldr	r3, [fp, #-36]
	cmp	r3, #2
	ble	.L9
	mov	r3, #0
	str	r3, [fp, #-36]
	b	.L10
.L11:
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-60]
	add	r8, r2, r3
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-52]
	add	r3, r2, r3
	ldrd	r4, [r3]
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-48]
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldrd	r2, [fp, #-108]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-44]
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldrd	r2, [fp, #-100]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, [fp, #-36]
	mov	r2, r3, asl #3
	ldr	r3, [fp, #-40]
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldrd	r2, [fp, #-92]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r4
	mov	r1, r5
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [r8]
	ldr	r3, [fp, #-36]
	add	r3, r3, #1
	str	r3, [fp, #-36]
.L10:
	ldr	r2, [fp, #-36]
	ldr	r3, [fp, #-32]
	cmp	r2, r3
	blt	.L11
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #124]
	ldr	r1, [r3, #0]
	ldrd	r2, [fp, #-76]
	strd	r2, [r1]
	ldr	r3, [fp, #-112]
	ldr	r3, [r3, #4]
	mov	r2, #1
	str	r2, [r3, #0]
	sub	sp, fp, #28
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, fp, pc}
.L14:
	.align	2
.L13:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC0+8)
	.word	rt_ODE3_B.4071(GOTOFF)
	.word	rt_ODE3_A.4070(GOTOFF)
.LFE0:
	.fnend
	.size	rt_ertODEUpdateContinuousStates, .-rt_ertODEUpdateContinuousStates
	.align	2
	.global	HW6_v1_MeasurementUpdate_Init
	.type	HW6_v1_MeasurementUpdate_Init, %function
HW6_v1_MeasurementUpdate_Init:
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
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, [fp, #-12]
	ldrd	r2, [r3]
	ldr	r1, [fp, #-8]
	strd	r2, [r1]
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.LFE1:
	.fnend
	.size	HW6_v1_MeasurementUpdate_Init, .-HW6_v1_MeasurementUpdate_Init
	.align	2
	.global	HW6_v_MeasurementUpdate_Disable
	.type	HW6_v_MeasurementUpdate_Disable, %function
HW6_v_MeasurementUpdate_Disable:
	.fnstart
.LFB2:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI6:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI7:
	.pad #20
	sub	sp, sp, #20
.LCFI8:
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	ldr	r3, [fp, #-16]
	ldrd	r2, [r3]
	ldr	r1, [fp, #-8]
	strd	r2, [r1]
	ldr	r3, [fp, #-12]
	mov	r2, #0
	strb	r2, [r3, #0]
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.LFE2:
	.fnend
	.size	HW6_v_MeasurementUpdate_Disable, .-HW6_v_MeasurementUpdate_Disable
	.global	__aeabi_dsub
	.align	2
	.global	HW6_v1_MeasurementUpdate
	.type	HW6_v1_MeasurementUpdate, %function
HW6_v1_MeasurementUpdate:
	.fnstart
.LFB3:
	@ args = 52, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, fp, lr}
	.save {r4, r5, fp, lr}
.LCFI9:
	.setfp fp, sp, #12
	add	fp, sp, #12
.LCFI10:
	.pad #16
	sub	sp, sp, #16
.LCFI11:
	str	r0, [fp, #-16]
	strd	r2, [fp, #-28]
	mov	r3, r1
	strb	r3, [fp, #-17]
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L20
	ldrb	r3, [fp, #-17]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L21
	ldr	r3, [fp, #48]
	mov	r2, #1
	strb	r2, [r3, #0]
	b	.L20
.L21:
	ldr	r3, [fp, #48]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L20
	ldr	r0, [fp, #44]
	ldr	r1, [fp, #48]
	ldr	r2, [fp, #52]
	bl	HW6_v_MeasurementUpdate_Disable(PLT)
.L20:
	ldr	r3, [fp, #48]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L23
	ldrd	r0, [fp, #12]
	ldrd	r2, [fp, #20]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r4, r2
	mov	r5, r3
	ldrd	r0, [fp, #28]
	ldrd	r2, [fp, #36]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r4
	mov	r1, r5
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldrd	r0, [fp, #4]
	bl	__aeabi_dsub(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-28]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, [fp, #44]
	strd	r2, [r1]
.L23:
	sub	sp, fp, #12
	ldmfd	sp!, {r4, r5, fp, pc}
.LFE3:
	.fnend
	.size	HW6_v1_MeasurementUpdate, .-HW6_v1_MeasurementUpdate
	.align	2
	.global	HW6_v1_EnabledSubsystem_Init
	.type	HW6_v1_EnabledSubsystem_Init, %function
HW6_v1_EnabledSubsystem_Init:
	.fnstart
.LFB4:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI12:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI13:
	.pad #12
	sub	sp, sp, #12
.LCFI14:
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, [fp, #-12]
	ldrd	r2, [r3]
	ldr	r1, [fp, #-8]
	strd	r2, [r1]
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.LFE4:
	.fnend
	.size	HW6_v1_EnabledSubsystem_Init, .-HW6_v1_EnabledSubsystem_Init
	.align	2
	.global	HW6_v1_EnabledSubsystem_Disable
	.type	HW6_v1_EnabledSubsystem_Disable, %function
HW6_v1_EnabledSubsystem_Disable:
	.fnstart
.LFB5:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI15:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI16:
	.pad #20
	sub	sp, sp, #20
.LCFI17:
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	ldr	r3, [fp, #-16]
	ldrd	r2, [r3]
	ldr	r1, [fp, #-8]
	strd	r2, [r1]
	ldr	r3, [fp, #-12]
	mov	r2, #0
	strb	r2, [r3, #0]
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.LFE5:
	.fnend
	.size	HW6_v1_EnabledSubsystem_Disable, .-HW6_v1_EnabledSubsystem_Disable
	.align	2
	.global	HW6_v1_EnabledSubsystem
	.type	HW6_v1_EnabledSubsystem, %function
HW6_v1_EnabledSubsystem:
	.fnstart
.LFB6:
	@ args = 36, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	.save {fp, lr}
.LCFI18:
	.setfp fp, sp, #4
	add	fp, sp, #4
.LCFI19:
	.pad #16
	sub	sp, sp, #16
.LCFI20:
	str	r0, [fp, #-8]
	strd	r2, [fp, #-20]
	mov	r3, r1
	strb	r3, [fp, #-9]
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L29
	ldrb	r3, [fp, #-9]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L30
	ldr	r3, [fp, #32]
	mov	r2, #1
	strb	r2, [r3, #0]
	b	.L29
.L30:
	ldr	r3, [fp, #32]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L29
	ldr	r0, [fp, #28]
	ldr	r1, [fp, #32]
	ldr	r2, [fp, #36]
	bl	HW6_v1_EnabledSubsystem_Disable(PLT)
.L29:
	ldr	r3, [fp, #32]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L32
	ldrd	r0, [fp, #4]
	ldrd	r2, [fp, #20]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldrd	r0, [fp, #12]
	bl	__aeabi_dsub(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-20]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, [fp, #28]
	strd	r2, [r1]
.L32:
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.LFE6:
	.fnend
	.size	HW6_v1_EnabledSubsystem, .-HW6_v1_EnabledSubsystem
	.global	__aeabi_ui2d
	.global	__aeabi_f2d
	.global	__aeabi_dcmpgt
	.global	__aeabi_dcmplt
	.global	__aeabi_d2f
	.global	__aeabi_ddiv
	.global	__aeabi_dcmpeq
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Simulation finished\000"
	.text
	.align	2
	.global	HW6_v1_step
	.type	HW6_v1_step, %function
HW6_v1_step:
	.fnstart
.LFB7:
	@ args = 0, pretend = 0, frame = 184
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, fp, lr}
	.save {r4, r5, r6, r7, r8, r9, fp, lr}
.LCFI21:
	.setfp fp, sp, #28
	add	fp, sp, #28
.LCFI22:
	.pad #240
	sub	sp, sp, #240
.LCFI23:
	ldr	r4, .L94+8
.LPIC1:
	add	r4, pc, r4
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L34
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r5, [r3, #0]
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #632]
	add	r3, r3, #1
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [r5, #32]
.L34:
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #0
	bne	.L35
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r1, [r3, #672]
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #132]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3]
	strd	r2, [r1]
.L35:
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #52]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #168]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #56]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #176]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #56]
	bl	__aeabi_dsub(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #184]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #68]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #192]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #72]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #200]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #76]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #208]
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L36
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #464]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L37
.L38:
	mov	r3, #1
	mov	r5, r3
.L37:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L39
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #464]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
	b	.L40
.L39:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #468]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmplt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L41
.L42:
	mov	r3, #1
	mov	r5, r3
.L41:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L43
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #468]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
	b	.L40
.L43:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
.L40:
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]	@ float
	ldr	r3, .L94+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #464]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L44
.L45:
	mov	r3, #1
	mov	r5, r3
.L44:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L46
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #464]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
	b	.L47
.L46:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #468]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmplt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L48
.L49:
	mov	r3, #1
	mov	r5, r3
.L48:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L50
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #468]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
	b	.L47
.L50:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
.L47:
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #4]	@ float
	ldr	r3, .L94+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #464]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L51
.L52:
	mov	r3, #1
	mov	r5, r3
.L51:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L53
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #464]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
	b	.L54
.L53:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #468]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmplt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L55
.L56:
	mov	r3, #1
	mov	r5, r3
.L55:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L57
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #468]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
	b	.L54
.L57:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
.L54:
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #8]	@ float
	ldr	r3, .L94+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #464]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L58
.L59:
	mov	r3, #1
	mov	r5, r3
.L58:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L60
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #464]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
	b	.L61
.L60:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #16]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #468]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmplt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L62
.L63:
	mov	r3, #1
	mov	r5, r3
.L62:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L64
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #468]	@ float
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
	b	.L61
.L64:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
.L61:
	ldr	r3, .L94+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #12]	@ float
	ldr	r3, .L94+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #479]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L65
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #478]	@ zero_extendqisi2
	ldr	r3, .L94+20
	ldr	r3, [r4, r3]
	strb	r2, [r3, #0]
	b	.L66
.L65:
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #477]	@ zero_extendqisi2
	ldr	r3, .L94+20
	ldr	r3, [r4, r3]
	strb	r2, [r3, #0]
.L66:
	ldr	r3, .L94+20
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #0]	@ zero_extendqisi2
	ldr	r3, .L94+16
	ldr	r3, [r4, r3]
	strb	r2, [r3, #16]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #416]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L94+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
	ldr	r3, .L94+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #16]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #24]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #4]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #32]
	ldr	r3, .L94+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #40]
	ldr	r3, .L94+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #24]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #48]
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #56]
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #176]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #64]
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #72]
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #80]
	ldr	r3, .L94+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #32]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #88]
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #192]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #96]
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #200]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #104]
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #208]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #112]
	ldr	r3, .L94+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #120]
	ldr	r3, .L94+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #48]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #128]
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L94
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-100]
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L67
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #48]
	mov	r2, r3
	sub	r3, fp, #100
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	mov	r2, r3
	bl	rt_UpdateStructLogVar(PLT)
.L67:
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #416]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r0, [r4, r1]
	mov	r1, #272
	strd	r2, [r0, r1]
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #76]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L68
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #120]
	ldr	r1, .L94+36
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #128]
	ldr	r1, .L94+36
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
.L68:
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L94+40
	ldr	r0, [r4, r1]
	mov	r1, #296
	strd	r2, [r0, r1]
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L94+40
	ldr	r0, [r4, r1]
	mov	r1, #304
	strd	r2, [r0, r1]
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L69
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #472]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L70
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #81]
	b	.L69
.L95:
	.align	3
.L94:
	.word	1202590843
	.word	1064598241
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC1+8)
	.word	motors_outport(GOT)
	.word	HW6_v1_Y(GOT)
	.word	flag_outport(GOT)
	.word	HW6_v1_X(GOT)
	.word	sensor_inport(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_M(GOT)
.L70:
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #81]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L69
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #240]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #248]
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #81]
.L69:
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #81]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L71
	ldr	r3, .L94+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #416]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r6, r0
	mov	r7, r1
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #104]
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r8, r2
	mov	r9, r3
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #112]
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r8
	mov	r1, r9
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dsub(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r0, [r4, r1]
	mov	r1, #280
	strd	r2, [r0, r1]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #88]
	ldr	r3, .L94+40
	ldr	r2, [r4, r3]
	mov	r3, #280
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #240]
	ldr	r3, .L94+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #96]
	ldr	r3, .L94+40
	ldr	r2, [r4, r3]
	mov	r3, #280
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #248]
.L71:
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #240]
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #136]
	ldr	r3, .L94+40
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #248]
	ldr	r3, .L94+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L94+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #144]
	ldr	r3, .L94+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L96
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-108]
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L72
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #52]
	mov	r2, r3
	sub	r3, fp, #108
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L96+20
	ldr	r3, [r4, r3]
	add	r2, r3, #136
	bl	rt_UpdateStructLogVar(PLT)
.L72:
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L96
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-116]
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L73
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #56]
	mov	r1, r3
	ldr	r3, .L96+20
	ldr	r3, [r4, r3]
	add	r3, r3, #144
	sub	r2, fp, #116
	mov	r0, r1
	mov	r1, r2
	mov	r2, r3
	bl	rt_UpdateStructLogVar(PLT)
.L73:
	ldr	r3, .L96+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L96+20
	ldr	r0, [r4, r1]
	mov	r1, #312
	strd	r2, [r0, r1]
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #77]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L74
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #152]
	ldr	r1, .L96+8
	ldr	r1, [r4, r1]
	strd	r2, [r1, #16]
.L74:
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	ldr	r1, .L96+20
	ldr	r0, [r4, r1]
	mov	r1, #320
	strd	r2, [r0, r1]
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #473]	@ zero_extendqisi2
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #136]
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrd	r8, [r3, #144]
	ldr	r3, .L96+20
	ldr	r2, [r4, r3]
	mov	r3, #312
	ldrd	r0, [r2, r3]
	ldr	r3, .L96+20
	ldr	r2, [r4, r3]
	mov	r3, #320
	add	r3, r3, r2
	ldrd	r2, [r3]
	strd	r8, [sp]
	strd	r0, [sp, #8]
	strd	r2, [sp, #16]
	ldr	r3, .L96+20
	ldr	r3, [r4, r3]
	add	r3, r3, #352
	str	r3, [sp, #24]
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	add	r3, r3, #85
	str	r3, [sp, #28]
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	add	r3, r3, #496
	str	r3, [sp, #32]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L96+20
	ldr	r2, [r4, r3]
	mov	r3, #352
	ldrd	r0, [r2, r3]
	ldr	r3, .L96+20
	ldr	r2, [r4, r3]
	mov	r3, #320
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L96+20
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L96
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-124]
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L75
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]
	mov	r2, r3
	sub	r3, fp, #124
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L96+20
	ldr	r3, [r4, r3]
	add	r2, r3, #328
	bl	rt_UpdateStructLogVar(PLT)
.L75:
	ldr	r3, .L96+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #4]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-92]
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #78]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L76
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #176]
	ldr	r1, .L96+8
	ldr	r1, [r4, r1]
	strd	r2, [r1, #24]
.L76:
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #24]
	strd	r2, [fp, #-84]
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	r0, [r3, #0]
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrb	r1, [r3, #474]	@ zero_extendqisi2
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #160]
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	strd	r2, [sp]
	ldrd	r2, [fp, #-92]
	strd	r2, [sp, #8]
	ldrd	r2, [fp, #-84]
	strd	r2, [sp, #16]
	ldr	r3, .L96+20
	ldr	r3, [r4, r3]
	add	r3, r3, #336
	str	r3, [sp, #24]
	ldr	r3, .L96+8
	ldr	r3, [r4, r3]
	add	r3, r3, #83
	str	r3, [sp, #28]
	b	.L97
.L98:
	.align	3
.L96:
	.word	1202590843
	.word	1064598241
	.word	HW6_v1_DW(GOT)
	.word	sensor_inport(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_M(GOT)
.L97:
	ldr	r3, .L96+16
	ldr	r3, [r4, r3]
	add	r3, r3, #480
	str	r3, [sp, #32]
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L96+20
	ldr	r2, [r4, r3]
	mov	r3, #336
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-84]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L96+20
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L96+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L99
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-132]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L36
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #64]
	mov	r2, r3
	sub	r3, fp, #132
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	add	r2, r3, #328
	bl	rt_UpdateStructLogVar(PLT)
.L36:
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #176]
	ldr	r3, .L99+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_ddiv(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L99+20
	ldr	r0, [r4, r1]
	mov	r1, #280
	strd	r2, [r0, r1]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L77
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #79]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L78
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #200]
	ldr	r1, .L99+12
	ldr	r1, [r4, r1]
	strd	r2, [r1, #32]
.L78:
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #32]
	strd	r2, [fp, #-76]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #475]	@ zero_extendqisi2
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #184]
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #192]
	ldr	r3, .L99+20
	ldr	r2, [r4, r3]
	mov	r3, #280
	add	r3, r3, r2
	ldrd	r2, [r3]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	ldrd	r2, [fp, #-76]
	strd	r2, [sp, #16]
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	add	r3, r3, #384
	str	r3, [sp, #24]
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	add	r3, r3, #89
	str	r3, [sp, #28]
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	add	r3, r3, #528
	str	r3, [sp, #32]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L99+20
	ldr	r2, [r4, r3]
	mov	r3, #384
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-76]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L99+20
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L99
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-140]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L77
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #68]
	mov	r2, r3
	sub	r3, fp, #140
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	add	r2, r3, #328
	bl	rt_UpdateStructLogVar(PLT)
.L77:
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #224]
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #176]
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #176]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r8, r2
	mov	r9, r3
	ldr	r3, .L99+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	strd	r0, [fp, #-188]
	ldr	r3, .L99+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldrd	r0, [fp, #-188]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r8
	mov	r1, r9
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	bl	sqrt(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_ddiv(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L99+20
	ldr	r0, [r4, r1]
	mov	r1, #288
	strd	r2, [r0, r1]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L79
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #80]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L80
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #232]
	ldr	r1, .L99+12
	ldr	r1, [r4, r1]
	strd	r2, [r1, #40]
.L80:
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	b	.L100
.L101:
	.align	3
.L99:
	.word	1202590843
	.word	1064598241
	.word	sensor_inport(GOT)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_M(GOT)
.L100:
	ldrd	r2, [r3, #40]
	strd	r2, [fp, #-68]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #476]	@ zero_extendqisi2
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #208]
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #216]
	ldr	r3, .L99+20
	ldr	r2, [r4, r3]
	mov	r3, #288
	add	r3, r3, r2
	ldrd	r2, [r3]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	ldrd	r2, [fp, #-68]
	strd	r2, [sp, #16]
	ldr	r3, .L99+20
	ldr	r3, [r4, r3]
	add	r3, r3, #368
	str	r3, [sp, #24]
	ldr	r3, .L99+12
	ldr	r3, [r4, r3]
	add	r3, r3, #87
	str	r3, [sp, #28]
	ldr	r3, .L99+16
	ldr	r3, [r4, r3]
	add	r3, r3, #512
	str	r3, [sp, #32]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L99+20
	ldr	r2, [r4, r3]
	mov	r3, #368
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L99+20
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L99+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L102
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-148]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L79
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #72]
	mov	r2, r3
	sub	r3, fp, #148
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	add	r2, r3, #328
	bl	rt_UpdateStructLogVar(PLT)
.L79:
	ldr	r3, .L102+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #56]
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #216]
	ldr	r3, .L102+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #64]
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #224]
	ldr	r3, .L102+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #72]
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #232]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L81
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #264
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-76]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #475]	@ zero_extendqisi2
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #280
	ldrd	r6, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #280
	ldrd	r0, [r2, r3]
	strd	r0, [fp, #-180]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r8, [r3, #192]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #288
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-208]
	ldr	r3, [fp, #-208]
	ldrd	r2, [r3, #192]
	strd	r2, [fp, #-204]
	ldrd	r2, [fp, #-180]
	strd	r2, [sp]
	strd	r8, [sp, #8]
	ldrd	r8, [fp, #-76]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-204]
	strd	r0, [sp, #32]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	add	r3, r3, #392
	str	r3, [sp, #40]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	add	r3, r3, #90
	str	r3, [sp, #44]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	add	r3, r3, #536
	str	r3, [sp, #48]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #272
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #192]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #328
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #392
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-60]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #304
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #200]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #476]	@ zero_extendqisi2
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #312
	ldrd	r6, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #288
	ldrd	r0, [r2, r3]
	strd	r0, [fp, #-172]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r8, [r3, #216]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #320
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-208]
	ldr	r3, [fp, #-208]
	ldrd	r2, [r3, #200]
	strd	r2, [fp, #-204]
	ldrd	r2, [fp, #-172]
	strd	r2, [sp]
	strd	r8, [sp, #8]
	ldrd	r8, [fp, #-68]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-204]
	strd	r0, [sp, #32]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	add	r3, r3, #376
	str	r3, [sp, #40]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	add	r3, r3, #88
	str	r3, [sp, #44]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	add	r3, r3, #520
	str	r3, [sp, #48]
	b	.L103
.L104:
	.align	3
.L102:
	.word	1202590843
	.word	1064598241
	.word	HW6_v1_X(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_M(GOT)
.L103:
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #296
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #328
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #376
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-52]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #336
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #473]	@ zero_extendqisi2
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #344
	ldrd	r6, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #312
	ldrd	r0, [r2, r3]
	strd	r0, [fp, #-164]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #144]
	strd	r0, [fp, #-156]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #320
	ldrd	r8, [r2, r3]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #352
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-208]
	ldr	r3, [fp, #-208]
	ldrd	r2, [r3, #168]
	strd	r2, [fp, #-204]
	ldrd	r2, [fp, #-164]
	strd	r2, [sp]
	ldrd	r2, [fp, #-156]
	strd	r2, [sp, #8]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-204]
	strd	r0, [sp, #32]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	add	r3, r3, #360
	str	r3, [sp, #40]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	add	r3, r3, #86
	str	r3, [sp, #44]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	add	r3, r3, #504
	str	r3, [sp, #48]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #328
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #320
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #328
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #360
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-44]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #368
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #176]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #474]	@ zero_extendqisi2
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #376
	ldrd	r6, [r2, r3]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r8, [r3, #168]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #384
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-208]
	ldr	r3, [fp, #-208]
	ldrd	r2, [r3, #176]
	strd	r2, [fp, #-204]
	ldrd	r2, [fp, #-92]
	strd	r2, [fp, #-196]
	ldrd	r2, [fp, #-196]
	strd	r2, [sp]
	strd	r8, [sp, #8]
	ldrd	r8, [fp, #-84]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-204]
	strd	r0, [sp, #32]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	add	r3, r3, #344
	str	r3, [sp, #40]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	add	r3, r3, #84
	str	r3, [sp, #44]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	add	r3, r3, #488
	str	r3, [sp, #48]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #360
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-84]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #328
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #344
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-36]
	ldr	r3, .L102+16
	ldr	r1, [r4, r3]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [r1, #136]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #136]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #392
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #296
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #136]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #136]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #408
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #304
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #136]
	ldr	r3, .L102+16
	ldr	r1, [r4, r3]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [r1, #144]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #144]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #400
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #296
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #144]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #144]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #416
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #304
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #144]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L82
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #472]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L83
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #82]
	b	.L82
.L83:
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #82]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L82
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #256
	strd	r2, [r0, r1]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #264
	strd	r2, [r0, r1]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #82]
.L82:
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #82]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L84
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #456
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #272
	ldrd	r6, [r2, r3]
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #104]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #296
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r8, r2
	mov	r9, r3
	ldr	r3, .L102+12
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #112]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #304
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r8
	mov	r1, r9
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #328
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dsub(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #280
	strd	r2, [r0, r1]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #440
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #280
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #256
	strd	r2, [r0, r1]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #448
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #280
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r0, [r4, r1]
	mov	r1, #264
	strd	r2, [r0, r1]
.L84:
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #424
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #136]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #256
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #152]
	ldr	r3, .L102+12
	ldr	r2, [r4, r3]
	mov	r3, #432
	ldrd	r0, [r2, r3]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #144]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L102+16
	ldr	r2, [r4, r3]
	mov	r3, #264
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L102+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #160]
.L81:
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L85
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #4]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #672]
	mov	r0, r2
	mov	r1, r3
	bl	rt_UpdateTXYLogVars(PLT)
.L85:
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L86
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L86
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #76]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #152]
	ldr	r1, .L102+20
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L102+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #160]
	ldr	r1, .L102+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #77]
	ldr	r3, .L102+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-44]
	strd	r2, [r1, #16]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #78]
	ldr	r3, .L102+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-36]
	strd	r2, [r1, #24]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #79]
	ldr	r3, .L102+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-60]
	strd	r2, [r1, #32]
	ldr	r3, .L102+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #80]
	ldr	r3, .L102+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-52]
	strd	r2, [r1, #40]
.L86:
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L92
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	mov	r2, #0
	mov	r3, #-1090519040
	add	r3, r3, #15728640
	bl	__aeabi_dcmpeq(PLT)
	mov	r3, r0
	cmp	r3, #0
	bne	.L88
.L93:
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r6, [r2, r3]
	ldr	r3, .L102+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L105
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, .L105+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L105+8
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	mov	r2, #0
	mov	r3, #1015021568
	add	r3, r3, #3145728
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L90
.L91:
	mov	r3, #1
	mov	r5, r3
.L90:
	and	r3, r5, #255
	eor	r3, r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L88
	ldr	r3, .L105+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L105+20
	add	r2, r4, r2
	str	r2, [r3, #0]
.L88:
	ldr	r3, .L105+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	add	r3, r3, #8
	mov	r0, r3
	bl	rt_ertODEUpdateContinuousStates(PLT)
	ldr	r3, .L105+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #632]
	add	r2, r2, #1
	str	r2, [r3, #632]
	ldr	r3, .L105+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r1, [r3, #672]
	ldr	r3, .L105+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #32]
	strd	r2, [r1]
	ldr	r3, .L105+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #648]
	add	r2, r2, #1
	str	r2, [r3, #648]
.L92:
	sub	sp, fp, #28
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, fp, pc}
.L106:
	.align	3
.L105:
	.word	1202590843
	.word	-1082885407
	.word	1202590843
	.word	1064598241
	.word	HW6_v1_M(GOT)
	.word	.LC0(GOTOFF)
.LFE7:
	.fnend
	.size	HW6_v1_step, .-HW6_v1_step
	.align	2
	.global	HW6_v1_derivatives
	.type	HW6_v1_derivatives, %function
HW6_v1_derivatives:
	.fnstart
.LFB8:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI24:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI25:
	.pad #12
	sub	sp, sp, #12
.LCFI26:
	ldr	r3, .L109
.LPIC2:
	add	r3, pc, r3
	ldr	r2, .L109+4
	ldr	r2, [r3, r2]
	ldr	r2, [r2, #0]
	ldr	r2, [r2, #268]
	str	r2, [fp, #-8]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #184]
	ldr	r2, [fp, #-8]
	strd	r0, [r2]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #232]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #8]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #192]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #16]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #200]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #24]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #208]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #32]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #216]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #40]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #224]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #48]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #168]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #56]
	ldr	r2, .L109+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #176]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #64]
	ldr	r2, .L109+8
	ldr	r3, [r3, r2]
	ldrd	r2, [r3, #184]
	ldr	r1, [fp, #-8]
	strd	r2, [r1, #72]
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L110:
	.align	2
.L109:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC2+8)
	.word	HW6_v1_M(GOT)
	.word	HW6_v1_B(GOT)
.LFE8:
	.fnend
	.size	HW6_v1_derivatives, .-HW6_v1_derivatives
	.section	.rodata
	.align	2
.LC1:
	.ascii	"ode3\000"
	.align	2
.LC2:
	.ascii	"tout\000"
	.align	2
.LC3:
	.ascii	"\000"
	.align	2
.LC4:
	.ascii	"rt_\000"
	.align	2
.LC5:
	.ascii	"states\000"
	.align	2
.LC6:
	.ascii	"zkalman\000"
	.align	2
.LC7:
	.ascii	"wkalman\000"
	.align	2
.LC8:
	.ascii	"ukalman\000"
	.align	2
.LC9:
	.ascii	"vkalman\000"
	.align	2
.LC10:
	.ascii	"phikalman\000"
	.align	2
.LC11:
	.ascii	"thetakalman\000"
	.text
	.align	2
	.global	HW6_v1_initialize
	.type	HW6_v1_initialize, %function
HW6_v1_initialize:
	.fnstart
.LFB9:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, fp, lr}
	.save {r4, fp, lr}
.LCFI27:
	.setfp fp, sp, #8
	add	fp, sp, #8
.LCFI28:
	.pad #60
	sub	sp, sp, #60
.LCFI29:
	ldr	r4, .L128+8
.LPIC3:
	add	r4, pc, r4
	mov	r0, #8
	bl	rt_InitInfAndNaN(PLT)
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #696
	bl	memset(PLT)
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #664
	str	r2, [r3, #12]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #672
	str	r2, [r3, #132]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #640
	str	r2, [r3, #40]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #268
	str	r2, [r3, #128]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #256
	str	r2, [r3, #140]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #616
	str	r2, [r3, #136]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #620
	str	r2, [r3, #144]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #260
	str	r2, [r3, #148]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #264
	str	r2, [r3, #152]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	str	r2, [r3, #208]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	str	r2, [r3, #8]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #12]
	mov	r2, #1
	str	r2, [r3, #0]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #280
	str	r2, [r3, #600]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #360
	str	r2, [r3, #604]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #360
	add	r2, r2, #80
	str	r2, [r3, #608]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #360
	add	r2, r2, #160
	str	r2, [r3, #612]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+16
	ldr	r2, [r4, r2]
	str	r2, [r3, #256]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #600
	str	r2, [r3, #16]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+20
	add	r2, r4, r2
	str	r2, [r3, #20]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #680
	str	r2, [r3, #672]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r0, [r3, #0]
	mov	r1, #656
	mov	r2, #0
	mov	r3, #1073741824
	add	r3, r3, #3407872
	strd	r2, [r0, r1]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r0, [r3, #0]
	mov	r1, #640
	adr	r3, .L128
	ldrd	r2, [r3]
	strd	r2, [r0, r1]
	ldr	r3, .L128+24
	add	r3, r4, r3
	mov	r2, #0
	str	r2, [r3, #68]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L128+24
	add	r2, r4, r2
	str	r2, [r3, #4]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #48]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #4]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L128+28
	add	r2, r4, r2
	str	r2, [r3, #28]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L128+32
	add	r2, r4, r2
	str	r2, [r3, #32]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L128+32
	add	r2, r4, r2
	str	r2, [r3, #36]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L128+36
	add	r2, r4, r2
	str	r2, [r3, #24]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #2
	str	r2, [r3, #12]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #16]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #1
	str	r2, [r3, #20]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L128+32
	add	r2, r4, r2
	str	r2, [r3, #40]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #52]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #8]
	ldr	r3, .L128+40
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #400
	bl	memset(PLT)
	ldr	r3, .L128+44
	ldr	r3, [r4, r3]
	ldr	r2, .L128+48	@ float
	str	r2, [r3, #0]	@ float
	ldr	r3, .L128+44
	ldr	r3, [r4, r3]
	ldr	r2, .L128+48	@ float
	str	r2, [r3, #4]	@ float
	ldr	r3, .L128+44
	ldr	r3, [r4, r3]
	ldr	r2, .L128+48	@ float
	str	r2, [r3, #8]	@ float
	ldr	r3, .L128+44
	ldr	r3, [r4, r3]
	ldr	r2, .L128+48	@ float
	str	r2, [r3, #12]	@ float
	ldr	r3, .L128+52
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #0]
	ldr	r3, .L128+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #80
	bl	memset(PLT)
	ldr	r3, .L128+56
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #96
	bl	memset(PLT)
	ldr	r3, .L128+60
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #36
	bl	memset(PLT)
	ldr	r3, .L128+64
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #2496
	bl	memset(PLT)
	ldr	r3, .L128+68
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #20
	bl	memset(PLT)
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L128+12
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_StartDataLoggingWithStartTime(PLT)
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L128+12
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L128+72
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L128
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L128+76
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L128+80
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L128+56
	ldr	r3, [r4, r3]
	str	r2, [r3, #48]
	ldr	r3, .L128+56
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #48]
	cmp	r3, #0
	beq	.L121
.L112:
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L128+12
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	b	.L129
.L130:
	.align	3
.L128:
	.word	1202590843
	.word	1064598241
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC3+8)
	.word	HW6_v1_M(GOT)
	.word	HW6_v1_X(GOT)
	.word	.LC1(GOTOFF)
	.word	rt_DataLoggingInfo.4843(GOTOFF)
	.word	.LC2(GOTOFF)
	.word	.LC3(GOTOFF)
	.word	.LC4(GOTOFF)
	.word	HW6_v1_B(GOT)
	.word	motors_outport(GOT)
	.word	0
	.word	flag_outport(GOT)
	.word	HW6_v1_DW(GOT)
	.word	cmd_inport(GOT)
	.word	sensor_inport(GOT)
	.word	HW6_v1_Y(GOT)
	.word	.LC5(GOTOFF)
	.word	rt_ToWksSignalInfo.4855(GOTOFF)
	.word	rt_ToWksBlockName.4856(GOTOFF)
	.word	.LC6(GOTOFF)
.L129:
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L128+84
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L131
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L131+8
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L131+12
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #52]
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #52]
	cmp	r3, #0
	beq	.L122
.L114:
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L131+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L131+20
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L131
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L131+24
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L131+28
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #56]
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #56]
	cmp	r3, #0
	beq	.L123
.L115:
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L131+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L131+32
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L131
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L131+36
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L131+40
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #60]
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]
	cmp	r3, #0
	beq	.L124
.L116:
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L131+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L131+44
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L131
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L131+48
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L131+52
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #64]
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #64]
	cmp	r3, #0
	beq	.L125
.L117:
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L131+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L131+56
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L131
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L131+60
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L131+64
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #68]
	ldr	r3, .L131+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #68]
	cmp	r3, #0
	beq	.L126
.L118:
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	b	.L132
.L133:
	.align	3
.L131:
	.word	1202590843
	.word	1064598241
	.word	rt_ToWksSignalInfo.4868(GOTOFF)
	.word	rt_ToWksBlockName.4869(GOTOFF)
	.word	HW6_v1_DW(GOT)
	.word	.LC7(GOTOFF)
	.word	rt_ToWksSignalInfo.4881(GOTOFF)
	.word	rt_ToWksBlockName.4882(GOTOFF)
	.word	.LC8(GOTOFF)
	.word	rt_ToWksSignalInfo.4894(GOTOFF)
	.word	rt_ToWksBlockName.4895(GOTOFF)
	.word	.LC9(GOTOFF)
	.word	rt_ToWksSignalInfo.4907(GOTOFF)
	.word	rt_ToWksBlockName.4908(GOTOFF)
	.word	.LC10(GOTOFF)
	.word	rt_ToWksSignalInfo.4920(GOTOFF)
	.word	rt_ToWksBlockName.4921(GOTOFF)
	.word	HW6_v1_M(GOT)
	.word	.LC11(GOTOFF)
.L132:
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L131+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L131+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L131+72
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L134
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L134+8
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L134+12
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L134+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #72]
	ldr	r3, .L134+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #72]
	cmp	r3, #0
	beq	.L127
.L119:
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #24]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #32]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #16]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #48]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #24]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #64]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #32]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #72]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #40]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #80]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #48]
	ldr	r3, .L134+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #76]
	ldr	r3, .L134+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #77]
	ldr	r3, .L134+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #78]
	ldr	r3, .L134+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #79]
	ldr	r3, .L134+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #80]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #240]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #56]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #248]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #64]
	ldr	r3, .L134+20
	ldr	r2, [r4, r3]
	mov	r3, #256
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L134+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #72]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L134+28
	ldr	r1, [r4, r1]
	strd	r2, [r1, #240]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L134+28
	ldr	r1, [r4, r1]
	strd	r2, [r1, #248]
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #352
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #496
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #336
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #480
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #384
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #528
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #368
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #512
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #392
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #536
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #376
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #520
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #360
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #504
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L134+28
	ldr	r3, [r4, r3]
	add	r0, r3, #344
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	add	r1, r3, #488
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L134+28
	ldr	r0, [r4, r1]
	mov	r1, #256
	strd	r2, [r0, r1]
	ldr	r3, .L134+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L134+28
	ldr	r0, [r4, r1]
	mov	r1, #264
	strd	r2, [r0, r1]
	b	.L120
.L121:
	mov	r0, r0	@ nop
	b	.L120
.L122:
	mov	r0, r0	@ nop
	b	.L120
.L123:
	mov	r0, r0	@ nop
	b	.L120
.L124:
	mov	r0, r0	@ nop
	b	.L120
.L125:
	mov	r0, r0	@ nop
	b	.L120
.L126:
	mov	r0, r0	@ nop
	b	.L120
.L127:
	mov	r0, r0	@ nop
.L120:
	sub	sp, fp, #8
	ldmfd	sp!, {r4, fp, pc}
.L135:
	.align	3
.L134:
	.word	1202590843
	.word	1064598241
	.word	rt_ToWksSignalInfo.4933(GOTOFF)
	.word	rt_ToWksBlockName.4934(GOTOFF)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_X(GOT)
	.word	HW6_v1_B(GOT)
.LFE9:
	.fnend
	.size	HW6_v1_initialize, .-HW6_v1_initialize
	.align	2
	.global	HW6_v1_terminate
	.type	HW6_v1_terminate, %function
HW6_v1_terminate:
	.fnstart
.LFB10:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI30:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI31:
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.LFE10:
	.fnend
	.size	HW6_v1_terminate, .-HW6_v1_terminate
	.local	rt_DataLoggingInfo.4843
	.comm	rt_DataLoggingInfo.4843,72,4
	.section	.data.rel.local,"aw",%progbits
	.align	2
	.type	rt_ToWksSignalInfo.4855, %object
	.size	rt_ToWksSignalInfo.4855, 76
rt_ToWksSignalInfo.4855:
	.word	1
	.word	rt_ToWksWidths.4844
	.word	rt_ToWksNumDimensions.4845
	.word	rt_ToWksDimensions.4846
	.word	rt_ToWksIsVarDims.4847
	.word	rt_ToWksCurrSigDims.4848
	.word	rt_ToWksCurrSigDimsSize.4849
	.word	rt_ToWksDataTypeIds.4850
	.word	rt_ToWksComplexSignals.4851
	.word	rt_ToWksFrameData.4852
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4853
	.word	rt_ToWksLabels.4854
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4856, %object
	.size	rt_ToWksBlockName.4856, 43
rt_ToWksBlockName.4856:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace1\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.4868, %object
	.size	rt_ToWksSignalInfo.4868, 76
rt_ToWksSignalInfo.4868:
	.word	1
	.word	rt_ToWksWidths.4857
	.word	rt_ToWksNumDimensions.4858
	.word	rt_ToWksDimensions.4859
	.word	rt_ToWksIsVarDims.4860
	.word	rt_ToWksCurrSigDims.4861
	.word	rt_ToWksCurrSigDimsSize.4862
	.word	rt_ToWksDataTypeIds.4863
	.word	rt_ToWksComplexSignals.4864
	.word	rt_ToWksFrameData.4865
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4866
	.word	rt_ToWksLabels.4867
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4869, %object
	.size	rt_ToWksBlockName.4869, 43
rt_ToWksBlockName.4869:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace2\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.4881, %object
	.size	rt_ToWksSignalInfo.4881, 76
rt_ToWksSignalInfo.4881:
	.word	1
	.word	rt_ToWksWidths.4870
	.word	rt_ToWksNumDimensions.4871
	.word	rt_ToWksDimensions.4872
	.word	rt_ToWksIsVarDims.4873
	.word	rt_ToWksCurrSigDims.4874
	.word	rt_ToWksCurrSigDimsSize.4875
	.word	rt_ToWksDataTypeIds.4876
	.word	rt_ToWksComplexSignals.4877
	.word	rt_ToWksFrameData.4878
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4879
	.word	rt_ToWksLabels.4880
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4882, %object
	.size	rt_ToWksBlockName.4882, 43
rt_ToWksBlockName.4882:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace3\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.4894, %object
	.size	rt_ToWksSignalInfo.4894, 76
rt_ToWksSignalInfo.4894:
	.word	1
	.word	rt_ToWksWidths.4883
	.word	rt_ToWksNumDimensions.4884
	.word	rt_ToWksDimensions.4885
	.word	rt_ToWksIsVarDims.4886
	.word	rt_ToWksCurrSigDims.4887
	.word	rt_ToWksCurrSigDimsSize.4888
	.word	rt_ToWksDataTypeIds.4889
	.word	rt_ToWksComplexSignals.4890
	.word	rt_ToWksFrameData.4891
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4892
	.word	rt_ToWksLabels.4893
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4895, %object
	.size	rt_ToWksBlockName.4895, 43
rt_ToWksBlockName.4895:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace4\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.4907, %object
	.size	rt_ToWksSignalInfo.4907, 76
rt_ToWksSignalInfo.4907:
	.word	1
	.word	rt_ToWksWidths.4896
	.word	rt_ToWksNumDimensions.4897
	.word	rt_ToWksDimensions.4898
	.word	rt_ToWksIsVarDims.4899
	.word	rt_ToWksCurrSigDims.4900
	.word	rt_ToWksCurrSigDimsSize.4901
	.word	rt_ToWksDataTypeIds.4902
	.word	rt_ToWksComplexSignals.4903
	.word	rt_ToWksFrameData.4904
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4905
	.word	rt_ToWksLabels.4906
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4908, %object
	.size	rt_ToWksBlockName.4908, 43
rt_ToWksBlockName.4908:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace5\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.4920, %object
	.size	rt_ToWksSignalInfo.4920, 76
rt_ToWksSignalInfo.4920:
	.word	1
	.word	rt_ToWksWidths.4909
	.word	rt_ToWksNumDimensions.4910
	.word	rt_ToWksDimensions.4911
	.word	rt_ToWksIsVarDims.4912
	.word	rt_ToWksCurrSigDims.4913
	.word	rt_ToWksCurrSigDimsSize.4914
	.word	rt_ToWksDataTypeIds.4915
	.word	rt_ToWksComplexSignals.4916
	.word	rt_ToWksFrameData.4917
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4918
	.word	rt_ToWksLabels.4919
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4921, %object
	.size	rt_ToWksBlockName.4921, 43
rt_ToWksBlockName.4921:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace6\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.4933, %object
	.size	rt_ToWksSignalInfo.4933, 76
rt_ToWksSignalInfo.4933:
	.word	1
	.word	rt_ToWksWidths.4922
	.word	rt_ToWksNumDimensions.4923
	.word	rt_ToWksDimensions.4924
	.word	rt_ToWksIsVarDims.4925
	.word	rt_ToWksCurrSigDims.4926
	.word	rt_ToWksCurrSigDimsSize.4927
	.word	rt_ToWksDataTypeIds.4928
	.word	rt_ToWksComplexSignals.4929
	.word	rt_ToWksFrameData.4930
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4931
	.word	rt_ToWksLabels.4932
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4934, %object
	.size	rt_ToWksBlockName.4934, 43
rt_ToWksBlockName.4934:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace7\000"
	.align	2
.LC12:
	.ascii	"z\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4932, %object
	.size	rt_ToWksLabels.4932, 4
rt_ToWksLabels.4932:
	.word	.LC12
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4931
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4931,4,4
	.local	rt_ToWksFrameData.4930
	.comm	rt_ToWksFrameData.4930,4,4
	.local	rt_ToWksComplexSignals.4929
	.comm	rt_ToWksComplexSignals.4929,4,4
	.local	rt_ToWksDataTypeIds.4928
	.comm	rt_ToWksDataTypeIds.4928,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4927, %object
	.size	rt_ToWksCurrSigDimsSize.4927, 4
rt_ToWksCurrSigDimsSize.4927:
	.word	4
	.local	rt_ToWksCurrSigDims.4926
	.comm	rt_ToWksCurrSigDims.4926,4,4
	.local	rt_ToWksIsVarDims.4925
	.comm	rt_ToWksIsVarDims.4925,1,4
	.align	2
	.type	rt_ToWksDimensions.4924, %object
	.size	rt_ToWksDimensions.4924, 4
rt_ToWksDimensions.4924:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.4923, %object
	.size	rt_ToWksNumDimensions.4923, 4
rt_ToWksNumDimensions.4923:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4922, %object
	.size	rt_ToWksWidths.4922, 4
rt_ToWksWidths.4922:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4919, %object
	.size	rt_ToWksLabels.4919, 4
rt_ToWksLabels.4919:
	.word	.LC12
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4918
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4918,4,4
	.local	rt_ToWksFrameData.4917
	.comm	rt_ToWksFrameData.4917,4,4
	.local	rt_ToWksComplexSignals.4916
	.comm	rt_ToWksComplexSignals.4916,4,4
	.local	rt_ToWksDataTypeIds.4915
	.comm	rt_ToWksDataTypeIds.4915,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4914, %object
	.size	rt_ToWksCurrSigDimsSize.4914, 4
rt_ToWksCurrSigDimsSize.4914:
	.word	4
	.local	rt_ToWksCurrSigDims.4913
	.comm	rt_ToWksCurrSigDims.4913,4,4
	.local	rt_ToWksIsVarDims.4912
	.comm	rt_ToWksIsVarDims.4912,1,4
	.align	2
	.type	rt_ToWksDimensions.4911, %object
	.size	rt_ToWksDimensions.4911, 4
rt_ToWksDimensions.4911:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.4910, %object
	.size	rt_ToWksNumDimensions.4910, 4
rt_ToWksNumDimensions.4910:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4909, %object
	.size	rt_ToWksWidths.4909, 4
rt_ToWksWidths.4909:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4906, %object
	.size	rt_ToWksLabels.4906, 4
rt_ToWksLabels.4906:
	.word	.LC12
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4905
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4905,4,4
	.local	rt_ToWksFrameData.4904
	.comm	rt_ToWksFrameData.4904,4,4
	.local	rt_ToWksComplexSignals.4903
	.comm	rt_ToWksComplexSignals.4903,4,4
	.local	rt_ToWksDataTypeIds.4902
	.comm	rt_ToWksDataTypeIds.4902,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4901, %object
	.size	rt_ToWksCurrSigDimsSize.4901, 4
rt_ToWksCurrSigDimsSize.4901:
	.word	4
	.local	rt_ToWksCurrSigDims.4900
	.comm	rt_ToWksCurrSigDims.4900,4,4
	.local	rt_ToWksIsVarDims.4899
	.comm	rt_ToWksIsVarDims.4899,1,4
	.align	2
	.type	rt_ToWksDimensions.4898, %object
	.size	rt_ToWksDimensions.4898, 4
rt_ToWksDimensions.4898:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.4897, %object
	.size	rt_ToWksNumDimensions.4897, 4
rt_ToWksNumDimensions.4897:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4896, %object
	.size	rt_ToWksWidths.4896, 4
rt_ToWksWidths.4896:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4893, %object
	.size	rt_ToWksLabels.4893, 4
rt_ToWksLabels.4893:
	.word	.LC12
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4892
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4892,4,4
	.local	rt_ToWksFrameData.4891
	.comm	rt_ToWksFrameData.4891,4,4
	.local	rt_ToWksComplexSignals.4890
	.comm	rt_ToWksComplexSignals.4890,4,4
	.local	rt_ToWksDataTypeIds.4889
	.comm	rt_ToWksDataTypeIds.4889,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4888, %object
	.size	rt_ToWksCurrSigDimsSize.4888, 4
rt_ToWksCurrSigDimsSize.4888:
	.word	4
	.local	rt_ToWksCurrSigDims.4887
	.comm	rt_ToWksCurrSigDims.4887,4,4
	.local	rt_ToWksIsVarDims.4886
	.comm	rt_ToWksIsVarDims.4886,1,4
	.align	2
	.type	rt_ToWksDimensions.4885, %object
	.size	rt_ToWksDimensions.4885, 4
rt_ToWksDimensions.4885:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.4884, %object
	.size	rt_ToWksNumDimensions.4884, 4
rt_ToWksNumDimensions.4884:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4883, %object
	.size	rt_ToWksWidths.4883, 4
rt_ToWksWidths.4883:
	.word	1
	.section	.rodata
	.align	2
.LC13:
	.ascii	"w\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4880, %object
	.size	rt_ToWksLabels.4880, 4
rt_ToWksLabels.4880:
	.word	.LC13
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4879
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4879,4,4
	.local	rt_ToWksFrameData.4878
	.comm	rt_ToWksFrameData.4878,4,4
	.local	rt_ToWksComplexSignals.4877
	.comm	rt_ToWksComplexSignals.4877,4,4
	.local	rt_ToWksDataTypeIds.4876
	.comm	rt_ToWksDataTypeIds.4876,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4875, %object
	.size	rt_ToWksCurrSigDimsSize.4875, 4
rt_ToWksCurrSigDimsSize.4875:
	.word	4
	.local	rt_ToWksCurrSigDims.4874
	.comm	rt_ToWksCurrSigDims.4874,4,4
	.local	rt_ToWksIsVarDims.4873
	.comm	rt_ToWksIsVarDims.4873,1,4
	.align	2
	.type	rt_ToWksDimensions.4872, %object
	.size	rt_ToWksDimensions.4872, 4
rt_ToWksDimensions.4872:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.4871, %object
	.size	rt_ToWksNumDimensions.4871, 4
rt_ToWksNumDimensions.4871:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4870, %object
	.size	rt_ToWksWidths.4870, 4
rt_ToWksWidths.4870:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4867, %object
	.size	rt_ToWksLabels.4867, 4
rt_ToWksLabels.4867:
	.word	.LC12
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4866
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4866,4,4
	.local	rt_ToWksFrameData.4865
	.comm	rt_ToWksFrameData.4865,4,4
	.local	rt_ToWksComplexSignals.4864
	.comm	rt_ToWksComplexSignals.4864,4,4
	.local	rt_ToWksDataTypeIds.4863
	.comm	rt_ToWksDataTypeIds.4863,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4862, %object
	.size	rt_ToWksCurrSigDimsSize.4862, 4
rt_ToWksCurrSigDimsSize.4862:
	.word	4
	.local	rt_ToWksCurrSigDims.4861
	.comm	rt_ToWksCurrSigDims.4861,4,4
	.local	rt_ToWksIsVarDims.4860
	.comm	rt_ToWksIsVarDims.4860,1,4
	.align	2
	.type	rt_ToWksDimensions.4859, %object
	.size	rt_ToWksDimensions.4859, 4
rt_ToWksDimensions.4859:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.4858, %object
	.size	rt_ToWksNumDimensions.4858, 4
rt_ToWksNumDimensions.4858:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4857, %object
	.size	rt_ToWksWidths.4857, 4
rt_ToWksWidths.4857:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4854, %object
	.size	rt_ToWksLabels.4854, 4
rt_ToWksLabels.4854:
	.word	.LC3
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4853
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4853,4,4
	.local	rt_ToWksFrameData.4852
	.comm	rt_ToWksFrameData.4852,4,4
	.local	rt_ToWksComplexSignals.4851
	.comm	rt_ToWksComplexSignals.4851,4,4
	.local	rt_ToWksDataTypeIds.4850
	.comm	rt_ToWksDataTypeIds.4850,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4849, %object
	.size	rt_ToWksCurrSigDimsSize.4849, 4
rt_ToWksCurrSigDimsSize.4849:
	.word	4
	.local	rt_ToWksCurrSigDims.4848
	.comm	rt_ToWksCurrSigDims.4848,4,4
	.local	rt_ToWksIsVarDims.4847
	.comm	rt_ToWksIsVarDims.4847,1,4
	.align	2
	.type	rt_ToWksDimensions.4846, %object
	.size	rt_ToWksDimensions.4846, 4
rt_ToWksDimensions.4846:
	.word	17
	.align	2
	.type	rt_ToWksNumDimensions.4845, %object
	.size	rt_ToWksNumDimensions.4845, 4
rt_ToWksNumDimensions.4845:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4844, %object
	.size	rt_ToWksWidths.4844, 4
rt_ToWksWidths.4844:
	.word	17
	.section	.rodata
	.align	3
	.type	rt_ODE3_B.4071, %object
	.size	rt_ODE3_B.4071, 72
rt_ODE3_B.4071:
	.word	0
	.word	1071644672
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	1072168960
	.word	0
	.word	0
	.word	477218588
	.word	1070363079
	.word	1431655765
	.word	1070945621
	.word	477218588
	.word	1071411655
	.align	3
	.type	rt_ODE3_A.4070, %object
	.size	rt_ODE3_A.4070, 24
rt_ODE3_A.4070:
	.word	0
	.word	1071644672
	.word	0
	.word	1072168960
	.word	0
	.word	1072693248
	.ident	"GCC: (Sourcery G++ Lite 2009q3-67) 4.4.1"
	.section	.note.GNU-stack,"",%progbits
