/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */
#include <iostream>
#include <cstdio>
#include <string>
#include "Persona.h"
#include "Usuario.h"
#include "Cartelera.h"
#include "Fichero.h"
using namespace std;
using namespace containers;
using namespace persona;
using namespace cartelera;


int main()
{
	printf("hola\n");

	char* cart = "GML";

	Cartelera cartelera = leerCartelera(cart);


	cout << cartelera.getCine() << endl;
	cout << cartelera.getNumPelis() << endl;
	cout << cartelera.peliculas[0].getDesc() << endl;
	//Hay algun problema con los strings porque no devuelve los atributos string del todo bien
	cout << cartelera.peliculas[0].getNumSesiones() << endl;
	cout <<"Los horaaaaarios son: " << cartelera.peliculas[0].sesiones[0].getPlazas() << endl;
	//Vale no solo strings porque las plazas tampoco devuelve bien

	Usuario *us;

	us = new Usuario("mahandy", "Maarten", "Handels", "72557736G");

	cout << us->getNombre() << endl;


	char c;
	do
	{
		cout << "Menu Principal" <<endl;
		cout << "1. Inicio Sesion" <<endl;
		cout << "2. Estadisticas" <<endl;

		cin >> c;

	}while(c!='q');



	return 0;
}


