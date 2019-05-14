/*
 * menu.cpp
 *
 *  Created on: May 13, 2019
 *      Author: maarten
 */
#include "menu.h"
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
using namespace menu;

Menu::Menu()
{

}

Menu::Menu(vector <Usuario> users)
{
	this->users = users;
}

void Menu::AnyadirUsuario(Usuario* usuario)
{
	this->users.push_back(*usuario);
	GuardarUsuarios(users);
}

void Menu::MenuPrincipal()
{

	cout << "Hola" << endl;
	vector <Usuario> users = leerUsuarios();


	cout << "El nombre del primer usuario es: " << users[0].getNombre() << endl;


	char c;
	do
	{
		cout << endl;
		cout << "MENU PRINCIPAL" << endl;
		cout << "-------------------" << endl;
		cout << "1. Inicio sesion" << endl;
		cout << "2. Administrador" << endl;
		cout << "3. Registarse" << endl;
		cout << "Introduzca una opcion del 1-3:"<< endl;
		cout << "Pulse 'q' para salir" << endl;
		cin >> c;

		if (c == '1')
		{
			inicioSesion();
		}
		else if (c == '2')
		{
			menuGestor();
			menuEstadisticas();
		}
		else if(c=='3')
		{
			nuevoUsuario();
		}

	}while(c!='q');

}

void Menu::inicioSesion()//vector <Usuario> &users)
{
	char* cart = "URBIL";

	cout << "Usuario:" << endl;
	string nomUsuario;
	cin >> nomUsuario;

	cout << "Contrasenya (DNI):" << endl;
	string dni;
	cin >> dni;

	int tamanyo = this->users.size();
	while (dni.size()!= 9)
	{
		cout << "Debe contener 9 caracteres, vuelva a introducirla por favor: " << endl;
		cin >> dni;
	}


	for (Usuario a: this->users)
	{

		if (nomUsuario.compare(a.getNombreUs())!=1 && dni.compare(a.getDNI())!=1)
		{
			int op = 0;

			a.imprimirMenu();

			cin >> op;

			switch (op)
			{
				case 1:
					verCartelera(cart);
					break;
				case 2:
					masTaquillera(cart);
					break;
				case 3:
					descuentos();
					break;
			}


		}
	}
}


void Menu::verCartelera(char *cart)
{
	 Cartelera cartelera = leerCartelera(cart);

	 Usuario us;
	 int op=0;

	 cout<<"PELICULAS"<<endl;
	 cout<<"------------"<<endl;
	 for(int a=0; a<cartelera.getNumPelis(); a++)
	 {
		 cout<<"Pelicula "<< a+1 << ": " <<cartelera.peliculas[a].getTitulo()<<endl;
	 }
}

void Menu::menuEstadisticas()
{
	char* cart = "URBIL";

	int op=0;
	cout << "Que estadisticas quieres consultar?" << endl;
	cout << "1. Pelicula mas taquillera"<<endl;
	cout << "2. Echa un vistazo a los descuentos!" << endl;
	cout << "3. Media de edad de los usuarios que visitan el cine" << endl;
	cout << "4. Menu principal" << endl;
	cin >> op;

	switch (op) {
	case 1:
		masTaquillera(cart);
		break;
	case 2:
		descuentos();
		break;
	case 3:
		mediaEdad();
		break;
	case 4:
//		main();
		MenuPrincipal();
		break;
	}
}

void Menu::masTaquillera(char *cart) //leer el fichero y coger la pelicula que mas entradas haya vendido
{
	cout << "Llega aqui" << endl;
	Pelicula peli;
	Cartelera cartelera = leerCartelera(cart);
	int mayor = cartelera.peliculas[0].sesiones[0].getPlazas();

	int mayorVisitas = 0;


	for(int i=0; i<cartelera.getNumPelis(); i++)
	{
		int suma = 0;
		for(int j=0; j<cartelera.peliculas[i].getNumSesiones(); j++)
		{
			int aux = 22-cartelera.peliculas[i].sesiones[j].getPlazas();
			suma += aux;
		}
		if(i==0)
		{
			peli = cartelera.peliculas[i];
			mayorVisitas = suma;
		}else
		{
			if(suma>mayorVisitas)
			{
				peli = cartelera.peliculas[i];
			}
		}
	}

	cout << "La peli más taquillera es: " << peli.getTitulo() << endl;

}

void Menu::descuentos()
{
	char dia;
	cout<<"DESCUENTOS"<<endl;
	cout<<"------------"<<endl;
	cout<<"Que dia de la semana quieres ir al cine?"<<endl;
	cout<<endl;
	cout<<"Lunes (L)"<<endl;
	cout<<"Martes (M)"<<endl;
	cout<<"Miercoles (X)"<<endl;
	cout<<"Jueves (J)"<<endl;
	cout<<"Viernes (V)"<<endl;
	cout<<"Sabado (S)"<<endl;
	cout<<"Domingo (D)"<<endl;
	cin>>dia;

	if(dia=='X' || dia=='x')
	{
		cout<<"Tienes un descuento del 50% en todas las peliculas"<<endl;
	}

	else
	{
		cout<<"Lo sentimos, hoy no hay descuentos"<<endl;
	}

}
void Menu::menuGestor()
{
//	Gestor gestor = new Gestor();
//	gestor.menuGestor();
}

void Menu::nuevoUsuario()
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
		cout << "La contrasenya es su DNI, vuelva a introducirlo por favor: " << endl;
		cin >> dni;
	}while(dni.size()!= 9);

	Usuario* us = new Usuario(nomUsuario, nombre, apellido, dni, edad);


	this->AnyadirUsuario(us);


	GuardarUsuarios(users);

	cout<<"BIENVENID@ "<< us->getNombre()<<"!!"<<endl;
}

void Menu::mediaEdad()
{
	float media = 0;
	int tamanyo = sizeof(users);

	for (int i = 0; i<tamanyo;i++)
	{
		media = +users[i].getEdad();
	}

	cout << "La media de edad de las personas que visitan C-ine es de: " << media/tamanyo << "anyos." << endl;
}


