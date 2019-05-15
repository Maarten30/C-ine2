/*
 * main.h
 *
 *  Created on: May 13, 2019
 *      Author: maarten
 */

#include <iostream>
#include "Usuario.h"
#include "Gestor.h"
#include <vector>
using namespace containers;
using namespace std;
using namespace gestor;

#ifndef MAIN_H_
#define MAIN_H_

namespace menu
{
	class Menu
	{
			private:
				vector <Usuario> users;
				vector <Gestor> gestores;
			public:
				Menu();
				Menu(vector <Usuario> users);
				Menu(vector <Gestor> gestores);
				Menu(vector <Usuario> users, vector <Gestor> gestores);

				void AnyadirUsuario(Usuario *us);
				void AnyadirGestor(Gestor* gestor);

				void MenuPrincipal();
				void inicioSesion();
				void inicioSesionGestor();
				void menuEstadisticas();
				void masTaquillera(char *cart);
				void descuentos();
				void menuGestor();
				void mediaEdad();
				void nuevoUsuario();
				void nuevoGestor();
				void verCartelera(char *cart);
				int exists(const char *fname);
				char* nombreCine();
	};
}






#endif /* MAIN_H_ */
