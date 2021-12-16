/*
 * usart.cpp
 *
 *  Created on: Dec 13, 2021
 *      Author: keith
 */

#include <usart.h>
#include "main.h"

usart::usart(const uint32_t uart) {
	switch(uart)
	{
	case 1:
		uint32_t base = (uint32_t)USART2_BASE;
		_clk = (uint32_t)USART2_CLK;
		_pin_clk = (uint32_t)GPIOA_CLK;
		_pin_mode = (uint32_t)GPIOA_MODE;
		_pin_alt = _pin_mode + 0x20;
		_base = base;
	}

}


void usart::start_clks()
{
	uint32_t volatile *clk = (uint32_t*)_clk;
	uint32_t volatile *pin_clk = (uint32_t*)_pin_clk;

	*pin_clk |= (1 << 0);
	*clk |= (1 << 17);
}

void usart::gpio_config()
{
	uint32_t volatile *pin_mode = (uint32_t*)_pin_mode;
	uint32_t volatile *alt = (uint32_t*)_pin_alt;

	*pin_mode |= (2 << 4) | (2 << 6);
	*alt |= (7 << 8) | (7 << 12);
}

void usart::usart_config()
{
	uint32_t brr = _base + 0x08;
	uint32_t cr1 = _base + 0x0c;
	uint32_t volatile *pBrr = (uint32_t*)brr;
	uint32_t volatile *pCr1 = (uint32_t*)cr1;

	*pCr1 = 0x00;
	*pCr1 |= (1 << 13);
	*pBrr = 0x104;
	*pCr1 |= (1 << 2) | (1 << 3);
}

void usart::usart_init()
{
	this->start_clks();
	this->gpio_config();
	this->usart_config();
}

void usart::uputc(char c)
{
	uint32_t sr = (uint32_t)_base;
	uint32_t dr = (uint32_t)_base + 0x04;

	uint32_t volatile *pSr = (uint32_t*)sr;
	uint32_t volatile *pDr = (uint32_t*)dr;

	*pDr = c;
	while(!(*pSr & (1<<6)));
}


usart::~usart() {
	// TODO Auto-generated destructor stub
}

