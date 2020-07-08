#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "auto.h"
#include "trabajo.h"
#include "informes.h"
#include "empleado.h"
#define TAM 10
#define TAMT 8
#define TAMC 10
#define TAMSEC 4
#define TAMEMP 7

int menu();

int main()
{
    char seguir = 's';
    char confirma;

    int proximoIdAuto = 1000;
    int proximoIdTrabajo = 100;
    int flagAuto = 1;

    eMarca listaMarca[5] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    eColor listaColor[5] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eServicio listaServicios[4] =
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };

    eAuto listaAuto[TAM] =
    {
        {1000, "NVZ087", 1000, 5001, 1998, 0, 1000, 0},
        {1001, "SOS911", 1002, 5003, 2010, 0, 1001, 2005},
        {1002, "AVS573", 1004, 5004, 2008, 0, 1003, 2005},
        {1003, "MEF295", 1001, 5002, 2006, 0, 1002, 0},
        {1004, "GIF243", 1000, 5002, 2018, 0, 1004, 0},
        {1005, "NEU735", 1001, 5000, 2019, 0, 1005, 2000},
        {1006, "BDI358", 1003, 5001, 2012, 0, 1006, 0},
        {1007, "ISM929", 1004, 5002, 2005, 0, 1007, 0},
        {1008, "NUW936", 1002, 5001, 2000, 0, 1008, 2005},
        {1009, "DME334", 1001, 5004, 1995, 0, 1009, 2002}
    };

    eCliente listaCliente[TAMC] =
    {
        {1000, "Carla", 'f'},
        {1001, "Pedro", 'm'},
        {1002, "Lucia", 'f'},
        {1003, "Joaquin", 'm'},
        {1004, "Carlos", 'm'},
        {1005, "Carmen", 'f'},
        {1006, "Dardo", 'm'},
        {1007, "Lujan", 'f'},
        {1008, "Marcos", 'm'},
        {1009, "Matias", 'm'}
    };


    eTrabajo listaTrabajo[TAMT] =
    {
        {100, "SOS911", 20003, {12, 05, 2020}, 0},
        {101, "SOS911", 20002, {12, 05, 2020}, 0},
        {102, "NEU735", 20001, {15, 05, 2020}, 0},
        {103, "NUW936", 20003, {07, 05, 2020}, 0},
        {104, "GIF243", 20000, {10, 05, 2020}, 0},
        {105, "DME334", 20001, {11, 05, 2020}, 0},
        {106, "DME334", 20002, {11, 05, 2020}, 0},
        {107, "AVS573", 20003, {13, 05, 2020}, 0}
    };

    eMarcaME marcaMasElegida[5];

    eEmpleado listaEmpleados[TAMEMP] =
    {
        {2000, "Julia", "Sanchez", 17, 5200, 20001, 0},
        {2001, "Pablo", "Perez", 19, 6500, 20000, 0},
        {2002, "Lucrecia", "Atienza", 23, 10000, 20001, 0},
        {2003, "Juan", "Martinez", 18, 5000, 20000, 0},
        {2004, "Camilo", "Diaz", 17, 12000, 20002, 0},
        {2005, "Ana", "Pico", 25, 14500, 20003, 0},
        {2006, "Martin", "Paz", 37, 13000, 20002, 0}
    };

    eSector sectores[TAMSEC] =
    {
        {20000, "Lavado"},
        {20001, "Pulido"},
        {20002, "Encerado"},
        {20003, "Completo"}
    };

    //para el hardcodeo se comenta la inicializacion.
    //se debe sacar el comentario a la hora de dar de alta de un auto y/o de un trabajo.
    //inicializarAutos(listaAuto, TAM);
    //inicializarTrabajos(listaTrabajo, TAMT);
    //inicializarEmpleados(listaEmpleados, TAMEMP);

    do{
            switch(menu())
            {
            case 'a':
                if(altaAuto(proximoIdAuto, listaAuto, TAM, listaMarca, 5, listaColor, 5) == 1)
                {
                    proximoIdAuto++;
                    flagAuto = 1;
                }
                break;
            case 'b':
                if(flagAuto == 1)
                {
                    modificarAuto(listaAuto, TAM, listaMarca, 5, listaColor, 5, listaCliente, TAMC);
                }
                break;
            case 'c':
                if(flagAuto == 1)
                {
                    bajaAuto(listaAuto, TAM, listaMarca, 5, listaColor, 5, listaCliente, TAMC);
                }
                break;
            case 'd':
                if(flagAuto == 1)
                {
                    ordenarAutosPorMarcaYPatente(listaAuto, TAM, listaMarca, 5);
                    mostrarAutos(listaAuto, TAM, listaMarca, 5, listaColor, 5, listaCliente, TAMC);
                }
                break;
            case 'e':
                system("cls");
                mostrarMarcas(listaMarca, 5);
                break;
            case 'f':
                system("cls");
                mostrarColores(listaColor, 5);
                break;
            case 'g':
                system("cls");
                mostrarServicios(listaServicios, 4);
                break;
            case 'h':
                if(flagAuto == 1)
                {
                    altaTrabajo(proximoIdTrabajo, listaTrabajo, 5, listaServicios, 4, listaAuto, TAM, listaMarca, 5, listaColor, 5, listaCliente, TAMC);
                }
                break;
            case 'i':
                if(flagAuto == 1)
                {
                    mostrarTrabajos(listaTrabajo, 5, listaServicios, 4);
                }
                break;
            case 'j':
                informar(listaAuto, TAM, listaCliente, TAMC, listaColor, 5, listaMarca, 5, marcaMasElegida, listaTrabajo, TAMT, listaServicios, 4);
                break;
            case 'k':
                empleados(listaEmpleados, TAMEMP, sectores, TAMSEC, listaAuto, TAM, listaMarca, 5, listaColor, 5);
            case 'l':
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

    return 0;
}

//---------------------------------------------------------------------------------------------------

int menu()
{
    char opcion;

    system("cls");
    printf("***** Lavadero de Autos *****\n\n");
    printf("A. Alta Auto\n");
    printf("B. Modificar Auto\n");
    printf("C. Baja Auto\n");
    printf("D. Listar Autos\n");
    printf("E. Listar Marcas\n");
    printf("F. Listar Colores\n");
    printf("G. Listar Servicios\n");
    printf("H. Alta Trabajo\n");
    printf("I. Listar Trabajos\n");
    printf("J. Informar\n");
    printf("K. Empleados\n");
    printf("L. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}

//---------------------------------------------------------------------------------------------------
