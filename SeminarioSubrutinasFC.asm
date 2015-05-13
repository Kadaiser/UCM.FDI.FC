/*-----------------------------------------------------------------
**
**  Fichero:
**    init.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid Notas de diseño:
**
**---------------------------------------------------------------*/

    .extern Es_multiplo			//No es mio, pero lo necesito
    .extern _stack
	.global start
.equ N, 8
.equ M, 4
.data
	A:	 .word 15, 16, 4, 17, 11, 33, 22, 12
	primos:	 .word 2, 3, 5, 7

.bss
	B:	 .space N*4
.text

start:
    ldr sp,=_stack
    ldr r6, =A
    ldr r7, =B
    mov r4, #0
 for_A:   	cmp r4, #N    //recorre el vector A
 			bge fin_for_A
 			ldr r8, [r6, r4, lsl #2]	//cargar el valor de A(i)

 			mov r0, r8	//primer parametro A[i];
 			mov r1, r7	//segundo parametro Direccion del vector B
 			mov r2, #M	//longitud del vector B
			bl dime_si_primo

			cmp r0,#0
			BEQ no_es_primo

 fin_for_primos:	str r8, [r6, r4, lsl #2]
 no_es_primo:		add r4, r4, #1
 					b for_A
fin_for_A:	b .


		//SUBRUTINA
dime_si_primo:
				PUSH {r5,r7,r8,LR}	//prologo
for:			mov r5, #0
				cmp r5, r2
 				bge fin_for_primos
				ldr r8 [r1,r5,lsl#2]		// R8 = valor de B[i]

 				PUSH {R0, R1}
 								//r0 = primer parametro valor de A[i] (VIENE DEFINIDO)
 				mov r1, r8		//r1 = segundo parametro es el valor de B[i]
 				bl Es_multiplo
 				MOV r7, R0		//resultadod de la subruina Es_multiplo a r7
 				POP {R0, R1}

 				add r5, r5, #1
 				b for
 fin_for_primos:
 				mov r7, r0 		//resultado final de la subrrutina a r0
				POP {r5,r7,r8,LR}	//epílogo
 				mov pc,rl



				.end



/*-----------------------------------------------------------------
**
**  Fichero:
**    rutinas_asm.asm
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**
**
**  Notas de diseño:
**
**---------------------------------------------------------------*/

.global Es_multiplo		//puedo ser utilizado por alguien

.text

Es_multiplo:
			push {r4}
			mov r4, #1	//registro temporal donde se indica si primo
						//se considera primo por defecto
while:		cmp r0, #0
			ble fin_while
			sub r0, r0, r1
			b while
fin_while:	cmp r0, #0
			bne fin
			mov r4, #0
fin:		mov r0, r4
			pop {r4}
			mov pc, lr
.end
*/