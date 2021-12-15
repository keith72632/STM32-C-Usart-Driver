/*
 * usart.cpp
 *
 *  Created on: Dec 13, 2021
 *      Author: keith
 */

#include <usart.h>

usart::usart(uint32_t clk, uint32_t pin_clk, uint32_t pin_mode, uint32_t base) {
	// TODO Auto-generated constructor stub
	_clk = clk;
	_pin_clk = pin_clk;
	_pin_mode = pin_mode;
	_pin_alt = pin_mode + 0x20;
	_base = base;
}


void usart::start_clks()
{
	uint32_t *clk = (uint32_t*)_clk;
	uint32_t *pin_clk = (uint32_t*)_pin_clk;

	*pin_clk |= (1 << 0);
	*clk |= (1 << 17);
}

void usart::gpio_config()
{
	uint32_t *pin_mode = (uint32_t*)_pin_mode;
	uint32_t *alt = (uint32_t*)_pin_alt;

	*pin_mode |= (2 << 4) | (2 << 6);
	*alt |= (7 << 8) | (7 << 12);
}

void usart::usart_config()
{
	uint32_t brr = _base + 0x08;
	uint32_t cr1 = _base + 0x0c;
	uint32_t *pBrr = (uint32_t*)brr;
	uint32_t *pCr1 = (uint32_t*)cr1;

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

	uint32_t *pSr = (uint32_t*)sr;
	uint32_t *pDr = (uint32_t*)dr;

	*pDr = c;
	while(!(*pSr & (1<<6)));
}


usart::~usart() {
	// TODO Auto-generated destructor stub
}

