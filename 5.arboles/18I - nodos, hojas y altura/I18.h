#pragma once

#ifndef I18
#define I18

#include <iostream>
#include <fstream>

#include "bintree_eda.h"

template<class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T>(l, e, r) {};

	int nodos() {
		return numNodos(this->raiz);
	}
	int hojas() {
		return numHojas(this->raiz);
	}
	int alt() {
		return altura(this->raiz);
	}
private:
	int numNodos(Link a) {
		if (a == nullptr) {
			return 0;
		}
		else {
			return numNodos(a->left) + numNodos(a->right) + 1;
		}
	}

	int numHojas(Link a) {
		if (a == nullptr) {
			return 0;
		}
		else if (a->left == nullptr && a->right == nullptr) {
			return 1;
		}
		else {
			return numHojas(a->left) + numHojas(a->right);
		}
	}

	int altura(Link a) {
		if (a == nullptr) {
			return 0;
		}
		else {
			return std::max(altura(a->left) + 1, altura(a->right) + 1);
		}

	}
};


// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_ext<T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_ext<T> iz = leerArbol_ext(vacio);
		bintree_ext<T> dr = leerArbol_ext(vacio);
		return { iz, raiz, dr };
	}
}

#endif // !I18
