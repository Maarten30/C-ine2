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

}

Usuario::Usuario(string nomUs, string nombre, string ape, string dni)
{

	this->nombre = nombre;
	this->apellido = ape;
	this->dni = dni;
	this->nomUsuario = nomUs;

}

string Usuario::getNombre()
{
	return this->nombre;
}









