/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 8.4                                      */
/*  Fecha:     21/04/2022                                  */
/***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Base de datos de empleados con la posibilidad de dar de alta, de baja y de ver los empleados
segun su departamento*/
typedef struct
{
    char calle[50];
    char colonia[50];
    char ciudad[50];
    char cp[50];
    char telefono[50];
} direccion;

typedef struct
{
    int numero;
    char nombre[50];
    char departamento[50];
    direccion domicilio;
    float sueldo;
} EMPLEADO;

EMPLEADO emple[100];
int n;

void alta(EMPLEADO RTS[]);
void baja(EMPLEADO RTS[]);
void lista(EMPLEADO RTS[]);

void main(void)
{
    int opcion;
    printf("Ingrese la cantidad de empleados: ");
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    // Datos de los empleados ya existentes
    {
        printf("\nEmpleado %d\n", i + 1);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(emple[i].nombre);
        printf("Ingrese el numero de empleado: ");
        scanf("%d", &emple[i].numero);
        printf("Ingrese el departamento: ");
        fflush(stdin);
        gets(emple[i].departamento);
        printf("Ingrese la calle y el numero: ");
        fflush(stdin);
        gets(emple[i].domicilio.calle);
        printf("Ingrese la colonia: ");
        fflush(stdin);
        gets(emple[i].domicilio.colonia);
        printf("Ingrese la ciudad: ");
        fflush(stdin);
        gets(emple[i].domicilio.ciudad);
        printf("Ingrese el codigo postal: ");
        fflush(stdin);
        gets(emple[i].domicilio.cp);
        printf("Ingrese el telefono: ");
        fflush(stdin);
        gets(emple[i].domicilio.telefono);
        printf("Ingrese el sueldo: ");
        scanf("%f", &emple[i].sueldo);
    }
    while (1)
    //Menu de opciones
    {
        printf("\n\n1. Alta\n2. Baja\n3. Listado segun el departamento\n4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            alta(emple);
            break;
        case 2:
            baja(emple);
            break;
        case 3:
            lista(emple);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    }
}

void alta(EMPLEADO RTS[])
//Funcion que agrega un empleado
{
    printf("\nDatos del nuevo empleado: ");
    printf("\nIngrese el nombre: ");
    fflush(stdin);
    gets(RTS[n].nombre);
    printf("Ingrese el numero de empleado: ");
    scanf("%d", &RTS[n].numero);
    printf("Ingrese el departamento: ");
    fflush(stdin);
    gets(RTS[n].departamento);
    printf("Ingrese la calle y el numero: ");
    fflush(stdin);
    gets(RTS[n].domicilio.calle);
    printf("Ingrese la colonia: ");
    fflush(stdin);
    gets(RTS[n].domicilio.colonia);
    printf("Ingrese la ciudad: ");
    fflush(stdin);
    gets(RTS[n].domicilio.ciudad);
    printf("Ingrese el codigo postal: ");
    fflush(stdin);
    gets(RTS[n].domicilio.cp);
    printf("Ingrese el telefono: ");
    fflush(stdin);
    gets(RTS[n].domicilio.telefono);
    printf("Ingrese el sueldo: ");
    scanf("%f", &RTS[n].sueldo);
    n++;
}

void baja(EMPLEADO RTS[])
//Funcion que elimina un empleado
{
    int num, control = 0;
    printf("\nIngrese el numero de empleado: ");
    scanf("%d", &num);
    for (size_t i = 0; i < n; i++)
    {
        if (RTS[i].numero == num)
        {
            for (size_t j = i; j < n - 1; j++)
            {
                RTS[j] = RTS[j + 1];
            }
            n--;
            printf("\nEmpleado eliminado\n");
            break;
            control = 1;
        }
    }
    if (control == 0)
    {
        printf("\nNo se encontro el empleado\n");
    }
}

void lista(EMPLEADO RTS[])
// listado por departamentos
{
    int i, control = 0;
    char departamento[50];
    printf("\nIngrese el departamento: ");
    fflush(stdin);
    gets(departamento);
    for (i = 0; i < n; i++)
    {
        if (strcmp(departamento, RTS[i].departamento) == 0)
        {
            printf("\nEmpleado %d\n", i + 1);
            printf("Nombre: %s\n", RTS[i].nombre);
            printf("Numero de empleado: %d\n", RTS[i].numero);
            printf("Sueldo: %.2f\n", RTS[i].sueldo);
            control = 1;
        }
    }
    if (control == 0)
    {
        printf("\nNo hay empleados en el departamento\n");
    }
}