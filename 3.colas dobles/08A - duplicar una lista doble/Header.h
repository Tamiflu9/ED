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

	void duplicar() {
		
		if (this->fantasma->sig != this->fantasma) {
			Nodo* p = this->fantasma->sig;

			while (p != this->fantasma) {

				Nodo* dupli = new Nodo(p->elem, p, p->sig);

				p->sig= dupli;
				p = dupli->sig;

			}

			this->nelems = this->nelems * 2;

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

