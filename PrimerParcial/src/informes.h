/*
 * informes.h
 *
 *  Created on: 2020/10/19
 *      Author: PC
 */

#ifndef INFORMES_H_
#define INFORMES_H_

void menuInformes();
int informe_clienteConMasPublicaciones(sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes, int *cantidad);
int informe_cantidadPublicacionesPausadas(sPublicacion* pArrayPublicaciones, int limite);
int informe_cantidadPublicacionesActivas(sPublicacion* pArrayPublicaciones, int limite);
int sPublicacion_cantidadPublicacionesSegunRubro(sPublicacion* pArrayPublicacion, int limite);
int sPublicacion_cantidadPublicacionesSegunCuit(sPublicacion* pArrayPublicacion, int limite, sCliente* pArrayCliente, int limiteCliente);
#endif /* INFORMES_H_ */

