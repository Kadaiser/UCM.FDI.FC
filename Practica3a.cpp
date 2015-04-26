/*-----------------------------------------------------------------
Codificar en ensamblador del ARM la siguiente función de C.    Esta función
busca el valor máximo de un vector A de enteros positivos de longitud longA y
devuelve la posición de ese máximo

	int A[N]={7,3,25,4,75,2,1,1};
	int LongA=8;

	int PosMax(int A[], int LongA){
	int max=0;
	int posmax=0;
	for(i=0; i<longA; i++){
		if(A[i]>max){
		max=A[i];
		posmax=i;
		}
	}
return(posmax);
}
---------------------------------------------------------------*/

	.global start

.EQU			N,8
		.data
A:		.word	7,3,25,4,75,2,1,1
LongA:	.word	8

		.text

start:
		MOV R0, #0
		MOV R1, #0
		LDR R2, =A
		LDR R3, =LongA

		.end

