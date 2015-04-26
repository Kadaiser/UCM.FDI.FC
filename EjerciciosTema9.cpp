/**

Programa para ensalblador ARM que dado un vector A genere un Vector B, 
tal que B solo contenga los componenetes de  A que son mayores que 0.

A = (0,1,2,7,-8,4,5,12,11,-2,6,3) -> b = (2,4,12,6)

Empelar la subrrutina NuperoPar(A(i)) que retorna 1 si A(i) es par y devulve 0 en caso contrario.

*/

	.global start

.EQU			N,12
		.data
A:		.word	0,1,2,7,-8,4,5,12,11,-2,6,3
		.bss
B:		.space 4*N
		.text

start:
		MOV R4, #0
		MOV R7, #0
		LDR R5, =A
		LDR R6, =B

for:
		CMP R4, #N
		BGE fin
		LDR R0,[R5,R4,LSL#2]
		CMP R0, #0
		BLE menorCero
		PUSH, {R0}
		BL numeroPar
		CMP R0,#1
		POP, {R0}
		BEQ esPar

menorCero:
		ADD R4,R4,#1
		B for

esPar:
		STR R0,[R6,R7,LSL#2]
		ADD R7,R7,#1
		ADD R4,R4,#1
		B for
fin:
		B .

numeroPar:
		MOV R2, #1
		ADD R0,R0,R2
		CMP R0, #0
		BEQ par
		MOV R0, #1
		MOV PC, LR
par:
		MOV R0,#1
		MOV PC,LR

		.end

