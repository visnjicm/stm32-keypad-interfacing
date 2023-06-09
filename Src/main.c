/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

uint32_t* rcc_ahb1enr = (uint32_t*) (0x40023800+0x30);
uint32_t* gpioa_moder = (uint32_t*) (0x40020000);
uint32_t* gpiob_moder = (uint32_t*) (0x40020400);
uint32_t* gpioa_pupdr = (uint32_t*) (0x4002000c);
uint32_t* gpiob_pupdr = (uint32_t*) (0x4002040c);
uint32_t* gpioa_odr = (uint32_t*) (0x40020014);
uint32_t* gpioa_idr = (uint32_t*) (0x40020010);
uint32_t* gpiob_odr = (uint32_t*) (0x40020414);
uint32_t* gpiob_idr = (uint32_t*) (0x40020410);

extern void initialise_monitor_handles(void);

int main(void)
{
	initialise_monitor_handles();

	*rcc_ahb1enr |= (uint32_t) 0x3;
	*gpioa_moder &= (uint32_t) 0xFFE0FFFF;
	*gpioa_moder |= (uint32_t) 0x10000;
	*gpiob_moder &= (uint32_t) 0xFFCFC0FF;
	*gpiob_moder |= (uint32_t) 0x100500;

	*gpioa_odr &= (uint32_t) 0xFFFFFEFF;
	*gpioa_odr |= (uint32_t) 0x100;
	*gpiob_odr &= (uint32_t) 0xFFFFFBC0;
	*gpiob_odr |= (uint32_t) 0x430;



    /* Loop forever */
	for(;;)
	{

		*gpioa_odr &= (uint32_t) 0xFFFFFEFF;

		if (((uint32_t) *gpiob_idr & (1<<3)) == 0)
		{
			printf("1\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<10)) == 0)
		{
			printf("2\n");
		}

		if (((uint32_t) *gpiob_idr & (1<<6)) == 0)
		{
			printf("3\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<9)) == 0)
		{
			printf("A\n");
		}

		*gpioa_odr |= (uint32_t) 0x100;




		*gpiob_odr &= (uint32_t) 0xFFFFFBFF;

		if (((uint32_t) *gpiob_idr & (1<<3)) == 0)
		{
			printf("4\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<10)) == 0)
		{
			printf("5\n");
		}

		if (((uint32_t) *gpiob_idr & (1<<6)) == 0)
		{
			printf("6\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<9)) == 0)
		{
			printf("B\n");
		}

		*gpiob_odr |= (uint32_t) 0x400;



		*gpiob_odr &= (uint32_t) 0xFFFFFFEF;

		if (((uint32_t) *gpiob_idr & (1<<3)) == 0)
		{
			printf("7\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<10)) == 0)
		{
			printf("8\n");
		}

		if (((uint32_t) *gpiob_idr & (1<<6)) == 0)
		{
			printf("9\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<9)) == 0)
		{
			printf("C\n");
		}

		*gpiob_odr |= (uint32_t) 0x10;




		*gpiob_odr &= (uint32_t) 0xFFFFFFDF;

		if (((uint32_t) *gpiob_idr & (1<<3)) == 0)
		{
			printf("*\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<10)) == 0)
		{
			printf("0\n");
		}

		if (((uint32_t) *gpiob_idr & (1<<6)) == 0)
		{
			printf("#\n");
		}

		if (((uint32_t) *gpioa_idr & (1<<9)) == 0)
		{
			printf("D\n");
		}

		*gpiob_odr |= (uint32_t) 0x20;


	}
}
