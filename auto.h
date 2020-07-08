#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
    int idCliente;
    int idEmpleado;

}eAuto;

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;

}eCliente;


#endif // AUTO_H_INCLUDED


/** \brief Inicializa los autos
 *
 * \param vec[] eAuto
 * \param tam int
 *
 */
void inicializarAutos(eAuto vec[], int tam);


/** \brief Buscar un espacio libre donde no haya un auto
 *
 * \param vec[] eAuto
 * \param tam int
 * \return indice int, devuelve la posicion libre
 *
 */
int buscarLibre(eAuto vec[], int tam);


/** \brief Da de alta un nuevo auto
 *
 * \param idx int
 * \param vec[] eAuto
 * \param tam int
 * \param marca[] eMarca
 * \param tamM int
 * \param color[] eColor
 * \param tamC int
 * \return todoOk int, devuelve [0] si hubo error, [1] si hubo exito
 *
 */
int altaAuto(int idx, eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);


/** \brief Imprime un auto
 *
 * \param x eAuto
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void mostrarAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);


/** \brief Imprime la lista de autos
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marca[] eMarca
 * \param tamM int
 * \param color[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void mostrarAutos(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC, eCliente clientes[], int tamCl);


/** \brief Ordena los autos por marca y despues por patente
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 *
 */
void ordenarAutosPorMarcaYPatente(eAuto autos[], int tam, eMarca marcas[], int tamM);


/** \brief Busca un auto en la lista, indicado por patente
 *
 * \param patente[] char
 * \param vec[] eAuto
 * \param tam int
 * \return indice int, devuelve la posicion del auto a buscar
 *
 */
int buscarAuto(char patente[], eAuto vec[], int tam);


/** \brief Modifica los campos de un auto, indicado por patente
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marca[] eMarca
 * \param tamM int
 * \param color[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void modificarAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC, eCliente clientes[], int tamCl);


/** \brief Imprime las opciones para modificar un auto
 *
 * \return opcion int, devuelve la opcion elegida
 *
 */
int menuModificar();


/** \brief Imprime una marca
 *
 * \param x eMarca
 *
 */
void mostrarMarca(eMarca x);


/** \brief Recorre las marcas y las imprime
 *
 * \param vec[] eMarca
 * \param tam int
 *
 */
void mostrarMarcas(eMarca vec[], int tam);


/** \brief Busca una marca por id
 *
 * \param vec[] eMarca
 * \param tam int
 * \param id int
 * \return indice int
 *
 */
int buscarMarca(eMarca vec[], int tam, int id);


/** \brief Recorre los colores y los imprime
 *
 * \param vec[] eColor
 * \param tam int
 *
 */
void mostrarColores(eColor vec[], int tam);


/** \brief Da de baja un auto, indicado por patente
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marca[] eMarca
 * \param tamM int
 * \param color[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamCl int
 *
 */
void bajaAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC, eCliente clientes[], int tamCl);


/** \brief Recorre las marcas por id y carga la descripcion de las mismas
 *
 * \param descripcion[] char
 * \param id int
 * \param marcas[] eMarca
 * \param tam int
 * \return todoOk int, devuelve [0] si hubo error, [1] si hubo exito
 *
 */
int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam);


/** \brief Recorre los colores por id y carga la descripcion de los mismos
 *
 * \param descripcion[] char
 * \param id int
 * \param colores[] eColor
 * \param tam int
 * \return todoOk int, devuelve [0] si hubo error, [1] si hubo exito
 *
 */
int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam);


/** \brief Recorre los clientes por id y carga los nombres de los mismos
 *
 * \param nombre[] char
 * \param id int
 * \param clientes[] eCliente
 * \param tamCl int
 * \return todoOk int, devuelve [0] si hubo error, [1] si hubo exito
 *
 */
int cargarNombreCliente(char nombre[], int id, eCliente clientes[], int tamCl);
