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
#include "Gestor.h"
#include "Cartelera.h"
#include "Fichero.h"
using namespace std;
using namespace containers;
using namespace persona;
using namespace cartelera;
using namespace gestor;

void inicioSesion();
void menuEstadisticas();
void masTaquillera();
void descuentos();
void menuGestor();
void rangoEdad();
void nuevoUsuario();

int main()
{
	char* cart = "GML";

//	Cartelera cartel = leerCartelera(cart);
//
//	cout << "E nombre de la peli es: "<< cartel.peliculas[0].getTitulo() << endl;
//	cout << "La descripciond de la peli es: "<< cartel.peliculas[0].getDesc() << endl;
//	cout << "Las plazas disponibles son: "<< cartel.peliculas[0].sesiones[0].getPlazas() << endl;
//	cout << "Las hora es: "<< cartel.peliculas[0].sesiones[0].getHora() << endl;

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
		cout << "3. Administrador" << endl;
		cout << "4. Crear cuenta" << endl;
		cout <<"Introduzca una opción del 1-4:"<<endl;
		cout << "Pulse 'q' para salir"<<endl;
		cin >> c;

		if (c == '1')
		{
			inicioSesion();
		}
		else if (c == '2')
		{
			menuEstadisticas();
		}
		else if (c == '3')
		{
			menuGestor();
		}
		else if (c == '4')
		{
			nuevoUsuario();
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
	do
	{
		cout << "La contrasena es su DNI, vuelva a introducirla por favor: " << endl;
		cin >> dni;
	}
	while (dni.size() !=9);

}

void menuEstadisticas()
{
	int op=0;
	cout << "¿Que estadisticas quieres consultar?" << endl;
	cout << "1. Pelicula mas taquillera"<<endl;
	cout << "2. ¡Echa un vistazo a los descuentos!" << endl;
	cout << "3. Rango de edad que mas visita nuestros cines" << endl;
	cout << "4. Menu principal" << endl;
	cin >> op;


	switch (op)
			{
				case 1: masTaquillera();
				break;
				case 2:	descuentos();
				break;
				case 3: rangoEdad();
				break;
				case 4: main();
				break;
			}
}
void masTaquillera() //leer el fichero y coger la pelicula que mas entradas haya vendido
{
	Pelicula peli;
	cout << "La pelicula mas taquillera es: " << peli.getTitulo() << endl;
	main();

}

void descuentos()
{
	Cartelera *cart = new Cartelera();
	cout<<"Descuentos de este mes:"<<endl;

	cout<<"Introduzca el cine: "<<endl;
//	cin >> cart->cine;
}
void menuGestor()
{
//	Gestor gestor = new Gestor();
//	gestor.menuGestor();
}

void nuevoUsuario()
{
	cout << "Nombre:" << endl;
	string nombre;;
	cin >> nombre;

	cout << "Apellido:" << endl;
	string apellido;
	cin >> apellido;

	cout << "Edad:" << endl;
	int edad;
	cin >> edad;

	cout << "Usuario:" << endl;
	string nomUsuario;
	cin >> nomUsuario;

	cout << "Contrasenya (DNI):" << endl;
	string dni;
	cin >> dni;
	do
	{
		cout << "La contrasena es su DNI, vuelva a introducirla por favor: " << endl;
		cin >> dni;
	}
	while (dni.size() !=9);

	Usuario* us = new Usuario(nomUsuario, nombre, apellido, dni, edad);
}

void rangoEdad()
{

}
