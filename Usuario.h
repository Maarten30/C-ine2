/*
 * Usuario.h
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */
#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;
using namespace persona;

#ifndef USUARIO_H_
#define USUARIO_H_

namespace containers
{

	class Usuario: public Persona
	{
		private:
			string nomUsuario;
			string contra;
			int edad;
		public:
			Usuario();
			Usuario(string nombre, string apellido, string dni, string nomUs, int edad);
			virtual ~Usuario();
			virtual void imprimirMenu();

			string getNombreUs();
			int getEdad();
			void setNombreUs(string nombreUs);
			void setEdad (int edad);
	};
}

#endif /* USUARIO_H_ */
