#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

typedef struct
{
    int idMarca;
    int cantidad;
    int isEmpty;

}eMarcaME;

#endif // INFORMES_H_INCLUDED

/** \brief Imprime las opciones para los informes
 *
 * \return opcion int, devuelve la opcion elegida
 *
 */
int menuInformes();


/** \brief Menu que permite llamar a las funciones de los informes
 *
 * \param autos[] eAuto
 * \param tam int
 * \param clientes[] eCliente
 * \param tamCl int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 *
 */
void informar(eAuto autos[], int tam, eCliente clientes[], int tamCl, eColor colores[], int tamC, eMarca marcas[], int tamM, eMarcaME marcaElegida[], eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer);


/** \brief Muestra los autos del color seleccionado por el usuario
 *
 * \param autos[] eAuto
 * \param tam int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void informarAutosColor(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl);


/** \brief Muestra autos de una marca seleccionada
 *
 * \param autos[] eAuto
 * \param tam int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void informarAutosPorMarcaS(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl);


/** \brief Informa el o los autos mas viejos
 *
 * \param autos[] eAuto
 * \param tam int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void informarAutoMasViejo(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl);


/** \brief Muestra un listado de los autos separados por marca
 *
 * \param autos[] eAuto
 * \param tam int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void informarAutosPorMarca(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl);


/** \brief Le da a elegir al usuario un color y una marca y cuenta cuantos autos hay de ese color y esa marca
 *
 * \param autos[] eAuto
 * \param tam int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void informarAutosPorColorYMarca(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eCliente clientes[], int tamCl);


/** \brief Muestra la o las marcas mas elegidas por los clientes
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param marcaElegida[] eMarcaME
 *
 */
void informarMarcaME(eAuto autos[], int tam, eMarca marcas[], int tamM, eMarcaME marcaElegida[]);


/** \brief Muestra los trabajos realizados a un auto seleccionado
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
  * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamSer int
 *
 */
void informarTrabajosAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer);


/** \brief Muestra el importe total de los servicios de un auto seleccion
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
  * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamSer int
 *
 */
void informarImporteAuto(eAuto autos[], int tam,  eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer);


/** \brief Pide un servicio y muestra los autos a los que se realizo ese servicio y la fecha
 *
 * \param autos[] eAuto
 * \param tam int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamSer int
 *
 */
void informarAutoYFechaServicio(eAuto autos[], int tam, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer);


/** \brief Muestra un servicio realizado en una fecha seleccionada
 *
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamSer int
 *
 */
void informarFechaServicio(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer);
