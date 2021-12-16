/*
 * usart.h
 *
 *  Created on: Dec 13, 2021
 *      Author: keith
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>

typedef enum
{
	USART_1,
	USART_2,
	USART_3
}uart_t;


class usart {
private:
	uint32_t _clk;
	uint32_t _pin_clk;
	uint32_t _pin_mode;
	uint32_t _pin_alt;
	uint32_t _base;
public:
	usart(const uint32_t base);
	void start_clks();
	void gpio_config();
	void usart_config();
	void usart_init();
	void uputc(char c);
	virtual ~usart();
};

#endif /* USART_H_ */
