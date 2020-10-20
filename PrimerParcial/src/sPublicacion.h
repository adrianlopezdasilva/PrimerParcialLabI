/*
 * sPublicacion.h
 *
 *  Created on: 2020/10/12
 *      Author: PC
 */

#ifndef SPUBLICACION_H_
#define SPUBLICACION_H_
#include "sCliente.h"
#define SIZEPUBLICACION 40
#define PAUSADO 0
#define ACTIVO 1
#define TRUE 1
#define FALSE 0


typedef struct
{
	int idPublicacion;
	int isEmpty;
	int numeroRubro;
	char textoAviso[65];
	int estadoPublicacion;
	int idCliente;
}sPublicacion;

int sPublicacion_init(sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_buscarLibre(sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_altaPublicacion(sPublicacion *pArrayPublicacion, int limite, sCliente *pArrayCliente, int limiteCliente);
int sPublicacion_buscarLibreRef (sPublicacion *pArrayPublicacion, int limite, int *pIndice);
int sPublicacion_imprimirActivos (sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_imprimirPausados (sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_pausarPublicacion(sPublicacion *pArrayPublicacion, int limite, sCliente *pArrayCliente, int limiteCliente);
int sPublicacion_reanudarPublicacion(sPublicacion* pArrayPublicacion, int limite, sCliente* pArrayCliente, int limiteCliente);
int sPublicacion_modificar (sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_buscarIndicePorId (sPublicacion * pArrayPublicacion, int limite, int idBuscar,int * pIndice);
int sPublicacion_ImprimirPublicacionSegunCliente(sPublicacion *pArrayPublicacion, int limite, int idCliente);
int sPublicacion_cantidadPublicacionesActivas(sPublicacion* pArrayPublicacion,int limite,int id,int *pResultado);
int sPublicacion_imprimirClientesYPublicaciones(sPublicacion *pArrayPublicacion,int limite, sCliente *pArrayCliente,int limiteCliente);
int publicacion_altaForzada(sPublicacion* pArrayPublicacion, int limite ,int idCliente,int rubro,  char* publicacion);
int sPublicacion_imprimirClienteSegunPublicacion(sPublicacion *pArrayPublicacion, int limite, int idCliente, sCliente* pArrayCliente, int limiteCliente);
int sPublicacion_totalidadPublicacionesEnUnCliente(sPublicacion* pArrayPublicacion,int  limite,int  idCliente);
int sPublicacion_totalidadPublicacionesEnUnRubro(sPublicacion* pArrayPublicacion,int  limite,int  numeroRubro);
#endif /* SPUBLICACION_H_ */
