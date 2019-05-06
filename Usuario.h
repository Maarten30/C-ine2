/*
 * Usuario.h
 *
 *  Created on: May 6, 2019
 *      Author: maarten
 */
#include <iostream>
using namespace std;

#ifndef USUARIO_H_
#define USUARIO_H_

namespace containers
{
	class Usuario
	{
		private:

			string nomUsuario;
			string nombre;
			string apellido;


		public:
			Usuario();
			Usuario(string nomUs, string nombre, string apellido);
			~Usuario();
			int poll();
			void clear();
	};

}

#endif /* USUARIO_H_ */
