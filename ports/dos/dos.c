#include <stdio.h>
#include <dos.h>

#include "py/mpconfig.h"

// Receive single character
int mp_hal_stdin_rx_chr(void)
{
	return getchar();
}

// Send string of given length
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len)
{
	for (mp_uint_t i = 0; i < len; i++) {
		putchar(str[i]);
	}
}
