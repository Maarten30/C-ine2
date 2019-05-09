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

#include <iostream>
//#include "pelicula.h"
//#include "cartelera.h"
using namespace std;
#include <string>
#include "gestor.h"
using namespace gestor;

Gestor:: Gestor()
{
	this->nombre = "";
	this->apellido = "";
	this->dni = "";
	this->codigo = 0;
}
Gestor:: Gestor(string nombre, string apellido,string dni, int codigo)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->dni = dni;
	this->codigo = codigo;
}

void menuGestor()
{
}

void NuevaCartelera()
{
}

int exists(const char *fname)
{
}





