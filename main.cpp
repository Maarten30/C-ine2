/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */
#include <iostream>
using namespace std;

int main()
{

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


