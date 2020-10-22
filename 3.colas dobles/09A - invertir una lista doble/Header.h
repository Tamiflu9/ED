// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#ifndef queue_ext
#define queue_ext

#include "deque_eda.h"
#include <iostream>

using namespace std;

template <class T>
class ListaInsertar : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:

	void invertir() {
		
		if (this->nelems == 0) {
			return;
		}

		Nodo* act = this->fantasma->sig;
		Nodo* sig = act->sig;
		Nodo* ant = act->ant;

		act->sig = ant;
		act->ant = sig;

		ant = act;
		act = sig;
		sig = sig->sig;

		while (ant != this->fantasma) {

			act->sig = ant;
			act->ant = sig;

			ant = act;
			act = sig;
			sig = sig->sig;

		}

	}

	void print(std::ostream& o = std::cout) {
		int i = this->nelems;
		Nodo* n = this->fantasma->sig;

		while (i > 0) {
			cout << n->elem << " ";
			n = n->sig;
			i--;
		}
		cout << endl;
	}
};

#endif // !queue_ext

