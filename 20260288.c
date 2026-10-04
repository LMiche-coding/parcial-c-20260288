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

int main(){
    int SF, N, M, L, U, i, j, prom; 
    int jorn[30][30]; 


    printf("Numero de filas = "); 
    scanf("%d", &N); 
    printf("Numero de columnas = "); 
    scanf("%d", &M); 
    printf("Umbral = "); 
    scanf("%d", &L); 
    printf("Numero maximo = "); // i think i kinda get the problem 
    scanf("%d", &U); 

    for(i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("a (%d,%d) = ", i,j); 
            scanf("%d", &jorn[i][j]); 
        }
    }

    printf("Salida \n"); 
    for (i=0; i<N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d, ", jorn[i][j]); 
        }

        printf("\n"); 
    }


}
