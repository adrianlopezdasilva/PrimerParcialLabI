/*
 * informes.c
 *
 *  Created on: 2020/10/19
 *      Author: PC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "utn.h"
#include "sPublicacion.h"
#include "sCliente.h"

/**
 * \brief Compara la cantidad de publicaciones que tiene cada cliente e imprime por pantalla el de mayor numero
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El limite de larray de publicaciones
 * \param pArrayCliente Puntero al array de clientes
 * \param limiteCliente El limite del array de clientes
 * \return (-1) Error / (0) Ok
 *
 */

int informe_clienteConMasPublicaciones (sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes)
{
	int i;
	int retorno = -1;
	int contadorPublicaciones;
	int mayorPublicaciones;
	if(pArrayPublicaciones != NULL && pArrayClientes != NULL && limite >0 && limiteClientes > 0)
	{
		sPublicacion_imprimirClientesYPublicaciones(pArrayPublicaciones, limite, pArrayClientes, limiteClientes);
		for ( i = 0; i <limiteClientes; i++)
		{
			if(pArrayClientes[i].isEmpty == FALSE)
			{
				contadorPublicaciones = sPublicacion_totalidadPublicacionesEnUnCliente
										(pArrayPublicaciones, limite, pArrayClientes[i].idCliente);
				if(i == 0)
				{
					mayorPublicaciones = contadorPublicaciones;
				}
				else if (contadorPublicaciones > mayorPublicaciones)
				{
					mayorPublicaciones = contadorPublicaciones;
				}
			 }
		 }
		printf("\nEl cliente con mayor publicaciones es el ID: %d con %d publicaciones"
				,pArrayClientes[i].idCliente, mayorPublicaciones);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Compara la cantidad de publicaciones que tiene cada cliente e imprime por pantalla el de meor numero
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El limite de larray de publicaciones
 * \param pArrayCliente Puntero al array de clientes
 * \param limiteCliente El limite del array de clientes
 * \return (-1) Error / (0) Ok
 *
 */
int informe_clienteConMenosPublicaciones (sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes)
{
	int i;
	int retorno = -1;
	int contadorPublicaciones;
	int menorPublicaciones;
	if(pArrayPublicaciones != NULL && pArrayClientes != NULL && limite >0 && limiteClientes > 0)
	{
		for ( i = 0; i <limiteClientes; i++)
		{
			if(pArrayClientes[i].isEmpty == FALSE)
			{
				contadorPublicaciones = sPublicacion_totalidadPublicacionesEnUnCliente
										(pArrayPublicaciones, limite, pArrayPublicaciones[i].idCliente);
				if(i == 0)
				{
					menorPublicaciones = contadorPublicaciones;
				}
				else if (contadorPublicaciones < menorPublicaciones)
				{
					menorPublicaciones = contadorPublicaciones;
				}
			}
		}
		printf("\nEl cliente con menor publicaciones es el ID: %d con %d publicaciones",pArrayPublicaciones[i].idCliente, menorPublicaciones);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Cuenta las cantidas de publicaciones pausadas totatles y lo imprime por pantalla
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El limite del array de publicaciones
 * \return 1- si error, 0 si ok
 *
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

/**
 * \brief Cuenta las cantidad de publicaciones activas totales y lo imprime por pantalla
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El limite del array de publicaciones
 * \return (-1) Error / (0) Ok
 *
 */

int informe_cantidadPublicacionesActivas(sPublicacion* pArrayPublicaciones, int limite)
{
	int retorno = -1;
	int contadorActivos = 0;

	if( pArrayPublicaciones != NULL && limite > 0)
	{
		sPublicacion_imprimirActivos(pArrayPublicaciones, limite);
		for(int i = 0; i < limite; i++)
		{
			if (pArrayPublicaciones[i].estadoPublicacion == ACTIVO && pArrayPublicaciones[i].isEmpty == FALSE)
			{
				contadorActivos++;
			}
		}
		if(contadorActivos == 0)
		{
			printf("\nNo hay ninguna publicacion activa\n");
		}else
		{
			printf("\n\nLa cantidad de publicaciones activas es %d\n", contadorActivos);

		}
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief Cuenta las cantidad de publicaciones que tiene un rubro y lo imprime por pantalla
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite Acota el numero de publicaciones
 * \return (-1) Error / (0) Ok
 *
 */
int informe_cantidadPublicacionesSegunRubro(sPublicacion* pArrayPublicaciones, int limite)
{
	int retorno = -1;
	int indice;
	int contador = 0;
	if(pArrayPublicaciones != NULL && limite > 0)
	{
		sPublicacion_imprimirActivos(pArrayPublicaciones, limite);
		if(utn_getNumero("\n\nIngrese el numero del rubro que quiere investigar:\nOPCION 1: ADMINISTRACION\nOPCION 2: ATENCION AL CLIENTE\nOPCION 3: OPERARIO\n\n"
							,"\nEse rubro no existe\n",&indice, 2, 1, 3)== 0)
		{
			for(int i = 0; i < limite; i++)
			{
				if(pArrayPublicaciones[i].numeroRubro == indice && pArrayPublicaciones[i].isEmpty == FALSE)
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
/**
 * \brief Cuenta las cantidad de publicaciones que tiene un cuit y lo imprime por pantalla
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El limite del array de publicaciones
 * \param pArrayCliente Puntero al array de clientes
 * \param limiteCliente Ell imite del array de clientes
 * \return (-1) Error / (0) Ok
 *
 */
/*
int informe_cantidadPublicacionesSegunCuit(sPublicacion* pArrayPublicaciones, int limite, sCliente* pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	char auxIndice[SIZECLIENTE];
	char indice[SIZECLIENTE];
	int contador = 0;
	if(pArrayPublicaciones != NULL && limite > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		sCliente_imprimir(pArrayCliente, limiteCliente);
		if(utn_getString("\nIngrese el cuit del cliente al que quiere investigar:"
							,"\nEese cuit no existe",auxIndice, 2, SIZECLIENTE)== 0 &&
			sCliente_buscarClientePorCuit(pArrayCliente, limite,auxIndice,indice)== 0)
		{

			for(int i = 0; i < limite; i++)
			{

				if(pArrayCliente[i].cuit == indice && pArrayPublicaciones[i].isEmpty == FALSE)
				{
					contador++;
				}
			}
			if(contador == 0)
			{
				printf("Este cliente no tiene publicaciones");
			}else
			{
				printf("La cantidad de publicaciones de ese cliente es %d", contador);
			}
		}
		retorno = 0;
	}
	return retorno;
}
 */
/**
 * \brief Ordena la lista de rubros de menor a mayor, utilizando el textoAviso como segundo critero para ordenar en caso de empate
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El limite de larray de publicaciones
 * \return (-1) Error / (0) Ok
 *
 */
int informe_ImprimirListaDeRubrosDeMenorAMayor(sPublicacion* pArrayPublicaciones, int limite)
{
	int retorno = -1;
	int flagConfirmar = 2;

	if(pArrayPublicaciones != NULL && limite > 0)
	{
		sPublicacion_imprimirActivos(pArrayPublicaciones, limite);
		utn_getNumero("\nConfirma reordenar segun rubro? \n1 = SI \n2 = NO\n","No es una opcion valida",&flagConfirmar,3,1,2);
		if(flagConfirmar == 1)
		{
			int i;
			int j;
			sPublicacion bufferPublicaciones;

			for(i=0; i<limite-1; i++)
			 {
				for(j=i+1; j<limite; j++)
				{
					 if(pArrayPublicaciones[i].numeroRubro >
						pArrayPublicaciones[j].numeroRubro)
					 {
						  bufferPublicaciones = pArrayPublicaciones[i];
						  pArrayPublicaciones[i] = pArrayPublicaciones[j];
						  pArrayPublicaciones[j] = bufferPublicaciones;
					 }
					 else
					{
						if(pArrayPublicaciones[i].numeroRubro == pArrayPublicaciones[j].numeroRubro)
						{
							if(strcmp(pArrayPublicaciones[i].textoAviso,pArrayPublicaciones[j].textoAviso)>0)
							 {
								bufferPublicaciones = pArrayPublicaciones[i];
								pArrayPublicaciones[i] = pArrayPublicaciones[j];
								pArrayPublicaciones[j] = bufferPublicaciones;
							 }
						 }
					 }
				 }

			 }
			sPublicacion_imprimirActivos(pArrayPublicaciones, limite);
			printf("\n Reordenamiento logrado con exito");
			retorno = 0;
		}
		else
		{
			printf("Operacion abortada");
		}
	}
	return retorno;
}

/**
 * \brief Compara la cantidad de publicaciones que tiene cada rubro e imprime por pantalla el de mayor numero, con sus cantidad
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El limite del array de publicaciones
 * \return (-1) Error / (0) Ok
 *
 */
int informe_rubroConMasPublicaciones(sPublicacion* pArrayPublicaciones,int limite)
{
	int retorno = -1;
	int contadorPublicaciones;
	int mayorPublicaciones;
	int auxiliarRubro;

	if(pArrayPublicaciones != NULL  && limite >0)
	{
		sPublicacion_imprimirActivos(pArrayPublicaciones, limite);
		for (int  i = 0; i <limite; i++)
		{
			if(pArrayPublicaciones[i].isEmpty == FALSE &&
				informe__CalcularRubroRepetido(pArrayPublicaciones, limite,
									pArrayPublicaciones[i].numeroRubro, &contadorPublicaciones) ==0)
			{

				if(i == 0 || contadorPublicaciones > mayorPublicaciones)
				{
					mayorPublicaciones = contadorPublicaciones;
					auxiliarRubro = pArrayPublicaciones[i].numeroRubro;
					retorno = 0;
				}
			}

		}
		printf("\n\nEl rubro con mayor publicaciones es el %d con %d publicaciones\n",auxiliarRubro, contadorPublicaciones);
	}else
	{
		printf("No hay publicaciones cargadas");
	}
	return retorno;
}


int informe_clienteConMasPublicacione (sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes)
{
	int i;
	int retorno = -1;
	int contadorPublicaciones;
	int mayorPublicaciones;
	if(pArrayPublicaciones != NULL && pArrayClientes != NULL && limite >0 && limiteClientes > 0)
	{
		sPublicacion_imprimirClientesYPublicaciones(pArrayPublicaciones, limite, pArrayClientes, limiteClientes);
		for ( i = 0; i <limiteClientes; i++)
		{
			if(pArrayClientes[i].isEmpty == FALSE)
			{
				contadorPublicaciones = sPublicacion_totalidadPublicacionesEnUnCliente
										(pArrayPublicaciones, limite, pArrayPublicaciones[i].idCliente);
				if(i == 0)
				{
					mayorPublicaciones = contadorPublicaciones;
				}
				else if (contadorPublicaciones > mayorPublicaciones)
				{
					mayorPublicaciones = contadorPublicaciones;
				}
			 }
		 }
		printf("\nEl cliente con mayor publicaciones es el ID: %d con %d publicaciones",pArrayPublicaciones[i].idCliente, mayorPublicaciones);
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Calcula la cantidad de veces que aparece repetido un mismo rubro en la lista de publicaciones
 * \param pArrayPublicacion Puntero al array de publicaciones
 * \param limite El campo numeroRubro del array de publicaciones
 * \param limite El limite del array de publicaciones
 * \param pResultado El puntero a donde se va a guardar el contador
 * \return (-1) Error / (0) Ok
 *
 */
int informe__CalcularRubroRepetido(sPublicacion* pArrayPublicaciones, int limite, int numeroRubro, int* pResultado)
{
	int retorno = -1;
	int contador = 0;
	if (pArrayPublicaciones != NULL && limite > 0 && numeroRubro > 0 && pResultado !=NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayPublicaciones[i].isEmpty == FALSE && pArrayPublicaciones[i].numeroRubro == numeroRubro)
			{
				contador++;
			}
		}
		*pResultado = contador;
		retorno = 0;
	}

	return retorno;
}
