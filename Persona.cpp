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

string Persona::getNombre()
{
	return this->nombre;
}

string Persona::getApellido()
{
	return this->apellido;
}

string Persona::getDNI()
{
	return this->dni;
}

void Persona::setNombre(string nombre)
{
	this ->nombre = nombre;
}

void Persona::setApellido(string apellido)
{
	this ->apellido = apellido;
}

void Persona::setDni(string dni)
{
	this ->dni = dni;
}

Persona::~Persona(){

}
