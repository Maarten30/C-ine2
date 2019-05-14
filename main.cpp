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
#include "menu.h"
using namespace std;
using namespace containers;
using namespace persona;
using namespace cartelera;
using namespace gestor;
using namespace menu;


int main()
{
	cout << "Main" << endl;

	if(fexists("USUARIOS.txt")==true && fexists("GESTORES.txt")==true)
	{
		cout << "CASO 1" << endl;
		vector <Usuario> users = leerUsuarios();
		vector <Gestor> gestores = leerGestores();
		Menu* menucito = new Menu(users, gestores);
		menucito->MenuPrincipal();

	}else if(fexists("USUARIOS.txt")==true && fexists("GESTORES.txt")==false)
	{
		cout << "CASO 2" << endl;
		vector <Usuario> users = leerUsuarios();
		Menu* menucito = new Menu(users);
		menucito->MenuPrincipal();

	}else if(fexists("USUARIOS.txt")==false && fexists("GESTORES.txt")==true)
	{
		cout << "CASO 3" << endl;
		vector <Gestor> gestores = leerGestores();
		Menu* menucito = new Menu(gestores);
		menucito->MenuPrincipal();

	}else if(fexists("USUARIOS.txt")==false && fexists("GESTORES.txt")==false)
	{
		cout << "CASO 4" << endl;
		Menu* menucito = new Menu();
		cout << "Se crea el menu vacio" << endl;
		menucito->MenuPrincipal();
	}

	return 0;
}
