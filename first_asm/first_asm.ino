void setup()
{
	;
}

void loop()
{
	asm volatile(	"ldi r18, 0xff" "\n\t"
					"out 10, r18" "\n\t"
					"out 11, r18" "\n\t"
					:::"r18");
}