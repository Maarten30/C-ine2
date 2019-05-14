/*
 * Usuario.cpp
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */

#include <iostream>
#include <string>
#include "Usuario.h"

#include "menu.h"
using namespace std;
using namespace containers;

Usuario::Usuario():Persona()
{
	this->nomUsuario = "";
	this -> edad = 0;

}

Usuario::Usuario(string nomUs, string nombre, string ape, string dni, int edad):Persona(nombre,ape,dni)
{

	this->nomUsuario = nomUs;
	this->edad = edad;

}

string Usuario::getNombreUs()
{
	return this->nomUsuario;
}

int Usuario::getEdad()
{
	return this->edad;
}

void Usuario :: setNombreUs(string nombreUs)
{
	this ->nomUsuario = nombreUs;
}

void Usuario :: setEdad(int edad)
{
	this ->edad = edad;
}

void Usuario::imprimirMenu()
{

	cout<<endl;
	cout << "MENU USUARIO" <<endl;
	cout << "-------------------"<<endl;
	cout << "1. Ver cartelera" <<endl;
	cout << "2. Pelicula mas taquillera" <<endl;
	cout << "3. Descuentos" << endl;
	cout << "Introduzca una opcion del 1-3:"<<endl;
	cout << "Pulse '4' para salir"<<endl;

}
