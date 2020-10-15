/*
 * sCliente.h
 *
 *  Created on: 2020/10/12
 *      Author: PC
 */

#ifndef SCLIENTE_H_
#define SCLIENTE_H_

#define SIZECLIENTE 20
#define FALSE 0
#define TRUE 1

typedef struct
{
	int idCliente;
	int isEmpty;
	char nombre[SIZECLIENTE];
	char apellido[SIZECLIENTE];
	char cuit[SIZECLIENTE];
}sCliente;

int sCliente_init(sCliente *pArrayCliente, int limite);
int sCliente_buscarLibre(sCliente *pArrayCliente, int limite);
int sCliente_altaCliente(sCliente *pArrayCliente, int limite);
int sCliente_buscarLibreRef (sCliente *pArrayCliente, int limite, int *pIndice);
int sCliente_imprimir (sCliente *pArrayCliente, int limite);
int sCliente_bajaCliente(sCliente *pArrayCliente, int limite);
int sCliente_modificar (sCliente *pArrayCliente, int limite);
int sCliente_buscarIndicePorId (sCliente * pArrayCliente, int limite, int idBuscar,int * pIndice);



#endif /* SCLIENTE_H_ */
