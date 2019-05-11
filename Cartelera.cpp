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


//Clase Sesion
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



//Clase Pelicula
Pelicula::Pelicula()
{
	this->titulo ="";
	this->descripcion = "";
	this->numSesiones = 0;
	this->sesiones = NULL;
}

string Pelicula::getDesc()
{
	return this->descripcion;
}

void Pelicula::setDesc(string desc)
{
	this->descripcion.assign(desc);
}

string Pelicula::getTitulo()
{
	return this->titulo;
}
void Pelicula::setTitulo(string titulo)
{
	this->titulo.assign(titulo);
}

int Pelicula::getNumSesiones()
{
	return this->numSesiones;
}
void Pelicula::setNumSesiones(int NumSesiones)
{
	this->numSesiones = NumSesiones;
}

Sesion* Pelicula::getSesiones()
{
	return this->sesiones;
}
void Pelicula::setSesiones(Sesion* sesiones)
{
	this->sesiones = sesiones;
}

//Clase Cartelera
Cartelera::Cartelera()
{
	this->cine = "";
	this->numPelis = 0;
	this->peliculas = NULL;
}

string Cartelera::getCine()
{
	return this->cine;
}
void Cartelera::setCine(string cine)
{
	this->cine = cine;
}

Pelicula* Cartelera::getPeliculas()
{
	return this->peliculas;
}
void Cartelera::setPelis(Pelicula* Pelis)
{
	this->peliculas = Pelis;
}

int Cartelera::getNumPelis()
{
	return this->numPelis;
}
void Cartelera::setNumPelis(int NumPelis)
{
	this->numPelis = NumPelis;
}


