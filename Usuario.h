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
//	class Persona
//	{
//	private:
//		string nombre, apellido, dni;
//
//	public:
//		Persona();
//		Persona (string nombre, string apellido, string dni);
//		~Persona();
//
//	};

	class Usuario: public Persona
	{
			private:
				string nomUsuario;
				string contra;
				int edad;
			public:
				Usuario();
				Usuario(string nombre, string apellido, string dni, string nomUs, int edad);

				string getNombre();
				string getApellido();
				string getNombreUs();
				string getDNI();
				int getEdad();

	};
//	{
//		private:
//
//			string nomUsuario;
//			string nombre;
//			string apellido;
//			string dni;
//
//
//		public:
//			Usuario();
//			Usuario(string nomUs, string nombre, string apellido): Persona(string nombre, string apellido, string dni);
//			Usuario(string nomUs, string nombre, string apellido);
//			~Usuario();
//			int poll();
//			string getNomUs();
//			void setNomUs(string nombre);
//
//
//
//			void clear();
//	};

}

#endif /* USUARIO_H_ */
