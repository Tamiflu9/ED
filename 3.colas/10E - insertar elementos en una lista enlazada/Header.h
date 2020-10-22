
#ifndef Header
#define Header

#include "queue_eda.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

template<class T>
class ListaInserta : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:

	void inserta(ListaInserta<T> &other, int p) {
		int i = 0;
		Nodo* ini = this->prim;
		Nodo* ult = nullptr;
		// si insertamos al principio de la lista principal la lista 'other'
		// el siguiente del ultimo elemento de la lista 'other' apunta al primero de la lista principal
		// el primero de la lista final es el primero de la lista 'other'
		if (p == 0) {
			other.ult->sig = this->prim; 
			this->prim = other.prim;
		}
		else {
			// buscamos la posicion del nodo anterior desde donde vamos a insertar la lista 'other'
			while (i < p-1) {
				ini = ini->sig;
				i++;
			}
			// ya hemos encontrado el sitio donde empezar a insertar, pero antes nos guardamos la posicion
			// del resto de la lista para enlazarla cuando acabe la insercion de elementos
			ult = ini->sig;
			// enlazamos la primera parte de la lista con la lista 'other' que vamos a insertar
			ini->sig = other.prim;
			// enlazamos el fin de la lista 'other' con la segunda parte de la lista principal que tenemos en el nodo ult
			other.ult->sig = ult;
		}

		if (p == this->nelems) {
			this->ult = other.ult;
		}

		// aumentamos el numero de elementos
		this->nelems += other.nelems;
		// anulamos la segunda lista
		other.prim = nullptr;
		other.nelems = 0;
	}

	void print(std::ostream& o = std::cout) const {
		int i = this->nelems;
		Nodo* n = this->prim;
		while (i > 0) {
			cout << n->elem << " ";
			n = n->sig;
			i--;
		}
		cout << endl;
	}

private:

};

#endif // !Header
