/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */
#include <iostream>
#include <string>
#include "Persona.h"
#include "Usuario.h"
using namespace std;
using namespace containers;
using namespace persona;


int main()
{

	Usuario *us;

	us = new Usuario("mahandy", "Maarten", "Handels", "72557736G");

	cout << us->getNombre() << endl;


	char c;
	do
	{
		cout << "Menu Principal" <<endl;
		cout << "1. Inicio Sesion" <<endl;
		cout << "2. Estadísticas" <<endl;

		cin >> c;

	}while(c!='q');



	return 0;
}


