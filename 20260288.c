/**********************************************************/
/*           Programación para mecatrónicos               */
/*  Nombre:    Layla Garcia                               */
/*  Matricula: 2026-0288                                  */
/*  Seccion:   Miercoles                                  */
/*  Practica:  Parcial #1                                 */
/*  Fecha:     13/10/2026                                 */                       
/* Link Practica: https://github.com/LMiche-coding/parcial-c-20260288 */
/**********************************************************/
/*
*
*
*
*
*
*
*
*/


#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

int main(){

    int SF, N, M, L, U, i, j;  
    int jornada[30][30]; // La matriz que se va a analizar
    int EventosColumna[30] = {0}; 
    int impacto[30] = {0}; 

    bool condicion;

 

    printf("Numero de filas = "); 
    scanf("%d", &N); 
    printf("Numero de columnas = "); 
    scanf("%d", &M); 
    printf("Umbral = "); 
    scanf("%d", &L); 
    printf("Numero maximo = "); // i think i kinda get the problem 
    scanf("%d", &U); 

    condicion =  N < 1 || N > 30 ||
                 M < 1 || M > 30 ||
                 L < 0 || U > 1000; 


    if(condicion)
    {
        printf("ERROR"); 
        return 0; 
    }


    for(i = 0; i < N; i++) // toma los datos de la matriz y valida que cumple con las restricciones
    {

        for (j = 0; j < M; j++)
        { 
            printf("a (%d,%d) = ", i,j); 
            scanf("%d", &jornada[i][j]); 

            if (jornada[i][j] < 0 || jornada [i][j] > 1000)
            {
                printf("ERROR"); 
                return 0; 
            }
      
        }
    }

    for(i = 0; i < N; i++) // verifica si hay un evento
    {
        SF = 0;

        for(j = 0; j < M; j++)
        {
            SF = SF + jornada[i][j]; 
        } // fin de for

        for (j = 0; j < M; j++)
        {
            
            int x = jornada[i][j]; // es la posicion en la matriz

            if (SF-M*x >= M*L && x <= U) 
            {
                impacto[i] = impacto[i] + SF - M * x + 1; 
            } //fin de if


        } // fin de for

        printf("%d\n", SF);

    } // fin de for 


    for (i = 0; i < N; i++)
    {
        printf("IMPACTO %d\n", impacto[i]); 
    }

    printf("Salida \n"); 
    for (i=0; i<N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d, ", jornada[i][j]); 
        }

        printf("\n"); 
    }


}
