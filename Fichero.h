/*
 * Fichero.h
 *
 *  Created on: May 10, 2019
 *      Author: maarten
 */
#include <iostream>
#include "Cartelera.h"
#include "Usuario.h"
#include <vector>
using namespace containers;
using namespace cartelera;

#ifndef FICHERO_H_
#define FICHERO_H_

int lineasFichero(char *fichero);
Cartelera leerCartelera(char *cine);
void GuardarUsuarios(vector <Usuario> users);
vector<Usuario> leerUsuarios();

#endif /* FICHERO_H_ */
