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

void verCartelera(char *cart);
void inicioSesion(vector <Usuario> users);
void menuEstadisticas(vector <Usuario> users);
void masTaquillera();
void descuentos();
void menuGestor();
void mediaEdad(vector <Usuario> users);
void nuevoUsuario(vector <Usuario> &users);

int main()
{
	char* cart = "Antiguo";

	vector <Usuario> users;


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
		cout<<endl;
		cout << "MENU PRINCIPAL" <<endl;
		cout << "-------------------"<<endl;
		cout << "1. Inicio sesion" <<endl;
		cout << "2. Administrador" << endl;
		cout<< "3. Registarse"<<endl;
		cout << "Introduzca una opcion del 1-3:"<<endl;
		cout << "Pulse 'q' para salir"<<endl;
		cin >> c;

		if (c == '1')
		{
			inicioSesion(users);
		}
		else if (c == '2')
		{
			menuGestor();
			menuEstadisticas(users);
		}
		else if(c=='3')
		{
			nuevoUsuario(users);
		}

	}while(c!='q');
	return 0;
}

void inicioSesion(vector <Usuario> users)
{
	char* cart = "Antiguo";

	cout << "Usuario:" << endl;
	string nomUsuario;
	cin >> nomUsuario;

	cout << "Contrasenya (DNI):" << endl;
	string dni;
	cin >> dni;

	int tamanyo = users.size();
	if (dni.size()!= 9)
	{
		cout << "La contrasenya es su DNI, vuelva a introducirla por favor: " << endl;
		cin >> dni;
	}

<<<<<<< HEAD
	if(tamanyo !=0)
=======
	for(Usuario a:users)
>>>>>>> 8cd4878c1daa4e87cff3a0f74c7912a413e524d0
	{
		cout<< "Hola "<< tamanyo << endl;

		for (Usuario a: users)
		{
			cout<< "Holaaaa" << endl;

			if (nomUsuario.compare(a.getNombreUs())!=0 && dni.compare(a.getDNI())!=0)
			{
				cout << "La contrasenya o nombre de usuario insertados no existen, registrese para poder acceder " << endl;
				main();
			}
			else {

				int op = 0;
				cout << "Que estadisticas quieres consultar?" << endl;
				cout << "1. Ver cartelera" << endl;
				cout << "2. Pelicula mas taquillera" << endl;
				cout << "3. Echa un vistazo a los descuentos!" << endl;
				cout << "Pulse 'q' para cerrar sesion"<< endl;

				switch (op) {
				case 1:
					verCartelera(cart);
					break;
				case 2:
					masTaquillera();
					break;
				case 3:
					descuentos();
					break;
				case 4:
					main();
					break;
				}

			}
		}

	}
	else
	{
		cout << "No hay nadie registrado" << endl;
		cout<<"Registrarse: "<<endl;
		nuevoUsuario(users);
	}

}

void verCartelera(char *cart)
{
	 Cartelera cartelera = leerCartelera(cart);

	 for(int a=0; a<cartelera.getNumPelis(); a++)
	 {
		 cout<<"Pelicula "<< a << ": " <<cartelera.peliculas[a].getTitulo()<<endl;
		 cout<<endl;
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
	char dia;
	cout<<"Que dia de la semana quieres ir al cine?"<<endl;
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
void menuGestor()
{
//	Gestor gestor = new Gestor();
//	gestor.menuGestor();
}

void nuevoUsuario(vector <Usuario> &users)
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

	Usuario* us = new Usuario(nomUsuario, nombre, apellido, dni, edad);

	users.push_back(*us);

	cout<< users.size()<<endl;
	for(Usuario a: users)
	{
		cout<<a.getNombre()<<endl;
	}

//	cout << "nombre del usuario: " << nomUsuario << endl;
	cout<<"Bienvenid@ "<< us->getNombre()<<"!"<<endl;
}

void mediaEdad(vector <Usuario> users)
{
	float media = 0;
	int tamanyo = sizeof(users);

	for (int i = 0; i<tamanyo;i++)
	{
		media = +users[i].getEdad();
	}

	cout << "La media de edad de las personas que visitan C-ine es de: " << media/tamanyo << "anyos." << endl;
}
