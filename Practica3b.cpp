/**
Codificar en ensamblador del ARM un programa que dado un vector A de N
enteros mayores de 0, obtenga un vector B con los valores de A ordenados de
mayor a menor. Para ello usar la función definida en el apartado anterior y
seguir  un algoritmo de ordenación basado en el siguiente código de alto nivel:

#define N 8

int A[N]={7,3,25,4,75,2,1,1};
int B[N];

void main(){
	int valor;
	for(j=0, j<N,j++){
		Valor = DatoValido(A,N);
		if(valor != 0)	B[j]= valor;
	}
}

int DatoValido(int A[], int N){
	int maxValido = 0;
	int posmx = 0;
	
	posmax = PosMax(A[],N);
	if(A[posmax] > 3)	maxValido = A[posmax];
	else maxValido = 0;
	A[posmax]=0;
return (maxValido);
}



--------------------------------------------------------------------------------------------------------------------------------*/

		.global start
		.EQU	N,8

		.data
A:		.word 2,3,25,0,75,2,1,1

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
		BL DatoValido
		MOV R3, R0				//GUARDAMOS EL RESULTADO DE LA SUBRRUTINA EN UNA VARIABLE AUXILIAR
		POP {R0, R1, R2}		//RECUPERAR CONTENIDO DE LOS REGISTROS
		LDR  R4,=B				//DIRECCION DEL VECTOR B
		STR R3, [R4, R0, LSL#2]	//INCLUYO EL VALOR VALIDADO EN EL SEGUNDO VECTOR
		ADD R0,R0,#1			//INCREMENTO EL CONTADOR
		B for

fin:
		B .


		//SUBRUTINA DatoValido PARAMETROS: R0 = A[] | R1 = N
DatoValido:
		PUSH {R4,R5,LR}		//PROLOGO SUBRUTINA CON ANIDAMIENTO

		PUSH {R0,R1}
		BL PosMax			//NO NECESITAMOS DECLARAR PARAMETROS YA QUE R0 Y R1 POSSEN LOS DATOS CORRESPONDIENTES
		MOV R2, R0			//R2 SE CARGA CON EL RESULTADO DE LA SUBRUTINA
		POP {R0,R1}

		LDR R3, [R0,R2,LSL#2]
		CMP R3, #3
		BGT maxValido
		MOV R4,#0		//CARGO 0 EN AXILIAR R4
		B vaciarPos

maxValido:
		MOV R4, R3				//CARGO maxValido EN AXILIAR R4
vaciarPos:
		MOV R5, #0				//AUXILAR PARA COLOCAR 0 EN VECTOR A
		STR R5, [R0,R2,LSL#2]	//SUSTITULLO LA POSICION R2 DEL VECTOR A CON UN 0
		MOV R0, R4				//LA SUBRUTINA RETORNA EL VALOR maxValido
		POP {R4,R5,LR}			//EPILOGO DE SUBRUTINA CON ANIDAMIENTO
		MOV PC, LR



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
