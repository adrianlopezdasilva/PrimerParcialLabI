/*
 * informes.h
 *
 *  Created on: 2020/10/19
 *      Author: PC
 */
#include "utn.h"
#include "sPublicacion.h"
#include "sCliente.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int informe_clienteConMasPublicaciones(sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes);
int informe_clienteConMenosPublicaciones (sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes);
int informe_cantidadPublicacionesPausadas(sPublicacion* pArrayPublicaciones, int limite);
int informe_cantidadPublicacionesActivas(sPublicacion* pArrayPublicaciones, int limite);
int informe_cantidadPublicacionesSegunRubro(sPublicacion* pArrayPublicacion, int limite);
int informe_cantidadPublicacionesSegunCuit(sPublicacion* pArrayPublicacion, int limite, sCliente* pArrayCliente, int limiteCliente);
int informe_ImprimirListaDeRubrosDeMenorAMayor(sPublicacion* pArrayPublicaciones, int limite);
int informe_clienteConMenosPublicaciones (sPublicacion* pArrayPublicaciones,int limite, sCliente* pArrayClientes, int limiteClientes);
int informe_rubroConMasPublicaciones(sPublicacion* pArrayPublicaciones,int limite);
int informe_CalcularRubroRepetido(sPublicacion* pArrayPublicaciones, int limite, int numeroRubro, int* pResultado);
int informe_CalcularClienteRepetido(sPublicacion* pArrayPublicaciones,int  limite,int idCliente, int *pResultado);
#endif /* INFORMES_H_ */

