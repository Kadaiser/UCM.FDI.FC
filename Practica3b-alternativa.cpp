/**
Codificar en ensamblador del ARM un programa que dado un vector A de N
enteros mayores de 0, obtenga un vector B con los valores de A ordenados de
mayor a menor. Para ello usar la función definida en el apartado anterior y
seguir  un algoritmo de ordenación basado en el siguiente código de alto nivel:

#define N 8

int A[N]={7,3,25,4,75,2,1,1};
int B[N];

void main(){

Int posmax;

	for(j=0; j<N; j++){

		posmax= PosMax(A,N)
		B[j]=A[posmax];
		A[posmax]=0;
	}
}
--------------------------------------------------------------------------------------------------------------------------------*/

		.global start
		.EQU	N,8

		.data
A:		.word 7,3,25,4,75,2,1,1

		.bss
B:		.space 4*N
		.text

start:
		LDR SP, =_stack

		LDR R0, =A			//DIRECCION DE CABECERA DEL VECTOR A
		LDR R1, =B			//DIRECCION DE CABECERA DEL VECTOR B
		MOV R2, #N
		BL ordenar
		B .


		//SUBRUTINA ORDENAR - PARAMETROS: R0, =A | R1 =B | R2 = N
ordenar:
		PUSH {R4,R5, LR}
		MOV R5, #0					//CONTADOR DE BUCLE FOR
for:
		CMP R5, R2					// CONTADOR < N
		BGE finbucle

		PUSH {R0, R1}
		MOV R1, R2					//ASIGNACION DE PARAMETROS (SE MANTIENE R0 POR DECLARACION ANTERIOR), R1 ASIGNA N
		BL posmax					//LLAMADA DE LA SUBRUTINA PARA CALCULAR LA POSICION DEL ELEMENTO MAYOR EN EL VECTOR A
		MOV R3, R0					//ALMACENAR RESULTADO DE SUBRRUTINA EN REGISTRO AUXILIAR
		POP {R0, R1}

		LDR R4, [R0, R3, LSL#2]		//GUARDAMOS EN R4 EL VALOR DE LA POSICION MAXIMA DEL VECTOR A
		STR R4, [R1, R5, LSL#2]		//ESCRIBIMOS EN MEMORIA EL VALOR EN LA SIGUIENTE POSICION DISPONIBLE DEL VECTOR B (LA 1ª POSICION PARA LA 1ª VUELTA)
		MOV	R4, #0					//ALMACENAMOS UN 0 EN R4
		STR R4, [R0, R3, LSL#2]		//ESCRIBIMOS UN 0 EN LA POSICION DEL MAXIMO ENCONTRADO, PARA DESCARTARLO EN SUCESIVAS BUSQUEDAS

		ADD R5,R5, #1				//INCREMENTAMOS EL CONTADOR
		B for						//REGRESAMOS AL BUCLE
finbucle:
		POP {R4,R5, LR}
		MOV PC, LR					//REGRESAMOS A LA RUTINA PRINCIPAL


		//SUBRUTINA POSMAX - PARAMETROS R0 =A | R1 = N
posmax:
		PUSH {R4,R5}		//PROLOGO
		MOV R5, #0			//INICIALIZO CONTADOR
		MOV R2, #0			//AUXILIAR DEL MAXIMO
for2:
		CMP R5, R1
		BGE finbucle2
		LDR R3, [R0, R5, LSL#2]		//ALMACENAMOS EN R3 EL VALOR DEL VECTOR
		CMP R3, R2
		BGT esmayor					//SI EL VALOR DEL VECTOR ES MAYOR QUE EL ACTUAL MAYOR, ACTUALIZO EL VALOR
		ADD R1, R1, #1
		B for2

esmayor:
		MOV R2, R3			//ACTUALIZO EL VALOR DEL MAXIMO
		MOV R4, R5			//ACTUALIZO LA POSICION DEL MAXIMO
		ADD R5, R5, #1

finbucle2:
		MOV R0, R4
		POP {R4,R5}			//EPILOGO
		MOV PC, LR

		.end
