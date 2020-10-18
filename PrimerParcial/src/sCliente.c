/*
 * sCliente.c
 *
 *  Created on: 2020/10/12
 *      Author: PC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sCliente.h"
#include "utn.h"

/**
 * \brief Genera un nuevo id y lo incrementa cada vez que sea necesario
 * \return el id a utilizar
 */

static int sCliente_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

/**
 * \brief Inicializa la totalidad del array a utilizar como vacios
 * \param *pArrayCliente El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sCliente_init(sCliente *pArrayCliente, int limite)
{
	int retorno = -1;
	{
		if(pArrayCliente != NULL && limite > 0 )
		{
			for(int i = 0; i < limite; i++)
			{
				pArrayCliente[i].isEmpty = TRUE;

			}
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Inicializa El array de clientes en
 * \param *pArrayCliente El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 */
int sCliente_buscarLibre(sCliente *pArrayCliente, int limite)
{
	int retorno = -1;

	if(pArrayCliente != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayCliente[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Busca una posicion libre en el array y lo pasa por referencia
 * \param *pArrayCliente El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sCliente_buscarLibreRef (sCliente *pArrayCliente, int limite, int * pIndice)
{
	int retorno = -1;

	if(pArrayCliente != NULL && limite > 0 && pIndice != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayCliente[i].isEmpty == TRUE)
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
 * \brief Da de alta un cliente
 * \param *pArrayCliente El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sCliente_altaCliente(sCliente *pArrayCliente, int limite)
{
	int retorno = -1;
	int indice;
	sCliente bufferCliente;

	if(pArrayCliente != NULL && limite > 0)
	{
		if(sCliente_buscarLibreRef(pArrayCliente, limite, &indice)== 0)
			{
				if (utn_getNombre("Nombre?: ", "\nError",bufferCliente.nombre, 2,SIZECLIENTE)==0 &&
					utn_getNombre("Apellido?: ", "\nError", bufferCliente.apellido, 2,SIZECLIENTE)==0 &&
					utn_getString("Cuit?: ", "\nError", bufferCliente.cuit, 2, SIZECLIENTE)==0 )
				{
					pArrayCliente[indice] = bufferCliente;
					pArrayCliente[indice].idCliente =  sCliente_generarNuevoId();
					pArrayCliente[indice].isEmpty = FALSE;
				}
				else
				{
					printf("Error");
				}

				}
			else
			{
				printf("No se encontro un lugar libre");
			}
			retorno = 0;
	}

	return retorno;
}
/**
 * \brief Imprime el array por pantalla
 * \param *pArrayCliente El array a imprimir
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sCliente_imprimir (sCliente *pArrayCliente, int limite)
{
	int retorno = -1;

	if(pArrayCliente !=NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayCliente[i].isEmpty == FALSE)
			{
				printf("\n Nombre:  %s     Apellido:   %s      Cuit:   %s     id:    %d",
						pArrayCliente[i].nombre, pArrayCliente[i].apellido,pArrayCliente[i].cuit,pArrayCliente[i].idCliente);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Da de baja un cliente
 * \param *pArrayCliente El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sCliente_bajaCliente(sCliente *pArrayCliente, int limite)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrayCliente != NULL && limite>0)
	{
		sCliente_imprimir(pArrayCliente, limite);
		if(utn_getNumero("\nIngrese el id del cliente a borrar: \n","Error",&idABorrar,6,1,9999)==0)
		{
			// busco la posicion a borrar
			if(sCliente_buscarIndicePorId(pArrayCliente,limite,idABorrar,&indiceABorrar)==0)
			{
				// borro esa posicion
				pArrayCliente[indiceABorrar].isEmpty=TRUE;
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Modifica un cliente ya existente
 * \param *pArrayCliente El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \return (-1) Error / (0) Ok
 *
 */
int sCliente_modificar (sCliente *pArrayCliente, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	sCliente bufferCliente;

	if (pArrayCliente != NULL && limite>0)
	{
		sCliente_imprimir(pArrayCliente, limite);

		if(utn_getNumero("\nId que quiere modificar?: ","ERROR!",&idBuscar,6,1,9999)==0)
		{
			if(sCliente_buscarIndicePorId(pArrayCliente, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferCliente = pArrayCliente[indiceAModificar]; // IMPORTANTE!

				if (utn_getNombre("Ingrese un nuevo nombre: ", "\nError",bufferCliente.nombre, 2,SIZECLIENTE)==0)
				{
					if (utn_getNombre("Ingrese un nuevo apellido: ", "\nError", bufferCliente.apellido, 2,SIZECLIENTE)==0)
					{
						if(utn_getString("Ingrese un nuevo cuit: ", "\nError", bufferCliente.cuit, 2, SIZECLIENTE)==0 )
						{
							pArrayCliente[indiceAModificar] = bufferCliente; // COPIAMOS AL ARRAY
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief Busca el indice de un cliente segun su id
 * \param *pArrayCliente El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \param int idBuscar El id que usaremos como referencia para buscar el indice deseado
 * \param int *pIndice El puntero donde se va a guardar el indice deseado
 * \return El indice que se queria buscar; -1 si surge un error
 *
 */
int sCliente_buscarIndicePorId (sCliente * pArrayCliente, int limite, int idBuscar,int * pIndice)
{
    int retorno = -1;
    int i ;

     if (pArrayCliente != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
     {
    	 for ( i = 0; i<limite; i++)
          {
    		 if(pArrayCliente[i].isEmpty==FALSE &&
    			pArrayCliente[i].idCliente == idBuscar)
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


int cliente_altaForzada(sCliente* pArrayCliente, int limite , char * nombre, char * apellido, char * cuit)
{

    int retorno = -1;
    int indice;
    if (sCliente_buscarLibre(pArrayCliente, limite) >=0)
    {
    	indice = sCliente_buscarLibre(pArrayCliente, limite);
        strncpy(pArrayCliente[indice].nombre,nombre,10);
        strncpy(pArrayCliente[indice].apellido,apellido,10);
        strncpy(pArrayCliente[indice].cuit,cuit,10);
        pArrayCliente[indice].idCliente = sCliente_generarNuevoId();
        pArrayCliente[indice].isEmpty = FALSE;
        retorno = 0;
    }
    else
    {
        printf("No queda un lugar libre");
    }
    return retorno;
}
