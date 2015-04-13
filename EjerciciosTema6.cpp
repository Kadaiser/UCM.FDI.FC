===============================================================================
Programa que almacena en la variable "Mayor" el entero mas grande
===============================================================================

.global start
.data
X: 		.word 0x03
Y: 		.word 0x0A

.bss
Mayor: 	.space 4

.text
start:
		LDR R4, =X
		LDR R3, =Y
		LDR R5, =Mayor
		LDR R1, [R4]
		LDR R2, [R3]
		CMP R1, R2
		BLE else
		STR R1, [R5]
		B FIN
else: 	STR R2, [R5]
FIN: 	B .

		.end

===============================================================================
Programa que divide 2 enteros y devuelve el resultado en memoria y el resto en el registro
===============================================================================


.global start
.data
A: 		.word 0x0F
B: 		.word 0x03
C:		.word 0X00

.text
start:		LDR R1, =A
		LDR R2, [R1]
		LDR R1, =B
		LDR R3, [R1]
		LDR R1, =C
		LDR R4, [R1]
		CMP R2, R3
loop:	BLE fin
		SUBS R2, R2, R3
		ADD R4, R4 , #1
		B loop
fin:	STR R4, [R1]
		B .
		.end

