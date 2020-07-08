#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"


int menuInformes()
{
    int opcion;

    system("cls");
    printf("***** Informes autos *****\n\n");
    printf("1. Mostrar autos de un color seleccionado\n");
    printf("2. Mostrar autos de una marca seleccionado\n");
    printf("3. Mostrar auto mas viejo\n");
    printf("4. Mostrar autos por marca\n");
    printf("5. Mostrar autos por marca y color seleccionados\n");
    printf("6. Mostrar la o las marcas mas elegidas por los clientes\n");
    printf("7. Mostrar todos los trabajos que se le hicieron a un auto seleccionado\n");
    printf("8. Mostrar la suma de los importes de los trabajos que se le hicieron a un auto seleccionado\n");
    printf("9. Mostrar los autos a los que se realizo un servicio seleccionado y la fecha del mismo\n");
    printf("10. Mostrar todos los servicios realizados en una fecha seleccionada\n");
    printf("11. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void informar(eAuto autos[], int tam, eCliente clientes[], int tamCl, eColor colores[], int tamC, eMarca marcas[], int tamM, eMarcaME marcaElegida[], eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer)
{
    char seguir = 's';
    char confirma;

    do{
        switch(menuInformes())
        {
        case 1:
            informarAutosColor(autos, tam, colores, tamC, marcas, tamM, clientes, tamCl);
            break;
        case 2:
            informarAutosPorMarcaS(autos, tam, colores, tamC, marcas, tamM, clientes, tamCl);
            break;
        case 3:
            informarAutoMasViejo(autos, tam, colores, tamC, marcas, tamM, clientes, tamCl);
            break;
        case 4:
            informarAutosPorMarca(autos, tam, colores, tamC, marcas, tamM, clientes, tamCl);
            break;
        case 5:
            informarAutosPorColorYMarca(autos, tam, colores, tamC, marcas, tamM, clientes, tamCl);
            break;
        case 6:
            informarMarcaME(autos, tam, marcas, tamM, marcaElegida);
            break;
        case 7:
            informarTrabajosAuto(autos, tam, marcas, tamM, colores, tamC, clientes, tamCl, trabajos, tamT, servicios, tamSer);
            break;
        case 8:
            informarImporteAuto(autos, tam, marcas, tamM, colores, tamC, clientes, tamCl, trabajos, tamT, servicios, tamSer);
            break;
        case 9:
            informarAutoYFechaServicio(autos, tam, trabajos, tamT, servicios, tamSer);
            break;
        case 10:
            informarFechaServicio(trabajos, tamT, servicios, tamSer);
            break;
        case 11:
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

void informarAutosColor(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl)
{
    int flag;
    int auxColor;

    system("cls");
    printf("***** Autos por color especifico *****\n\n");

    mostrarColores(colores, tamC);
	utn_getEntero(&auxColor, 3, "\nIngrese el ID del color de los autos a listar: ", "Error, no es un color", 5000, 5004);

	printf("  Id      Patente    ID Marca      Marca       ID Color       Color       Modelo     Cliente\n\n");

	for(int i = 0 ; i < tam; i++)
	{
		if(autos[i].isEmpty == 0 && autos[i].idColor == auxColor)
		{
		    printf("\n");
			mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("\nNo hay autos con ese color\n\n");
	}

}

//---------------------------------------------------------------------------------------------------

void informarAutosPorMarcaS(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl)
{
	int flag = 0;
	int auxMarca;

	system("cls");
	printf("***** Autos por marca especifica *****\n\n");

	mostrarMarcas(marcas, tamM);
	utn_getEntero(&auxMarca, 3, "\nIngrese el ID de la marca del auto a listar: ", "Error, no es una marca", 1000, 1004);


	printf("  Id      Patente    ID Marca      Marca       ID Color       Color       Modelo     Cliente\n\n");

	for(int i = 0 ; i < tam; i++)
	{
		if(autos[i].isEmpty == 0 && autos[i].idMarca == auxMarca)
		{
		    printf("\n");
			mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("No existen autos con esa marca para listar.\n\n");
	}

}

//---------------------------------------------------------------------------------------------------

void informarAutoMasViejo(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl)
{
    eAuto mayorAuto;
    int flag = 0;

    system("cls");
    printf("***** Auto/s mas viejo *****\n\n");

    printf("  Id      Patente    ID Marca      Marca       ID Color       Color       Modelo     Cliente\n\n");

    for(int i=0; i<tam; i++)
    {
        if(autos[i].modelo < mayorAuto.modelo || flag == 0)
        {
            mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
            mayorAuto = autos[i];
            flag = 1;
        }
    }
}

//---------------------------------------------------------------------------------------------------

void informarAutosPorMarca(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl)
{
    int flag;

    system("cls");
    printf("***** Autos por marca *****\n\n");

    for(int i=0; i<tamM; i++)
    {
        flag = 0;
        printf("Marca: %s\n", marcas[i].descripcion);
        printf(" ---------\n\n");
        printf("  Id      Patente    ID Marca      Marca       ID Color       Color       Modelo     Cliente\n");


        for(int j=0; j<tam; j++)
        {
            if(autos[j].isEmpty == 0 && autos[j].idMarca == marcas[i].id)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay autos registrados con esta marca\n");
        }
        printf("\n--------------------------------------------------------------\n");
    }

}

//---------------------------------------------------------------------------------------------------

void informarAutosPorColorYMarca(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl)
{
	int flag = 0;
	int auxMarca;
	int auxColor;
    int contadorMarcaColor = 0;
    char confirma;

	system("cls");
	printf("***** Autos por marca especifica *****\n\n");

	mostrarMarcas(marcas, tamM);
	utn_getEntero(&auxMarca, 3, "Ingrese Id Marca (1000-1004): ", "Error, no es una marca: \n", 1000, 1004);
	mostrarColores(colores, tamC);
	utn_getEntero(&auxColor, 3, "Ingrese Id Color (5000-5004): ", "Error, no es un color: \n", 5000, 5004);


	for(int i = 0 ; i < tam; i++)
	{
		if(autos[i].isEmpty == 0 && autos[i].idMarca == auxMarca && autos[i].idColor == auxColor)
		{
			contadorMarcaColor++;
			flag = 1;
		}
	}
	if(flag == 1)
    {
        printf("La cantidad de autos de la marca y el color elegido es: %d\n\n", contadorMarcaColor);

        printf("Mostrar auto de la marca y el color seleccionado (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            printf("  Id      Patente    ID Marca      Marca       ID Color       Color       Modelo     Cliente\n\n");
            for(int i = 0 ; i < tam; i++)
            {
                if(autos[i].isEmpty == 0 && autos[i].idMarca == auxMarca && autos[i].idColor == auxColor)
                {
                    mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
                }
            }
        }
        else if(confirma == 'n')
        {
            printf("Se ha cancelado la operacion\n\n");
        }


    }
	else if(flag == 0)
	{
		printf("\nNo existen autos con esa marca y ese color para listar.\n\n");
	}

}

//---------------------------------------------------------------------------------------------------

void informarMarcaME(eAuto autos[], int tam, eMarca marcas[], int tamM, eMarcaME marcaElegida[])
{
    int marca = 0;
    int flag;
    int flagMax = 0;
    int indiceMarca;
    eMarcaME marcaMasElegida;

    system("cls");
    printf("***** Marca mas elegida *****\n\n");

    for(int i=0; i<tamM; i++)
    {
        flag = 0;
        for(int j=0; j<tam; j++)
        {
            if(!(autos[j].isEmpty) && autos[j].idMarca == marcas[i].id)
            {
                flag++;
            }
        }

        marcaElegida[marca].idMarca = marcas[i].id;
        marcaElegida[marca].cantidad = flag;
        marca++;
    }

    for(int i=0; i<tamM; i++)
    {
        if(!flagMax)
        {
            marcaMasElegida = marcaElegida[i];
            flagMax = 1;
        }
        else if(marcaElegida[i].cantidad > marcaMasElegida.cantidad && marcaElegida[i].idMarca > 0)
        {
            marcaMasElegida = marcaElegida[i];
        }
    }

    printf(" ID Marca     Descripcion \n\n");

    for(int i=0; i<tamM; i++)
    {
        if(marcaMasElegida.cantidad == marcaElegida[i].cantidad && marcaElegida[i].idMarca > 0)
        {
            indiceMarca = buscarMarca(marcas, tamM, marcaElegida[i].idMarca);
            mostrarMarca(marcas[indiceMarca]);
        }
    }

    printf("\n\n");
}

//---------------------------------------------------------------------------------------------------

void informarTrabajosAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer)
{
    char auxPatente[20];
    int indice;

    system("cls");
    printf("\n **** Trabajos hechos a un auto ****\n\n");

    mostrarAutos(autos, tam, marcas, tamM, colores, tamC, clientes, tamCl);
    printf("\n");

    //Se pide la patente
    printf("Ingrese patente (Mayusculas): ");
    scanf("%s", auxPatente);

    indice = buscarAuto(auxPatente, autos, tam);

    if(indice == -1)
    {
        printf("***No hay registro de un auto con la patente ingresada***\n");
    }
    else
    {
        printf("**** Trabajos hechos al auto ingresado ****\n");
        printf("ID   Patente   ID Servicio    Servicio    Fecha\n\n");

        for(int i=0; i<tamT; i++)
        {
            if(!(strcmp(trabajos[i].patente, auxPatente)))
            {
                mostrarTrabajo(trabajos[i], servicios, tamSer);
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------

void informarImporteAuto(eAuto autos[], int tam,  eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer)
{
    char auxPatente[20];
    int indice;
    float precioTotal = 0;

    system("cls");
    printf("**** Importe de los trabajos hechos a un auto ****\n\n");

    mostrarAutos(autos, tam, marcas, tamM, colores, tamC, clientes, tamCl);
    printf("\n");

    //Se pide la patente
    printf("Ingrese patente (Mayusculas): ");
    scanf("%s", auxPatente);

    indice = buscarAuto(auxPatente, autos, tam);

    if(indice == -1) // solo para comprobar si existe
    {
        printf("***No hay registro de un auto con la patente ingresada***\n");
    }
    else
    {
        for(int i=0; i<tamT; i ++)
        {
            for(int j=0; j<tamSer; j++)
            {
                if(trabajos[i].idServicio == servicios[j].id && !(strcmp(trabajos[i].patente, autos[indice].patente)))
                {
                    precioTotal = precioTotal + servicios[j].precio;
                }
            }
        }

        printf("El importe total de ese auto es: $%.2f\n", precioTotal);
    }

}

//---------------------------------------------------------------------------------------------------

void informarAutoYFechaServicio(eAuto autos[], int tam, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer)
{
    int auxIdServ;
    int flag = 0;

    system("cls");
    printf("**** Auto a lo que se le realizo un servicio ****\n\n");

    mostrarServicios(servicios, tamSer);
    printf("\n\n");

    printf("Ingrese ID servicio: ");
    fflush(stdin);
    scanf("%d", &auxIdServ);
    while(auxIdServ != 20000 && auxIdServ != 20001 && auxIdServ != 20002 && auxIdServ != 20003)
    {
        printf("Error. vuelva a intentarlo: ");
        fflush(stdin);
        scanf("%d", &auxIdServ);
        printf("\n");
    }

    printf("\n **** Auto/s y Fecha del servicio elegido ***\n");
    printf("  Id      Patente    ID Servicio      Servicio    Fecha\n\n ");

    for(int i=0; i<tamSer; i++)
    {
        for(int j=0; j<tamT; j++)
        {
            if(auxIdServ == servicios[i].id && trabajos[j].idServicio == auxIdServ)
            {
                mostrarTrabajo(trabajos[j], servicios, tamSer);
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf(" ***No hay registro de un auto con el servicio ingresado***\n");
    }

}

//---------------------------------------------------------------------------------------------------

void informarFechaServicio(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer)
{
    int auxDia;
    int auxMes;
    int auxAnio;
    int flag = 0;

    system("cls");
    printf("**** Servicios realizados en una fecha especifica ****\n\n");

    //mostrarTrabajos(trabajos, tamT, servicios, tamSer);

    printf("Ingrese fecha del servicio dd/mm/aaaa\n");
    utn_getEntero(&auxDia,2,"Ingrese Dia: ","Error. Dia invalido.", 1, 31);
    utn_getEntero(&auxMes,2,"Ingrese Mes: ","Error. Mes invalido", 1, 12);
    utn_getEntero(&auxAnio,2,"Ingrese Anio (2018-2020): ","Error. Anio invalido.", 2018, 2020);

    system("cls");

    printf(" \n**Los servicios realizados en la fecha %d/%d/%d son**\n", auxDia, auxMes, auxAnio);
    printf("  Id      Patente    ID Servicio      Servicio    Fecha\n");

    for(int i=0; i<tamT; i++)
    {
        if(auxDia == trabajos[i].fecha.dia && auxMes == trabajos[i].fecha.mes && auxAnio == trabajos[i].fecha.anio)
        {
            mostrarTrabajo(trabajos[i], servicios, tamSer);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf(" ***No hay registro de un trabajo realizado en la fecha ingresada***\n");
    }

}

//---------------------------------------------------------------------------------------------------
