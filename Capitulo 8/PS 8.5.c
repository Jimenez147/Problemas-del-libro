/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 8.5                                      */
/*  Fecha:     18/04/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Permite ingresar una cantidad especifica de productos y operar con ellos*/
typedef struct {
    int clave;
    char nombre[30];
    int existencia;
} producto;

int N;
producto tienda[100];
void operacion(char opcion, int clave, int cantidad);

void main(void)
{
    char OPE;
    int CLA, CAN;
    printf("Ingrese la cantidad de productos: ");
    scanf("%d", &N);
    printf("\n");
    for (int i = 0; i < N; i++)
    // Lee los datos de los productos
    {
        printf("Ingrese la clave del producto %d: ", i + 1);
        scanf("%d", &tienda[i].clave);
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fflush(stdin);
        gets(tienda[i].nombre);
        printf("Ingrese la existencia del producto %d: ", i + 1);
        scanf("%d", &tienda[i].existencia);
        printf("\n");
    }
    while (1)
    // Menu de operaciones
    {
        printf("Ingrese la operacion a realizar 'C' compra, 'V' venta y 'X' para salir: ");
        fflush(stdin);
        scanf("%c", &OPE);
        if (OPE == 'X')
            break;
        printf("Ingrese la clave del producto: ");
        scanf("%d", &CLA);
        printf("Ingrese la cantidad a operar: ");
        scanf("%d", &CAN);
        operacion(OPE, CLA, CAN);
    }
}

void operacion(char opcion, int clave, int cantidad)
//Realiza la operacion de compra o venta del producto deseado
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (tienda[i].clave == clave)
        {
            if (opcion == 'V')
            {
                if (tienda[i].existencia >= cantidad)
                {
                    tienda[i].existencia -= cantidad;
                    printf("Venta realizada con exito\n");
                    break;
                }
                else
                    printf("No hay suficiente existencia\n");
                    break;
            }
            else if (opcion == 'C')
            {
                tienda[i].existencia += cantidad;
                printf("Compra realizada con exito\n");
                break;
            }
            else
                printf("Operacion invalida\n");
                break;
        }
    }
    if (i == N)
        printf("No existe el producto\n");
}