/*
author          Oliver Blaser
date            23.06.2024
copyright       GPL-3.0 - Copyright (c) 2024 Oliver Blaser
*/

#ifndef IG_DRIVER_GPIO_H
#define IG_DRIVER_GPIO_H

#include <stdint.h>

#include "stm32f0xx.h"



#define GPIO_BTN0 GPIOB, 1
#define GPIO_LED0 GPIOA, 8



#define BIT(n) (1u << (n))



void GPIO_init();

static inline uint32_t __attribute__((always_inline)) GPIO_read(const GPIO_TypeDef* port) { return (port->IDR); }

static inline void __attribute__((always_inline)) GPIO_write(GPIO_TypeDef* port, uint32_t value) { port->ODR = value; }

static inline void __attribute__((always_inline)) GPIO_set(GPIO_TypeDef* port, uint32_t mask) { port->BSRR = mask; }

static inline void __attribute__((always_inline)) GPIO_clr(GPIO_TypeDef* port, uint32_t mask) { port->BRR = mask; }

static inline int __attribute__((always_inline)) GPIO_readPin(const GPIO_TypeDef* port, uint8_t pin) { return ((port->IDR) & BIT(pin)); }

static inline void __attribute__((always_inline)) GPIO_writePin(GPIO_TypeDef* port, uint8_t pin, int state)
{
    if (state) { port->BSRR = BIT(pin); }
    else { port->BRR = BIT(pin); }
}

static inline void __attribute__((always_inline)) GPIO_setPin(GPIO_TypeDef* port, uint8_t pin) { port->BSRR = BIT(pin); }

static inline void __attribute__((always_inline)) GPIO_clrPin(GPIO_TypeDef* port, uint8_t pin) { port->BRR = BIT(pin); }

static inline void __attribute__((always_inline)) GPIO_togglePin(GPIO_TypeDef* port, uint8_t pin)
{
    if ((port->ODR) & BIT(pin)) { port->BRR = BIT(pin); }
    else { port->BSRR = BIT(pin); }
}


#endif // IG_DRIVER_GPIO_H
