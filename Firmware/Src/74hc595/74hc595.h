#ifndef __74HC595_H
#define __74HC595_H

#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio.h"

#include "74HC595.h"

#define HC595_SHCP_Low() HAL_GPIO_WritePin(GPIOA, IN14_SHCP_Pin,GPIO_PIN_RESET);
#define HC595_SHCP_High() HAL_GPIO_WritePin(GPIOA, IN14_SHCP_Pin,GPIO_PIN_SET);
#define HC595_STCP_Low() HAL_GPIO_WritePin(GPIOA, IN14_STCP_Pin,GPIO_PIN_RESET);
#define HC595_STCP_High() HAL_GPIO_WritePin(GPIOA, IN14_STCP_Pin,GPIO_PIN_SET);
#define HC595_DS_Low() HAL_GPIO_WritePin(GPIOA, IN14_DS_Pin,GPIO_PIN_RESET);
#define HC595_DS_High() HAL_GPIO_WritePin(GPIOA, IN14_DS_Pin,GPIO_PIN_SET);

void delay(uint16_t t);
void HC595_CS(void);
void HC595_Send_Byte(uint8_t byte);
void HC595_Send_Multi_Byte(uint8_t *data, uint16_t len);
#endif /* __MAIN_H */
