/*
 * led.h
 *
 *  Created on: Dec 13, 2021
 *      Author: keith
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>

typedef enum {
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD
}rcc_clk_t;

typedef enum {
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,
}pin_t;
class led {
private:
	uint32_t _rcc;
	uint32_t _mode;
	uint32_t _output;
	uint32_t _pin_clk;
	uint32_t _pin_no;
public:
	led(uint32_t rcc, uint32_t mode, uint32_t output, uint32_t pin_clk, uint32_t pin_no);
	void start_clock(void);
	void led_on(void);
	void led_off(void);
	virtual ~led();
};

#endif /* LED_H_ */

