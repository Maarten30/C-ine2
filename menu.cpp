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

/**
 * Constructor vacío
 */
Menu::Menu()
{}

Menu::Menu(vector <Usuario> users)
{
	this->users = users;
}

Menu::Menu(vector <Gestor> gestores)
{
	this->gestores = gestores;
}

Menu::Menu(vector <Usuario> users, vector <Gestor> gestores)
{
	this->users = users;
	this->gestores = gestores;
}

void Menu::AnyadirUsuario(Usuario* usuario)
{
	this->users.push_back(*usuario);
	GuardarUsuarios(users);
}

void Menu::AnyadirGestor(Gestor* gestor)
{
	this->gestores.push_back(*gestor);
	GuardarGestores(gestores);
}

void Menu::MenuPrincipal()
{



	char c;
	do
	{
		cout << "Tamanyoo users" << users.size() << endl;
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
		}
		else if(c=='3')
		{
			nuevoUsuario();
		}

	}while(c!='q');

}

void Menu::menuGestor()
{
	char c;
	do
	{
		cout << endl;
		cout << "MENU GESTOR" << endl;
		cout << "-------------------" << endl;
		cout << "1. Inicio sesion" << endl;
		cout << "2. Registar nuevo gestor" << endl;
		cout << "Introduzca una opcion del 1-2:"<< endl;
		cout << "Pulse 'q' para salir" << endl;
		cin >> c;

		if (c == '1')
		{
			inicioSesionGestor();
		}
		else if (c == '2')
		{
			nuevoGestor();
		}

	}while(c!='q');
}

void Menu::inicioSesion()
{
	char* cart = "GML";
	Usuario* us = new Usuario();

	cout << "Usuario:" << endl;
	string nomUsuario;
	cin >> nomUsuario;


	cout << "Contrasenya (DNI):" << endl;
	string dni;
	cin >> dni;

	bool  repetido = false;

	while (dni.size()!= 9)
	{
		cout << "Debe contener 9 caracteres, vuelva a introducirla por favor: " << endl;
		cin >> dni;
	}

	cout << "LLega aquiiiiiiiiiii " << endl;
	for (Usuario a: users)
	{
		cout << "Entra acaaaaa " << endl;

		if (nomUsuario.compare(a.getNombreUs())==0 && dni.compare(a.getDNI())==0)
		{
			cout << "Y aqui tambn " << endl;
			repetido = true;
			*us = a;

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

			if(repetido == true)
			{
				int op;

					do
					{
						cout << "entra en dowhilee"<<endl;
						op = 0;
						us ->imprimirMenu();
						cin >> op;

						switch(op)
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


					}while (op!=4);
			}

		}


	}
	if (repetido == false)
	{
		cout << "No hay ningun usuario registrado con ese nombre de usuario y contrasenya"<<endl;
	}
}

void Menu::inicioSesionGestor()
{
	char* cart = "GML";

	int codigo;
	string dni;
	bool existente;
	Gestor* ges = new Gestor();

	do
	{
		existente = false;
		cout << "Codigo Gestor:" << endl;
		cin >> codigo;

		cout << "Contrasenya (DNI):" << endl;
		cin >> dni;

		for(Gestor a:gestores)
		{

			if(a.getCodigo()==codigo && a.getDNI().compare(dni)==0)
			{
				cout << "Se encuentra la coincidencia" << endl;
				existente = true;
				*ges = a;
			}

			cout << "Sale de la comprobacion" << endl;
		}
		if(existente == false)
		{
			cout << "Los datos introducidos no coinciden con ningun gestor existente " <<endl;
		}

	}while(existente==false);


	if(existente == true)
	{

		cout << "Entra en el if del boolean" << endl;
		int op;

		do
		{
			cout << "Entra en el dowhile del if" << endl;
			op = 0;
			ges->imprimirMenu();
			cin >> op;

			switch (op)
			{
				case 1:
					mediaEdad();
					break;
				case 2:
					masTaquillera(cart);
					break;
				case 3:
					break;
			}
		}while(op!=3);

	}

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

	string dni;
	string nomUsuario;


	cout << "Usuario:" << endl;
	cin >> nomUsuario;


	for (Usuario a: users)
	{
		if(a.getNombreUs().compare(nomUsuario)==0)
		{
			cout << "Este nombre de usuario ya existe, introduzca uno nuevo: " << endl;
			cin >> nomUsuario;
		}
	}

	cout << "DNI (Contrasenya):" << endl;
	cin >> dni;

	for (Usuario a: users)
	{
		if(a.getDNI().compare(dni) == 0)
		{
			cout << "Este dni ya existe, introduzca uno nuevo: " << endl;
			cin >> dni;
		}
	}
	if(dni.size()!= 9)
	{
		cout << "Recuerde que el dni tiene que tener 9 caracteres: " << endl;
		cin >> dni;
	}


	Usuario* us = new Usuario(nomUsuario, nombre, apellido, dni, edad);


	this->AnyadirUsuario(us);


	GuardarUsuarios(users);

	cout<<"BIENVENIDO/A "<< us->getNombre()<<"!!"<<endl;
}

void Menu::nuevoGestor()
{
	cout << "Nombre:" << endl;
	string nombre;;
	cin >> nombre;

	cout << "Apellido:" << endl;
	string apellido;
	cin >> apellido;

	string dni;
	bool repetido;

	do
	{
		repetido = false;

		cout << "DNI (Contraseña):" << endl;
		cin >> dni;

		for(Gestor a:gestores)
		{
			if(a.getDNI().compare(dni)==0)
			{
				repetido = true;
				cout << "Este dni ya esta registrado, introduzca otro" << endl;
			}
		}
		if(dni.size()!=9)
		{
			cout << "Recuerde que el dni debe tener 9 caracteres" << endl;
		}


	}while(dni.size()!= 9 || repetido == true);

	int codigo = gestores.size() + 1;




	Gestor* ges = new Gestor(nombre, apellido, dni, codigo);
	this->AnyadirGestor(ges);

	cout << "Su codigo para acceder a la plataforma es: " << codigo << endl;

	GuardarGestores(gestores);

	cout<<"BIENVENID@ "<< ges->getNombre()<<"!!"<<endl;
}

void Menu::menuEstadisticas()
{
	char* cart = "GML";

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

void Menu::verCartelera(char *cart)
{
	 Cartelera cartelera = leerCartelera(cart);

	 Usuario us;

	 cout<<"PELICULAS"<<endl;
	 cout<<"------------"<<endl;
	 for(int a=0; a<cartelera.getNumPelis(); a++)
	 {
		 cout<<"Pelicula "<< a+1 << ": " <<cartelera.peliculas[a].getTitulo()<<endl;
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

void Menu::mediaEdad()
{
	float media = 0.0;
	int tamanyo = users.size();

	cout << tamanyo << endl;

	for (int i = 0; i<tamanyo;i++)
	{
		cout << users[i].getEdad() << endl;
		media = +users[i].getEdad();
	}

	cout << "La media de edad de las personas que visitan C-ine es de: " << media/tamanyo << " anyos." << endl;
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


