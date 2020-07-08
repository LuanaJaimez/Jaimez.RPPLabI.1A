#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief Imprime un servicio
 *
 * \param x eServicio
 *
 */
void mostrarServicio(eServicio x);


/** \brief Imprime la lista de servicios
 *
 * \param vec[] eServicio
 * \param tam int
 *
 */
void mostrarServicios(eServicio vec[], int tam);


/** \brief Recorre los servicios por id y carga la descripcion de los mismos
 *
 * \param descripcion[] char
 * \param id int
 * \param servicios[] eServicio
 * \param tam int
 * \return todoOk int, devuelve [0] si hubo error, [1] si hubo exito
 *
 */
int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam);
