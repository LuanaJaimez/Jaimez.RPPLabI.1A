#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

/** \brief Funciones que validan el ingreso de los datos
 *
 */


 /** \brief Pausa el programa, espera que el usuario presione una tecla para continuar
  *
  *
  */
void pause();


/** \brief Valida que los caracteres ingresados sea una cadena
 *
 * \param pAux char*
 * \param limit int
 * \param retry int
 * \param msg char*
 * \param msgError char*
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);


/** \brief Asigna la cadena
 *
 * \param pAux char*
 * \param limit int
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int getCadena(char* pAux, int limit);


/** \brief Si es de tipo char
 *
 * \param srt[] char
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int isChar(char str[]);


/** \brief Valida que los caracteres ingresados sea de tipo flotante
 *
 * \param pFloat float*
 * \param retry int
 * \param msg char*
 * \param msgError char*
 * \param min float
 * \param max float
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);


/** \brief Asigna el flotante
 *
 * \param pAux float*
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int getFloat(float*pAux);


/** \brief Si es de tipo flotante
 *
 * \param pAux char*
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int isFloat(char* pAux);


/** \brief Valida que los caracteres ingresados sea de tipo entero
 *
 * \param pEntero int*
 * \param retry int
 * \param msg char*
 * \param msgError char*
 * \param min int
 * \param max int
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);


/** \brief Asigna el entero
 *
 * \param pAux int*
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int getInt(int* pAux);


/** \brief Si es entero
 *
 * \param pAux char*
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int isInt(char *pAux);


/** \brief Pasa un caracter a minuscula
 *
 * \param str char*
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int strLwr(char* str);


/** \brief Normaliza la cadena
 *
 * \param str char*
 * \return isOk int, devuelve [-1] si hubo error y [0] si hubo exito
 *
 */
int normalizeStr(char* str);
