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
	uint32_t _pin_mode;
	uint32_t _pin_alt;
	uint32_t _base;
public:
	usart(uint32_t clk, uint32_t pin_clk, uint32_t pin_mode, uint32_t base);
	void start_clks();
	void gpio_config();
	void usart_config();
	void usart_init();
	void uputc(char c);
	virtual ~usart();
};

#endif /* USART_H_ */
