Algoritmo Promedio_Jornada
	Definir SF, x, N, M, L, U, i, j, fila, racha, rachaMayor, inicio, eventos Como Entero
	Dimensionar Jornada(30,30)
	Dimensionar columnaEvendo(30)
	Dimensionar filasEvento(30)
	Dimensionar listaracha(30)
	Dimensionar listainicio(30)
	Dimensionar impacto(30)
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
			racha <- 0
			rachaMayor <- 0
			inicio <- 0
			Para j<-1 Hasta M Con Paso 1 Hacer
				SF <- SF+Jornada[i,j]
			FinPara
			Para j<-1 Hasta M Con Paso 1 Hacer
				x <- Jornada[i,j]
				Si SF-M*x>=M*L Y x<=U Entonces
					filasEvento[i] <- filasEvento[i]+1
					impacto[i] <- impacto[i]+SF-M*x+1
					columnaEvendo[j] <- columnaEvendo[j]+1
					racha <- racha+1
					eventos <- eventos+1
					Si racha>rachaMayor Entonces
						rachaMayor <- racha
						inicio <- j-racha+2
					FinSi
				SiNo
					racha <- 0
				FinSi
			FinPara
			listaracha[i] <- rachaMayor
			listainicio[i] <- inicio
		FinPara
		Para i<-1 Hasta N Con Paso 1 Hacer
			fila <- i
			Escribir 'FILA ', fila, ' EVENTOS ', filasEvento[i], ' IMPACTO ', impacto[i], ' RACHA ', listaracha[i], ' INICIO ', listainicio[i]
		FinPara
		Escribir ' '
		Escribir 'COLUMNA'
		Para j<-1 Hasta M Con Paso 1 Hacer
			Escribir columnaEvendo[j]
		FinPara
		Definir filaPrioritaria Como Entero
		filaPrioritaria <- 1
		Si eventos==1 Entonces
			Escribir 'COLUMNA 0'
			Escribir 'PRIORIDAD 0'
		SiNo
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
		FinSi
	FinSi
FinAlgoritmo
