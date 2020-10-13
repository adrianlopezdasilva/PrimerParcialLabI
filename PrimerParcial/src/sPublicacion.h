/*
 * sPublicacion.h
 *
 *  Created on: 2020/10/12
 *      Author: PC
 */

#ifndef SPUBLICACION_H_
#define SPUBLICACION_H_

#define SIZEPUBLICACION 40

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
int sPublicacion_altaCliente(sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_buscarLibreRef (sPublicacion *pArrayPublicacion, int limite, int *pIndice);
int sPublicacion_imprimir (sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_bajaCliente(sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_modificar (sPublicacion *pArrayPublicacion, int limite);
int sPublicacion_buscarIndicePorId (sPublicacion * pArrayPublicacion, int limite, int idBuscar,int * pIndice);

#endif /* SPUBLICACION_H_ */
