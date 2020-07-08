#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "auto.h"
#include "utn.h"


int menuEmpleados()
{
    int opcion;

    system("cls");
    printf("***** Empleados *****\n\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Mostrar empleados\n");
    printf("5. Mostrar empleados asignados a un auto\n"); //muestra los empleados con los autos
    printf("6. Mostrar sector que mas cobra\n");
    printf("7. Mostrar empleados mayores de edad (+18)\n");
    printf("8. Mostrar mayor sueldo de un sector\n");
    printf("9. Mostrar los empleados que cobran mas de 10000 pesos\n");
    printf("10. Mostrar empleados separados por sector\n");
    printf("11. Mostrar los empleados ordenados por edad\n");
    printf("12. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void empleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec, eAuto autos[], int tamAu, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    char seguir = 's';
    char confirma;

    int proximoIdEmp = 2000;

    do{
        switch(menuEmpleados())
        {
        case 1:
            altaEmpleado(proximoIdEmp, vec, tam, sectores, tamSec);
            break;
        case 2:
            modificarEmpleado(vec, tam, sectores, tamSec);
            break;
        case 3:
            bajaEmpleado(vec, tam, sectores, tamSec);
            break;
        case 4:
            mostrarEmpleados(vec, tam, sectores, tamSec);
            break;
        case 5:
            mostrarEmpleadosAuto(autos, tamAu, marcas, tamM, colores, tamC, vec, tam);
            break;
        case 6:
            sectorQueMasCobra(vec, tam, sectores, tamSec);
            break;
        case 7:
            empleadosMayoresEdad(vec, tam, sectores, tamSec);
            break;
        case 8:
            informarMayorSueldoSector(vec, tam, sectores, tamSec);
            break;
        case 9:
            empleadosSueldoAlto(vec, tam, sectores, tamSec);
            break;
        case 10:
            informarEmpleadoXSector(vec, tam, sectores, tamSec);
            break;
        case 11:
            ordenarEmpleadosEdad(vec, tam, sectores, tamSec);
            break;
        case 12:
            printf("Confirme salida (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }

        system("pause");

    }while(seguir == 's');

}

//---------------------------------------------------------------------------------------------------

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

//---------------------------------------------------------------------------------------------------

int buscarLibreEmp(eEmpleado vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamSec)
{
    char nombreSector[20];
    cargarDescripcionSector(nombreSector, x.idSector, sectores, tamSec);

    printf("%d  %10s    %10s   %d   %6.2f      %10s\n", x.id, x.nombre, x.apellido, x.edad, x.sueldo, nombreSector);
}

//---------------------------------------------------------------------------------------------------

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int flag = 0;

    system("cls");
    printf("***** Listado de Empleados *****\n");
    printf("  Id      Nombre   Apellido    Edad    Suelo     Sector\n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay empleados que listar ***\n");
    }
}

//---------------------------------------------------------------------------------------------------

int buscarEmpleado(int id, eEmpleado vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

int altaEmpleado(int idx, eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int indice = buscarLibreEmp(vec, tam);
    //int id;
    //int existe;
    eEmpleado auxEmpleado;

    system("cls");

    printf("***** Alta empleado *****\n\n");

    if(indice == -1) //hay lugar?
    {
        printf("Sistema completo\n\n");
    }
    else
    {
            auxEmpleado.id = idx;

            utn_getCadena(auxEmpleado.nombre, 20, 2, "Ingrese nombre: ", "\nError. Reingrese nombre\n");

            utn_getCadena(auxEmpleado.apellido, 51, 2, "Ingrese apellido: ", "\nError. Reingrese apellido\n");

            utn_getEntero(&auxEmpleado.edad, 2, "Ingrese edad: ", "\nError. Reingrese edad\n", 16, 90);

            utn_getFlotante(&auxEmpleado.sueldo, 2, "Ingrese sueldo (1000-100000): ", "\nError. Reingrese sueldo\n", 1000, 100000);

            mostrarSectores(sectores, tamSec);
            utn_getEntero(&auxEmpleado.idSector, 2, "Ingrese Id del sector: ", "\nError. Reingrese sector (solo numeros)\n", 1, 1000);


            auxEmpleado.isEmpty = 0;


            vec[indice] = auxEmpleado; //copio al vector el empleado nuevo
            todoOk = 1;

    }//else exterior

    return todoOk;

}//fin de la funcion

//---------------------------------------------------------------------------------------------------

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("***** Baja empleado *****\n\n");

    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un empleado con el Id: %d\n", id);
    }
    else
    {
        mostrarEmpleado(vec[indice], sectores, tamSec);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

}

//---------------------------------------------------------------------------------------------------

void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int id;
    int indice;
    char confirm;
    char seguir = 's';
    float nuevoSueldo;
    char nuevoNombre[20];
    char nuevoApellido[20];
    int nuevaEdad;
    int nuevoSector;

    system("cls");
    printf("***** Modificar empleado *****\n\n");

    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un empleado con el Id: %d\n", id);
    }
    else
    {
        mostrarEmpleado(vec[indice], sectores, tamSec);

//SUBMENU QUE PERMITA MODIFICAR CUALQUIERA DE LOS CAMPOS---------------------------------------------------
    do{
        switch(menuModificar())
        {
        case 1:
            printf("\nModifica Nombre?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                utn_getCadena(nuevoNombre, 20, 2, "Ingrese nuevo nombre: ", "\nError. Reingrese nombre\n");

                strcpy(vec[indice].nombre, nuevoNombre);
                printf("Se ha actualizado el nombre con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 2:
            printf("\nModifica Apellido?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                utn_getCadena(nuevoApellido, 51, 2, "Ingrese nuevo apellido: ", "\nError. Reingrese apellido\n");

                strcpy(vec[indice].apellido, nuevoApellido);
                printf("Se ha actualizado el apellido con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 3:
            printf("\nModifica Edad?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                utn_getEntero(&nuevaEdad, 2, "Ingrese edad: ", "\nError. Reingrese edad\n", 16, 90);

                vec[indice].edad = nuevaEdad;
                printf("Se ha actualizado la edad con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 4:
            printf("\nModifica Sueldo?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                utn_getFlotante(&nuevoSueldo, 2, "Ingrese nuevo sueldo (1000-100000): ", "\nError. Reingrese sueldo\n", 1000, 100000);

                vec[indice].sueldo = nuevoSueldo;
                printf("Se ha actualizado el sueldo con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 5:
            printf("\nModifica Sector?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                mostrarSectores(sectores, tamSec);
                utn_getEntero(&nuevoSector, 2, "Ingrese Id del nuevo sector: ", "\nError. Reingrese sector (solo numeros)\n", 20000, 20003);

                vec[indice].idSector = nuevoSector;
                printf("Se ha actualizado el sector con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 6:
            printf("Confirme salida: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                seguir = 'n';
            }
                system("pause");
        }

    }while(seguir == 's');

    }

}

//---------------------------------------------------------------------------------------------------

int menuModificarEmp()
{
    int opcion;

    printf("***** Modificar Empleados *****\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Apellido\n");
    printf("3. Modificar Edad\n");
    printf("4. Modificar Sueldo\n");
    printf("5. Modificar Sector\n");
    printf("6. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void mostrarSectores(eSector sectores[], int tam)
{
    system("cls");
    printf("***** Sectores *****\n");
    printf("  Id     Descripcion  \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d   %10s\n", sectores[i].id, sectores[i].descripcion);
    }
}

int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion, sectores[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}


int cargarNombreEmp(char nombre[], int id, eEmpleado vec[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(nombre, vec[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}


void mostrarEmpleadoAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC, eEmpleado vec[], int tam)
{
    char descripcionM[20];
    char descripcionC[20];
    char nombreEmpleados[20];
	cargarDescripcionMarca(descripcionM, x.idMarca, marcas, tamM);
	cargarDescripcionColor(descripcionC, x.idColor, colores, tamC);
	cargarNombreEmp(nombreEmpleados, x.idCliente, vec, tam);

    printf("  %d    %s     %d       %10s      %d       %10s      %d      %s\n", x.id, x.patente, x.idMarca, descripcionM, x.idColor, descripcionC, x.modelo, nombreEmpleados);
}


void mostrarEmpleadosAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eEmpleado empleado[], int tamEmp)
{
    int flag = 0;

    system("cls");
    printf("***** Listado de Autos y Empleados *****\n");
    printf("  Id      Patente    ID Marca      Marca       ID Color       Color       Modelo     Nombre Empleado\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleadoAuto(vec[i], marcas, tamM, colores, tamC, empleado, tamEmp);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay autos que listar ***\n");
    }
}



float obtenerTotalSueldosSector(eEmpleado empleados[], int tam, int idSector)
{
    float totalSueldos = 0;

        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0 && empleados[i].idSector == idSector)
            {
                totalSueldos += empleados[i].sueldo;
            }
        }

    return totalSueldos;
}

//---------------------------------------------------------------------------------------------------

void sectorQueMasCobra(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    float totalSueldos[tamsec];
    int mayorTotal;
    int flag = 0;

    system("cls");
    printf(" *****Sector que mas cobra*****\n\n");

    for(int i=0; i<tam; i++)
    {
        totalSueldos[i] = obtenerTotalSueldosSector(empleados, tam, sectores[i].id);
    }

    for(int i=0; i<tam; i++)
    {
        if(totalSueldos[i] > mayorTotal || flag == 0)
        {
            mayorTotal = totalSueldos[i];
            flag = 1;
        }
    }

    printf("El total de sueldos mayor es $%.2f y pertenece al sector: \n\n", mayorTotal);

    for(int i=0; i<tamsec; i++)
    {
        if(totalSueldos[i] == mayorTotal)
        {
            printf("%s\n", sectores[i].descripcion);
        }
    }
}



void empleadosMayoresEdad(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int flag = 0;

    system("cls");
    printf("***** Empleados Mayores de Edad *****\n");
    printf("  Id      Nombre   Apellido    Edad    Suelo     Sector\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].edad >= 18)
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay empleados mayores que listar ***\n\n");
    }
}



void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int idSector;
    int flag = 0;
    float mayorSueldo = 0;
    char nombreSector[20];

    system("cls");
    printf("***** Mayor sueldo sector *****\n\n");

    mostrarSectores(sectores, tamsec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idSector == idSector)
        {
            if(vec[i].sueldo > mayorSueldo || flag == 0)
            {
                mayorSueldo = vec[i].sueldo;
                flag = 1;
            }
        }
    }

    cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);
    printf("El mayor sueldo del sector %s es $%.2f\n\n", nombreSector, mayorSueldo);

}




void empleadosSueldoAlto(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int flag = 0;

    system("cls");
    printf("***** Empleados que cobran mas de 10000 pesos *****\n");
    printf("  Id      Nombre   Apellido    Edad    Suelo     Sector\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].sueldo > 10000)
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay empleados que cobren mas de 10000 pesos que listar ***\n\n");
    }
}




void informarEmpleadoXSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int flag;

    system("cls");
    printf("***** Empleados por sector *****\n\n");

    //recorro los sectores
    for(int i=0; i<tamsec; i++)
    {
        flag = 0;
        printf("Sector: %s\n", sectores[i].descripcion);
        printf(" ---------\n\n");


        for(int j=0; j<tam; j++)
        {
            if(vec[j].isEmpty == 0 && vec[j].idSector == sectores[i].id)
            {
                mostrarEmpleado(vec[j], sectores, tamsec);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay empleados en este sector\n");
        }
        printf("\n--------------------------------------------------------------\n");
    }

}




void ordenarEmpleadosEdad(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    eEmpleado auxEmpleado;

    system("cls");
    printf("***** Ordenar empleados por edad *****\n\n");

    for(int i=0; i<tam; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].edad > vec[j].edad)
            {
                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
            }
        }
    }

    mostrarEmpleados(vec, tam, sectores, tamSec);
}
