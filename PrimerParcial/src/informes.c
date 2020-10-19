/*
 * informes.c
 *
 *  Created on: 2020/10/19
 *      Author: PC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "sPublicacion.h"
#include "sCliente.h"
/*
int informe_clienteConMasAvisos (sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes, int *cantidad)
{
	int i;
	int retorno = -1;
	int contadorPublicaciones;
	int mayorPublicaciones;
	if(pArrayPublicaciones != NULL && pArrayClientes != NULL && limite >0 && limiteClientes > 0)
	{
		for (i = 0; i <limiteClientes; i++)
		{
			if(pArrayClientes[i].isEmpty == FALSE)
			{
				contadorPublicaciones = sPublicacion_totalidadPublicacionesEnUnCliente
										(pArrayPublicaciones, limite, pArrayPublicaciones[i].idCliente);
				if(i == 0)
				{
					mayorPublicaciones = contadorPublicaciones;
				}
				else if (contadorPublicaciones >mayorPublicaciones)
				{
					mayorPublicaciones = contadorPublicaciones;
				}


				retorno = 0;
			}
		}
	}

	return retorno;
}
*/
int informe_cantidadPublicacionesPausadas(sPublicacion* pArrayPublicaciones, int limite)
{
	int retorno = -1;
	int contadorPausados = 0;

	if( pArrayPublicaciones != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if (pArrayPublicaciones[i].estadoPublicacion == PAUSADO && pArrayPublicaciones[i].isEmpty == FALSE)
			{
				contadorPausados++;
			}
		}
		if(contadorPausados == 0)
		{
			printf("No hay ninguna publicacion  pausada");
		}else
		{
			printf("La cantidad de publicaciones pausadas es %d", contadorPausados);

		}
		retorno = 0;
	}

	return retorno;
}


int informe_cantidadPublicacionesActivas(sPublicacion* pArrayPublicaciones, int limite)
{
	int retorno = -1;
	int contadorActivos = 0;

	if( pArrayPublicaciones != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if (pArrayPublicaciones[i].estadoPublicacion == ACTIVO && pArrayPublicaciones[i].isEmpty == FALSE)
			{
				contadorActivos++;
			}
		}
		if(contadorActivos == 0)
		{
			printf("No hay ninguna publicacion activa");
		}else
		{
			printf("La cantidad de publicaciones activas es %d", contadorActivos);

		}
		retorno = 0;
	}

	return retorno;
}

int sPublicacion_cantidadPublicacionesSegunRubro(sPublicacion* pArrayPublicacion, int limite)
{
	int retorno = -1;
	int indice;
	int contador = 0;
	if(pArrayPublicacion != NULL && limite > 0)
	{
		if(utn_getNumero("\nIngrese el numero del rubro que quiere investigar:\nOPCION 1: ADMINISTRACION\nOPCION 2: ATENCION AL CLIENTE\nOPCION 3: OPERARIO\n"
							,"\nEese rubro no existe",&indice, 2, 1, 3)== 0)
		{
			for(int i = 0; i < limite; i++)
			{
				if(pArrayPublicacion[i].numeroRubro == indice && pArrayPublicacion[i].isEmpty == FALSE)
				{
					contador++;
				}
			}
			if(contador == 0)
			{
				printf("Ese rubro no tiene publicaciones");
			}else
			{
				printf("La cantidad de publicaciones en ese rubro es %d", contador);

			}
		}
		retorno = 0;
	}
	return retorno;
}
