10)

tipo instruccion	nº instrucciones	nºciclos/instruccion
		A					70					4
		B					35					5
		C					20					3
		D					15					70
							[140]
							
a)	CPI= (70*4 + 35*5 + 20*3 + 15*70) / 140 = 4.4285 c/i
	
b) T. ejecucion = nº instrucines * CPI * T. ciclo = 140 instrucciones *4.42 ciclo/seg * (1/2*10^9)seg/ciclo = 350 nanoseg (tipico de los gigahercios)



11)

				frec			T.ciclo				MIPS
PowerPC			1,8 GHz		->	055		ns				700		(1 seg - 700 millones de instrucciones)
PowerPC			1,6 GHz		->	0.625	ns				850		(1 seg - 800 millones de instrucciones)


MIPS = frecuencia/CPI * 10^6 	->			CPI (PC)= frec(PC)/MIPS (PC) *10^6 = 1.8  10^9 /(700 * 10^6)	(usa menos ciclos por instruccion)
											CPI (P4)= frec(P4)/MIPS (P4) *10^6 = 1.66 * 10^9/(850 * 10^6)	(menos ciclos por instruccion)
											
cual es mas rapido?

una instruccion tarda 2.57 cliclos de media en (PC) -> 2.57 ciclos*0.55 ns/ciclos= 1.41 ns
una instruccion tarda 1.88 cliclos de media en (P4) -> 1.88*0.62= 1.16 ns (es mas rapido en ejecutar una intruccion)


9)

load 22%   - 5 ciclos
store 11%	- 4 ciclos
arit	49%	- 4 ciclos
salto 18%(50% salta, 50% no salta) - 4 ciclos y 3 ciclos


b)				T.ejecucion = Nº inst * CPI ^ T.ciclo= 1000 instrucciones * 4.13 * T.Ciclo
 
				CPI= 0.22*5+0.11*4+0.49*4+0.18*.5*4+0.18*05*3 = 4.13
				
a)
				- fecth:																		ALU=10ns	MUX=2ns	LeerMen=10ns leeBR= 5ns
						IR<-MEm(PC)		(1mux+lect.mem)= 12 ns
						PC<-PC+4		(1mux + alu)= 20 ns
				
				- dec:
						leeBR			(leeBR)= 5ns
				- Ex
						AluOUT <-A+B	(1mx + alu)= 12 ns
						AluOUT <-A+extension de sigo)	(Texsigno + mux+ alu)= 13ns
						
				- Men
				
				- WB
				