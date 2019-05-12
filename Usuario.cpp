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

string Usuario::getNombre()
{
	return this->nombre;
}

string Usuario::getApellido()
{
	return this->apellido;
}

string Usuario::getNombreUs()
{
	return this->nomUsuario;
}

string Usuario::getDNI()
{
	return this->dni;
}

int Usuario::getEdad()
{
	return this->edad;
}







