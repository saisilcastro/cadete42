#define _XTAL_FREQ 48000000

void pin_io(void)
{
	TRISB = 0xFF; // entrada do usuario
	TRISD = 0x00; // saida dos leds

	PORTB = 0x00; // inicia tudo com 0
	PORTD = 0x00;
}

int main(void)
{
	char s1[] = {0b11111110, 0b11111101, 0b11111011, 0b11110111,
				 0b11101111, 0b11011111, 0b10111111, 0b01111111};
	char i = 0;

	pin_io();
	while(1)
	{
		if (!PORTBbits.RB1) // botao pressionado
		{
			PORTD = s1[i]; // liga led selecionado
			__delay_ms(250);
			PORTD = 0xFF; // desliga todos os bits
			__delay_ms(250);
			i++;
			if (i > 7)
				i = 0;
		}
		else // se o botao for solto
			PORTD = 0xFF; // desliga todos os leds
	}
	return (0);
}