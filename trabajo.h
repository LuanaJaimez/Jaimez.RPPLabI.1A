#include "auto.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Inicializa los trabajos
 *
 * \param vec[] eTrabajo
 * \param tam int
 *
 */
void inicializarTrabajos(eTrabajo vec[], int tam);


/** \brief Buscar un espacio libre donde no haya un trabajo
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \return indice int, devuelve la posicion libre
 *
 */
int buscarLibreT(eTrabajo vec[], int tam);


/** \brief Da de alta un nuevo trabajo
 *
 * \param idx int
 * \param vec[] eTrabajo
 * \param tam int
 * \param lavados[] eServicio
 * \param tamSer int
 * \param autos[] eAuto
 * \param tamAu int
 * \param marca[] eMarca
 * \param tamM int
 * \param color[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 * \return todoOk int, devuelve [0] si hubo error, [1] si hubo exito
 *
 */
int altaTrabajo(int idx, eTrabajo vec[], int tam, eServicio lavados[], int tamSer, eAuto autos[], int tamAu, eMarca marca[], int tamM, eColor color[], int tamC, eCliente clientes[], int tamCl);


/** \brief Imprime un trabajo
 *
 * \param x eTrabajo
 * \param servicios[] eServicio
 * \param tamS int
 *
 */
void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamS);


/** \brief Imprime la lista de trabajos
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \param servicios[] eServicio
 * \param tamS int
 *
 */
void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS);
