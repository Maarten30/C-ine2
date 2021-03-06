/*
 * Fichero.cpp
 *
 *  Created on: May 10, 2019
 *      Author: maarten
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Cartelera.h"
#include "Fichero.h"
#include "Usuario.h"
#include "Gestor.h"
using namespace std;
using namespace cartelera;
using namespace containers;
using namespace gestor;

Cartelera leerCartelera(char *cine)
{

	Cartelera cart;
	FILE *f;
	char fichero[100];
	int numPelis = 0;

	strcpy(fichero, cine);
	strcat(fichero, "Cartelera.txt");

	f = fopen(fichero, "r");

	//cart.cine = malloc(sizeof(char)*TAMANYO_tit);

	numPelis = (lineasFichero(fichero)-1)/3;
	cart.setNumPelis(numPelis);

	Pelicula *pelis = new Pelicula[numPelis];

	//cart.peliculas = malloc(sizeof(Pelicula)*numPelis);

	char buff[255];
	string buff2 = "";
	double hora=0.0;
	int plazas = 0;
	int numSesiones = 0;

	fscanf(f, " %[^\t\n]s", buff);
	//strcpy(cart.cine, buff);
	buff2 = string(buff);

	cart.setCine(buff2);

	for(int i=0; i<numPelis; i++)
	{
		//cart.peliculas[i].titulo = malloc (sizeof(char)*TAMANYO_tit);
		fscanf(f, " %[^\t\n]s", buff);
		buff2.clear();
		buff2 = string(buff);
		//strcpy(cart.peliculas[i].titulo,buff);
		pelis[i].setTitulo(buff2);

		//cart.peliculas[i].descripcion = malloc (sizeof(char)*TAMANYO_descr);
		fscanf(f, " %[^\t\n]s", buff);
		buff2.clear();
		buff2 = string(buff);
		//strcpy(cart.peliculas[i].descripcion,buff);
		pelis[i].setDesc(buff2);

		fscanf(f, "%d", &numSesiones);

		//cart.peliculas[i].numSesiones = numSesiones;
		pelis[i].setNumSesiones(numSesiones);

		//cart.peliculas[i].sesiones = (Sesion*)malloc (sizeof(Sesion)*numSesiones);
		Sesion *sesiones= new Sesion[numSesiones];

		for(int j=0; j<numSesiones;j++)
		{
			fscanf(f, "%i", &plazas);
			fscanf(f, "%lf", &hora);
			//cart.peliculas[i].sesiones[j].plazas = plazas;
			sesiones[j].setPlazas(plazas);
			sesiones[j].setHora(hora);


		}

		pelis[i].setSesiones(sesiones);

	}

	cart.peliculas = pelis;

	return cart;
}

void GuardarUsuarios(vector <Usuario> users)
{

	FILE *f;

	f = fopen("USUARIOS.txt", "w+");

	fprintf(f, "USUARIOS");
	fprintf(f, "\n");

	for(Usuario a:users)
	{
		fprintf(f, "%s", a.getNombre().c_str());
		fprintf(f, "\n");
		fprintf(f, "%s", a.getApellido().c_str());
		fprintf(f, "\n");
		fprintf(f, "%i", a.getEdad());
		fprintf(f, "\n");
		fprintf(f, "%s", a.getNombreUs().c_str());
		fprintf(f, "\n");
		fprintf(f, "%s", a.getDNI().c_str());
		fprintf(f, "\n");

	}
	fclose(f);
}

vector<Usuario> leerUsuarios()
{
	vector <Usuario> users;
	FILE *f;
	int numUsuarios = 0;

	f = fopen("USUARIOS.txt", "r");

	numUsuarios = (lineasFichero("USUARIOS.txt")-1)/5;

//	cout << "numUsuarios: " << numUsuarios<< endl;

	char buff[255];
	string nombre = "";
	string apellido = "";
	int edad = 0;
	string nomUs = "";
	string dni = "";

	fscanf(f, " %[^\t\n]s", buff);

	for(int i=0; i<numUsuarios; i++)
	{
		fscanf(f, " %[^\t\n]s", buff);
		nombre = string(buff);

		fscanf(f, " %[^\t\n]s", buff);
		apellido = string(buff);

		fscanf(f, "%i", &edad);

		fscanf(f, " %[^\t\n]s", buff);
		nomUs = string(buff);

		fscanf(f, " %[^\t\n]s", buff);
		dni = string(buff);

		Usuario* us = new Usuario(nomUs, nombre, apellido, dni, edad);

		users.push_back(*us);

	}

	return users;
}

void GuardarGestores(vector <Gestor> gestores)
{

	FILE *f;

	f = fopen("GESTORES.txt", "w+");

	fprintf(f, "GESTORES");
	fprintf(f, "\n");

	for(Gestor a:gestores)
	{
		fprintf(f, "%s", a.getNombre().c_str());
		fprintf(f, "\n");
		fprintf(f, "%s", a.getApellido().c_str());
		fprintf(f, "\n");
		fprintf(f, "%s", a.getDNI().c_str());
		fprintf(f, "\n");
		fprintf(f, "%i", a.getCodigo());
		fprintf(f, "\n");

	}
	fclose(f);
}

vector<Gestor> leerGestores()
{

	vector <Gestor> gestores;
	FILE *f;
	int numGestores = 0;

	f = fopen("GESTORES.txt", "r");

	numGestores = (lineasFichero("GESTORES.txt")-1)/4;

	char buff[255];
	string nombre = "";
	string apellido = "";
	string dni = "";
	int codigo = 0;

	fscanf(f, " %[^\t\n]s", buff);


	for(int i=0; i<numGestores; i++)
	{

		fscanf(f, " %[^\t\n]s", buff);
		nombre = string(buff);

		fscanf(f, " %[^\t\n]s", buff);
		apellido = string(buff);

		fscanf(f, " %[^\t\n]s", buff);
		dni = string(buff);

		fscanf(f, "%i", &codigo);

		Gestor* ges = new Gestor(nombre, apellido, dni, codigo);

		gestores.push_back(*ges);

	}

	return gestores;
}

bool fexists(const char *filename)
{
	std::ifstream ifile(filename);
  return (bool)ifile;
}

int lineasFichero(char *fichero)
{
    FILE *fileptr;
    int count_lines = 0;
    char chr;

    fileptr = fopen(fichero, "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
    fclose(fileptr); //close file.

    return count_lines;
}
