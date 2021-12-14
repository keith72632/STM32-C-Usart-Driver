/*
 * usart.h
 *
 *  Created on: Dec 13, 2021
 *      Author: keith
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>
class usart {
private:
	uint32_t _clk;
	uint32_t _pin_clk;
public:
	usart(uint32_t clk, uint32_t pin_clk);
	void start_clks();
	virtual ~usart();
};

#endif /* USART_H_ */
