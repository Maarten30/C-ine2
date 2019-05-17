/*
 * Cartelera.h
 *
 *  Created on: 9 may. 2019
 *      Author: ALUMNO
 */

#ifndef CARTELERA_H_
#define CARTELERA_H_
#include <iostream>
#include <string>
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
			~Sesion();
			int getPlazas();
			void setPlazas(int plazas);
			double getHora();
			void setHora(double hora);
	};

	class Pelicula
	{
		private:
			string titulo;
			string descripcion;
			int numSesiones;

		public:
			Sesion *sesiones;
			Pelicula();
			~Pelicula();
			string getTitulo();
			void setTitulo(string titulo);
			string getDesc();
			void setDesc(string desc);
			int getNumSesiones();
			void setNumSesiones(int NumSesiones);
			Sesion* getSesiones();
			void setSesiones(Sesion* sesiones);
	};

	class Cartelera
	{
		private:
			string cine;
			int numPelis;

		public:
			Pelicula *peliculas;
			Cartelera();
			~Cartelera();
			string getCine();
			void setCine(string cine);
			Pelicula* getPeliculas();
			void setPelis(Pelicula* Pelis);
			int getNumPelis();
			void setNumPelis(int NumPelis);
	};
}

#endif /* CARTELERA_H_ */
