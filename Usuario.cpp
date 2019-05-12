/*
 * Usuario.cpp
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */

#include <iostream>
#include <string>
#include "Usuario.h"
using namespace std;
using namespace containers;

Usuario::Usuario()
{
	this->nomUsuario = "";
	this->nombre = "";
	this->apellido = "";
	this -> edad = 0;

}

Usuario::Usuario(string nomUs, string nombre, string ape, string dni, int edad)
{

	this->nombre = nombre;
	this->apellido = ape;
	this->dni = dni;
	this->nomUsuario = nomUs;
	this->edad = edad;

}

string Persona::getNombre()
{
	return this->nombre;
}

string Persona::getApellido()
{
	return this->apellido;
}

string Usuario::getNombreUs()
{
	return this->nomUsuario;
}

string Persona::getDNI()
{
	return this->dni;
}

int Usuario::getEdad()
{
	return this->edad;
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

void Usuario :: setNombreUs(string nombreUs)
{
	this ->nomUsuario = nombreUs;
}

void Usuario :: setEdad(int edad)
{
	this ->edad = edad;
}




