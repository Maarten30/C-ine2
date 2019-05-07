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

Usuario::Usuario(string nomUs, string nombre, string ape)
{
	this->nomUsuario = nomUs;
	this->nombre = nombre;
	this->apellido = ape;
}






