/*
 * Gestor.cpp
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */
/*
 * gestor.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */

//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include "Cartelera.h"
//using namespace std;
//#include <string.h>
//#include "gestor.h"
//using namespace gestor;
//using namespace cartelera;
//#define TAMANYO_tit = 100
//
//Gestor:: Gestor()
//{
//	this->nombre = "";
//	this->apellido = "";
//	this->dni = "";
//	this->codigo = 0;
//}
//Gestor:: Gestor(string nombre, string apellido,string dni, int codigo)
//{
//	this->nombre = nombre;
//	this->apellido = apellido;
//	this->dni = dni;
//	this->codigo = codigo;
//}
//
//void menuGestor()
//{
//	char caracter;
//	char caracter2;
//	Pelicula peli;
//
//	do
//	{
//		printf("Menu Gestor: \n");
//		printf("1.- Editar cartelera\n2.- Crear cartelera\n3.- Pulse 'q' para volver a menu principal\n");
//		scanf(" %c", &caracter);
//		printf("%c\n", caracter);
//		if(caracter == '1')
//		{
//			printf("Elija el cine que quiera editar:\n");
//			char *nombrecart;
//			char *nombrecart2 = malloc(100*sizeof(char));
//			nombrecart = malloc(100*sizeof(char));
//			scanf("%s", nombrecart);
//			strcpy(nombrecart2, nombrecart);
//			for (int i = 0; i < strlen(nombrecart); i++)
//			{
//			    nombrecart[i] = toupper(nombrecart[i]);
//			    nombrecart2[i] = toupper(nombrecart2[i]);
//			}
//			strcat(nombrecart, "Cartelera.txt");
//			int existe = exists(nombrecart);
//
//			if (existe ==0)
//			{
//				printf("El cine introducido no existe, vuelva a introducirlo:\n");
//				menuGestor();
//			}
//			else
//			{
//				Cartelera cartelerita = leerCartelera(nombrecart2);
//				printf("1.- Anyadir pelicula \n2.- Retirar pelicula\n3.- Restaurar Plazas\n");
//				scanf(" %c", &caracter2);
//
//				if(caracter2 == '1')
//				{
//					Pelicula peli1;
//					int sesiones = 0;
//					double hora = 0.0;
//					char *titulo=malloc(100*sizeof(char));
//					char *descr = malloc(200*sizeof(char));
//					fflush(stdin);
//
//					printf("Inserte el nombre de la pelicula que desee anyadir\n");
//
//					scanf(" %[^\t\n]s", titulo);
//					peli1.titulo = malloc((strlen(titulo)+1)*sizeof(char));
//					peli1.titulo = strcpy(peli1.titulo, titulo);
//
//					free(titulo);
//					titulo=NULL;
//
//					fflush(stdin);
//
//					printf("Inserte la descripcion de la pelicula %s\n", peli1.titulo);
//					//fgets(descr,TAMANYO_descr,stdin);
//					scanf(" %[^\t\n]s", descr);
//
//					peli1.descripcion = malloc((strlen(descr)+1)*sizeof(char));
//					peli1.descripcion = strcpy(peli1.descripcion, descr);
//
//					free(descr);
//					descr=NULL;
//
//					printf("Cuantas sesiones diarias quiere tener de la pelicula %s?\n", peli1.titulo);
//					scanf("%i", &sesiones);
//
//					peli1.sesiones = malloc(sizeof(Sesion)*sesiones);
//					peli1.numSesiones = sesiones;
//
//					for(int i=0; i<sesiones; i++)
//					{
//						printf("Introduzca la hora de la sesion %i:\n", i+1);
//						scanf("%lf", &hora);
//						peli1.sesiones[i].hora = hora;
//						peli1.sesiones[i].plazas = 22;
//					}
//
//					anyadirPelicula(&cartelerita, peli1);
//					free(nombrecart);
//					nombrecart=NULL;
//				}
//				else if (caracter2=='2')
//				{
//					int indice=0;
//
//					printf("Escoja la pelicula a borrar\n");
//
//					for(int i=0; i<cartelerita.numPelis; i++)
//					{
//						printf("Titulo: %s\n", cartelerita.peliculas[i].titulo);
//					}
//
//					char *titulo = malloc(sizeof(char)*100);
//					scanf(" %[^\t\n]s", titulo);
//
//					for (int i = 0; i < strlen(titulo); i++)
//					{
//						titulo[i] = toupper(titulo[i]);
//					}
//					char *titulo2= malloc(sizeof(char)*100);
//
//					for(int i=0; i<cartelerita.numPelis; i++)
//					{
//						strcpy(titulo2, cartelerita.peliculas[i].titulo);
//						for (int j = 0; j < strlen(titulo2); j++)
//						{
//							titulo2[j] = toupper(titulo2[j]);
//						}
//						if(strcmp(titulo, titulo2) == 0)
//						{
//							indice=i;
//							break;
//						}
//					}
//
//					ficheroCarteleraBorrado(cartelerita, indice);
//					free(titulo);
//					titulo=NULL;
//					free(titulo2);
//					titulo2=NULL;
//
//			}
//			else if(caracter2 == '3')
//			{
//				for(int i=0; i<cartelerita.numPelis; i++)
//				{
//					for(int j=0; j<cartelerita.peliculas[i].numSesiones; j++)
//					{
//						cartelerita.peliculas[i].sesiones[j].plazas = 22;
//					}
//				}
//
//				ficheroCartelera(cartelerita);
//			}
//			}
//		}
//		else if(caracter == '2')
//		{
//			NuevaCartelera();
//		}
//
//	}
//	while(caracter!='q');
//}
//
//void NuevaCartelera()
//{
//	Cartelera *cart = malloc(sizeof(Cartelera));
//
//	char cine[100];
//	char aux[100];
//	printf("Introduzca el nombre del cine: \n");
//	scanf("%s", aux);
//	strcpy(cine,aux);
//	int existe = exists(strcat(aux, "Cartelera.txt"));
//	if (existe ==1)
//	{
//		printf("Esta cartelera ya existe.\n");
//		menuGestor();
//	}
//	else
//	{
//		char numPelis[20];
//		int numPelis2;
//		printf("Introduzca el numero de peliculas que desea anyadir a la cartelera: \n");
//		scanf("%s", numPelis);
//		numPelis2 = atoi(numPelis);
//		if (numPelis2!=0)
//		{
//			cart->cine = malloc (sizeof(char)*100);
//			strcpy(cart->cine, cine);
//
//			cart->numPelis = numPelis2;
//
//			cart->peliculas = malloc(sizeof(Pelicula)*numPelis2);
//
//			char titulo[100];
//			char desc[200];
//			int longitud = 0;
//			int longitud2 = 0;
//			int sesiones = 0;
//			double hora = 0.0;
//
//			for(int i=0; i<cart->numPelis; i++)
//			{
//				printf("Introduzca el titulo de la pelicula: \n");
//				scanf(" %[^\t\n]s", titulo);
//				longitud = strlen(titulo);
//
//				printf("Introduzca una breve descripcion sobre la pelicula: \n");
//				scanf(" %[^\t\n]s", desc);
//				longitud2 = strlen(desc);
//
//				printf("Cuantas sesiones diarias quiere tener de la pelicula %s?\n", titulo);
//				scanf("%i", &sesiones);
//
//				cart->peliculas[i].sesiones = malloc(sizeof(Sesion)*sesiones);
//				cart->peliculas[i].numSesiones = sesiones;
//
//				for(int j=0; j<sesiones; j++)
//				{
//					printf("Introduzca la hora de la sesion %i:\n", j+1);
//					scanf("%lf", &hora);
//					cart->peliculas[i].sesiones[j].hora = hora;
//					cart->peliculas[i].sesiones[j].plazas = 22;
//				}
//
//				cart->peliculas[i].titulo= malloc (sizeof(char)*(longitud+1));
//				cart->peliculas[i].descripcion = malloc (sizeof(char)*(longitud2+1));
//
////				strcpy(cart->peliculas[i].titulo, titulo);
////				strcpy(cart->peliculas[i].descripcion, desc);
//
//			}
//			ficheroCartelera(*cart);
//		}
//		else
//		{
//			printf("�Error! Debe introducir un numero.!Vuelva a intentarlo!\n");
//			menuGestor();
//		}
//	}
//}
//
//int exists(const char *fname)
//{
//    FILE *file;
//    if ((file = fopen(fname, "r")))
//    {
//        fclose(file);
//        return 1;
//    }
//    return 0;
//}
//
//
//
//
//
