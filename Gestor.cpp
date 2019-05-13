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
#include <string.h>
#include "Gestor.h"
using namespace gestor;
using namespace std;


Gestor::Gestor():Persona()
{
	this->codigo = 0;
}

Gestor::Gestor(string nombre, string apellido, string dni, int codigo):Persona(nombre, apellido, dni)
{
	this ->codigo=codigo;
}

int Gestor::getCodigo()
{
	return this->codigo;
}

void Gestor::setCodigo(int codigo)
{
	this->codigo=codigo;
}
void Gestor::imprimirMenu()
{
	cout<<endl;
	cout << "MENU GESTOR" <<endl;
	cout << "-------------------"<<endl;
	cout << "1. Media de edad" <<endl;
	cout << "2. Pelicula mas taquillera" <<endl;
	cout << "Introduzca una opcion del 1-2:"<<endl;
	cout << "Pulse 'q' para salir"<<endl;
}

