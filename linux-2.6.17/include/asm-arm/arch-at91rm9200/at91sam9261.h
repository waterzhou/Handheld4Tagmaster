/*
 * include/asm-arm/arch-at9sam9261/at91sam9261.h
 *
 * Copyright (C) SAN People
 *
 * Common definitions.
 * Based on AT91SAM9261 datasheet revision A.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef AT91SAM9261_H
#define AT91SAM9261_H

/*
 * Peripheral identifiers/interrupts.
 */
#define AT91_ID_FIQ	0	/* Advanced Interrupt Controller (FIQ) */
#define AT91_ID_SYS	1	/* System Peripheral */
#define AT91_ID_PIOA	2	/* Parallel IO Controller A */
#define AT91_ID_PIOB	3	/* Parallel IO Controller B */
#define AT91_ID_PIOC	4	/* Parallel IO Controller C */
#define AT91_ID_US0	6	/* USART 0 */
#define AT91_ID_US1	7	/* USART 1 */
#define AT91_ID_US2	8	/* USART 2 */
#define AT91_ID_MCI	9	/* Multimedia Card Interface */
#define AT91_ID_UDP	10	/* USB Device Port */
#define AT91_ID_TWI	11	/* Two-Wire Interface */
#define AT91_ID_SPI0	12	/* Serial Peripheral Interface 0 */
#define AT91_ID_SPI1	13	/* Serial Peripheral Interface 1 */
#define AT91_ID_SSC0	14	/* Serial Synchronous Controller 0 */
#define AT91_ID_SSC1	15	/* Serial Synchronous Controller 1 */
#define AT91_ID_SSC2	16	/* Serial Synchronous Controller 2 */
#define AT91_ID_TC0	17	/* Timer Counter 0 */
#define AT91_ID_TC1	18	/* Timer Counter 1 */
#define AT91_ID_TC2	19	/* Timer Counter 2 */
#define AT91_ID_UHP	20	/* USB Host port */
#define AT91_ID_LCDC	21	/* LDC Controller */
#define AT91_ID_IRQ0	29	/* Advanced Interrupt Controller (IRQ0) */
#define AT91_ID_IRQ1	30	/* Advanced Interrupt Controller (IRQ1) */
#define AT91_ID_IRQ2	31	/* Advanced Interrupt Controller (IRQ2) */


/*
 * Peripheral physical base addresses.
 */
#define AT91_BASE_TCB0		0xfffa0000
#define AT91_BASE_TC0		0xfffa0000
#define AT91_BASE_TC1		0xfffa0040
#define AT91_BASE_TC2		0xfffa0080
#define AT91_BASE_UDP		0xfffa4000
#define AT91_BASE_MCI		0xfffa8000
#define AT91_BASE_TWI		0xfffac000
#define AT91_BASE_US0		0xfffb0000
#define AT91_BASE_US1		0xfffb4000
#define AT91_BASE_US2		0xfffb8000
#define AT91_BASE_SSC0		0xfffbc000
#define AT91_BASE_SSC1		0xfffc0000
#define AT91_BASE_SSC2		0xfffc4000
#define AT91_BASE_SPI0		0xfffc8000
#define AT91_BASE_SPI1		0xfffcc000
#define AT91_BASE_SYS		0xffffea00

#define AT91_BASE_AIC		0xfffff000
#define AT91_BASE_PIOA		0xfffff400
#define AT91_BASE_PIOB		0xfffff600
#define AT91_BASE_PIOC		0xfffff800
#define AT91_BASE_PITC		0xfffffD30
#define AT91_BASE_PMC		0xfffffC00
#define AT91_BASE_DBGU		0xfffff200


/*
 * PIO pin definitions (peripheral A/B multiplexing).
 */

// TODO: "PIO PIN definitions"

#endif
