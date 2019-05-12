/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
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

void inicioSesion(std::vector<containers::Usuario> users);
void menuEstadisticas(std::vector<containers::Usuario> users);
void masTaquillera();
void descuentos();
void menuGestor();
void mediaEdad(std::vector<containers::Usuario> users);
void nuevoUsuario(std::vector<containers::Usuario> users);

int main()
{
	char* cart = "GML";
	std::vector<containers::Usuario> users;


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
		cout<<endl;
		cout << "MENU PRINCIPAL" <<endl;
		cout<<"-------------------"<<endl;
		cout << "1. Inicio sesion" <<endl;
		cout << "2. Estadisticas" <<endl;
		cout << "3. Administrador" << endl;
		cout << "4. Crear cuenta" << endl;
		cout <<"Introduzca una opcion del 1-4:"<<endl;
		cout << "Pulse 'q' para salir"<<endl;
		cin >> c;

		if (c == '1')
		{
			inicioSesion(users);
		}
		else if (c == '2')
		{
			menuEstadisticas(users);
		}
		else if (c == '3')
		{
			menuGestor();
		}
		else if (c == '4')
		{
			nuevoUsuario(users);
		}

	}while(c!='q');
	return 0;
}

void inicioSesion(std::vector<containers::Usuario> users)
{
	cout << "Usuario:" << endl;
	string nomUsuario;
	cin >> nomUsuario;

	cout << "Contrasenya (DNI):" << endl;
	string dni;
	cin >> dni;

	if (dni.size()!= 9)
	{
		cout << "La contrasenya es su DNI, vuelva a introducirla por favor: " << endl;
		cin >> dni;
	}
//	do
//	{
//		cout << "La contrasena es su DNI, vuelva a introducirla por favor: " << endl;
//		cin >> dni;
//	}
//	while (dni.size() !=8);

	for (Usuario a : users)
	{
		if (!(nomUsuario.compare(a.getNombreUs()) && dni.compare(a.getDNI())))
		{
			cout << "La contrasenya o nombre de usuario insertados no existen, registrese para poder acceder " << endl;
			main();
		}
		else
		{
			cout << "Se ha registrado satisfactoriamente " << a.getNombre()<<endl;
		}
	}

}

void menuEstadisticas(std::vector<containers::Usuario> users)
{
	int op=0;
	cout << "Que estadisticas quieres consultar?" << endl;
	cout << "1. Pelicula mas taquillera"<<endl;
	cout << "2. Echa un vistazo a los descuentos!" << endl;
	cout << "3. Media de edad de los usuarios que visitan el cine" << endl;
	cout << "4. Menu principal" << endl;
	cin >> op;


	switch (op)
			{
				case 1: masTaquillera();
				break;
				case 2:	descuentos();
				break;
				case 3: mediaEdad(users);
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

void nuevoUsuario(std::vector<containers::Usuario> users)
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
	if (dni.size()!= 9)
	{
		cout << "La contrasenya es su DNI, vuelva a introducirla por favor: " << endl;
		cin >> dni;
	}
//	do
//	{
//		cout << "La contrasena es su DNI, vuelva a introducirla por favor: " << endl;
//		cin >> dni;
//	}
//	while (dni.size() !=8);

	Usuario* us = new Usuario(nomUsuario, nombre, apellido, dni, edad);


	users.push_back(*us);

//	cout << "nombre del usuario: " << nomUsuario << endl;
	cout<<"Bienvenid@ "<< us->getNombre()<<"!"<<endl;
}

void mediaEdad(std::vector<containers::Usuario> users)
{
	float media = 0;

	for (int i = 0; i<users.size();i++)
	{
		media = +users[i].getEdad();
	}

	cout << "La media de edad de las personas que visitan C-ine es de: " << media << "anyos." << endl;
}
