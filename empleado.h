#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "auto.h"

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int edad;
    float sueldo;
    int idSector;
    int isEmpty;

}eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

#endif // EMPLEADO_H_INCLUDED

/** \brief Muestra las opciones para  los empleados
 *
 * \return opcion int, opcion elegida
 *
 */
int menuEmpleados();


/** \brief Menu que permite dar de alta a un empleado y muestra los informes
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 * \param autos[] eAuto
 * \param tamAu int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colorres[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void empleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec, eAuto autos[], int tamAu, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief Inicializa los empleados
 *
 * \param vec[] eEmpleado
 * \param tam int
*
 */
void inicializarEmpleados(eEmpleado vec[], int tam);


/** \brief Busca un espacio libre para un nuevo empleado
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return indice int
 *
 */
int buscarLibreEmp(eEmpleado vec[], int tam);


/** \brief Muestra un empleado
 *
 * \param x eEmpleado
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamSec);


/** \brief Muestra la lista de empleados
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);


/** \brief Busca un empleado por Id
 *
 * \param id int
 * \param vec[] eEmpleado
 * \param tam int
 * \return indice int
 *
 */
int buscarEmpleado(int id, eEmpleado vec[], int tam);


/** \brief Da de alta un nuevo empleado
 *
 * \param idx int
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 * \return todoOk int
 *
 */
int altaEmpleado(int idx, eEmpleado vec[], int tam, eSector sectores[], int tamSec);


/** \brief Da de baja un empleado
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);


/** \brief Modifica los campos de un empleado
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);


/** \brief Muestras las opciones para modificar un empleado
 *
 * \return opcion int, opcion elegida
 *
 */
int menuModificarEmp();


/** \brief Muestra los sectores
 *
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void mostrarSectores(eSector sectores[], int tam);


/** \brief Carga la descripcion del sector desde el Id
 *
 * \param descripcion[] char
 * \param sectores[] eSector
 * \param tamSec int
 * \return todoOk int
 *
 */
int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam);


/** \brief Carga el nombre del empleado desde el id
 *
 * \param nombre[] char
 * \param vec[] eEmpleado
 * \param tam int
 * \return todoOk int
 *
 */
int cargarNombreEmp(char nombre[], int id, eEmpleado vec[], int tam);


/** \brief Muestra un empleado y auto
 *
 * \param x[] eAuto
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param vec[] eEmpleado
 * \param tam int
 * \return
 *
 */
void mostrarEmpleadoAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC, eEmpleado vec[], int tam);


/** \brief Muestra la lista de autos y empleados
 *
 * \param vec[] eAuto
 * \param tamAu int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param empleados[] eEmpleado
 * \param tamEmp int
 *
 */
void mostrarEmpleadosAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eEmpleado empleado[], int tamEmp);


/** \brief Informa el sector que mas cobra
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void sectorQueMasCobra(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);


/** \brief Informa los empleados mayores de edad
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void empleadosMayoresEdad(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);


/** \brief Informa el mayor sueldo de un sector
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);


/** \brief Informa el sueldo mas alto
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void empleadosSueldoAlto(eEmpleado vec[], int tam, eSector sectores[], int tamsec);


/** \brief Informa los empleados por sector
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void informarEmpleadoXSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);


/** \brief Ordena los empleados por edad de menos a mayor
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSec int
 *
 */
void ordenarEmpleadosEdad(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
