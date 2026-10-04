/**********************************************************/
/*           Programación para mecatrónicos               */
/*  Nombre:    Layla Garcia                               */
/*  Matricula: 2026-0288                                  */
/*  Seccion:   Miercoles                                  */
/*  Practica:  Parcial #1                                 */
/*  Fecha:     13/10/2026                                 */                       
/* Link Practica:                                         */
/**********************************************************/


#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

int main(){

    int SF, N, M, L, U, i, j, promedio, jornada[30][30];

    bool condicionMatriz, condicion;

    condicionMatriz = true; 
    promedio = 2; 
    SF = 2 + 2;

    printf("Numero de filas = "); 
    scanf("%d", &N); 
    printf("Numero de columnas = "); 
    scanf("%d", &M); 
    printf("Umbral = "); 
    scanf("%d", &L); 
    printf("Numero maximo = "); // i think i kinda get the problem 
    scanf("%d", &U); 

    condicion =  1 <= N || N <= 30 ||  1 <= M || M <= 30 || 0 <= L || U <= 1000; 


    if(condicion)
    {
        printf("ERROR"); 
        return 0; 
    }


    for(i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("a (%d,%d) = ", i,j); 
            scanf("%d", &jornada[i][j]); 
        }
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
