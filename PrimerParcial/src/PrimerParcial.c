/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "sCliente.h"

#define CANTIDAD_CLIENTES 2

int main(void)
{
	setbuf(stdout, NULL);
	sCliente arrayCliente[CANTIDAD_CLIENTES];
	int opcion;

	if(sCliente_init(arrayCliente,CANTIDAD_CLIENTES ) == 0)
	{
		do
		{if(utn_getNumero("\nMenu de opciones"
							"\n1-Dar de alta un cliente "
							"\n2-Modificar un cliente"
							"\n3-Dar de baja un cliente"
							"\n4-"
							"\n7-imprimir lista "
							"\n8-salir\n","Error,opcion invalida\n",&opcion, 20, 1, 8)== 0)
				{
					switch(opcion)
					{
						case 1:
							if(sCliente_altaCliente(arrayCliente, CANTIDAD_CLIENTES)==0)
							{
								printf("\nCarga realizada correctamente\n");
							}
							else
							{
								printf("No hay mas lugar\n");
							}
							break;
						case 2:
							if(	sCliente_modificar(arrayCliente, CANTIDAD_CLIENTES)==0)
							{
								printf("\nModificacion realizada con exito");
							}
							break;
						case 3:
							if(sCliente_bajaCliente(arrayCliente, CANTIDAD_CLIENTES)==0)
							{
							printf("\nBaja realizada con exito");
							}
							break;

						case 7:
							sCliente_imprimir(arrayCliente, CANTIDAD_CLIENTES);

					}
				}
		}while(opcion !=8);
	}
}


