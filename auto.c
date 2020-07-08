#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"


void inicializarAutos(eAuto vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

//---------------------------------------------------------------------------------------------------

int buscarLibre(eAuto vec[], int tam)
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

int altaAuto(int idx, eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC)
{
    int todoOk = 0;
    int indice = buscarLibre(vec, tam);
    eAuto auxAuto;

    system("cls");

    printf("***** Alta Auto *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxAuto.id = idx;

        printf("Ingrese patente (mayusculas): ");
        fflush(stdin);
        scanf("%s", auxAuto.patente);

        printf("\n");
        mostrarMarcas(marca, tamM);
        utn_getEntero(&auxAuto.idMarca, 2, "Ingrese Id Marca (1000-1005): ", "Error. vuelva a intentarlo: \n", 1000, 1005);

        printf("\n");
        mostrarColores(color, tamC);
        utn_getEntero(&auxAuto.idColor, 2, "Ingrese Id Color (5000-5004): ", "Error, vuelva a intentarlo: \n", 5000, 5004);

        utn_getEntero(&auxAuto.modelo, 2, "Ingrese modelo (1890-2020): ", "Error, vuelve a intentarlo: \n", 1890, 2020);


        auxAuto.isEmpty = 0;

        vec[indice] = auxAuto;

        todoOk = 1;

        printf("\n*Alta excitosa*\n\n");

    }

    return todoOk;
}

//---------------------------------------------------------------------------------------------------

void mostrarAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    char descripcionM[20];
    char descripcionC[20];
    char nombreCliente[20];
	cargarDescripcionMarca(descripcionM, x.idMarca, marcas, tamM);
	cargarDescripcionColor(descripcionC, x.idColor, colores, tamC);
	cargarNombreCliente(nombreCliente, x.idCliente, clientes, tamCl);

    printf("  %d    %s     %d       %10s      %d       %10s      %d      %s\n", x.id, x.patente, x.idMarca, descripcionM, x.idColor, descripcionC, x.modelo, nombreCliente);
}

//---------------------------------------------------------------------------------------------------

void mostrarAutos(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int flag = 0;
    system("cls");
    printf("***** Listado de Autos *****\n");
    printf("  Id      Patente    ID Marca      Marca       ID Color       Color       Modelo     Cliente\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarAuto(vec[i], marcas, tamM, colores, tamC, clientes, tamCl);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay autos que listar ***\n");
    }
}

//---------------------------------------------------------------------------------------------------

void ordenarAutosPorMarcaYPatente(eAuto autos[], int tam, eMarca marcas[], int tamM)
{
    eAuto aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(autos[i].idMarca > autos[j].idMarca)
            {
                aux = autos[i];
                autos[i] = autos[j];
                autos[j] = aux;
            }
            else if(autos[i].idMarca == autos[j].idMarca && strcmp(autos[i].patente, autos[j].patente) > 0)
            {
                aux = autos[i];
                autos[i] = autos[j];
                autos[j] = aux;
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------

int buscarAuto(char patente[], eAuto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if((strcmp(vec[i].patente, patente)) == 0 && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

void modificarAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    char patente[20];
    int indice;
    char seguir = 's';
    char confirma;
    int nuevoColor;
    int nuevoModelo;

    system("cls");
    printf("***** Modificar Auto *****\n\n");

    mostrarAutos(vec, tam, marcas, tamM, colores, tamC, clientes, tamCl);

    printf("Ingrese patente (Mayusculas): ");
    scanf("%s", patente);

    indice = buscarAuto(patente, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un auto con la patente: %s\n", patente);
    }
    else
    {
        printf("\n  Id      Patente     ID Marca    Marca    ID Color   Color   Modelo  \n\n");
        mostrarAuto(vec[indice], marcas, tamM, colores, tamC, clientes, tamCl);

//SUBMENU QUE PERMITE MODIFICAR COLOR Y MARCA---------------------------------------------------
    do{
        switch(menuModificar())
        {
        case 1:
            printf("\nModifica Color? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                printf("\n");
                mostrarColores(colores, tamC);
                utn_getEntero(&nuevoColor, 2, "Ingrese Id del nuevo Color (5000-5004): ", "Error, vuelva a intentarlo: \n", 5000, 5004);

                vec[indice].idColor = nuevoColor;
                printf("\n **Se ha actualizado el color con exito** \n\n");
            }
            else
            {
                printf("\n *Se ha cancelado la operacion* \n\n");
            }
            break;
        case 2:
            printf("\nModifica Modelo? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                utn_getEntero(&nuevoModelo, 2, "Ingrese nuevo modelo (1890-2020): ", "Error, vuelve a intentarlo: \n", 1890, 2020);

                vec[indice].modelo = nuevoModelo;
                printf("\n **Se ha actualizado el modelo con exito** \n\n");
            }
            else
            {
                printf("\n *Se ha cancelado la operacion* \n\n");
            }
            break;
        case 3:
            printf("Confirme salida (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            system("pause");
        }

    }while(seguir == 's');
    }
}

//---------------------------------------------------------------------------------------------------

int menuModificar()
{
    int opcion;

    printf("***** Modificar Color/Modelo *****\n\n");
    printf("1. Modificar Color\n");
    printf("2. Modificar Modelo\n");
    printf("3. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void mostrarMarca(eMarca x)
{
    printf("  %d       %10s \n", x.id, x.descripcion);
}

//---------------------------------------------------------------------------------------------------

void mostrarMarcas(eMarca vec[], int tam)
{
    printf("***** Listado de Marcas *****\n");
    printf(" ID Marca     Descripcion \n\n");
    for(int i=0; i<tam; i++)
    {
        mostrarMarca(vec[i]);
    }
}

//---------------------------------------------------------------------------------------------------

int buscarMarca(eMarca vec[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

void mostrarColores(eColor vec[], int tam)
{
    printf("***** Listado de Colores *****\n");
    printf(" ID Color    Descripcion \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d       %10s  \n", vec[i].id, vec[i].nombreColor);
    }
}

//---------------------------------------------------------------------------------------------------

void bajaAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    char patente[20];
    int indice;
    char confirma;

    system("cls");
    printf("***** Baja Auto *****\n\n");

    printf("Ingrese patente: ");
    scanf("%s", patente);

    indice = buscarAuto(patente, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un auto con la patente: %d\n", patente);
    }
    else
    {
        mostrarAuto(vec[indice], marcas, tamM, colores, tamC, clientes, tamCl);

        printf("\nConfirma baja? (s/n): ");
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

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}

//---------------------------------------------------------------------------------------------------

int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(colores[i].id == id)
        {
            strcpy(descripcion, colores[i].nombreColor);
            todoOk = 1;
        }
    }
    return todoOk;
}

//---------------------------------------------------------------------------------------------------

int cargarNombreCliente(char nombre[], int id, eCliente clientes[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(clientes[i].id == id)
        {
            strcpy(nombre, clientes[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}

//---------------------------------------------------------------------------------------------------

