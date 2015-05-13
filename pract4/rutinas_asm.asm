/*-----------------------------------------------------------------
**
**  Fichero:
**    rutinas_asm.asm  10/6/2014
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
.global contarUnos

.extern ActVector(vector[], valor, pos)


.text
valor:	.word 0
pos: 	.word 0
//	PROCEDIMIENTO QUE RECIBE 4 PARAMETROS
//R0	DIRECCION DEL PRIMER ELEMENTO DE LA MATRIZ
//R1	DIRECCION DEL VECTOR (nª de filas de la matriz = longitud del vector | elementos obntenidos en posiciones del vector = nº de filas )
//R2	VALOR DEL NUMERO DE FILAS DE LA MATRIZ
//R3	VALOR DEL NUMERO DE COLUMNAS DE LA MATRIZ


contarUnos:
  		PUSH {R4,R5,R6,R7,R8,LR}	//prologo, subrutina hoja, 2 variabes locales "i" "j", no retorna resultado
 		MOV R4, #0				//inicializar "i"
 		MOV R6, #0				//INICIALIZAR "j"
 bucleI:
 		CMP R4, R2 				//for (i=0;i<nfilas;i++)
		BGE finbucleI
 		MOV R5, #0				//auxiliar de intercambio a 0 | auxiliar de nº de 1 en fila
 		STR	R5, [R1,R4,LSL#2] 	// vector[i]=0

 bucleJ:
 		CMP R6, R3
 		BGE finbucleJ			//for (j=0; j<ncols; j++)
		MUL R7, R4, R3			//R7 = i * ncolumnas
		ADD R7, R7, R6			//R7 = i * ncolumnas+ j  (posicion del elemento en la matriz tomada unidimensionalmente)
		LDR R8, [R0,R7,LSL#2]	//R8 = mat[i][j]

		push {R0, R1, R2, R3}

		MOV R0, R1				//PRIMER PARAMETRO DE LA FUNCION vector[]
		MOV R1, R8				//SEGUNDO PARAMETRO  DE LA FUNCION valor
		MOV R2, R4				//TERCER PARAMETRO DE LA FUNCION POS

		bl ActVector

		pop {R0, R1, R2, R3}

		ADD R6, R6, #1			//incrementar contador j
		B bucleJ

finbucleJ:
		MOV R6, #0 				//reinicar contador "j"
 		ADD R4, R4, #1			//icrementar contador "i"
 		B bucleI

finbucleI:
		POP {R4,R5,R6,R7,R8,LR}	//epílogo
  		bx lr

		.end


