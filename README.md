# Source
These are demo projects adapted from the following courses in Udemy:

1. [Mastering Microcontroller: Timers, PWM, CAN, Low Power(MCU2)](https://www.udemy.com/course/microcontroller-programming-stm32-timers-pwm-can-bus-protocol)
2. [Mastering RTOS: Hands on FreeRTOS and STM32Fx with Debugging](https://www.udemy.com/course/mastering-rtos-hands-on-with-freertos-arduino-and-stm32fx)
3. [Embedded Systems Programming on ARM Cortex-M3/M4 Processor](https://www.udemy.com/course/embedded-system-programming-on-arm-cortex-m3m4)

The original source code for each lecture can be found in Kiran's [Github repositories](https://github.com/niekiran). 

# Hardware / Software Requirements
## Software
- STM32CubeIDE Ver 1.17.0
- Ubuntu Linux 24.04

## Hardware
The projects are implemented on the [STM32F429I-DISC1](https://www.st.com/en/evaluation-tools/32f429idiscovery.html).
It uses the same ARM Cortex M4 processor as F407 or F446 (the ones that are used in the lectures), but there are differences such as:

- SWO (Serial Wire Output): SWO signal in F429I is by default **NOT** connected. SB9 needs to be *manually* soldered to activate SWO signal connection.
- GPIO pins: For USART1, PA9 and PA10 can be used. In F446, PA2 or PA3 is used for USART2.
- The number of LEDs: Two leds: LD3 (orange LED) and LD4 (green LED) are provided. In F407, there are four LEDs to be maneuvered (PD12~PD15).


# Takeaway

## 1. It is run on a different microcontroller
The code is run on STM32F429I and it will be helpful for those who try to use it for the lectures.
Also, working on the different board setting makes (forces) you to learn good lessons: how to configure GPIO pins, how to initialize peripherals, and why referencing datasheets matters, etc.

An embedded systems programmer must pay attention to low-level details of a microcontroller. By using a different board than the one in the lectures for this project, I was able to learn this lesson through trial and error, although the process may have been painful and frustrating.


## 2. Updated environments
The lectures are well structured and informative but somewhat old.
I tried to use recently updated libraries and environment as much as possible.
For example, instead of using CMSIS-RTOS v1 I applied v2 in FreeRTOS projects.


# File Structure
To reduce uploaded file size, I excluded most of the header and source files required for build.
Any files that are modified by the lecturer or needs different config due to the different microcontroller settings are committed to this repo.

As an example, UART2_Example' folder has the following files uploaded in this repository.

```
├── Core
│   ├── Inc
│   │   ├── it.h
│   │   ├── main.h
│   │   └── stm32f4xx_hal_conf.h
│   ├── Src
│   │   ├── it.c
│   │   ├── main.c
│   │   ├── msp.c
│   │   └── system_stm32f4xx.c
```

However, the original files have a lot more :
These files are intact 


```
.
├── Core
│   ├── Inc
│   │   ├── it.h
│   │   ├── main.h
│   │   └── stm32f4xx_hal_conf.h
│   ├── Src
│   │   ├── it.c
│   │   ├── main.c
│   │   ├── msp.c
│   │   └── system_stm32f4xx.c
│   └── Startup
│       └── startup_stm32f446retx.s
├── Debug
│   ├── Core
│   │   ├── Inc
│   │   │   └── subdir.mk
│   │   ├── Src
│   │   │   ├── it.cyclo
│   │   │   ├── it.d
│   │   │   ├── it.o
│   │   │   ├── it.su
│   │   │   ├── main.cyclo
│   │   │   ├── main.d
│   │   │   ├── main.o
│   │   │   ├── main.su
│   │   │   ├── msp.cyclo
│   │   │   ├── msp.d
│   │   │   ├── msp.o
│   │   │   ├── msp.su
│   │   │   ├── subdir.mk
│   │   │   ├── system_stm32f4xx.cyclo
│   │   │   ├── system_stm32f4xx.d
│   │   │   ├── system_stm32f4xx.o
│   │   │   └── system_stm32f4xx.su
│   │   └── Startup
│   │       ├── startup_stm32f446retx.d
│   │       ├── startup_stm32f446retx.o
│   │       └── subdir.mk
│   ├── Drivers
│   │   └── STM32F4xx_HAL_Driver
│   │       └── Src
│   │           ├── stm32f4xx_hal_cortex.cyclo
│   │           ├── stm32f4xx_hal_cortex.d
│   │           ├── stm32f4xx_hal_cortex.o
│   │           ├── stm32f4xx_hal_cortex.su
│   │           ├── stm32f4xx_hal.cyclo
│   │           ├── stm32f4xx_hal.d
│   │           ├── stm32f4xx_hal_dma.cyclo
│   │           ├── stm32f4xx_hal_dma.d
│   │           ├── stm32f4xx_hal_dma_ex.cyclo
│   │           ├── stm32f4xx_hal_dma_ex.d
│   │           ├── stm32f4xx_hal_dma_ex.o
│   │           ├── stm32f4xx_hal_dma_ex.su
│   │           ├── stm32f4xx_hal_dma.o
│   │           ├── stm32f4xx_hal_dma.su
│   │           ├── stm32f4xx_hal_exti.cyclo
│   │           ├── stm32f4xx_hal_exti.d
│   │           ├── stm32f4xx_hal_exti.o
│   │           ├── stm32f4xx_hal_exti.su
│   │           ├── stm32f4xx_hal_flash.cyclo
│   │           ├── stm32f4xx_hal_flash.d
│   │           ├── stm32f4xx_hal_flash_ex.cyclo
│   │           ├── stm32f4xx_hal_flash_ex.d
│   │           ├── stm32f4xx_hal_flash_ex.o
│   │           ├── stm32f4xx_hal_flash_ex.su
│   │           ├── stm32f4xx_hal_flash.o
│   │           ├── stm32f4xx_hal_flash_ramfunc.cyclo
│   │           ├── stm32f4xx_hal_flash_ramfunc.d
│   │           ├── stm32f4xx_hal_flash_ramfunc.o
│   │           ├── stm32f4xx_hal_flash_ramfunc.su
│   │           ├── stm32f4xx_hal_flash.su
│   │           ├── stm32f4xx_hal_gpio.cyclo
│   │           ├── stm32f4xx_hal_gpio.d
│   │           ├── stm32f4xx_hal_gpio.o
│   │           ├── stm32f4xx_hal_gpio.su
│   │           ├── stm32f4xx_hal.o
│   │           ├── stm32f4xx_hal_pwr.cyclo
│   │           ├── stm32f4xx_hal_pwr.d
│   │           ├── stm32f4xx_hal_pwr_ex.cyclo
│   │           ├── stm32f4xx_hal_pwr_ex.d
│   │           ├── stm32f4xx_hal_pwr_ex.o
│   │           ├── stm32f4xx_hal_pwr_ex.su
│   │           ├── stm32f4xx_hal_pwr.o
│   │           ├── stm32f4xx_hal_pwr.su
│   │           ├── stm32f4xx_hal_rcc.cyclo
│   │           ├── stm32f4xx_hal_rcc.d
│   │           ├── stm32f4xx_hal_rcc_ex.cyclo
│   │           ├── stm32f4xx_hal_rcc_ex.d
│   │           ├── stm32f4xx_hal_rcc_ex.o
│   │           ├── stm32f4xx_hal_rcc_ex.su
│   │           ├── stm32f4xx_hal_rcc.o
│   │           ├── stm32f4xx_hal_rcc.su
│   │           ├── stm32f4xx_hal.su
│   │           ├── stm32f4xx_hal_tim.cyclo
│   │           ├── stm32f4xx_hal_tim.d
│   │           ├── stm32f4xx_hal_tim_ex.cyclo
│   │           ├── stm32f4xx_hal_tim_ex.d
│   │           ├── stm32f4xx_hal_tim_ex.o
│   │           ├── stm32f4xx_hal_tim_ex.su
│   │           ├── stm32f4xx_hal_tim.o
│   │           ├── stm32f4xx_hal_tim.su
│   │           ├── stm32f4xx_hal_uart.cyclo
│   │           ├── stm32f4xx_hal_uart.d
│   │           ├── stm32f4xx_hal_uart.o
│   │           ├── stm32f4xx_hal_uart.su
│   │           └── subdir.mk
│   ├── makefile
│   ├── objects.list
│   ├── objects.mk
│   ├── sources.mk
│   ├── UART2_Example.elf
│   ├── UART2_Example_F429I.map
│   ├── UART2_Example.list
│   └── UART2_Example.map
├── Drivers
│   ├── CMSIS
│   │   ├── Device
│   │   │   └── ST
│   │   │       └── STM32F4xx
│   │   │           ├── Include
│   │   │           │   ├── stm32f429xx.h
│   │   │           │   ├── stm32f4xx.h
│   │   │           │   └── system_stm32f4xx.h
│   │   │           └── License.md
│   │   ├── Include
│   │   │   ├── cmsis_armcc.h
│   │   │   ├── cmsis_armclang.h
│   │   │   ├── cmsis_compiler.h
│   │   │   ├── cmsis_gcc.h
│   │   │   ├── cmsis_iccarm.h
│   │   │   ├── cmsis_version.h
│   │   │   ├── core_armv8mbl.h
│   │   │   ├── core_armv8mml.h
│   │   │   ├── core_cm0.h
│   │   │   ├── core_cm0plus.h
│   │   │   ├── core_cm1.h
│   │   │   ├── core_cm23.h
│   │   │   ├── core_cm33.h
│   │   │   ├── core_cm3.h
│   │   │   ├── core_cm4.h
│   │   │   ├── core_cm7.h
│   │   │   ├── core_sc000.h
│   │   │   ├── core_sc300.h
│   │   │   ├── mpu_armv7.h
│   │   │   ├── mpu_armv8.h
│   │   │   └── tz_context.h
│   │   └── LICENSE.txt
│   └── STM32F4xx_HAL_Driver
│       ├── Inc
│       │   ├── Legacy
│       │   │   └── stm32_hal_legacy.h
│       │   ├── stm32f4xx_hal_cortex.h
│       │   ├── stm32f4xx_hal_def.h
│       │   ├── stm32f4xx_hal_dma_ex.h
│       │   ├── stm32f4xx_hal_dma.h
│       │   ├── stm32f4xx_hal_exti.h
│       │   ├── stm32f4xx_hal_flash_ex.h
│       │   ├── stm32f4xx_hal_flash.h
│       │   ├── stm32f4xx_hal_flash_ramfunc.h
│       │   ├── stm32f4xx_hal_gpio_ex.h
│       │   ├── stm32f4xx_hal_gpio.h
│       │   ├── stm32f4xx_hal.h
│       │   ├── stm32f4xx_hal_pwr_ex.h
│       │   ├── stm32f4xx_hal_pwr.h
│       │   ├── stm32f4xx_hal_rcc_ex.h
│       │   ├── stm32f4xx_hal_rcc.h
│       │   ├── stm32f4xx_hal_tim_ex.h
│       │   ├── stm32f4xx_hal_tim.h
│       │   └── stm32f4xx_hal_uart.h
│       ├── License.md
│       └── Src
│           ├── stm32f4xx_hal.c
│           ├── stm32f4xx_hal_cortex.c
│           ├── stm32f4xx_hal_dma.c
│           ├── stm32f4xx_hal_dma_ex.c
│           ├── stm32f4xx_hal_exti.c
│           ├── stm32f4xx_hal_flash.c
│           ├── stm32f4xx_hal_flash_ex.c
│           ├── stm32f4xx_hal_flash_ramfunc.c
│           ├── stm32f4xx_hal_gpio.c
│           ├── stm32f4xx_hal_pwr.c
│           ├── stm32f4xx_hal_pwr_ex.c
│           ├── stm32f4xx_hal_rcc.c
│           ├── stm32f4xx_hal_rcc_ex.c
│           ├── stm32f4xx_hal_tim.c
│           ├── stm32f4xx_hal_tim_ex.c
│           └── stm32f4xx_hal_uart.c
├── STM32F446RETX_FLASH.ld
├── STM32F446RETX_RAM.ld
├── UART2_Example_F429I.ioc
└── UART2_Example.launch

```