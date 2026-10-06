Algoritmo Promedio_Jornada
	Definir SF, x, N, M, L, U, i, j, fila, racha, rachaMayor, inicio, eventos Como Entero
	Dimensionar Jornada(30,30), columnaEvendo(30), filasEvento(30), listaracha(30), listainicio(30), impacto(30)
	Leer N, M, L, U
	Para i<-1 Hasta N Con Paso 1 Hacer
		Para j<-1 Hasta M Con Paso 1 Hacer
			Leer Jornada[i,j]
			Si Jornada[i,j]<0 O Jornada[i,j]>1000 Entonces
				Escribir 'ERROR'
			FinSi
		FinPara
	FinPara
	Escribir 'Error'
	Escribir ' '
	Para i<-1 Hasta N Con Paso 1 Hacer
		Para i<-1 Hasta N Con Paso 1 Hacer
			Si listaracha[i]>listaracha[filaPrioritaria] Entonces
				filaPrioritaria <- i
			FinSi
			Si listaracha[i]==listaracha[filaPrioritaria] Entonces
				Si impacto[i]>impacto[filaPrioritaria] Entonces
					filaPrioritaria <- i
				FinSi
				Si impacto[i]==impacto[filaPrioritaria] Entonces
					Si filasEvento[i]>filasEvento[filaPrioritaria] Entonces
						filaPrioritaria <- i
					FinSi
				FinSi
			FinSi
		FinPara
		Escribir 'PRIORIDAD', filaPrioritaria+1
		Escribir 'COLUMNA', inicio
	FinPara
FinAlgoritmo
