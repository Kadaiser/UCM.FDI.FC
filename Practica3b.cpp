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

		MOV R0, #0			//INICIALIZAR CONTADOR
		LDR R1, =A			//DIRECCION DEL PRIMER ELEMENTO DEL VECTOR A
		MOV R2, #N			//VARIABLE DE LA LONGITUD DEL VECTOR
for:
		CMP R0, R2			//DE 0 HASTA N
		BGE fin

		PUSH {R0, R1, R2}		//GUARDAMOS CONTENIDO DE REGSTROS
		MOV R0, R1				//PRIMER PARAMETRO A[]
		MOV R1, R2				//SEGUNDO PARAMETRO N
		BL PosMax
		MOV R3, R0				//GUARDAMOS EL RESULTADO DE LA SUBRRUTINA EN UNA VARIABLE AUXILIAR
		POP {R0, R1, R2}		//RECUPERAR CONTENIDO DE LOS REGISTROS

		LDR R4, [R1, R3, LSL#2]	//ALMACENO EN R5 EL VALOR MAXIMO DEL VECTOR A
		LDR R5, =B				//DIRECCION DEL PRIMER ELEMENTO DEL VECTOR B
		STR R4, [R5, R0, LSL#2]	//RELLENO LA POSICION DEL VETOR B CON EL SIGUIENTE ELEMENTO MAXIMO
		MOV R4, #0				//ALMACENO EL VALOR 0
		STR R4, [R1, R3, LSL#2]	//SUSTITULLO EL ELEMENTO CON UN 0 PARA DESCARTARLO EN EL VECTOR A PARA SUCESIVAS BUSQUEDAS

		ADD R0, R0, #1			//INCREMENTO DEL CONADOR
		B for

fin:
		B .


		//SUBRUTINA PosMax	PARAMETROS: R0 = A[] | R1 = N
PosMax:
		PUSH {R4,R5}				//ALMACENAJE DEL CONTENIDO DE LOS REGISTROS ADICIONALES
		MOV R2, #0				//INICIALIZAR CONTADOR
		LDR R3, [R0, R2, LSL#2]	//LECTURA DEL PRIMER ELEMENTO DEL VECTOR Y ALMACENAMIENTO EN AUXLIAR (MAXIMO)
		MOV R5, #0				//INICIALIZAR RESULTADO (PODRIA DARSE EL CASO DE UN VECTOR NULO)

for2:	CMP R2, R1
		BGE fin2
		LDR R4, [R0, R2, LSL#2]	//CARGAMOS EL ELEMEMENTO DEL VECTOR CORRESPONDIENTE A ESA VUELTA
		CMP R4, R3
		BGT esMayor
		ADD R2,R2,#1			//INCREMENTO DEL CONTADOR
		B for2

esMayor:
		MOV R3, R4				//ACTUALIZAMOS EL VALOR MAXIMO
		MOV R5, R2				//ACTUALIZAMOS POSICION
		ADD R2,R2,#1			//INCREMENTO DEL CONTADOR
		B for2
fin2:
		MOV R0, R5				//ALMACENAJE DEL RESULTADO DE LA SUBRUTINA EN R0
		POP {R4,R5}				//RESTAURACION DEL CONTENIDO DE LOS REGISTROS ADICIONALES
		MOV PC, LR

		.end
