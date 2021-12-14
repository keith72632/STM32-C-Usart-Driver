/*
 * usart.cpp
 *
 *  Created on: Dec 13, 2021
 *      Author: keith
 */

#include <usart.h>

usart::usart(uint32_t clk, uint32_t pin_clk) {
	// TODO Auto-generated constructor stub
	_clk = clk;
	_pin_clk = pin_clk;
}

void usart::start_clks()
{
	uint32_t *clk = (uint32_t*)_clk;
	uint32_t *pin_clk = (uint32_t*)_pin_clk;

	*pin_clk |= (1 << 0);
	*clk |= (1 << 17);
}

usart::~usart() {
	// TODO Auto-generated destructor stub
}

