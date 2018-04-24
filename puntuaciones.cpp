#include "puntuaciones.h"
#include <fstream>
#include <iostream>
#include <iomanip>

// Pre:
bool cargarPuntuaciones(tPuntuaciones & puntos) {
	ifstream archivo;
	tJugadorPuntos item;
	archivo.open("Puntuaciones.txt");
	if (archivo.is_open()) {
		puntos.many = 0;
		puntos.capacity = 4;
		puntos.puntuaciones = new tJugadorPuntos[4];
		while (!archivo.eof()) {
			archivo >> item.nombre;
			archivo >> item.puntos;
			actualizarPuntuacion(puntos, item.nombre, item.puntos);
		}
		archivo.close();
	}
	return !archivo.eof();
}

void mostrarPuntuaciones(const tPuntuaciones & puntos) {
	cout << setw(5) << ' ';
	cout << left << setw(50) << "JUGADOR";
	cout << left << "PUNTUACIONES" << endl << endl;

	for (int i = puntos.many - 1; i >= 0; i--) {
		cout << setw(5) << ' ';
		cout << left << setw(50) << puntos.puntuaciones[i].nombre;
		cout << left << puntos.puntuaciones[i].puntos << endl;
	}
}


// Pre : 0 <= pos <= capacity  !! An eye!
bool actualizarPuntuacionPos(tPuntuaciones & puntos, const string & nombre, int nuevos, const int pos) {
	actualizarPuntuacion(puntos, nombre, nuevos);
}

void liberar(tPuntuaciones & puntos) {
	delete puntos.puntuaciones;
}

void redimensionar(tPuntuaciones & puntos)
{
	tJugadorPuntos *item;
	puntos.many += 4;
	item = new  tJugadorPuntos[4*puntos.many];
	for (int i = 0; i < puntos.capacity; i++)
		item[i] = puntos.puntuaciones[i];
	liberar(puntos);
	puntos.puntuaciones = item;
}


// Pre : true
bool actualizarPuntuacion(tPuntuaciones & puntos, const string & nombre, int nuevos) {
	int posicion;
	bool encontrado, actualizado = false, haymenor;
	encontrado = busquedaJugador(puntos, nombre, posicion, nuevos);
	if (encontrado) {
		puntos.puntuaciones[posicion].puntos = puntos.puntuaciones[posicion].puntos + nuevos;
		actualizado = true;
	}
	else {
	
		if (puntos.many == puntos.many)	redimensionar(puntos);
		// pos.
		int pos = 0; // RAFA
		actualizarPuntuacionPos(puntos, nombre, nuevos, pos);
	}
	return true;
}



void anadirPuntuaciones(tPuntuaciones & puntos, const string nombre, int posicion, int nuevos) {
	puntos.puntuaciones[posicion].puntos = nuevos;
	puntos.puntuaciones[posicion].nombre = nombre;
}

bool busquedaJugador(tPuntuaciones & puntos, const string & nombre, int &posicion, int nuevos) {
	int i = 0;
	bool encontrado = false;
	while (i < puntos.contador && !encontrado) {
		if (nombre == puntos.puntuaciones[i].nombre) {
			posicion = i;
			encontrado = true;
		}
		i++;
	}
	return encontrado;
}

bool busquedaMenor(tPuntuaciones puntos, int & posicion, int nuevos) {
	bool encontrado = false;
	int menor;
	menor = puntos.puntuaciones[0].puntos;
	posicion = 0;
	for (int i = 1; i < puntos.contador; i++) {
		if (menor > puntos.puntuaciones[i].puntos) {
			menor = puntos.puntuaciones[i].puntos;
			posicion = i;
		}
	}
	if (nuevos > menor)
		encontrado = true;
	return encontrado;
}

void guardarPuntuaciones(const tPuntuaciones & puntos) {
	ofstream archivo;
	archivo.open("Puntuaciones.txt");
	if (archivo.is_open()) {
		for (int i = 0; i < puntos.contador; i++)
			archivo << puntos.puntuaciones[i].nombre << " " << puntos.puntuaciones[i].puntos << endl;
		archivo.close();
	}
}

void ordenarAlfabeticamente(tPuntuaciones item) {
	char leter;
	int letra_ascii;
	for (int i = 0; i < item.capacity; i++) {
		leter = item.puntuaciones[i].nombre[0];
		letra_ascii = (int)leter;
		if(letra_ascii)
		
	}		

	


}
