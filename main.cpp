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
	if(fexists("USUARIOS") == true)
	{
		cout << "Entra en el if" << endl;
		vector <Usuario> users = leerUsuarios();
		Menu* menucito = new Menu(users);
		menucito->MenuPrincipal();
	}else
	{
		cout << "funciona else" << endl;
		Menu* menucito = new Menu();
		cout << "Se crea el menu vacio" << endl;
		menucito->MenuPrincipal();
	}

	return 0;
}
