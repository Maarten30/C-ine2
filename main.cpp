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
	if(fexists("USUARIOS.txt")==true && fexists("GESTORES.txt")==true)
	{
		vector <Usuario> users = leerUsuarios();
		vector <Gestor> gestores = leerGestores();
		Menu* menucito = new Menu(users, gestores);
		menucito->MenuPrincipal();
		menucito->~Menu();

	}else if(fexists("USUARIOS.txt")==true && fexists("GESTORES.txt")==false)
	{
		vector <Usuario> users = leerUsuarios();
		Menu* menucito = new Menu(users);
		menucito->MenuPrincipal();
		menucito->~Menu();

	}else if(fexists("USUARIOS.txt")==false && fexists("GESTORES.txt")==true)
	{
		vector <Gestor> gestores = leerGestores();
		Menu* menucito = new Menu(gestores);
		menucito->MenuPrincipal();
		menucito->~Menu();

	}else if(fexists("USUARIOS.txt")==false && fexists("GESTORES.txt")==false)
	{
		Menu* menucito = new Menu();
		menucito->MenuPrincipal();
		menucito->~Menu();
	}

	return 0;
}
