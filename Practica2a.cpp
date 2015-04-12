/*-----------------------------------------------------------------
**
**  Fichero:
**    pract2a.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Busca el valor máximo de un vector de enteros positivos
**
**  Notas de diseño:
**
**---------------------------------------------------------------*/

.global start

.EQU 	N, 8

.data
A: 		.word 7,3,25,4,75,2,1,1

.bss
max: 	.space 4

.text
start:
		mov r0,#0	//contador
		ldr r1,=max		@ Leo la dir. de max
		str r0,[r1]		@ Escribo 0 en max
		LDR R2,=A
		MOV R4,#0

for: 	CMP R0,#N
		BGE fin
		LDR R3,[R2, R0, LSL#2] //r3 = A(i)
		CMP R3,R4
		BLT menor
		STR R3,[R1]
		LDR R4,[R1]
		ADD R0,R0,#1
		B for
menor:	ADD R0,R0,#1
		B for
fin:	B .
		.end

