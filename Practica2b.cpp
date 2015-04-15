/*-----------------------------------------------------------------
**
**  Fichero:
**    pract2b.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Ordena de mayor a menor un vector de enteros positivos
**
**  Notas de diseño:


#define N 8

int A[N]={7,3,25,4,75,2,1,1};
int B[N];
int max, ind;

for(j=0; j<N; j++){
	max=0;
		for(i=0; i<N; i++){
			if(A[i]>max){
				max=A[i];
				ind=i;
		}
	}
	B[j]=A[ind];
	A[ind]=0;
}
**
**---------------------------------------------------------------*/

.global start

.EQU 	N, 6

.data
A: 		.word 5,0,7,1,5,-4

.bss
B: 		.space N*4
nMin: 	.space 4
ind: 	.space 4

.text
start:
		MOV R0, #0		//CONTADOR "j" INICIALIZADO A 0
		LDR R2, =A		//CABECERA ARRAY A
		LDR R3, =B		//CABECERA ARRAY B
		LDR R5, =ind	//DIRECCION DEL INDICE
		LDR R4, =nMin	//DIRECCION DEL NUMERO DE MINIMOS

bucleB:	CMP R0, #N 		//BUCLE DE RECORRIDO DE  B
		BGE fin
		MOV R1, #0		//REINICIAR CONTADOR "i" A 0
		LDR R6,[R2,R1,LSL#2]	//R6= A(0)  LO EL PRIMER ELEMENTO DEL ARRAY

		MOV R8, #0		//REINICIAR EL NUMERO DE NEGATIVOS ENCONTRADOS (SOLO ME LLEVARE LA ULTIMA ITERACION)

bucleA:	CMP R1, #N 				//BUCLE DE RECORRIDO DE A
		BGE finA
		LDR R7,[R2,R1,LSL#2]	//R7= A(i)

		CMP R7, #0			//COMPARAMOS EL ELEMENTO CONTRA 0
		BLT pos				//SALTO SI EL NUMERO ES POSITIVO, SALTO
		ADD R8,R8,#1		//INCREMETAMOS LA CANIDAD DE NEGATIVS ENCONTRADOS



pos:	CMP R7,R6				//COMPARACION DE ELEMENTO DEL ARRAY CONTRA VALOR MAXIMO
		BLT ifMenor				//SALTAR SI ELEMENTO DEL ARRAY ES MENOR QUE VALOR MAXIMO

		MOV R6,R7				//ALMACENAR  EL NUEVO VALOR MAX
		STR R1,[R5]				//ALMACENAR EN MEMORIA EL INDICE DEL NUEVO VALOR MAX
ifMenor:ADD R1, R1,#1
		B bucleA

finA:	STR R6,[R3,R0,LSL#2]	//INSERTAR EN ARRAY B EL ELEMENTO
		MOV R6, #0 				//ACTUALIZAR EL VALOR MAXIMO A 0
		LDR R1,[R5]				//TRAER VALOR DEL INDICE DEL ELEMENTO MAXIMO DEL ARRAY A
		STR R6,[R2,R1,LSL#2]	//SUSTITUIR EL ELEMENTO DEL ARRAY A CON UN 0
		ADD R0,R0,#1
		B bucleB

fin:	RSB R8,R8,#N
		STR R8,[R4]				//LEVAR A MEMORIA EL NUMERO DE NEGATIVOS CONTADOS EN LA ULTIMA ITERACION
		B .
		.end
