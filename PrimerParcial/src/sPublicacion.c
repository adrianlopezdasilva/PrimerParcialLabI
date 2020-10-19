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
#include "utn.h"

static int sPublicacion_pausarTodasLasPublicaciones(sPublicacion *pArrayPublicacion, int limite, int idCliente);
/*static int sPublicacion_reanudarTodasLasPublicaciones(sPublicacion  pArrayPublicacion,int limite, int idCliente);*/


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
 * \param *pArrayPublicacion Puntero al array de publicaciones
 * \param  limite Limite del array
 * \return (-1) Error / (0) Ok
 *
 */
int sPublicacion_init(sPublicacion *pArrayPublicacion, int limite)
{
	int retorno = -1;
		if(pArrayPublicacion != NULL && limite > 0 )
		{
			for(int i = 0; i < limite; i++)
			{
				pArrayPublicacion[i].isEmpty = TRUE;

			}
			retorno = 0;
		}
	return retorno;
}

/**
 * \brief Busca un lugar libre en el array
 * \param *pArrayPublicacion Puntero al array de publicaciones
 * \param limite Limite del array
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
				retorno = i;
				break;

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
		sCliente_imprimir(pArrayCliente, limiteCliente);
		if(utn_getNumero("\nA que cliente le quiere agregar una publicacion?:\n", "\nError", &idABuscar, 2, 0 ,1000)== 0 &&
		   sCliente_buscarIndicePorId(pArrayCliente, limiteCliente, idABuscar, &indice) == 0)
			{
				if (utn_getNumero("\nIngrese el numero del rubro:\nOPCION 1: ADMINISTRACION\nOPCION 2: ATENCION AL CLIENTE\nOPCION 3: OPERARIO\n"
									,"\nError",&bufferPublicacion.numeroRubro, 2, 1, 3)==0 &&
					utn_getString("Texto del aviso: ", "\nError", bufferPublicacion.textoAviso, 2,SIZEPUBLICACION)==0 )
				{
					pArrayPublicacion[indice] = bufferPublicacion;
					pArrayPublicacion[indice].idPublicacion =  sPlubicacion_generarNuevoId();
					pArrayPublicacion[indice].isEmpty = FALSE;
					pArrayPublicacion[indice].estadoPublicacion = ACTIVO;
					pArrayPublicacion[indice].idCliente = indice+1;
					printf("\nEl ID de esta publicacion es: %d\n", pArrayPublicacion[indice].idPublicacion);
					retorno = 0;
				}
				else
				{
					printf("\nError");
				}
			}
			else
			{
				printf("Ese id no esta actualmente en uso");
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
int sPublicacion_imprimir (sPublicacion *pArrayPublicacion, int limite)
{
	int retorno = -1;
	int flagActivos = 0;

	if(pArrayPublicacion !=NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayPublicacion[i].isEmpty == FALSE && pArrayPublicacion[i].estadoPublicacion == ACTIVO )
			{
				printf("\n TEXTO AVISO: %s        NUMERO DE RUBRO: %d          ESTADO: %d ID CLIENT: %d ID PUBLICACION:%d",
						pArrayPublicacion[i].textoAviso, pArrayPublicacion[i].numeroRubro,
						pArrayPublicacion[i].estadoPublicacion,pArrayPublicacion[i].idCliente,
						pArrayPublicacion[i].idPublicacion);
				flagActivos = 1;
				retorno = 0;
			}
		}
		if (flagActivos == 0)
		{
			printf("No hay ninguna publicacion activa");
		}

	}
	return retorno;
}

/**
 * \brief Da de baja un Publicacion
 * \param sPublicacion *pArrayPublicacion El array a utilizar
 * \param int limite Acota el numero de iteraciones
 * \param sCliente pArrayCliente El array de clientes a utilizar
 * \param int limiteCliente Acota el numero de iteraciones en los array de clientes
 * \return (-1) Error / (0) Ok
 *
 */
int sPublicacion_pausarPublicacion(sPublicacion *pArrayPublicacion, int limite, sCliente *pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idAPausar;
	int indiceABuscar;
	int flagConfirmar = 2;

	if (pArrayPublicacion != NULL && limite>0)
	{
		sPublicacion_imprimir(pArrayPublicacion, limite);
		if(utn_getNumero("\nIngrese el id del Publicacion a pausar:\n","Error",&indiceABuscar,3,0,9999)==0 &&
		   sPublicacion_buscarIndicePorId(pArrayPublicacion,limite,indiceABuscar,&idAPausar)==0 &&
		   sPublicacion_ImprimirPublicacionSegunCliente(pArrayPublicacion, limite, indiceABuscar) != -1)
			{
				utn_getNumero("\nConfirma pausar publicacion? \n1 = SI \n2 = NO\n","Error",&flagConfirmar,3,1,9999);
				if(flagConfirmar == 1 && sPublicacion_pausarTodasLasPublicaciones(pArrayPublicacion, limite, indiceABuscar) == 0)
				{
					pArrayPublicacion[idAPausar].isEmpty = TRUE;
					retorno = 0;
				}
				else
				{
					printf("Operacion abortada");
				}
			}
		}
		retorno = 0;

	return retorno;
}
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

int sPublicacion_ImprimirPublicacionSegunCliente(sPublicacion *pArrayPublicacion, int limite, int idCliente)
{
	int retorno = -1;
	if(pArrayPublicacion != NULL && limite > 0 && idCliente > 0)
	{
		printf("\nPublicaciones del cliente %d", idCliente);
		for(int i =0 ; i <limite; i++)
		{
			if(pArrayPublicacion[i].isEmpty == FALSE && pArrayPublicacion[i].idCliente == idCliente && pArrayPublicacion[i].estadoPublicacion == ACTIVO)
			{
				printf("\n TEXTO AVISO: %s        NUMERO DE RUBRO: %d          ESTADO: %d ID CLIENT: %d ID PUBLICACION:%d",
				pArrayPublicacion[i].textoAviso, pArrayPublicacion[i].numeroRubro,
				pArrayPublicacion[i].estadoPublicacion,pArrayPublicacion[i].idCliente,
				pArrayPublicacion[i].idPublicacion);
			}
		}
		retorno = 0;
	}
	return retorno;
}

static int sPublicacion_pausarTodasLasPublicaciones(sPublicacion *pArrayPublicacion, int limite, int idCliente)
{
	int retorno = -1;

	if(pArrayPublicacion != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayPublicacion[i].idCliente == idCliente)
			{
				pArrayPublicacion[i].isEmpty = TRUE;

			}
		}
		retorno = 0;
	}

	return retorno;
}

/*static int sPublicacion_reanudarTodasLasPublicaciones(sPublicacion  pArrayPublicacion,int limite, int idCliente)
{
	int retorno=-1;
	if(pArrayPublicacion !=NULL && limite>0)
	{
		for(int i=0; i<limite; i++)
		{
			if(pArrayPublicacion[i].idCliente==idCliente)
			{
				pArrayPublicacion[i].isEmpty=FALSE;
				retorno=0;
			}
		}
	}
	return retorno;
}
*/

int sPublicacion_cantidaPublicaciones(sPublicacion* pArrayPublicacion,int limite,int id,int *pResultado)
{
	int retorno=-1;
	int contadorPublicaciones=0;

	if(pArrayPublicacion!=NULL && limite>0 && id>0 && pResultado!=NULL)
	{
		for(int i=0; i<limite; i++)
		{
			if(pArrayPublicacion[i].isEmpty==FALSE && pArrayPublicacion[i].idCliente == id && pArrayPublicacion[i].estadoPublicacion==ACTIVO)
			{
				contadorPublicaciones++;
			}
		}

		*pResultado=contadorPublicaciones;
		retorno=0;
	}
	return retorno;
}

int sPublicacion_imprimirClientesYPublicaciones(sPublicacion* pArrayPublicacion,int limite, sCliente *pArrayCliente,int limiteCliente)
{
	int retorno=-1;
	int cantidadPublicaciones;
	if(pArrayPublicacion!=NULL && limite>0 && pArrayCliente!=NULL && limiteCliente>0)
	{
		for(int i=0; i<limiteCliente;i++)
		{
			if( pArrayCliente[i].isEmpty == FALSE &&
				sPublicacion_cantidaPublicaciones(pArrayPublicacion,limite,pArrayCliente[i].idCliente,&cantidadPublicaciones)==0)
			{
				printf("\n Nombre:  %s     Apellido:   %s      Cuit:   %s     id:    %d    Publicaciones activas: %d",
						pArrayCliente[i].nombre, pArrayCliente[i].apellido,pArrayCliente[i].cuit,
						pArrayCliente[i].idCliente, cantidadPublicaciones);
			}
		}
		retorno=0;
	}

	return retorno;
}

int publicacion_altaForzada(sPublicacion* pArrayPublicacion, int limite ,int idCliente,int rubro,  char* publicacion)
{
    int retorno = -1;
    int indice;
    if (sPublicacion_buscarLibre(pArrayPublicacion, limite) >=0)
    {
    	indice = sPublicacion_buscarLibre(pArrayPublicacion, limite);
        strncpy(pArrayPublicacion[indice].textoAviso,publicacion,64);
        pArrayPublicacion[indice].idCliente = idCliente;
        pArrayPublicacion[indice].numeroRubro=rubro;
        pArrayPublicacion[indice].estadoPublicacion=ACTIVO;
        pArrayPublicacion[indice].idPublicacion = sPlubicacion_generarNuevoId();
        pArrayPublicacion[indice].isEmpty = FALSE;
        retorno=0;
    }
    return retorno;
}

