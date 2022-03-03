
#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
int i,a,b,c,out;
 //Declare as input pins
 DDRD   |= 0b00000000;
 /* Arduino boards have a LED at PB5 */
 //set PB5, pin 13 of arduino as output
 DDRB    |= ((1 << DDB5));
while (1) 
{
//Getting inputs to i
i = PIND;
a = i & 0b00100000;
b = i & 0b01000000;
c = i & 0b10000000;
out=!(a&&!((!b)&&c));
if(out==1)
//turn led on
 PORTB = ((1 <<  PB5));
//turn led off
else
 PORTB = ((0 <<  PB5));
}
  return 0;
}
