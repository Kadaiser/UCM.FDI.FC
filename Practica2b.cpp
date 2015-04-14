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

.EQU 	N, 8

.data
A: 		.word 7,3,25,4,75,2,1,1

.bss
B: 		.space N*4
max: 	.space 4
ind: 	.space 4

.text
start:
		MOV R0, #0		//CONTADOR "j" INICIALIZADO A 0
		LDR R2, =A		//CABECERA ARRAY A
		LDR R3, =B		//CABECERA ARRAY B
		LDR R4, =max	//DIRECCION DE MAX EN MEMORIA
		LDR R5, =ind	//DIRECCION DE
		STR R0, [R4]	//INSERCION DE VALOR 0 EN DIRECCION DE MAX

bucleB:	CMP R0, #N 		//BUCLE DE RECORRIDO DE  B
		BGE fin
		MOV R1, #0		//CONTADOR "i" INICIALIZADO A 0

bucleA:	CMP R1, #N 				//BUCLE DE RECORRIDO DE A
		BGE finA
		LDR R6, [R4] 			//R6 ALMACENA VALOR MAX COMO VARIABLE AUXILIAR
		LDR R7,[R2,R1,LSL#2]	//R7= A(i)
		CMP R7,R6				//COMPARACION DE ELEMENTO DEL ARRAY CONTRA VALOR MAXIMO
		BGE ifMayor				//SALTAR SI ELEMENTO DEL ARRAY ES MAYOR QUE VALOR MAXIMO
		ADD R1,R1,#1
		B bucleA
ifMayor:STR R7,[R4]		//ALMACENAR EN MEMORIA EL NUEVO VALOR MAX
		STR R1,[R5]		//ALMACENAR EN MEMORIA EL INDICE DE NUEVO VALOR MAX
		ADD R1, R1,#1
		B bucleA

finA:	STR R6,[R4]				//ALMACENAR EN MEMORIA EL VALOR MAXIMO ENCONTRADO EN EL ARRAY
		STR R6,[R3,R0,LSL#2]	//INSERTAR EN ARRAY B EL ELEMENTO
		MOV R6, #0 				//ACTUALIZAR EL VALOR MAXIMO A 0
		LDR R1,[R5]				//TRAER VALOR DEL INDICE DEL ELEMENTO MAXIMO DEL ARRAY A
		STR R6,[R2,R1,LSL#2]	//SUSTITUIR EL ELEMENTO DEL ARRAY A CON UN 0  --FALLO--
		STR R6,[R4]				//ALMACENAR EN MEMORIA COMO MAXIMO EL VALOR 0 EN EL AUXILAR DE COMPARACIONES (PARA LAS SIGUIENTES ITERACIONES)
		ADD R0,R0,#1
		B bucleB

fin:	B .
		.end