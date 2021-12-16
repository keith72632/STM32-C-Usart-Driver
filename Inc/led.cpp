/*
 * led.cpp
 *
 *  Created on: Dec 13, 2021
 *      Author: keith
 */

#include "led.h"
#include "main.h"

led::led(uint32_t gpio, uint32_t pin_no) {
	// TODO Auto-generated constructor stub
	switch(gpio)
	{
	case 3:
		uint32_t base = (uint32_t)GPIOD_BASE;
		_rcc = GPIOD_CLK;
		_mode = base;
		_output = (uint32_t)GPIOD_ODR;
		_pin_clk = gpio;
		break;
	}

	_pin_no = pin_no;
}

void led::start_clock(void)
{
	uint32_t *rcc = (uint32_t *)_rcc;
	*rcc |= 1 << _pin_clk;
}

void led::led_on(void)
{
	uint32_t *mode = (uint32_t*)_mode;
	uint32_t *out = (uint32_t*)_output;

	*mode |= 1 << (_pin_no * 2);
	*out |= 1 << _pin_no;
}

void led::led_off(void)
{
	uint32_t *out = (uint32_t*)_output;
	*out &= ~(1 << _pin_no);

}

led::~led() {
	// TODO Auto-generated destructor stub
}

