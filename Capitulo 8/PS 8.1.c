/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 8.1                                      */
/*  Fecha:     18/04/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Es una base de datos que contiene la informacion de una sierta cantidad de clientes de un banco
y tiene la opcion de hacer depositos, retiros y consultar la informacion de los clientes*/

typedef struct hola
{
    char Calle_Numero[50];
    char colonia[50];
    char ciudad[50];
    char telefono[50];
    char codigo_postal[50];
} domicilio;

typedef struct
{
    long numero_de_cuenta;
    char nombre[50];
    domicilio direccion;
    float saldo;
} cliente;

cliente CLI[100];
int N;
void deposito(cliente VEC[]);
void retiro(cliente VEC[]);
void consulta(cliente VEC[]);

void main(void)
{
    int opcion;
    printf("Ingrese el numero de clientes: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    // Lectura de los clientes
    {
        printf("\n\nCliente %d\n", i + 1);
        printf("Ingrese el numero de cuenta: ");
        scanf("%ld", &CLI[i].numero_de_cuenta);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(CLI[i].nombre);
        printf("Ingrese la calle y numero: ");
        fflush(stdin);
        gets(CLI[i].direccion.Calle_Numero);
        printf("Ingrese la colonia: ");
        fflush(stdin);
        gets(CLI[i].direccion.colonia);
        printf("Ingrese la ciudad: ");
        fflush(stdin);
        gets(CLI[i].direccion.ciudad);
        printf("Ingrese el telefono: ");
        scanf("%s", CLI[i].direccion.telefono);
        printf("Ingrese el codigo postal: ");
        scanf("%s", CLI[i].direccion.codigo_postal);
        printf("Ingrese el saldo: ");
        scanf("%f", &CLI[i].saldo);
    }
    while (opcion != 0)
    // Menu de opciones
    {
        printf("\nQue desea hacer?\n0. Salir\n1. Deposito\n2. Retiro\n3. Consulta\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            deposito(CLI);
            break;
        case 2:
            retiro(CLI);
            break;
        case 3:
            consulta(CLI);
            break;
        }
    }
}

void deposito(cliente VEC[])
{
    long cuenta;
    float deposito;
    int x = 0;
    printf("\nIngrese el numero de cuenta: ");
    scanf("%ld", &cuenta);
    for (int i = 0; i < N; i++)
    {
        if (cuenta == VEC[i].numero_de_cuenta)
        // Busca la cuenta seleccionada para realizar el deposito
        {
            printf("\nIngrese el deposito: ");
            scanf("%f", &deposito);
            VEC[i].saldo += deposito;
            x = 1;
        }
    }
    if (x == 0)
    {
        printf("\nNumero de cuenta no encontrado\n");
    }
}

void retiro(cliente VEC[])
{
    long cuenta;
    float retiro;
    int x = 0;
    printf("\nIngrese el numero de cuenta: ");
    scanf("%ld", &cuenta);
    for (int i = 0; i < N; i++)
    {
        if (cuenta == VEC[i].numero_de_cuenta)
        // Busca la cuenta seleccionada para realizar el retiro
        {
            printf("\nIngrese el retiro: ");
            scanf("%f", &retiro);
            if (VEC[i].saldo -= retiro > 0)
            {
                VEC[i].saldo -= retiro;
            }
            else
            {
                printf("\nNo tiene saldo suficiente\n");
            }
            x = 1;
        }
    }
    if (x == 0)
    {
        printf("\nNumero de cuenta no encontrado\n");
    }
}

void consulta(cliente VEC[])
{
    long cuenta;
    int x = 0;
    printf("\nIngrese el numero de cuenta: ");
    scanf("%ld", &cuenta);
    for (int i = 0; i < N; i++)
    {
        if (cuenta == VEC[i].numero_de_cuenta)
        // Busca la cuenta seleccionada para realizar la consulta
        {
            printf("\nNombre: %s\n", VEC[i].nombre);
            printf("Direccion: %s\n", VEC[i].direccion.Calle_Numero);
            printf("Colonia: %s\n", VEC[i].direccion.colonia);
            printf("Ciudad: %s\n", VEC[i].direccion.ciudad);
            printf("Telefono: %s\n", VEC[i].direccion.telefono);
            printf("Codigo postal: %s\n", VEC[i].direccion.codigo_postal);
            printf("Saldo: %.2f\n", VEC[i].saldo);
            x = 1;
        }
    }
    if (x == 0)
    {
        printf("\nNumero de cuenta no encontrado\n");
    }
}