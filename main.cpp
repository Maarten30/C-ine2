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
int main()
{
	char* cart = "GML";


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

	cout << "Contraseña (DNI):" << endl;
	string dni;
	cin >> dni;
}

void menuEstadisticas()
{
	char op;
	cout << "¿Que estadisticas quieres consultar?" << endl;
	cout << "1. Pelicula mas taquillera"<<endl;
	cout << "2. no se me ocurren mas cosas jajaja" << endl;
	cout << "3. Menu principal" << endl;
	cin >> op;
	switch (op)
			{
				case 1: masTaquillera();
				break;
				case 2:	// otro tipo de estadistica
				break;
			}
}
void masTaquillera()
{
	char* peli;
	cout << "La pelicula mas taquillera es: " << peli << endl;
	main();

}
