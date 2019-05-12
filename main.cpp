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

void inicioSesion();
void menuEstadisticas();
void masTaquillera();
void descuentos();

int main()
{
	char* cart = "GML";

	Cartelera cartel = leerCartelera(cart);

	cout << "E nombre de la peli es: "<< cartel.peliculas[0].getTitulo() << endl;
	cout << "La descripciond de la peli es: "<< cartel.peliculas[0].getDesc() << endl;
	cout << "Las plazas disponibles son: "<< cartel.peliculas[0].sesiones[0].getPlazas() << endl;
	cout << "Las hora es: "<< cartel.peliculas[0].sesiones[0].getHora() << endl;

//	Usuario *us;
//
//	us = new Usuario("mahandy", "Maarten", "Handels", "72557736G");
//
//	cout << us->getNombre() << endl;

	char c;
	do
	{
		cout << "Menu Principal" <<endl;
		cout << "1. Inicio Sesion" <<endl;
		cout << "2. Estadisticas" <<endl;

		cin >> c;
		cout << c << endl;

		if (c == '1')
		{
			inicioSesion();
		}
		else if (c == '2')
		{
			menuEstadisticas();
		}

	}while(c!='q');

	return 0;
}

void inicioSesion()
{
	cout << "Usuario:" << endl;
	string nomUsuario;
	cin >> nomUsuario;

	cout << "Contrasenya (DNI):" << endl;
	string dni;
	cin >> dni;
}

void menuEstadisticas()
{
	int op=0;
	cout << "¿Que estadisticas quieres consultar?" << endl;
	cout << "1. Pelicula mas taquillera"<<endl;
	cout << "2. ¡Echa un vistazo a los descuentos!" << endl;
	cout << "3. Menu principal" << endl;
	cin >> op;
	switch (op)
			{
				case 1: masTaquillera();
				break;
				case 2:	descuentos();
				break;
				case 3: main();
				break;
			}
}
void masTaquillera() //leer el fichero y coger la pelicula que mas entradas haya vendido
{
	char* peli;
	cout << "La pelicula mas taquillera es: " << peli << endl;
	main();

}

void descuentos()
{
	Cartelera *cart = new Cartelera();
	cout<<"Descuentos de este mes:"<<endl;
	cout<<"Introduzca el cine: "<<endl;
}
