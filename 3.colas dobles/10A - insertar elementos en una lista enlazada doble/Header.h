#ifndef queue_ext
#define queue_ext

#include "deque_eda.h"
#include <iostream>

using namespace std;

template <class T>
class ListaInsertar : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:

	void insertar(ListaInsertar<int> list, int pos) {
		
		Nodo* psig = this->fantasma->sig;
		Nodo* pant = this->fantasma->ant;

		Nodo* ssig = list.fantasma->sig;
		Nodo* sant = list.fantasma->ant;

		if (pos == 0) {

			this->fantasma->sig = ssig;
			ssig->ant = this->fantasma;

			sant->sig = psig;
			psig->ant = sant;
			
		}
		// 
		else if (pos == this->nelems) {

			pant->sig = ssig;
			ssig->ant = pant;

			sant->sig = this->fantasma;
			this->fantasma->ant = sant;
		}
		// 
		else {
			
			int i = 0;
			Nodo* p = this->fantasma->sig;
			while (i < pos-1) {
				p = p->sig;
				i++;
			}
			
			psig = p->sig;

			p->sig = ssig;
			ssig->ant = p;
			
			sant->sig = psig;
			psig->ant = sant;
			

		}

		// sumamos el numero de elementos insertados
		// anulamos la lista insertada

		this->nelems += list.nelems;
		list.fantasma->sig = list.fantasma;
		list.fantasma->ant = list.fantasma;
		list.nelems = 0;
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

