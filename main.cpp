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
using namespace std;
using namespace containers;
using namespace persona;


int main()
{
	printf("hola");

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

	}while(c!='q');



	return 0;
}


