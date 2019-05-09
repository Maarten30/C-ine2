/*
 * Gestor.h
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */

#ifndef GESTOR_H_
#define GESTOR_H_
#include <iostream>
using namespace std;
#include <string>
#include "Persona.h"
using namespace persona;

namespace gestor
{
	class Gestor : public Persona
	{
	private:
		int codigo;
	public:
		Gestor();
		Gestor (string nombre, string apellido,string dni, int codigo);
		void menuGestor();
		void NuevaCartelera();
	};

}


#endif /* GESTOR_H_ */
