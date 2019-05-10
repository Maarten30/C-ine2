/*
 * Cartelera.h
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */

#ifndef CARTELERA_H_
#define CARTELERA_H_
#include <iostream>
using namespace std;
namespace cartelera
{
	class Sesion
	{
		private:
			int plazas;
			double hora;

		public:
			Sesion();
			Sesion(int plazas, double hora);
			int getPlazas();
			void setPlazas(int plazas);
			double getHora();
			void setHora(double hora);

	};

	class Pelicula
	{
	private:
		char *titulo;
		char *descripcion;
		int numSesiones;
		Sesion *sesiones;
	};

	class Cartelera
	{
	private:
		char *cine;
		Pelicula *peliculas;
		int numPelis;
	};
}


#endif /* CARTELERA_H_ */
