/*
 * sPublicacion.c
 *
 *  Created on: 2020/10/13
 *      Author: PC
 */


/*
 * sPublicacion.c
 *
 *  Created on: 2020/10/12
 *      Author: PC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sPublicacion.h"
#include "sCliente.h"
#include "utn.h"


/**
 * \brief Genera un nuevo id y lo incrementa cada vez que sea necesario
 * \return el id a utilizar
 */

static int sPlubicacion_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

/**
 * \brief Inicializa la totalidad del array a utilizar como vacios
 * \param *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sPublicacion_init(sPublicacion *pArrayPublicacion, int limite)
{
	int retorno = -1;
	{
		if(pArrayPublicacion != NULL && limite > 0 )
		{
			for(int i = 0; i < limite; i++)
			{
				pArrayPublicacion[i].isEmpty = TRUE;

			}
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Inicializa El array de Publicacions en
 * \param *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 */
int sPublicacion_buscarLibre(sPublicacion *pArrayPublicacion, int limite)
{
	int retorno = -1;

	if(pArrayPublicacion != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayPublicacion[i].isEmpty == TRUE)
			{
				break;
				retorno = i;
			}
		}
	}
	return retorno;
}

/**
 * \brief Busca una posicion libre en el array y lo pasa por referencia
 * \param *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sPublicacion_buscarLibreRef (sPublicacion *pArrayPublicacion, int limite, int * pIndice)
{
	int retorno = -1;

	if(pArrayPublicacion != NULL && limite > 0 && pIndice != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayPublicacion[i].isEmpty == TRUE)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Da de alta un Publicacion
 * \param *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sPublicacion_altaPublicacion(sPublicacion *pArrayPublicacion, int limite, sCliente *pArrayCliente, int limiteCliente )
{
	int retorno = -1;
	int idABuscar;
	int indice;
	sPublicacion bufferPublicacion;

	if(pArrayPublicacion != NULL && limite > 0 &&
	   pArrayCliente != NULL && limiteCliente >0)
	{
		{
			sCliente_imprimir(pArrayCliente, limiteCliente);
			if(utn_getNumero("\nA que cliente le quiere agregar una publicacion?:\n", "\nError", &idABuscar, 2, 1 ,1000)== 0 &&
			   sCliente_buscarIndicePorId(pArrayCliente, limiteCliente, idABuscar, &indice) == 0)
			{
				if (utn_getNumero("\nIngrese el numero del rubro:\n"
								  "OPCION 1: ADMINISTRACION\n"
								  "OPCION 2: ATENCION AL CLIENTE\n"
								  "OPCION 3: OPERARIO\n" , "\nError",&bufferPublicacion.numeroRubro, 2, 1, 1000)==0 &&
								  utn_getString("Texto del aviso: ", "\nError", bufferPublicacion.textoAviso, 2,SIZEPUBLICACION)==0 )
				{
					pArrayPublicacion[indice] = bufferPublicacion;
					pArrayPublicacion[indice].idPublicacion =  sPlubicacion_generarNuevoId();
					pArrayPublicacion[indice].isEmpty = FALSE;
					pArrayPublicacion[indice].estadoPublicacion = ACTIVO;
					printf("El ID de esta publicacion es: %d", pArrayPublicacion[indice].idPublicacion);
				}
				else
				{
					printf("Error");
				}
			}
			else
			{
				printf("Ese id no esta actualmente en uso");
			}

			retorno = 0;
		}
	}

	return retorno;
}
/**
 * \brief Imprime el array por pantalla
 * \param *pArrayPublicacion El array a imprimir
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
/*int sPublicacion_imprimir (sPublicacion *pArrayPublicacion, int limite)
{
	int retorno = -1;

	if(pArrayPublicacion !=NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayPublicacion[i].isEmpty == FALSE)
			{
				printf("\n Nombre:  %s     Apellido:   %s      Cuit:   %s     id:    %d",
						pArrayPublicacion[i].nombre, pArrayPublicacion[i].apellido,pArrayPublicacion[i].cuit,pArrayPublicacion[i].idPublicacion);
			}
		}
		retorno = 0;
	}
	return retorno;
}*/

/**
 * \brief Da de baja un Publicacion
 * \param *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
/*int sPublicacion_bajaPublicacion(sPublicacion *pArrayPublicacion, int limite)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrayPublicacion != NULL && limite>0)
	{
		sCl(pArrayPublicacion, limite);
		if(utn_getNumero("\nIngrese el id del Publicacion a borrar: \n","Error",&idABorrar,6,1,9999)==0)
		{
			// busco la posicion a borrar
			if(sPublicacion_buscarIndicePorId(pArrayPublicacion,limite,idABorrar,&indiceABorrar)==0)
			{
				// borro esa posicion
				pArrayPublicacion[indiceABorrar].isEmpty=TRUE;
			}
		}
		retorno = 0;
	}
	return retorno;
}*/
/**
 * \brief Modifica un Publicacion ya existente
 * \param *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
/*int sPublicacion_modificar (sPublicacion *pArrayPublicacion, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	sPublicacion bufferPublicacion;

	if (pArrayPublicacion != NULL && limite>0)
	{
		sPublicacion_imprimir(pArrayPublicacion, limite);

		if(utn_getNumero("\nId que quiere modificar?: ","ERROR!",&idBuscar,6,1,9999)==0)
		{
			if(sPublicacion_buscarIndicePorId(pArrayPublicacion, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferPublicacion = pArrayPublicacion[indiceAModificar]; // IMPORTANTE!

				if (utn_getNombre("Ingrese un nuevo nombre: ", "\nError",bufferPublicacion.nombre, 2,SIZEPUBLICACION)==0)
				{
					if (utn_getNombre("Ingrese un nuevo apellido: ", "\nError", bufferPublicacion.apellido, 2,SIZEPUBLICACION)==0)
					{
						if(utn_getString("Ingrese un nuevo cuit: ", "\nError", bufferPublicacion.cuit, 2, SIZEPUBLICACION)==0 )
						{
							pArrayPublicacion[indiceAModificar] = bufferPublicacion; // COPIAMOS AL ARRAY
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}*/
/**
 * \brief Busca el indice de un Publicacion segun su id
 * \param *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \param int idBuscar El id que usaremos como referencia para buscar el indice deseado
 * \param int *pIndice El puntero donde se va a guardar el indice deseado
 * \return El indice que se queria buscar; -1 si surge un error
 *
 */
int sPublicacion_buscarIndicePorId (sPublicacion * pArrayPublicacion, int limite, int idBuscar,int * pIndice)
{
    int retorno = -1;
    int i ;

     if (pArrayPublicacion != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
     {
    	 for ( i = 0; i<limite; i++)
          {
    		 if(pArrayPublicacion[i].isEmpty==FALSE &&
    			pArrayPublicacion[i].idPublicacion == idBuscar)
                {
                 	 *pIndice = i;
                     retorno = 0;
                     break;
                 }
           }
      }
            else
            {
                printf("Error");
            }
     return retorno;
}
