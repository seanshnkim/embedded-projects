/*
 * it.c
 *
 *  Created on: Jan 11, 2025
 *      Author: sean-shk
 */


void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}
