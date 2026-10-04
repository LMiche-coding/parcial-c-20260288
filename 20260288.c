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

    int SF, N, M, L, U, i, j, jornada[30][30];
    bool condicionMatriz, condicion;
 
    SF = 2 + 2;

    printf("Numero de filas = "); 
    scanf("%d", &N); 
    printf("Numero de columnas = "); 
    scanf("%d", &M); 
    printf("Umbral = "); 
    scanf("%d", &L); 
    printf("Numero maximo = "); // i think i kinda get the problem 
    scanf("%d", &U); 

    condicion =  N < 1 || N > 30 || M < 1 || M > 30 || L < 0 || U > 1000; 
    // condicionMatriz = jornada[i][j] < 0 || jornada [i][j] > 1000; 


    if(condicion)
    {
        printf("ERROR"); 
        return 0; 
    }


    for(i = 0; i < N; i++) // toma los datos de la matriz y valida que cumple con las restricciones
    {
        SF = 0;

        for (j = 0; j < M; j++)
        { 
            printf("a (%d,%d) = ", i,j); 
            scanf("%d", &jornada[i][j]); 

            if (jornada[i][j] < 0 || jornada [i][j] > 1000)
            {
                printf("ERROR"); 
                return 0; 
            }

            
            SF = SF + jornada[i][j]; 
            printf("%d\n", SF); 
              
        }
    }

    for(i = 0; i < N; i++) // verifica si hay un evento
    {
        for (j = 0; j < M; j++)
        {
            int x = jornada[i][j]; // es la posicion en la matriz

            if (SF-M*x >= M*L && x <= U) 
            {
                printf("Hay evento mis amoreeeeeeeeeeeeeeees \n");
            }
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
