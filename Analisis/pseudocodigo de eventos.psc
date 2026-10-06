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
	Si (N)<(1) O (N)>(30) O (M)<(1) O (M)>(30) O (L)<(0) O (U)>(1000) O (U)<(L) Entonces
		Escribir 'Error'
	SiNo
		Escribir ' '
		Para i<-1 Hasta N Con Paso 1 Hacer
			SF <- 0
			Para j<-1 Hasta M Con Paso 1 Hacer
				SF <- SF+Jornada[i,j]
			FinPara
			Para j<-1 Hasta M Con Paso 1 Hacer
				x <- Jornada[i,j]
				Si SF-M*x>=M*L Y x<=U Entonces
					filasEvento[i] <- filasEvento[i]+1
					impacto[i] <- impacto[i]+SF-M*x+1
					columnaEvendo[j] <- columnaEvendo[j]+1
				FinSi
			FinPara
		FinPara
	FinSi
FinAlgoritmo
