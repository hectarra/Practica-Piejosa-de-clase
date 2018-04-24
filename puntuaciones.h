#pragma once
#ifndef __PUNTUACION__
#define __PUNTUACION__

#include <string>

using namespace std;

const int MAX_JUGADORES_PUNTOS = 30;

typedef struct {
	string nombre;
	int puntos;
} tJugadorPuntos;

typedef struct {
	tJugadorPuntos *puntuaciones;
	int capacity;
	int many;
} tPuntuaciones;

bool cargarPuntuaciones(tPuntuaciones & puntos);
void mostrarPuntuaciones(const tPuntuaciones & puntos);
void guardarPuntuaciones(const tPuntuaciones & puntos);
bool busquedaJugador(tPuntuaciones & puntos, const string & nombre, int &posicion, int nuevos);
bool busquedaMenor(tPuntuaciones puntos, int & posicion, int nuevos);
bool actualizarPuntuacion(tPuntuaciones & puntos, const string & nombre, int nuevos);
void anadirPuntuaciones(tPuntuaciones & puntos, const string nombre, int posicion, int nuevos);

#endif
