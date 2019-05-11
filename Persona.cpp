/*
 * Persona.cpp
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */
#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;
using namespace persona;

Persona:: Persona()
{
	this->nombre = "";
	this->apellido = "";
	this->dni = "";
}

Persona:: Persona(string nombre, string apellido, string dni)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->dni = dni;
}

//Persona::~Persona()
//{
//
//}




