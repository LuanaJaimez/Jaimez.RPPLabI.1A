#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"



void mostrarServicio(eServicio x)
{
    printf("  %d        %10s      %d  \n", x.id, x.descripcion, x.precio);
}

//---------------------------------------------------------------------------------------------------

void mostrarServicios(eServicio vec[], int tam)
{
    int flag = 0;
    printf("***** Listado de Servicios *****\n");
    printf(" ID Servicio   Descripcion   Precio  \n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id != 0)
        {
            mostrarServicio(vec[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay servicios que listar ***\n");
    }
}

//---------------------------------------------------------------------------------------------------

int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}

//---------------------------------------------------------------------------------------------------
