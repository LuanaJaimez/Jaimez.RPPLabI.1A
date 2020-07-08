#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "utn.h"


void inicializarTrabajos(eTrabajo vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

//---------------------------------------------------------------------------------------------------

int buscarLibreT(eTrabajo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

int altaTrabajo(int idx, eTrabajo vec[], int tam, eServicio lavados[], int tamSer, eAuto autos[], int tamAu, eMarca marca[], int tamM, eColor color[], int tamC, eCliente clientes[], int tamCl)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;
    int indiceT = buscarLibreT(vec, tam);
    char confirma;

    system("cls");

    printf("***** Alta Trabajo *****\n\n");

    if(indiceT == -1)
    {
        printf("Sistema Completo\n\n");
    }
    else
    {
        auxTrabajo.id = idx;

        mostrarAutos(autos, tamAu, marca, tamM, color, tamC, clientes, tamCl);

        printf("Ingrese patente (Mayusculas): ");
        fflush(stdin);
        scanf("%s", auxTrabajo.patente);

        indice = buscarAuto(auxTrabajo.patente, autos, tamAu);

        if(indice == -1)
        {
            printf("No hay registro de un auto con esa patente\n");
        }
        else
        {
            mostrarServicios(lavados, tamSer);
            printf("Ingrese ID servicio: ");
            fflush(stdin);
            scanf("%d", &auxTrabajo.idServicio);
            while(auxTrabajo.idServicio != 20000 && auxTrabajo.idServicio != 20001 && auxTrabajo.idServicio != 20002 && auxTrabajo.idServicio != 20003)
            {
                printf("Error. vuelva a intentarlo: \n");
                fflush(stdin);
                scanf("%d", &auxTrabajo.idServicio);
            }

            printf("Ingrese fecha actual dd/mm/aaaa\n");
            utn_getEntero(&auxTrabajo.fecha.dia,2,"Ingrese Dia: ","Error. Dia invalido.", 1, 31);
            utn_getEntero(&auxTrabajo.fecha.mes,2,"Ingrese Mes: ","Error. Mes invalido", 1, 12);
            utn_getEntero(&auxTrabajo.fecha.anio,2,"Ingrese Anio (2018-2020): ","Error. Anio invalido.", 2018, 2020);

            printf("\nConfirma trabajo? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                auxTrabajo.isEmpty = 0;

                vec[indiceT] = auxTrabajo;
                todoOk = 1;

                printf("\n*Alta excitosa*\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
        }
    }

    return todoOk;
}

//---------------------------------------------------------------------------------------------------

void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamS)
{
    char descripcionS[20];
    cargarDescripcionServicio(descripcionS, x.idServicio, servicios, tamS);
    printf("  %d     %s      %d        %10s    %d/%d/%d   \n", x.id, x.patente, x.idServicio, descripcionS, x.fecha.dia, x.fecha.mes, x.fecha.anio);
}

//---------------------------------------------------------------------------------------------------

void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS)
{
    int flag = 0;
    system("cls");
    printf("***** Listado de Trabajos *****\n");
    printf("  Id      Patente     ID Servicio    Servicio    Fecha  \n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
		{
			mostrarTrabajo(vec[i], servicios, tamS);
			flag = 1;
		}
    }
    if(flag == 0)
    {
        printf("***No hay trabajos que listar***\n");
    }
}

//---------------------------------------------------------------------------------------------------
