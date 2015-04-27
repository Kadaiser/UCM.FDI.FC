	.GLOBAL START
	.DATA

X:	.WORD	0x03
Y:  .WORD	-7

	.BSS
Z:	.SPACE 4

	.TEXT
	
START:
	LDR R1, =X
	LDR R0,[R1]
	BL ABS
	MOV R4,R0		//Resultado de la subrutina
	LDR R1, =Y
	LDR R0,[R1]
	BL ABS
	ADD R3,R4,R0	 //Resultado de la suma del absoluto de cada valor en R3
	LDR R1, =Z
	STR R3,[R1]
	B .
	//SUBRUTINA ABSOLUTO
ABS:
	PUSH[]
	
	//SUBRUTINA OPUESTO
	SRB R0,#0
	.END