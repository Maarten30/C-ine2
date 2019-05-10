/*
 * Fichero.cpp
 *
 *  Created on: May 10, 2019
 *      Author: maarten
 */
#include <iostream>
#include "Cartelera.h"
using namespace std;
using namespace cartelera;


//Cartelera leerCartelera(char *cine)
//{
//
//
//
//	Cartelera cart;
//	FILE *f;
//	char fichero[100];
//	int numPelis = 0;
//
//	strcpy(fichero, cine);
//	strcat(fichero, "Cartelera.txt");
//
//	f = fopen(fichero, "r");
//
//	cart.cine = malloc(sizeof(char)*TAMANYO_tit);
//
//	numPelis = (lineasFichero(fichero)-1)/3;
//	cart.numPelis = numPelis;
//
//	cart.peliculas = malloc(sizeof(Pelicula)*numPelis);
//
//	char buff[255];
//	double hora=0.0;
//	int plazas = 0;
//	int numSesiones = 0;
//
//	fscanf(f, " %[^\t\n]s", buff);
//	strcpy(cart.cine, buff);
//
//	for(int i=0; i<numPelis; i++)
//	{
//		cart.peliculas[i].titulo = malloc (sizeof(char)*TAMANYO_tit);
//		fscanf(f, " %[^\t\n]s", buff);
//		strcpy(cart.peliculas[i].titulo,buff);
//
//		cart.peliculas[i].descripcion = malloc (sizeof(char)*TAMANYO_descr);
//		fscanf(f, " %[^\t\n]s", buff);
//		strcpy(cart.peliculas[i].descripcion,buff);
//
//		fscanf(f, "%d", &numSesiones);
//
//		cart.peliculas[i].numSesiones = numSesiones;
//
//		cart.peliculas[i].sesiones = (Sesion*)malloc (sizeof(Sesion)*numSesiones);
//
//		for(int j=0; j<numSesiones;j++)
//		{
//			fscanf(f, "%i", &plazas);
//			fscanf(f, "%lf", &hora);
//			cart.peliculas[i].sesiones[j].plazas = plazas;
//			cart.peliculas[i].sesiones[j].hora = hora;
//		}
//	}
//	return cart;
//}
