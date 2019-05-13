/*
 * main.h
 *
 *  Created on: May 13, 2019
 *      Author: maarten
 */

#include <iostream>
#include "Usuario.h"
#include <vector>
using namespace containers;
using namespace std;
#ifndef MAIN_H_
#define MAIN_H_


void inicioSesion(vector <Usuario> &users);
void menuEstadisticas(vector <Usuario> &users);
void masTaquillera();
void descuentos();
void menuGestor();
void mediaEdad(vector <Usuario> users);
void nuevoUsuario(vector <Usuario> &users);
void verCartelera(char *cart);


#endif /* MAIN_H_ */
