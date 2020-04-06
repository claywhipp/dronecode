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
	.comm	HW6_v1_B,432,8
	.comm	HW6_v1_X,80,8
	.comm	HW6_v1_DW,112,8
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
	.word	rt_ODE3_B.4100(GOTOFF)
	.word	rt_ODE3_A.4099(GOTOFF)
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
	.global	__aeabi_dcmple
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
	@ args = 0, pretend = 0, frame = 216
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, fp, lr}
	.save {r4, r5, r6, r7, r8, r9, fp, lr}
.LCFI21:
	.setfp fp, sp, #28
	add	fp, sp, #28
.LCFI22:
	.pad #272
	sub	sp, sp, #272
.LCFI23:
	ldr	r4, .L121+8
.LPIC1:
	add	r4, pc, r4
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L34
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r5, [r3, #0]
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #632]
	add	r3, r3, #1
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	ldr	r3, .L121+44
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
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #0
	bne	.L35
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r1, [r3, #672]
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #132]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3]
	strd	r2, [r1]
.L35:
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #52]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #168]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #56]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #176]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #96]
	bl	__aeabi_dsub(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #184]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #68]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #192]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #72]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #200]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #76]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #208]
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L36
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #544]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #544]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
	b	.L40
.L39:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #548]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #548]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
	b	.L40
.L43:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #56]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
.L40:
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]	@ float
	ldr	r3, .L121+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #0]	@ float
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #544]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #544]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
	b	.L47
.L46:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #548]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #548]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
	b	.L47
.L50:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #56]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
.L47:
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #4]	@ float
	ldr	r3, .L121+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #4]	@ float
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #544]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #544]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
	b	.L54
.L53:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #548]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #548]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
	b	.L54
.L57:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #56]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
.L54:
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #8]	@ float
	ldr	r3, .L121+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #8]	@ float
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #544]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #544]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
	b	.L61
.L60:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #56]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #548]	@ float
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
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #548]	@ float
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
	b	.L61
.L64:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #56]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
.L61:
	ldr	r3, .L121+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #12]	@ float
	ldr	r3, .L121+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #12]	@ float
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #559]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L65
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #558]	@ zero_extendqisi2
	ldr	r3, .L121+20
	ldr	r3, [r4, r3]
	strb	r2, [r3, #0]
	b	.L66
.L65:
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #557]	@ zero_extendqisi2
	ldr	r3, .L121+20
	ldr	r3, [r4, r3]
	strb	r2, [r3, #0]
.L66:
	ldr	r3, .L121+20
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #0]	@ zero_extendqisi2
	ldr	r3, .L121+16
	ldr	r3, [r4, r3]
	strb	r2, [r3, #16]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #416]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L121+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
	ldr	r3, .L121+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #16]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #24]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #4]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #32]
	ldr	r3, .L121+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #40]
	ldr	r3, .L121+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #24]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #48]
	ldr	r3, .L121+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #56]
	ldr	r3, .L121+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #176]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #64]
	ldr	r3, .L121+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #72]
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #80]
	ldr	r3, .L121+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #32]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #88]
	ldr	r3, .L121+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #192]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #96]
	ldr	r3, .L121+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #200]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #104]
	ldr	r3, .L121+40
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #208]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #112]
	ldr	r3, .L121+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #120]
	ldr	r3, .L121+24
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #48]
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #128]
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L121
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-100]
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L67
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #48]
	mov	r2, r3
	sub	r3, fp, #100
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L121+40
	ldr	r3, [r4, r3]
	mov	r2, r3
	bl	rt_UpdateStructLogVar(PLT)
.L67:
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #416]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #296
	strd	r2, [r0, r1]
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #96]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L68
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #160]
	ldr	r1, .L121+36
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	ldr	r1, .L121+36
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
.L68:
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #320
	strd	r2, [r0, r1]
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #328
	strd	r2, [r0, r1]
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L69
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #552]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L70
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #101]
	b	.L69
.L122:
	.align	3
.L121:
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
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #101]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L69
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #48]
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #264
	strd	r2, [r0, r1]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #48]
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #272
	strd	r2, [r0, r1]
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #101]
.L69:
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #101]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L71
	ldr	r3, .L121+28
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #416]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r6, r0
	mov	r7, r1
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #144]
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r8, r2
	mov	r9, r3
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #152]
	ldr	r3, .L121+36
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
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #312
	strd	r2, [r0, r1]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #128]
	ldr	r3, .L121+40
	ldr	r2, [r4, r3]
	mov	r3, #312
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #264
	strd	r2, [r0, r1]
	ldr	r3, .L121+32
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #136]
	ldr	r3, .L121+40
	ldr	r2, [r4, r3]
	mov	r3, #312
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r0, [r4, r1]
	mov	r1, #272
	strd	r2, [r0, r1]
.L71:
	ldr	r3, .L121+40
	ldr	r2, [r4, r3]
	mov	r3, #264
	ldrd	r0, [r2, r3]
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #136]
	ldr	r3, .L121+40
	ldr	r2, [r4, r3]
	mov	r3, #272
	ldrd	r0, [r2, r3]
	ldr	r3, .L121+36
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #8]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L121+40
	ldr	r1, [r4, r1]
	strd	r2, [r1, #144]
	ldr	r3, .L121+44
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L123
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-108]
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L72
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #52]
	mov	r2, r3
	sub	r3, fp, #108
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L123+20
	ldr	r3, [r4, r3]
	add	r2, r3, #136
	bl	rt_UpdateStructLogVar(PLT)
.L72:
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L123
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-116]
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L73
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #56]
	mov	r1, r3
	ldr	r3, .L123+20
	ldr	r3, [r4, r3]
	add	r3, r3, #144
	sub	r2, fp, #116
	mov	r0, r1
	mov	r1, r2
	mov	r2, r3
	bl	rt_UpdateStructLogVar(PLT)
.L73:
	ldr	r3, .L123+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L123+20
	ldr	r0, [r4, r1]
	mov	r1, #336
	strd	r2, [r0, r1]
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #97]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L74
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #192]
	ldr	r1, .L123+8
	ldr	r1, [r4, r1]
	strd	r2, [r1, #16]
.L74:
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	ldr	r1, .L123+20
	ldr	r0, [r4, r1]
	mov	r1, #344
	strd	r2, [r0, r1]
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #553]	@ zero_extendqisi2
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #176]
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrd	r8, [r3, #184]
	ldr	r3, .L123+20
	ldr	r2, [r4, r3]
	mov	r3, #336
	ldrd	r0, [r2, r3]
	ldr	r3, .L123+20
	ldr	r2, [r4, r3]
	mov	r3, #344
	add	r3, r3, r2
	ldrd	r2, [r3]
	strd	r8, [sp]
	strd	r0, [sp, #8]
	strd	r2, [sp, #16]
	ldr	r3, .L123+20
	ldr	r3, [r4, r3]
	add	r3, r3, #384
	str	r3, [sp, #24]
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	add	r3, r3, #105
	str	r3, [sp, #28]
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	add	r3, r3, #576
	str	r3, [sp, #32]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L123+20
	ldr	r2, [r4, r3]
	mov	r3, #384
	ldrd	r0, [r2, r3]
	ldr	r3, .L123+20
	ldr	r2, [r4, r3]
	mov	r3, #344
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L123+20
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L123
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-124]
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L75
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]
	mov	r2, r3
	sub	r3, fp, #124
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L123+20
	ldr	r3, [r4, r3]
	add	r2, r3, #352
	bl	rt_UpdateStructLogVar(PLT)
.L75:
	ldr	r3, .L123+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #4]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-92]
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #98]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L76
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #216]
	ldr	r1, .L123+8
	ldr	r1, [r4, r1]
	strd	r2, [r1, #24]
.L76:
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #24]
	strd	r2, [fp, #-84]
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	r0, [r3, #0]
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrb	r1, [r3, #554]	@ zero_extendqisi2
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #200]
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #208]
	strd	r2, [sp]
	ldrd	r2, [fp, #-92]
	strd	r2, [sp, #8]
	ldrd	r2, [fp, #-84]
	strd	r2, [sp, #16]
	ldr	r3, .L123+20
	ldr	r3, [r4, r3]
	add	r3, r3, #368
	str	r3, [sp, #24]
	ldr	r3, .L123+8
	ldr	r3, [r4, r3]
	add	r3, r3, #103
	str	r3, [sp, #28]
	b	.L124
.L125:
	.align	3
.L123:
	.word	1202590843
	.word	1064598241
	.word	HW6_v1_DW(GOT)
	.word	sensor_inport(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_M(GOT)
.L124:
	ldr	r3, .L123+16
	ldr	r3, [r4, r3]
	add	r3, r3, #560
	str	r3, [sp, #32]
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L123+20
	ldr	r2, [r4, r3]
	mov	r3, #368
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-84]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L123+20
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L123+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L126
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-132]
	ldr	r3, .L126+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L36
	ldr	r3, .L126+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #64]
	mov	r2, r3
	sub	r3, fp, #132
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L126+20
	ldr	r3, [r4, r3]
	add	r2, r3, #352
	bl	rt_UpdateStructLogVar(PLT)
.L36:
	ldr	r3, .L126+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	ldr	r3, .L126+16
	ldr	r2, [r4, r3]
	mov	r3, #256
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	ip, #0
	mov	r5, ip
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L77
.L78:
	mov	r3, #1
	mov	r5, r3
.L77:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L79
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #240]
	ldr	r1, .L126+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #216]
	b	.L80
.L79:
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #248]
	ldr	r1, .L126+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #216]
.L80:
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3]
	ldr	r3, .L126+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmple(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L81
.L82:
	mov	r3, #1
	mov	r5, r3
.L81:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L83
	ldr	r3, .L126+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #16]
	mov	ip, #0
	mov	r5, ip
	bl	__aeabi_dcmple(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L84
.L85:
	mov	r3, #1
	mov	r5, r3
.L84:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L83
	mov	r3, #1
	b	.L86
.L83:
	mov	r3, #0
.L86:
	and	r2, r3, #255
	ldr	r3, .L126+20
	ldr	r3, [r4, r3]
	strb	r2, [r3, #360]
	ldr	r3, .L126+20
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #360]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L87
	ldr	r3, .L126+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #216]
	ldr	r1, .L126+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #224]
	b	.L88
.L127:
	.align	3
.L126:
	.word	1202590843
	.word	1064598241
	.word	sensor_inport(GOT)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_M(GOT)
.L87:
	ldr	r3, .L126+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L126+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #224]
.L88:
	ldr	r3, .L126+20
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #176]
	ldr	r3, .L126+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #224]
	bl	__aeabi_ddiv(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L126+20
	ldr	r0, [r4, r1]
	mov	r1, #312
	strd	r2, [r0, r1]
	ldr	r3, .L126+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L89
	ldr	r3, .L126+12
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #99]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L90
	ldr	r3, .L126+16
	ldr	r2, [r4, r3]
	mov	r3, #264
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L126+12
	ldr	r1, [r4, r1]
	strd	r2, [r1, #32]
.L90:
	ldr	r3, .L126+12
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #32]
	strd	r2, [fp, #-76]
	ldr	r3, .L126+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #555]	@ zero_extendqisi2
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #224]
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #232]
	ldr	r3, .L126+20
	ldr	r2, [r4, r3]
	mov	r3, #312
	add	r3, r3, r2
	ldrd	r2, [r3]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	ldrd	r2, [fp, #-76]
	strd	r2, [sp, #16]
	ldr	r3, .L126+20
	ldr	r3, [r4, r3]
	add	r3, r3, #416
	str	r3, [sp, #24]
	ldr	r3, .L126+12
	ldr	r3, [r4, r3]
	add	r3, r3, #109
	str	r3, [sp, #28]
	ldr	r3, .L126+16
	ldr	r3, [r4, r3]
	add	r3, r3, #608
	str	r3, [sp, #32]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L126+20
	ldr	r2, [r4, r3]
	mov	r3, #416
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-76]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L126+20
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L126+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L128
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-140]
	ldr	r3, .L128+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L89
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #68]
	mov	r2, r3
	sub	r3, fp, #140
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L128+20
	ldr	r3, [r4, r3]
	add	r2, r3, #352
	bl	rt_UpdateStructLogVar(PLT)
.L89:
	ldr	r3, .L128+20
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #176]
	ldr	r3, .L128+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #176]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, .L128+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r8, r0
	mov	r9, r1
	ldr	r3, .L128+8
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r8
	mov	r1, r9
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	bl	sqrt(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L128+20
	ldr	r0, [r4, r1]
	mov	r1, #304
	strd	r2, [r0, r1]
	ldr	r3, .L128+16
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #8]
	ldr	r3, .L128+20
	ldr	r2, [r4, r3]
	mov	r3, #304
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	ip, #0
	mov	r5, ip
	bl	__aeabi_dcmple(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L91
.L92:
	mov	r3, #1
	mov	r5, r3
.L91:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L93
	ldr	r3, .L128+20
	ldr	r2, [r4, r3]
	mov	r3, #304
	ldrd	r0, [r2, r3]
	ldr	r3, .L128+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #24]
	mov	ip, #0
	mov	r5, ip
	bl	__aeabi_dcmple(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L94
.L95:
	mov	r3, #1
	mov	r5, r3
.L94:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L93
	ldr	r3, .L128+20
	ldr	r2, [r4, r3]
	mov	r3, #304
	ldrd	r0, [r2, r3]
	ldr	r3, .L128+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #32]
	mov	ip, #0
	mov	r5, ip
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L96
.L97:
	mov	r3, #1
	mov	r5, r3
.L96:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L98
	ldr	r3, .L128+16
	ldr	r2, [r4, r3]
	mov	r3, #296
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L128+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #232]
	b	.L100
.L98:
	ldr	r3, .L128+16
	ldr	r2, [r4, r3]
	mov	r3, #304
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L128+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #232]
	b	.L100
.L129:
	.align	3
.L128:
	.word	1202590843
	.word	1064598241
	.word	sensor_inport(GOT)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_M(GOT)
.L93:
	ldr	r3, .L128+20
	ldr	r2, [r4, r3]
	mov	r3, #304
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L128+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #232]
.L100:
	ldr	r3, .L128+16
	ldr	r2, [r4, r3]
	mov	r3, #288
	ldrd	r0, [r2, r3]
	ldr	r3, .L128+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L128+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #232]
	bl	__aeabi_ddiv(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L128+20
	ldr	r0, [r4, r1]
	mov	r1, #304
	strd	r2, [r0, r1]
	ldr	r3, .L128+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L101
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #100]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L102
	ldr	r3, .L128+16
	ldr	r2, [r4, r3]
	mov	r3, #312
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L128+12
	ldr	r1, [r4, r1]
	strd	r2, [r1, #40]
.L102:
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	strd	r2, [fp, #-68]
	ldr	r3, .L128+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L128+16
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #556]	@ zero_extendqisi2
	ldr	r3, .L128+16
	ldr	r2, [r4, r3]
	mov	r3, #272
	ldrd	r6, [r2, r3]
	ldr	r3, .L128+16
	ldr	r2, [r4, r3]
	mov	r3, #280
	ldrd	r0, [r2, r3]
	ldr	r3, .L128+20
	ldr	r2, [r4, r3]
	mov	r3, #304
	add	r3, r3, r2
	ldrd	r2, [r3]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	ldrd	r2, [fp, #-68]
	strd	r2, [sp, #16]
	ldr	r3, .L128+20
	ldr	r3, [r4, r3]
	add	r3, r3, #400
	str	r3, [sp, #24]
	ldr	r3, .L128+12
	ldr	r3, [r4, r3]
	add	r3, r3, #107
	str	r3, [sp, #28]
	ldr	r3, .L128+16
	ldr	r3, [r4, r3]
	add	r3, r3, #592
	str	r3, [sp, #32]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_EnabledSubsystem(PLT)
	ldr	r3, .L128+20
	ldr	r2, [r4, r3]
	mov	r3, #400
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-68]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L128+20
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L128+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L130
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-148]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L103
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #72]
	mov	r2, r3
	sub	r3, fp, #148
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r2, r3, #352
	bl	rt_UpdateStructLogVar(PLT)
.L103:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L130
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-156]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L104
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #76]
	mov	r2, r3
	sub	r3, fp, #156
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r2, r3, #224
	bl	rt_UpdateStructLogVar(PLT)
.L104:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L130
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-164]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L105
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #80]
	mov	r2, r3
	sub	r3, fp, #164
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r2, r3, #216
	bl	rt_UpdateStructLogVar(PLT)
.L105:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L130
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-172]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L106
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #84]
	mov	r2, r3
	sub	r3, fp, #172
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r2, r3, #224
	bl	rt_UpdateStructLogVar(PLT)
.L106:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L130
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-180]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L107
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #88]
	mov	r2, r3
	sub	r3, fp, #180
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r2, r3, #360
	bl	rt_UpdateStructLogVar(PLT)
.L107:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L130
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-188]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L101
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #92]
	mov	r2, r3
	sub	r3, fp, #188
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r2, r3, #232
	bl	rt_UpdateStructLogVar(PLT)
.L101:
	ldr	r3, .L130+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #56]
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #240]
	ldr	r3, .L130+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #64]
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #248]
	ldr	r3, .L130+8
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #72]
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #256
	strd	r2, [r0, r1]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L108
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #344
	add	r3, r3, r2
	ldrd	r2, [r3]
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-76]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #555]	@ zero_extendqisi2
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #360
	b	.L131
.L132:
	.align	3
.L130:
	.word	1202590843
	.word	1064598241
	.word	HW6_v1_X(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_B(GOT)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_M(GOT)
.L131:
	ldrd	r6, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #312
	ldrd	r0, [r2, r3]
	strd	r0, [fp, #-220]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrd	r8, [r3, #232]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #368
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-240]
	ldr	r3, [fp, #-240]
	ldrd	r2, [r3, #192]
	strd	r2, [fp, #-236]
	ldrd	r2, [fp, #-220]
	strd	r2, [sp]
	strd	r8, [sp, #8]
	ldrd	r8, [fp, #-76]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-236]
	strd	r0, [sp, #32]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r3, r3, #424
	str	r3, [sp, #40]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	add	r3, r3, #110
	str	r3, [sp, #44]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	add	r3, r3, #616
	str	r3, [sp, #48]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #352
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #192]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #352
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #424
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-60]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #384
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #200]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #556]	@ zero_extendqisi2
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #392
	ldrd	r6, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #304
	ldrd	r0, [r2, r3]
	strd	r0, [fp, #-212]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #280
	ldrd	r8, [r2, r3]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #400
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-240]
	ldr	r3, [fp, #-240]
	ldrd	r2, [r3, #200]
	strd	r2, [fp, #-236]
	ldrd	r2, [fp, #-212]
	strd	r2, [sp]
	strd	r8, [sp, #8]
	ldrd	r8, [fp, #-68]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-236]
	strd	r0, [sp, #32]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r3, r3, #408
	str	r3, [sp, #40]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	add	r3, r3, #108
	str	r3, [sp, #44]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	add	r3, r3, #600
	str	r3, [sp, #48]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #376
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
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #352
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #408
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-52]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #416
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #168]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #553]	@ zero_extendqisi2
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #424
	ldrd	r6, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #336
	ldrd	r0, [r2, r3]
	strd	r0, [fp, #-204]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #184]
	strd	r0, [fp, #-196]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #344
	ldrd	r8, [r2, r3]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #432
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-240]
	ldr	r3, [fp, #-240]
	ldrd	r2, [r3, #168]
	strd	r2, [fp, #-236]
	ldrd	r2, [fp, #-204]
	strd	r2, [sp]
	ldrd	r2, [fp, #-196]
	strd	r2, [sp, #8]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-236]
	strd	r0, [sp, #32]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r3, r3, #392
	str	r3, [sp, #40]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	add	r3, r3, #106
	str	r3, [sp, #44]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	add	r3, r3, #584
	str	r3, [sp, #48]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #408
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #344
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #352
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #392
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-44]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #448
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #176]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	lr, [r3, #0]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrb	ip, [r3, #554]	@ zero_extendqisi2
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #456
	ldrd	r6, [r2, r3]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrd	r8, [r3, #208]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #464
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	str	r3, [fp, #-240]
	ldr	r3, [fp, #-240]
	ldrd	r2, [r3, #176]
	strd	r2, [fp, #-236]
	ldrd	r2, [fp, #-92]
	strd	r2, [fp, #-228]
	ldrd	r2, [fp, #-228]
	strd	r2, [sp]
	strd	r8, [sp, #8]
	ldrd	r8, [fp, #-84]
	strd	r8, [sp, #16]
	strd	r0, [sp, #24]
	ldrd	r0, [fp, #-236]
	strd	r0, [sp, #32]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	add	r3, r3, #376
	str	r3, [sp, #40]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	add	r3, r3, #104
	str	r3, [sp, #44]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	add	r3, r3, #568
	str	r3, [sp, #48]
	mov	r0, lr
	mov	r1, ip
	mov	r2, r6
	mov	r3, r7
	bl	HW6_v1_MeasurementUpdate(PLT)
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #440
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
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #352
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #376
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-36]
	ldr	r3, .L130+16
	ldr	r1, [r4, r3]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [r1, #136]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #136]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #472
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #320
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
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #136]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #136]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #488
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #328
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
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #136]
	ldr	r3, .L130+16
	ldr	r1, [r4, r3]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [r1, #144]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #144]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #480
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #320
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
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #144]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r6, [r3, #144]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #496
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #328
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
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #144]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L109
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #552]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L110
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #102]
	b	.L109
.L110:
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #102]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L109
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #280
	strd	r2, [r0, r1]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #288
	strd	r2, [r0, r1]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #102]
.L109:
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #102]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L111
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #536
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #352
	strd	r2, [r0, r1]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #296
	ldrd	r6, [r2, r3]
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #144]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #320
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r8, r2
	mov	r9, r3
	ldr	r3, .L130+12
	ldr	r3, [r4, r3]
	ldrd	r0, [r3, #152]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #328
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
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #352
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
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #312
	strd	r2, [r0, r1]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #520
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #312
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #280
	strd	r2, [r0, r1]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #528
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #312
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r0, [r4, r1]
	mov	r1, #288
	strd	r2, [r0, r1]
.L111:
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #504
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #136]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #280
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #152]
	ldr	r3, .L130+12
	ldr	r2, [r4, r3]
	mov	r3, #512
	ldrd	r0, [r2, r3]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #184]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #144]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L130+16
	ldr	r2, [r4, r3]
	mov	r3, #288
	add	r3, r3, r2
	ldrd	r2, [r3]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	ldr	r1, .L130+16
	ldr	r1, [r4, r1]
	strd	r2, [r1, #160]
.L108:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L112
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #4]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #672]
	mov	r0, r2
	mov	r1, r3
	bl	rt_UpdateTXYLogVars(PLT)
.L112:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L113
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L113
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #96]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #152]
	ldr	r1, .L130+20
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L130+16
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #160]
	ldr	r1, .L130+20
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #97]
	ldr	r3, .L130+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-44]
	strd	r2, [r1, #16]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #98]
	ldr	r3, .L130+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-36]
	strd	r2, [r1, #24]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #99]
	ldr	r3, .L130+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-60]
	strd	r2, [r1, #32]
	ldr	r3, .L130+20
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #100]
	ldr	r3, .L130+20
	ldr	r1, [r4, r3]
	ldrd	r2, [fp, #-52]
	strd	r2, [r1, #40]
.L113:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #664]
	cmp	r3, #1
	bne	.L119
	ldr	r3, .L130+24
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
	bne	.L115
.L120:
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r6, [r2, r3]
	ldr	r3, .L130+24
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L133
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
	ldr	r3, .L133+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #648]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	adr	r3, .L133+8
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
	beq	.L117
.L118:
	mov	r3, #1
	mov	r5, r3
.L117:
	and	r3, r5, #255
	eor	r3, r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L115
	ldr	r3, .L133+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L133+20
	add	r2, r4, r2
	str	r2, [r3, #0]
.L115:
	ldr	r3, .L133+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	add	r3, r3, #8
	mov	r0, r3
	bl	rt_ertODEUpdateContinuousStates(PLT)
	ldr	r3, .L133+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #632]
	add	r2, r2, #1
	str	r2, [r3, #632]
	ldr	r3, .L133+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r1, [r3, #672]
	ldr	r3, .L133+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #32]
	strd	r2, [r1]
	ldr	r3, .L133+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #648]
	add	r2, r2, #1
	str	r2, [r3, #648]
.L119:
	sub	sp, fp, #28
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, fp, pc}
.L134:
	.align	3
.L133:
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
	ldr	r3, .L137
.LPIC2:
	add	r3, pc, r3
	ldr	r2, .L137+4
	ldr	r2, [r3, r2]
	ldr	r2, [r2, #0]
	ldr	r2, [r2, #268]
	str	r2, [fp, #-8]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #184]
	ldr	r2, [fp, #-8]
	strd	r0, [r2]
	ldr	r2, .L137+8
	ldr	r1, [r3, r2]
	mov	r2, #256
	ldrd	r0, [r1, r2]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #8]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #192]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #16]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #200]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #24]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #208]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #32]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #240]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #40]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #248]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #48]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #168]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #56]
	ldr	r2, .L137+8
	ldr	r2, [r3, r2]
	ldrd	r0, [r2, #176]
	ldr	r2, [fp, #-8]
	strd	r0, [r2, #64]
	ldr	r2, .L137+8
	ldr	r3, [r3, r2]
	ldrd	r2, [r3, #184]
	ldr	r1, [fp, #-8]
	strd	r2, [r1, #72]
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L138:
	.align	2
.L137:
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
	.align	2
.LC12:
	.ascii	"possiblezero1\000"
	.align	2
.LC13:
	.ascii	"checksign\000"
	.align	2
.LC14:
	.ascii	"booleanoutput1\000"
	.align	2
.LC15:
	.ascii	"booleanoutput\000"
	.align	2
.LC16:
	.ascii	"possiblezero2\000"
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
	ldr	r4, .L166+8
.LPIC3:
	add	r4, pc, r4
	mov	r0, #8
	bl	rt_InitInfAndNaN(PLT)
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #696
	bl	memset(PLT)
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #664
	str	r2, [r3, #12]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #672
	str	r2, [r3, #132]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #640
	str	r2, [r3, #40]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #268
	str	r2, [r3, #128]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #256
	str	r2, [r3, #140]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #616
	str	r2, [r3, #136]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #620
	str	r2, [r3, #144]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #260
	str	r2, [r3, #148]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #264
	str	r2, [r3, #152]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	str	r2, [r3, #208]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	str	r2, [r3, #8]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #12]
	mov	r2, #1
	str	r2, [r3, #0]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #280
	str	r2, [r3, #600]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #360
	str	r2, [r3, #604]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #360
	add	r2, r2, #80
	str	r2, [r3, #608]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #360
	add	r2, r2, #160
	str	r2, [r3, #612]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+16
	ldr	r2, [r4, r2]
	str	r2, [r3, #256]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #600
	str	r2, [r3, #16]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+20
	add	r2, r4, r2
	str	r2, [r3, #20]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+12
	ldr	r2, [r4, r2]
	ldr	r2, [r2, #0]
	add	r2, r2, #680
	str	r2, [r3, #672]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r0, [r3, #0]
	mov	r1, #656
	mov	r2, #0
	mov	r3, #1073741824
	add	r3, r3, #3407872
	strd	r2, [r0, r1]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r0, [r3, #0]
	mov	r1, #640
	adr	r3, .L166
	ldrd	r2, [r3]
	strd	r2, [r0, r1]
	ldr	r3, .L166+24
	add	r3, r4, r3
	mov	r2, #0
	str	r2, [r3, #68]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L166+24
	add	r2, r4, r2
	str	r2, [r3, #4]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #48]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #4]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L166+28
	add	r2, r4, r2
	str	r2, [r3, #28]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L166+32
	add	r2, r4, r2
	str	r2, [r3, #32]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L166+32
	add	r2, r4, r2
	str	r2, [r3, #36]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L166+36
	add	r2, r4, r2
	str	r2, [r3, #24]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #2
	str	r2, [r3, #12]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #16]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #1
	str	r2, [r3, #20]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L166+32
	add	r2, r4, r2
	str	r2, [r3, #40]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #52]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #8]
	ldr	r3, .L166+40
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #432
	bl	memset(PLT)
	ldr	r3, .L166+44
	ldr	r3, [r4, r3]
	ldr	r2, .L166+48	@ float
	str	r2, [r3, #0]	@ float
	ldr	r3, .L166+44
	ldr	r3, [r4, r3]
	ldr	r2, .L166+48	@ float
	str	r2, [r3, #4]	@ float
	ldr	r3, .L166+44
	ldr	r3, [r4, r3]
	ldr	r2, .L166+48	@ float
	str	r2, [r3, #8]	@ float
	ldr	r3, .L166+44
	ldr	r3, [r4, r3]
	ldr	r2, .L166+48	@ float
	str	r2, [r3, #12]	@ float
	ldr	r3, .L166+52
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #0]
	ldr	r3, .L166+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #80
	bl	memset(PLT)
	ldr	r3, .L166+56
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #112
	bl	memset(PLT)
	ldr	r3, .L166+60
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #36
	bl	memset(PLT)
	ldr	r3, .L166+64
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #2496
	bl	memset(PLT)
	ldr	r3, .L166+68
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #20
	bl	memset(PLT)
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L166+12
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_StartDataLoggingWithStartTime(PLT)
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L166+12
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L166+72
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L166
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L166+76
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L166+80
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L166+56
	ldr	r3, [r4, r3]
	str	r2, [r3, #48]
	ldr	r3, .L166+56
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #48]
	cmp	r3, #0
	beq	.L154
.L140:
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L166+12
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L166+12
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	b	.L167
.L168:
	.align	3
.L166:
	.word	1202590843
	.word	1064598241
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC3+8)
	.word	HW6_v1_M(GOT)
	.word	HW6_v1_X(GOT)
	.word	.LC1(GOTOFF)
	.word	rt_DataLoggingInfo.4976(GOTOFF)
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
	.word	rt_ToWksSignalInfo.4988(GOTOFF)
	.word	rt_ToWksBlockName.4989(GOTOFF)
	.word	.LC6(GOTOFF)
.L167:
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L166+84
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L169
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L169+8
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L169+12
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #52]
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #52]
	cmp	r3, #0
	beq	.L155
.L142:
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L169+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L169+20
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L169
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L169+24
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L169+28
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #56]
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #56]
	cmp	r3, #0
	beq	.L156
.L143:
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L169+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L169+32
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L169
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L169+36
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L169+40
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #60]
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #60]
	cmp	r3, #0
	beq	.L157
.L144:
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L169+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L169+44
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L169
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L169+48
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L169+52
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #64]
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #64]
	cmp	r3, #0
	beq	.L158
.L145:
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L169+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L169+56
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L169
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L169+60
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L169+64
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #68]
	ldr	r3, .L169+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #68]
	cmp	r3, #0
	beq	.L159
.L146:
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	b	.L170
.L171:
	.align	3
.L169:
	.word	1202590843
	.word	1064598241
	.word	rt_ToWksSignalInfo.5001(GOTOFF)
	.word	rt_ToWksBlockName.5002(GOTOFF)
	.word	HW6_v1_DW(GOT)
	.word	.LC7(GOTOFF)
	.word	rt_ToWksSignalInfo.5014(GOTOFF)
	.word	rt_ToWksBlockName.5015(GOTOFF)
	.word	.LC8(GOTOFF)
	.word	rt_ToWksSignalInfo.5027(GOTOFF)
	.word	rt_ToWksBlockName.5028(GOTOFF)
	.word	.LC9(GOTOFF)
	.word	rt_ToWksSignalInfo.5040(GOTOFF)
	.word	rt_ToWksBlockName.5041(GOTOFF)
	.word	.LC10(GOTOFF)
	.word	rt_ToWksSignalInfo.5053(GOTOFF)
	.word	rt_ToWksBlockName.5054(GOTOFF)
	.word	HW6_v1_M(GOT)
	.word	.LC11(GOTOFF)
.L170:
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L169+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L169+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L169+72
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L172
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L172+8
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L172+12
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #72]
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #72]
	cmp	r3, #0
	beq	.L160
.L147:
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L172+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L172+20
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L172
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L172+24
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L172+28
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #76]
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #76]
	cmp	r3, #0
	beq	.L161
.L148:
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L172+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L172+32
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L172
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L172+36
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L172+40
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #80]
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #80]
	cmp	r3, #0
	beq	.L162
.L149:
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L172+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L172+44
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L172
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L172+48
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L172+52
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #84]
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #84]
	cmp	r3, #0
	beq	.L163
.L150:
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L172+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L172+56
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L172
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L172+60
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L172+64
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #88]
	ldr	r3, .L172+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #88]
	cmp	r3, #0
	beq	.L164
.L151:
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	b	.L173
.L174:
	.align	3
.L172:
	.word	1202590843
	.word	1064598241
	.word	rt_ToWksSignalInfo.5066(GOTOFF)
	.word	rt_ToWksBlockName.5067(GOTOFF)
	.word	HW6_v1_DW(GOT)
	.word	.LC12(GOTOFF)
	.word	rt_ToWksSignalInfo.5079(GOTOFF)
	.word	rt_ToWksBlockName.5080(GOTOFF)
	.word	.LC13(GOTOFF)
	.word	rt_ToWksSignalInfo.5092(GOTOFF)
	.word	rt_ToWksBlockName.5093(GOTOFF)
	.word	.LC14(GOTOFF)
	.word	rt_ToWksSignalInfo.5105(GOTOFF)
	.word	rt_ToWksBlockName.5106(GOTOFF)
	.word	.LC15(GOTOFF)
	.word	rt_ToWksSignalInfo.5118(GOTOFF)
	.word	rt_ToWksBlockName.5119(GOTOFF)
	.word	HW6_v1_M(GOT)
	.word	.LC16(GOTOFF)
.L173:
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #656
	ldrd	r0, [r2, r3]
	ldr	r3, .L172+68
	ldr	r3, [r4, r3]
	ldr	r2, [r3, #0]
	mov	r3, #640
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	lr, .L172+68
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	ldr	r3, .L172+72
	add	r3, r4, r3
	str	r3, [sp, #20]
	mov	r3, #1
	str	r3, [sp, #24]
	mov	r3, #0
	str	r3, [sp, #28]
	mov	r3, #1
	str	r3, [sp, #32]
	adr	r3, .L175
	ldrd	r2, [r3]
	strd	r2, [sp, #40]
	ldr	r3, .L175+8
	add	r3, r4, r3
	str	r3, [sp, #48]
	ldr	r3, .L175+12
	add	r3, r4, r3
	str	r3, [sp, #52]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_CreateStructLogVar(PLT)
	mov	r2, r0
	ldr	r3, .L175+16
	ldr	r3, [r4, r3]
	str	r2, [r3, #92]
	ldr	r3, .L175+16
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #92]
	cmp	r3, #0
	beq	.L165
.L152:
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #64]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #72]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #8]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #80]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #16]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #88]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #24]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #104]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #32]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #112]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #40]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #120]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #48]
	ldr	r3, .L175+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #96]
	ldr	r3, .L175+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #97]
	ldr	r3, .L175+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #98]
	ldr	r3, .L175+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #99]
	ldr	r3, .L175+16
	ldr	r3, [r4, r3]
	mov	r2, #1
	strb	r2, [r3, #100]
	ldr	r3, .L175+20
	ldr	r2, [r4, r3]
	mov	r3, #320
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #56]
	ldr	r3, .L175+20
	ldr	r2, [r4, r3]
	mov	r3, #328
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #64]
	ldr	r3, .L175+20
	ldr	r2, [r4, r3]
	mov	r3, #336
	add	r3, r3, r2
	ldrd	r2, [r3]
	ldr	r1, .L175+24
	ldr	r1, [r4, r1]
	strd	r2, [r1, #72]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #48]
	ldr	r1, .L175+28
	ldr	r0, [r4, r1]
	mov	r1, #264
	strd	r2, [r0, r1]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #48]
	ldr	r1, .L175+28
	ldr	r0, [r4, r1]
	mov	r1, #272
	strd	r2, [r0, r1]
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #384
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #576
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #368
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #560
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #416
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #608
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #400
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #592
	bl	HW6_v1_EnabledSubsystem_Init(PLT)
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #424
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #616
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #408
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #600
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #392
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #584
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L175+28
	ldr	r3, [r4, r3]
	add	r0, r3, #376
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	add	r1, r3, #568
	bl	HW6_v1_MeasurementUpdate_Init(PLT)
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	ldr	r1, .L175+28
	ldr	r0, [r4, r1]
	mov	r1, #280
	strd	r2, [r0, r1]
	ldr	r3, .L175+20
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #40]
	ldr	r1, .L175+28
	ldr	r0, [r4, r1]
	mov	r1, #288
	strd	r2, [r0, r1]
	b	.L153
.L154:
	mov	r0, r0	@ nop
	b	.L153
.L155:
	mov	r0, r0	@ nop
	b	.L153
.L156:
	mov	r0, r0	@ nop
	b	.L153
.L157:
	mov	r0, r0	@ nop
	b	.L153
.L158:
	mov	r0, r0	@ nop
	b	.L153
.L159:
	mov	r0, r0	@ nop
	b	.L153
.L160:
	mov	r0, r0	@ nop
	b	.L153
.L161:
	mov	r0, r0	@ nop
	b	.L153
.L162:
	mov	r0, r0	@ nop
	b	.L153
.L163:
	mov	r0, r0	@ nop
	b	.L153
.L164:
	mov	r0, r0	@ nop
	b	.L153
.L176:
	.align	3
.L175:
	.word	1202590843
	.word	1064598241
	.word	rt_ToWksSignalInfo.5131(GOTOFF)
	.word	rt_ToWksBlockName.5132(GOTOFF)
	.word	HW6_v1_DW(GOT)
	.word	HW6_v1_P(GOT)
	.word	HW6_v1_X(GOT)
	.word	HW6_v1_B(GOT)
.L165:
	mov	r0, r0	@ nop
.L153:
	sub	sp, fp, #8
	ldmfd	sp!, {r4, fp, pc}
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
	.local	rt_DataLoggingInfo.4976
	.comm	rt_DataLoggingInfo.4976,72,4
	.section	.data.rel.local,"aw",%progbits
	.align	2
	.type	rt_ToWksSignalInfo.4988, %object
	.size	rt_ToWksSignalInfo.4988, 76
rt_ToWksSignalInfo.4988:
	.word	1
	.word	rt_ToWksWidths.4977
	.word	rt_ToWksNumDimensions.4978
	.word	rt_ToWksDimensions.4979
	.word	rt_ToWksIsVarDims.4980
	.word	rt_ToWksCurrSigDims.4981
	.word	rt_ToWksCurrSigDimsSize.4982
	.word	rt_ToWksDataTypeIds.4983
	.word	rt_ToWksComplexSignals.4984
	.word	rt_ToWksFrameData.4985
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4986
	.word	rt_ToWksLabels.4987
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.4989, %object
	.size	rt_ToWksBlockName.4989, 43
rt_ToWksBlockName.4989:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace1\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5001, %object
	.size	rt_ToWksSignalInfo.5001, 76
rt_ToWksSignalInfo.5001:
	.word	1
	.word	rt_ToWksWidths.4990
	.word	rt_ToWksNumDimensions.4991
	.word	rt_ToWksDimensions.4992
	.word	rt_ToWksIsVarDims.4993
	.word	rt_ToWksCurrSigDims.4994
	.word	rt_ToWksCurrSigDimsSize.4995
	.word	rt_ToWksDataTypeIds.4996
	.word	rt_ToWksComplexSignals.4997
	.word	rt_ToWksFrameData.4998
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.4999
	.word	rt_ToWksLabels.5000
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5002, %object
	.size	rt_ToWksBlockName.5002, 43
rt_ToWksBlockName.5002:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace2\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5014, %object
	.size	rt_ToWksSignalInfo.5014, 76
rt_ToWksSignalInfo.5014:
	.word	1
	.word	rt_ToWksWidths.5003
	.word	rt_ToWksNumDimensions.5004
	.word	rt_ToWksDimensions.5005
	.word	rt_ToWksIsVarDims.5006
	.word	rt_ToWksCurrSigDims.5007
	.word	rt_ToWksCurrSigDimsSize.5008
	.word	rt_ToWksDataTypeIds.5009
	.word	rt_ToWksComplexSignals.5010
	.word	rt_ToWksFrameData.5011
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5012
	.word	rt_ToWksLabels.5013
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5015, %object
	.size	rt_ToWksBlockName.5015, 43
rt_ToWksBlockName.5015:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace3\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5027, %object
	.size	rt_ToWksSignalInfo.5027, 76
rt_ToWksSignalInfo.5027:
	.word	1
	.word	rt_ToWksWidths.5016
	.word	rt_ToWksNumDimensions.5017
	.word	rt_ToWksDimensions.5018
	.word	rt_ToWksIsVarDims.5019
	.word	rt_ToWksCurrSigDims.5020
	.word	rt_ToWksCurrSigDimsSize.5021
	.word	rt_ToWksDataTypeIds.5022
	.word	rt_ToWksComplexSignals.5023
	.word	rt_ToWksFrameData.5024
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5025
	.word	rt_ToWksLabels.5026
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5028, %object
	.size	rt_ToWksBlockName.5028, 43
rt_ToWksBlockName.5028:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace4\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5040, %object
	.size	rt_ToWksSignalInfo.5040, 76
rt_ToWksSignalInfo.5040:
	.word	1
	.word	rt_ToWksWidths.5029
	.word	rt_ToWksNumDimensions.5030
	.word	rt_ToWksDimensions.5031
	.word	rt_ToWksIsVarDims.5032
	.word	rt_ToWksCurrSigDims.5033
	.word	rt_ToWksCurrSigDimsSize.5034
	.word	rt_ToWksDataTypeIds.5035
	.word	rt_ToWksComplexSignals.5036
	.word	rt_ToWksFrameData.5037
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5038
	.word	rt_ToWksLabels.5039
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5041, %object
	.size	rt_ToWksBlockName.5041, 43
rt_ToWksBlockName.5041:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace5\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5053, %object
	.size	rt_ToWksSignalInfo.5053, 76
rt_ToWksSignalInfo.5053:
	.word	1
	.word	rt_ToWksWidths.5042
	.word	rt_ToWksNumDimensions.5043
	.word	rt_ToWksDimensions.5044
	.word	rt_ToWksIsVarDims.5045
	.word	rt_ToWksCurrSigDims.5046
	.word	rt_ToWksCurrSigDimsSize.5047
	.word	rt_ToWksDataTypeIds.5048
	.word	rt_ToWksComplexSignals.5049
	.word	rt_ToWksFrameData.5050
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5051
	.word	rt_ToWksLabels.5052
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5054, %object
	.size	rt_ToWksBlockName.5054, 43
rt_ToWksBlockName.5054:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace6\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5066, %object
	.size	rt_ToWksSignalInfo.5066, 76
rt_ToWksSignalInfo.5066:
	.word	1
	.word	rt_ToWksWidths.5055
	.word	rt_ToWksNumDimensions.5056
	.word	rt_ToWksDimensions.5057
	.word	rt_ToWksIsVarDims.5058
	.word	rt_ToWksCurrSigDims.5059
	.word	rt_ToWksCurrSigDimsSize.5060
	.word	rt_ToWksDataTypeIds.5061
	.word	rt_ToWksComplexSignals.5062
	.word	rt_ToWksFrameData.5063
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5064
	.word	rt_ToWksLabels.5065
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5067, %object
	.size	rt_ToWksBlockName.5067, 43
rt_ToWksBlockName.5067:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace7\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5079, %object
	.size	rt_ToWksSignalInfo.5079, 76
rt_ToWksSignalInfo.5079:
	.word	1
	.word	rt_ToWksWidths.5068
	.word	rt_ToWksNumDimensions.5069
	.word	rt_ToWksDimensions.5070
	.word	rt_ToWksIsVarDims.5071
	.word	rt_ToWksCurrSigDims.5072
	.word	rt_ToWksCurrSigDimsSize.5073
	.word	rt_ToWksDataTypeIds.5074
	.word	rt_ToWksComplexSignals.5075
	.word	rt_ToWksFrameData.5076
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5077
	.word	rt_ToWksLabels.5078
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5080, %object
	.size	rt_ToWksBlockName.5080, 43
rt_ToWksBlockName.5080:
	.ascii	"HW6_v1/Flight_Control_System/To Workspace8\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5092, %object
	.size	rt_ToWksSignalInfo.5092, 76
rt_ToWksSignalInfo.5092:
	.word	1
	.word	rt_ToWksWidths.5081
	.word	rt_ToWksNumDimensions.5082
	.word	rt_ToWksDimensions.5083
	.word	rt_ToWksIsVarDims.5084
	.word	rt_ToWksCurrSigDims.5085
	.word	rt_ToWksCurrSigDimsSize.5086
	.word	rt_ToWksDataTypeIds.5087
	.word	rt_ToWksComplexSignals.5088
	.word	rt_ToWksFrameData.5089
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5090
	.word	rt_ToWksLabels.5091
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5093, %object
	.size	rt_ToWksBlockName.5093, 62
rt_ToWksBlockName.5093:
	.ascii	"HW6_v1/Flight_Control_System/Check if near zero/To "
	.ascii	"Workspace1\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5105, %object
	.size	rt_ToWksSignalInfo.5105, 76
rt_ToWksSignalInfo.5105:
	.word	1
	.word	rt_ToWksWidths.5094
	.word	rt_ToWksNumDimensions.5095
	.word	rt_ToWksDimensions.5096
	.word	rt_ToWksIsVarDims.5097
	.word	rt_ToWksCurrSigDims.5098
	.word	rt_ToWksCurrSigDimsSize.5099
	.word	rt_ToWksDataTypeIds.5100
	.word	rt_ToWksComplexSignals.5101
	.word	rt_ToWksFrameData.5102
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5103
	.word	rt_ToWksLabels.5104
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5106, %object
	.size	rt_ToWksBlockName.5106, 62
rt_ToWksBlockName.5106:
	.ascii	"HW6_v1/Flight_Control_System/Check if near zero/To "
	.ascii	"Workspace2\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5118, %object
	.size	rt_ToWksSignalInfo.5118, 76
rt_ToWksSignalInfo.5118:
	.word	1
	.word	rt_ToWksWidths.5107
	.word	rt_ToWksNumDimensions.5108
	.word	rt_ToWksDimensions.5109
	.word	rt_ToWksIsVarDims.5110
	.word	rt_ToWksCurrSigDims.5111
	.word	rt_ToWksCurrSigDimsSize.5112
	.word	rt_ToWksDataTypeIds.5113
	.word	rt_ToWksComplexSignals.5114
	.word	rt_ToWksFrameData.5115
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5116
	.word	rt_ToWksLabels.5117
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5119, %object
	.size	rt_ToWksBlockName.5119, 62
rt_ToWksBlockName.5119:
	.ascii	"HW6_v1/Flight_Control_System/Check if near zero/To "
	.ascii	"Workspace8\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksSignalInfo.5131, %object
	.size	rt_ToWksSignalInfo.5131, 76
rt_ToWksSignalInfo.5131:
	.word	1
	.word	rt_ToWksWidths.5120
	.word	rt_ToWksNumDimensions.5121
	.word	rt_ToWksDimensions.5122
	.word	rt_ToWksIsVarDims.5123
	.word	rt_ToWksCurrSigDims.5124
	.word	rt_ToWksCurrSigDimsSize.5125
	.word	rt_ToWksDataTypeIds.5126
	.word	rt_ToWksComplexSignals.5127
	.word	rt_ToWksFrameData.5128
	.word	rt_ToWksLoggingPreprocessingFcnPtrs.5129
	.word	rt_ToWksLabels.5130
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.section	.rodata
	.align	2
	.type	rt_ToWksBlockName.5132, %object
	.size	rt_ToWksBlockName.5132, 62
rt_ToWksBlockName.5132:
	.ascii	"HW6_v1/Flight_Control_System/Check if near zero1/To"
	.ascii	" Workspace\000"
	.align	2
.LC17:
	.ascii	"a_z\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5130, %object
	.size	rt_ToWksLabels.5130, 4
rt_ToWksLabels.5130:
	.word	.LC17
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5129
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5129,4,4
	.local	rt_ToWksFrameData.5128
	.comm	rt_ToWksFrameData.5128,4,4
	.local	rt_ToWksComplexSignals.5127
	.comm	rt_ToWksComplexSignals.5127,4,4
	.local	rt_ToWksDataTypeIds.5126
	.comm	rt_ToWksDataTypeIds.5126,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5125, %object
	.size	rt_ToWksCurrSigDimsSize.5125, 4
rt_ToWksCurrSigDimsSize.5125:
	.word	4
	.local	rt_ToWksCurrSigDims.5124
	.comm	rt_ToWksCurrSigDims.5124,4,4
	.local	rt_ToWksIsVarDims.5123
	.comm	rt_ToWksIsVarDims.5123,1,4
	.align	2
	.type	rt_ToWksDimensions.5122, %object
	.size	rt_ToWksDimensions.5122, 4
rt_ToWksDimensions.5122:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5121, %object
	.size	rt_ToWksNumDimensions.5121, 4
rt_ToWksNumDimensions.5121:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5120, %object
	.size	rt_ToWksWidths.5120, 4
rt_ToWksWidths.5120:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5117, %object
	.size	rt_ToWksLabels.5117, 4
rt_ToWksLabels.5117:
	.word	.LC3
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5116
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5116,4,4
	.local	rt_ToWksFrameData.5115
	.comm	rt_ToWksFrameData.5115,4,4
	.local	rt_ToWksComplexSignals.5114
	.comm	rt_ToWksComplexSignals.5114,4,4
	.data
	.align	2
	.type	rt_ToWksDataTypeIds.5113, %object
	.size	rt_ToWksDataTypeIds.5113, 4
rt_ToWksDataTypeIds.5113:
	.word	8
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5112, %object
	.size	rt_ToWksCurrSigDimsSize.5112, 4
rt_ToWksCurrSigDimsSize.5112:
	.word	4
	.local	rt_ToWksCurrSigDims.5111
	.comm	rt_ToWksCurrSigDims.5111,4,4
	.local	rt_ToWksIsVarDims.5110
	.comm	rt_ToWksIsVarDims.5110,1,4
	.align	2
	.type	rt_ToWksDimensions.5109, %object
	.size	rt_ToWksDimensions.5109, 4
rt_ToWksDimensions.5109:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5108, %object
	.size	rt_ToWksNumDimensions.5108, 4
rt_ToWksNumDimensions.5108:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5107, %object
	.size	rt_ToWksWidths.5107, 4
rt_ToWksWidths.5107:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5104, %object
	.size	rt_ToWksLabels.5104, 4
rt_ToWksLabels.5104:
	.word	.LC17
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5103
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5103,4,4
	.local	rt_ToWksFrameData.5102
	.comm	rt_ToWksFrameData.5102,4,4
	.local	rt_ToWksComplexSignals.5101
	.comm	rt_ToWksComplexSignals.5101,4,4
	.local	rt_ToWksDataTypeIds.5100
	.comm	rt_ToWksDataTypeIds.5100,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5099, %object
	.size	rt_ToWksCurrSigDimsSize.5099, 4
rt_ToWksCurrSigDimsSize.5099:
	.word	4
	.local	rt_ToWksCurrSigDims.5098
	.comm	rt_ToWksCurrSigDims.5098,4,4
	.local	rt_ToWksIsVarDims.5097
	.comm	rt_ToWksIsVarDims.5097,1,4
	.align	2
	.type	rt_ToWksDimensions.5096, %object
	.size	rt_ToWksDimensions.5096, 4
rt_ToWksDimensions.5096:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5095, %object
	.size	rt_ToWksNumDimensions.5095, 4
rt_ToWksNumDimensions.5095:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5094, %object
	.size	rt_ToWksWidths.5094, 4
rt_ToWksWidths.5094:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5091, %object
	.size	rt_ToWksLabels.5091, 4
rt_ToWksLabels.5091:
	.word	.LC3
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5090
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5090,4,4
	.local	rt_ToWksFrameData.5089
	.comm	rt_ToWksFrameData.5089,4,4
	.local	rt_ToWksComplexSignals.5088
	.comm	rt_ToWksComplexSignals.5088,4,4
	.local	rt_ToWksDataTypeIds.5087
	.comm	rt_ToWksDataTypeIds.5087,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5086, %object
	.size	rt_ToWksCurrSigDimsSize.5086, 4
rt_ToWksCurrSigDimsSize.5086:
	.word	4
	.local	rt_ToWksCurrSigDims.5085
	.comm	rt_ToWksCurrSigDims.5085,4,4
	.local	rt_ToWksIsVarDims.5084
	.comm	rt_ToWksIsVarDims.5084,1,4
	.align	2
	.type	rt_ToWksDimensions.5083, %object
	.size	rt_ToWksDimensions.5083, 4
rt_ToWksDimensions.5083:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5082, %object
	.size	rt_ToWksNumDimensions.5082, 4
rt_ToWksNumDimensions.5082:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5081, %object
	.size	rt_ToWksWidths.5081, 4
rt_ToWksWidths.5081:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5078, %object
	.size	rt_ToWksLabels.5078, 4
rt_ToWksLabels.5078:
	.word	.LC3
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5077
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5077,4,4
	.local	rt_ToWksFrameData.5076
	.comm	rt_ToWksFrameData.5076,4,4
	.local	rt_ToWksComplexSignals.5075
	.comm	rt_ToWksComplexSignals.5075,4,4
	.local	rt_ToWksDataTypeIds.5074
	.comm	rt_ToWksDataTypeIds.5074,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5073, %object
	.size	rt_ToWksCurrSigDimsSize.5073, 4
rt_ToWksCurrSigDimsSize.5073:
	.word	4
	.local	rt_ToWksCurrSigDims.5072
	.comm	rt_ToWksCurrSigDims.5072,4,4
	.local	rt_ToWksIsVarDims.5071
	.comm	rt_ToWksIsVarDims.5071,1,4
	.align	2
	.type	rt_ToWksDimensions.5070, %object
	.size	rt_ToWksDimensions.5070, 4
rt_ToWksDimensions.5070:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5069, %object
	.size	rt_ToWksNumDimensions.5069, 4
rt_ToWksNumDimensions.5069:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5068, %object
	.size	rt_ToWksWidths.5068, 4
rt_ToWksWidths.5068:
	.word	1
	.section	.rodata
	.align	2
.LC18:
	.ascii	"z\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5065, %object
	.size	rt_ToWksLabels.5065, 4
rt_ToWksLabels.5065:
	.word	.LC18
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5064
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5064,4,4
	.local	rt_ToWksFrameData.5063
	.comm	rt_ToWksFrameData.5063,4,4
	.local	rt_ToWksComplexSignals.5062
	.comm	rt_ToWksComplexSignals.5062,4,4
	.local	rt_ToWksDataTypeIds.5061
	.comm	rt_ToWksDataTypeIds.5061,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5060, %object
	.size	rt_ToWksCurrSigDimsSize.5060, 4
rt_ToWksCurrSigDimsSize.5060:
	.word	4
	.local	rt_ToWksCurrSigDims.5059
	.comm	rt_ToWksCurrSigDims.5059,4,4
	.local	rt_ToWksIsVarDims.5058
	.comm	rt_ToWksIsVarDims.5058,1,4
	.align	2
	.type	rt_ToWksDimensions.5057, %object
	.size	rt_ToWksDimensions.5057, 4
rt_ToWksDimensions.5057:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5056, %object
	.size	rt_ToWksNumDimensions.5056, 4
rt_ToWksNumDimensions.5056:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5055, %object
	.size	rt_ToWksWidths.5055, 4
rt_ToWksWidths.5055:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5052, %object
	.size	rt_ToWksLabels.5052, 4
rt_ToWksLabels.5052:
	.word	.LC18
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5051
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5051,4,4
	.local	rt_ToWksFrameData.5050
	.comm	rt_ToWksFrameData.5050,4,4
	.local	rt_ToWksComplexSignals.5049
	.comm	rt_ToWksComplexSignals.5049,4,4
	.local	rt_ToWksDataTypeIds.5048
	.comm	rt_ToWksDataTypeIds.5048,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5047, %object
	.size	rt_ToWksCurrSigDimsSize.5047, 4
rt_ToWksCurrSigDimsSize.5047:
	.word	4
	.local	rt_ToWksCurrSigDims.5046
	.comm	rt_ToWksCurrSigDims.5046,4,4
	.local	rt_ToWksIsVarDims.5045
	.comm	rt_ToWksIsVarDims.5045,1,4
	.align	2
	.type	rt_ToWksDimensions.5044, %object
	.size	rt_ToWksDimensions.5044, 4
rt_ToWksDimensions.5044:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5043, %object
	.size	rt_ToWksNumDimensions.5043, 4
rt_ToWksNumDimensions.5043:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5042, %object
	.size	rt_ToWksWidths.5042, 4
rt_ToWksWidths.5042:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5039, %object
	.size	rt_ToWksLabels.5039, 4
rt_ToWksLabels.5039:
	.word	.LC18
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5038
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5038,4,4
	.local	rt_ToWksFrameData.5037
	.comm	rt_ToWksFrameData.5037,4,4
	.local	rt_ToWksComplexSignals.5036
	.comm	rt_ToWksComplexSignals.5036,4,4
	.local	rt_ToWksDataTypeIds.5035
	.comm	rt_ToWksDataTypeIds.5035,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5034, %object
	.size	rt_ToWksCurrSigDimsSize.5034, 4
rt_ToWksCurrSigDimsSize.5034:
	.word	4
	.local	rt_ToWksCurrSigDims.5033
	.comm	rt_ToWksCurrSigDims.5033,4,4
	.local	rt_ToWksIsVarDims.5032
	.comm	rt_ToWksIsVarDims.5032,1,4
	.align	2
	.type	rt_ToWksDimensions.5031, %object
	.size	rt_ToWksDimensions.5031, 4
rt_ToWksDimensions.5031:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5030, %object
	.size	rt_ToWksNumDimensions.5030, 4
rt_ToWksNumDimensions.5030:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5029, %object
	.size	rt_ToWksWidths.5029, 4
rt_ToWksWidths.5029:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5026, %object
	.size	rt_ToWksLabels.5026, 4
rt_ToWksLabels.5026:
	.word	.LC18
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5025
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5025,4,4
	.local	rt_ToWksFrameData.5024
	.comm	rt_ToWksFrameData.5024,4,4
	.local	rt_ToWksComplexSignals.5023
	.comm	rt_ToWksComplexSignals.5023,4,4
	.local	rt_ToWksDataTypeIds.5022
	.comm	rt_ToWksDataTypeIds.5022,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5021, %object
	.size	rt_ToWksCurrSigDimsSize.5021, 4
rt_ToWksCurrSigDimsSize.5021:
	.word	4
	.local	rt_ToWksCurrSigDims.5020
	.comm	rt_ToWksCurrSigDims.5020,4,4
	.local	rt_ToWksIsVarDims.5019
	.comm	rt_ToWksIsVarDims.5019,1,4
	.align	2
	.type	rt_ToWksDimensions.5018, %object
	.size	rt_ToWksDimensions.5018, 4
rt_ToWksDimensions.5018:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5017, %object
	.size	rt_ToWksNumDimensions.5017, 4
rt_ToWksNumDimensions.5017:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5016, %object
	.size	rt_ToWksWidths.5016, 4
rt_ToWksWidths.5016:
	.word	1
	.section	.rodata
	.align	2
.LC19:
	.ascii	"w\000"
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5013, %object
	.size	rt_ToWksLabels.5013, 4
rt_ToWksLabels.5013:
	.word	.LC19
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.5012
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.5012,4,4
	.local	rt_ToWksFrameData.5011
	.comm	rt_ToWksFrameData.5011,4,4
	.local	rt_ToWksComplexSignals.5010
	.comm	rt_ToWksComplexSignals.5010,4,4
	.local	rt_ToWksDataTypeIds.5009
	.comm	rt_ToWksDataTypeIds.5009,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.5008, %object
	.size	rt_ToWksCurrSigDimsSize.5008, 4
rt_ToWksCurrSigDimsSize.5008:
	.word	4
	.local	rt_ToWksCurrSigDims.5007
	.comm	rt_ToWksCurrSigDims.5007,4,4
	.local	rt_ToWksIsVarDims.5006
	.comm	rt_ToWksIsVarDims.5006,1,4
	.align	2
	.type	rt_ToWksDimensions.5005, %object
	.size	rt_ToWksDimensions.5005, 4
rt_ToWksDimensions.5005:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.5004, %object
	.size	rt_ToWksNumDimensions.5004, 4
rt_ToWksNumDimensions.5004:
	.word	1
	.align	2
	.type	rt_ToWksWidths.5003, %object
	.size	rt_ToWksWidths.5003, 4
rt_ToWksWidths.5003:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.5000, %object
	.size	rt_ToWksLabels.5000, 4
rt_ToWksLabels.5000:
	.word	.LC18
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4999
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4999,4,4
	.local	rt_ToWksFrameData.4998
	.comm	rt_ToWksFrameData.4998,4,4
	.local	rt_ToWksComplexSignals.4997
	.comm	rt_ToWksComplexSignals.4997,4,4
	.local	rt_ToWksDataTypeIds.4996
	.comm	rt_ToWksDataTypeIds.4996,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4995, %object
	.size	rt_ToWksCurrSigDimsSize.4995, 4
rt_ToWksCurrSigDimsSize.4995:
	.word	4
	.local	rt_ToWksCurrSigDims.4994
	.comm	rt_ToWksCurrSigDims.4994,4,4
	.local	rt_ToWksIsVarDims.4993
	.comm	rt_ToWksIsVarDims.4993,1,4
	.align	2
	.type	rt_ToWksDimensions.4992, %object
	.size	rt_ToWksDimensions.4992, 4
rt_ToWksDimensions.4992:
	.word	1
	.align	2
	.type	rt_ToWksNumDimensions.4991, %object
	.size	rt_ToWksNumDimensions.4991, 4
rt_ToWksNumDimensions.4991:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4990, %object
	.size	rt_ToWksWidths.4990, 4
rt_ToWksWidths.4990:
	.word	1
	.section	.data.rel.local
	.align	2
	.type	rt_ToWksLabels.4987, %object
	.size	rt_ToWksLabels.4987, 4
rt_ToWksLabels.4987:
	.word	.LC3
	.local	rt_ToWksLoggingPreprocessingFcnPtrs.4986
	.comm	rt_ToWksLoggingPreprocessingFcnPtrs.4986,4,4
	.local	rt_ToWksFrameData.4985
	.comm	rt_ToWksFrameData.4985,4,4
	.local	rt_ToWksComplexSignals.4984
	.comm	rt_ToWksComplexSignals.4984,4,4
	.local	rt_ToWksDataTypeIds.4983
	.comm	rt_ToWksDataTypeIds.4983,4,4
	.data
	.align	2
	.type	rt_ToWksCurrSigDimsSize.4982, %object
	.size	rt_ToWksCurrSigDimsSize.4982, 4
rt_ToWksCurrSigDimsSize.4982:
	.word	4
	.local	rt_ToWksCurrSigDims.4981
	.comm	rt_ToWksCurrSigDims.4981,4,4
	.local	rt_ToWksIsVarDims.4980
	.comm	rt_ToWksIsVarDims.4980,1,4
	.align	2
	.type	rt_ToWksDimensions.4979, %object
	.size	rt_ToWksDimensions.4979, 4
rt_ToWksDimensions.4979:
	.word	17
	.align	2
	.type	rt_ToWksNumDimensions.4978, %object
	.size	rt_ToWksNumDimensions.4978, 4
rt_ToWksNumDimensions.4978:
	.word	1
	.align	2
	.type	rt_ToWksWidths.4977, %object
	.size	rt_ToWksWidths.4977, 4
rt_ToWksWidths.4977:
	.word	17
	.section	.rodata
	.align	3
	.type	rt_ODE3_B.4100, %object
	.size	rt_ODE3_B.4100, 72
rt_ODE3_B.4100:
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
	.type	rt_ODE3_A.4099, %object
	.size	rt_ODE3_A.4099, 24
rt_ODE3_A.4099:
	.word	0
	.word	1071644672
	.word	0
	.word	1072168960
	.word	0
	.word	1072693248
	.ident	"GCC: (Sourcery G++ Lite 2009q3-67) 4.4.1"
	.section	.note.GNU-stack,"",%progbits
