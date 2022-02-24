.include "m328Pdef.inc"

Start:
        ldi r17, 0b11100011 ; identifying input pins 11,12,13
        out DDRB,r17            ; declaring pins as input
        ldi r17, 0b11111111 ;
        out PORTB,r17           ; activating internal pullup for pins 11,12,13  
        in r17,PINB

	ldi r20,0b00000010 ;counter
	rcall loopr

	ldi r21,0b00000001
	and r21,r17 ;getting value of C

	lsr r17
	ldi r22,0b00000001
        and r22,r17 ;getting value of B

	lsr r17
        ldi r23,0b00000001
        and r23,r17 ;getting value of A

	ldi r24,0b00000001
	eor r23,r24 ;A'
	eor r22,r24 ;B'
	and r22,r21 ;B'C
	or r23,r22  ;A'+B'C

	ldi r20,0b00000010
	rcall loopl

	ldi r16, 0b00111100     ;identifying output pins 2,3,4,5
	out DDRD,r16		;declaring pins as output
	out PORTD,r23		;writing output to pins 2,3,4,5

	rjmp Start

loopr:	lsr r17
	dec r20
	brne loopr
	ret
loopl:	lsl r23
	dec r20
	brne loopl
	ret
