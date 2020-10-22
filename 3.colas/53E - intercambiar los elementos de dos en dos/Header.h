#ifndef queue_ext
#define queue_ext

#include "queue_eda.h"
#include <iostream>

using namespace std;

template <class T>
class ListaIntercambia : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:

	void intercambiar() {
		if (this->empty()) {
			return;
		}
		else {
			if (this->nelems < 2) {
				return;
			}
			else {
				Nodo* ant;
				Nodo* p = this->prim->sig;

				this->prim->sig = p->sig;
				
				p->sig = this->prim;

				this->prim = p;

				ant = p->sig;

				while (ant->sig != nullptr && ant->sig->sig != nullptr) {

					p = ant->sig->sig;

					ant->sig->sig = p->sig;

					p->sig = ant->sig;

					ant->sig = p;

					ant = ant->sig->sig;
				}

				if (this->nelems % 2 == 0) {
					this->ult = ant;
				}
			}
			
		}
	}

	void print(std::ostream& o = std::cout) {
		Nodo* act = this->prim;

		while (act != nullptr) {
			cout << act->elem << ' ';
			act = act->sig;
		}
		cout << endl;
	}
};

#endif // !queue_ext

