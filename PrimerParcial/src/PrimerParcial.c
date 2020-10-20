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
#include "sPublicacion.h"
#include "sCliente.h"
#include "informes.h"

#define CANTIDAD_CLIENTES 10
#define CANTIDAD_PUBLICACIONES 20

int main(void)
{
	setbuf(stdout, NULL);
	sCliente arrayCliente[CANTIDAD_CLIENTES];
	sPublicacion arrayPublicacion[CANTIDAD_PUBLICACIONES];
	int opcion;
	int opcionInformes;

	sCliente_init(arrayCliente,CANTIDAD_CLIENTES );
	sPublicacion_init( arrayPublicacion, CANTIDAD_PUBLICACIONES);

	cliente_altaForzada(arrayCliente, CANTIDAD_CLIENTES,"Roberto","Perez","203943849");
	cliente_altaForzada(arrayCliente, CANTIDAD_CLIENTES,"aaaaa","bbbbb","203943848");
	cliente_altaForzada(arrayCliente, CANTIDAD_CLIENTES,"ccccc","ccccc","203943845");
	cliente_altaForzada(arrayCliente, CANTIDAD_CLIENTES,"dddddd","ddddd","203943846");
	cliente_altaForzada(arrayCliente, CANTIDAD_CLIENTES,"eeeeee","eeeee","2203943843");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,1,2,"Se busca");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,2,1,"Con urgencia");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,3,2,"Inmediatamente");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,4,1,"Se solicita");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,1,1,"Se emplea");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,2,2,"Se necesita");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,2,2,"Buscamos");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,3,1,"Urgente ");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,2,2,"De urgencia");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,4,1,"Con experiencia");
	publicacion_altaForzada(arrayPublicacion, CANTIDAD_PUBLICACIONES,5,2,"Sin experiencia");

		do
		{if(utn_getNumero("\n\nMenu de opciones"
							"\n1-Dar de alta un cliente "
							"\n2-Modificar un cliente"
							"\n3-Dar de baja un cliente"
							"\n4-Dar de alta una publicacion"
							"\n5-Pausar una publicacion"
							"\n6-Reanudar una publicacion"
							"\n7-imprimir lista "
							"\n8-Informes"
							"\n9-Salir\n","Error,opcion invalida\n",&opcion, 20, 1, 9)== 0)
				{
					switch(opcion)
					{
						case 1:
							if(sCliente_buscarLibre(arrayCliente, CANTIDAD_CLIENTES) != -1)
							{
								sCliente_altaCliente(arrayCliente, CANTIDAD_CLIENTES);
								printf("\nCarga realizada con exito");

							}
							else
							{
								printf("\nNo hay mas lugar");
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
						case 4:
							if(sPublicacion_altaPublicacion(arrayPublicacion, CANTIDAD_PUBLICACIONES,arrayCliente, CANTIDAD_CLIENTES) ==0)
							{
								printf("\nPublicacion realizada con exito\n");
							}
							break;
						case 5:
							sPublicacion_pausarPublicacion(arrayPublicacion, CANTIDAD_PUBLICACIONES,arrayCliente, CANTIDAD_CLIENTES);

							break;
						case 6:
							sPublicacion_reanudarPublicacion(arrayPublicacion, CANTIDAD_PUBLICACIONES,arrayCliente, CANTIDAD_CLIENTES);

							break;
						case 7:
							if(sPublicacion_imprimirClientesYPublicaciones(arrayPublicacion, CANTIDAD_PUBLICACIONES,arrayCliente, CANTIDAD_CLIENTES) !=0)
							{
								printf("\nNo hay clientes para mostrar");
							}
							break;
						case 8:
							do{
								if(utn_getNumero("\n\nMenu de informes"
											"\n1-Cliente con la mayor cantidad de publicaciones "
											"\n2-Cantidad de publicaciones pausadas"
											"\n3-Calcular el rubro con mayor cantidad de publicaciones"
											"\n4-Ordenar los rubros de menor a mayor"
											"\n5-Cantidad de publicaciones activas"
											"\n6-Cliente con la menor cantidad de publicaciones"
											"\n7-Cantidad de publicaciones segun rubro"
											"\n8-Cantidad de publicaciones segun cuit"
											"\n9-Salir\n","Error,opcion invalida\n",&opcionInformes, 4, 1, 9)== 0)
								{
									switch(opcionInformes)
									{
									case 1:
										informe_clienteConMasPublicaciones(arrayPublicacion, CANTIDAD_PUBLICACIONES,arrayCliente, CANTIDAD_CLIENTES);
										break;
									case 2:
										informe_cantidadPublicacionesPausadas(arrayPublicacion, CANTIDAD_PUBLICACIONES);
										break;
									case 3:
										informe_rubroConMasPublicaciones(arrayPublicacion, CANTIDAD_PUBLICACIONES);
										break;
									case 4:
										informe_ImprimirListaDeRubrosDeMenorAMayor(arrayPublicacion, CANTIDAD_PUBLICACIONES);
										break;
									case 5:
										informe_cantidadPublicacionesActivas(arrayPublicacion, CANTIDAD_PUBLICACIONES);
										break;
									case 6:
										informe_clienteConMenosPublicaciones(arrayPublicacion, CANTIDAD_PUBLICACIONES,arrayCliente, CANTIDAD_CLIENTES);
										break;
									case 7:
										informe_cantidadPublicacionesSegunRubro(arrayPublicacion, CANTIDAD_PUBLICACIONES);
										break;
									case 8:
										 //informe_cantidadPublicacionesSegunCuit(arrayPublicacion, CANTIDAD_PUBLICACIONES,arrayCliente, CANTIDAD_CLIENTES);
										 break;
										}
								}

								} while(opcionInformes != 9);
								break;
					}
			}

		}while(opcion !=9);

}
