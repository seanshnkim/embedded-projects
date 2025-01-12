/*
 * msp.c
 *
 *  Created on: Jan 11, 2025
 *      Author: sean-shk
 */
#include "stm32f4xx_hal.h"

void HAL_MspInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspInit could be implemented in the user file
   */
  // 1. Set up the priority grouping of the ARM Cortex Mx processor
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  // 2. Enable the required system exceptions of the ARM Cortex Mx processor
  SCB->SHCSR |= 0x7 << 16;

  // 3. Configure the priority for the system exceptions
  HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  // Here we are going to do the low level inits of the USART2 peripheral.
  GPIO_InitTypeDef gpio_uart;

  // 1. Enable the clock for the USART2 peripheral
  __HAL_RCC_USART1_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // 2. Do the pin muxing configurations.
  // It's not GPIO_PIN_2 because I am using F429I instead of F446!
  gpio_uart.Pin = GPIO_PIN_9 | GPIO_PIN_10;  // PA9 is TX, PA10 is RX for USART1
  gpio_uart.Mode = GPIO_MODE_AF_PP;
  gpio_uart.Pull = GPIO_PULLUP; // Most of the cases it is pulled up
  gpio_uart.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio_uart.Alternate = GPIO_AF7_USART1;  // USART1 uses AF7
  HAL_GPIO_Init(GPIOA, &gpio_uart);

  // 3. Enable the IRQ and set up the priority (NVIC settings)
  HAL_NVIC_EnableIRQ(USART1_IRQn);
  HAL_NVIC_SetPriority(USART1_IRQn, 15, 0);
}
