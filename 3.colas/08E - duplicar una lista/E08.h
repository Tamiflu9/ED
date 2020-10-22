//Tamara Huertas A78

#pragma once
#ifndef E08_H
#define E08_H

#include "queue_eda.h"
#include <iostream>

using namespace std;

template <class T>
class ListaDuplica : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
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
	// duplicar los nodos de una lista enlazada simple
	void duplica() {
		if (this->prim != nullptr) {
			Nodo* act = this->prim;
			while (act != nullptr) {
				Nodo* duplicado = new Nodo(act->elem, act->sig);
				act->sig = duplicado;
				act = duplicado->sig;
			}
			this->nelems = this->nelems * 2;
			this->ult = act;

		}
	}
};

#endif