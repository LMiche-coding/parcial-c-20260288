/**********************************************************/
/*           Programación para mecatrónicos               */
/*  Nombre:    Layla Garcia                               */
/*  Matricula: 2026-0288                                  */
/*  Seccion:   Miercoles                                  */
/*  Practica:  Parcial #1                                 */
/*  Fecha:     13/10/2026                                 */                       
/* Link Practica: https://github.com/LMiche-coding/parcial-c-20260288 */
/**********************************************************/
/*****************************************************************************//*!
   *
   * @brief funcion principal. 
   *        
   * @param[in] recive ninguno 
   *
   * @return devuelve un entero que puede ser utilizado como indicador de error
   *
   * @Pass/ Fail criteria:  none.
*****************************************************************************/


#include <stdio.h> // libreria que permite trabajar con entradas y salidas 
#include <conio.h> // libreria que permite trabajar con periferico
#include <stdbool.h> // libreria que permite trabajar con variables booleanas

int main(){

    int SF, N, M, L, U, i, j, fila, racha, rachaMayor, inicio, eventos;  
    /*
    SF = suma de las filas 
    N = filas
    M = columna
    L = que tanto puede estar debajo del promedio
    U = el numero maximo que debe de tener para ser un evento
    */

    int jornada[30][30]; // La matriz que se va a analizar
    int columnaEvento[30] = {0}; // eventos por columna
    int filasEvento[30] = {0}; // eventos por fila
    int listaracha[30] = {0}; // racha por columna
    int listainicio[30] = {0}; // la columna con la mejor racha 
    int impacto[30] = {0}; // el impacto por fila

    bool condicion; // variable booleana 

    eventos = 0; 

    scanf("%d", &N);  //Función estándar de la librería I/O de C que lee los datos introducidos
    scanf("%d", &M); 
    scanf("%d", &L); 
    scanf("%d", &U); 

    condicion =  N < 1 || N > 30 || // restriccion especifica del reto
                 M < 1 || M > 30 ||
                 L < 0 || U > 1000 || 
                 L > U; 

    if(condicion)
    {
        printf("ERROR"); 
        getch(); return 0; 
    }

    for(i = 0; i < N; i++) // toma los datos de la matriz y valida que cumple con las restricciones
    {

        for (j = 0; j < M; j++)
        { 
            scanf("%d", &jornada[i][j]); 

            if (jornada[i][j] < 0 || jornada [i][j] > 1000)
            {
                printf("ERROR"); 
                return 0; 
            }
      
        }
    }

    printf("\n"); 

    for(i = 0; i < N; i++) // verifica si hay un evento
    {
        SF = 0;
        racha = 0; 
        rachaMayor = 0;
        inicio = 0; 

        
        for(j = 0; j < M; j++)
        {
            SF = SF + jornada[i][j]; 
        } // fin de for

        for (j = 0; j < M; j++)
        {
            
            int x = jornada[i][j]; // es la posicion en la matriz

            if (SF-M*x >= M*L && x <= U) 
            {
                filasEvento[i] = filasEvento[i] + 1; // calcula los eventos por fila 
                impacto[i] = impacto[i] + SF - M * x + 1; // calcula el impacto
                columnaEvento[j] = columnaEvento[j] + 1; // calcula los eventos por la columna
                racha = racha + 1; 
                eventos = eventos + 1; 

                if (racha > rachaMayor)
                {
                    rachaMayor = racha; 
                    inicio = j - racha + 2; 
                }
                

            } else {
                racha = 0; 
            } // fin de if y else


        } // fin de for

        listaracha[i] = rachaMayor; 
        listainicio[i] = inicio; 

    } // fin de for 

    for (i = 0; i < N; i++) // reporte 1.ra parte
    {
        fila = i + 1; 
        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d \n" ,fila, filasEvento[i], impacto[i], listaracha[i], listainicio[i]); 
    }
    printf("COLUMNA"); 
    for (j = 0; j < M; j++) // reporte 2.da parte
    {
        printf(" %d", columnaEvento[j]);
    }

        int filaPrioritaria = 0; 

    if (eventos == 0) // Comprueba primero si hay eventos, sino comprueba la fila con prioridad en el informe 
    {
        printf("\nCOLUMNA 0 \nPRIORIDAD 0"); 
        return 0; 

    } else {
            for (i = 0; i < N; i++)
            {
                if(listaracha[i] > listaracha[filaPrioritaria])
                {
                    filaPrioritaria = i; 
                } else if (listaracha[i] == listaracha[filaPrioritaria]){
                    if (impacto[i] > impacto[filaPrioritaria]) 
                    {
                        filaPrioritaria = i; 
                    } else if (impacto[i] == impacto[filaPrioritaria]) {
                        if (filasEvento[i] > filasEvento[filaPrioritaria])
                        {
                            filaPrioritaria = i; 
                    } }
            }
    }


        printf("\nPRIORIDAD %d\n", filaPrioritaria + 1); 
        printf("COLUMNA %d\n", inicio); 

        getch(); return 0; 
    }

    /*printf("Salida \n"); 
    for (i=0; i<N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d, ", jornada[i][j]); 
        }

        printf("\n"); 
    }*/

}
