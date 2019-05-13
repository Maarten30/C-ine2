/*
 * Persona.h
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
#include <string>
using namespace std;

namespace persona
{
	class Persona
	{
		private:
			string nombre, apellido, dni;

		public:

			Persona();
			Persona (string nombre, string apellido, string dni);
			virtual ~Persona();

			string getNombre();
			string getApellido();
			string getDNI();

			virtual void imprimirMenu()=0;
			void setNombre(string nombre);
			void setApellido(string apellido);
			void setDni(string dni);


	};
}


#endif /* PERSONA_H_ */
