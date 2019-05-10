/*
 * Cartelera.cpp
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */

#include <iostream>
#include "Cartelera.h"
using namespace std;
using namespace cartelera;

Sesion::Sesion()
{
	this->hora = 0.0;
	this->plazas = 0;
}

Sesion::Sesion(int plazas, double hora)
{
	this->plazas = plazas;
	this->hora = hora;
}

int Sesion::getPlazas()
{
	return this->plazas;
}

void Sesion::setPlazas(int plazas)
{
	this->plazas = plazas;
}

double Sesion::getHora()
{
	return this->hora;
}

void Sesion::setHora(double hora)
{
	this->hora = hora;
}

