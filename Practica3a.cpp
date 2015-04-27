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
LongA:	.word 	0X08
		.bss
posmax:	.space 4

		.text

start:
		LDR SP, = _stack 		//inicia el registro SP con el valor de la direccion dela pila (0x0C7FF000)

		LDR R0, =A				//DIRECCION DE LA CABECERA DEL VECTOR
		LDR R1, =LongA			//DIRECCION DEL ENTERO LONGITUD DEL VECTOR
		PUSH {R0,R1}			//ALMACENO EN PILA LOS VALORES DE LOS REGISTROS (DESPRECIABLE)
		BL POSMAX				//INICIO LA SUBRUTINA
		LDR R2, =posmax			//DIRECCION DE LA POSICION DEL VECTOR CON EL ELEMETO MAS GRANDE
		STR R0,[R2]				//ALMACENO EL RESULTADO DE LA SUBRUTINA
		POP {R0,R1}				//RESTAURO LA POSICION DE LOS REGISTROS (DESPRECIABLE)
		B .

		//SUBRUTINA POSMAX
		//R0= (=A)
		//R1= (=LongA)
POSMAX:
		MOV R2,#0				//INICIALIZAR CONTADOR DEL BUCLE
		LDR R3,[R1]				//CARGAR EL VALOR DE LongA
		MOV R4,#0				//INICIALIZAR VALOR MAXIMO DEL VECTOR
		MOV R5,#0				//AUXILIAR QUE ALMACENA EL MAXIMO ACTUAL

for:
		CMP R2,R3
		BGE fin
		LDR R4, [R0, R2, LSL#2]	//R4 =A(i) CON i=R2
		CMP R4, R5
		BGT esmayor				//SI LA DIFERENCIA DA MAYOR, SALTAMOS
		ADD R2,R2,#1			//INCREMENTAMOS CONTADOR
		B for					//REGRASAMOS AL BUCLE
esmayor:
		MOV R5,R4				//ACTUALZIO EL VALOR MAXIMO
		MOV R6, R2				//ACTUALIZO EL VALOR DEL INDICE DEL MAXIMO ACTUAL
		ADD R2,R2,#1
		B for

fin:
		MOV R0, R6				//DEVOLVEMOS EL VALOR DE LA POSICION DEL ELEMENTO MAS GRANDE DEL VECTOR A R0
		MOV PC, LR

		.end
