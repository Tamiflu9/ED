#pragma once

#ifndef I19
#define I19

#include "bintree_eda.h"

#include <iostream>
#include <vector>
#include <fstream>

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T>(l, e, r) {};

	std::vector<int> frontera_ext() {
		std::vector<int> v;
		frontera(this->raiz, v);
		return v;
	}

private:

	void frontera(Link a, std::vector<int> &v) {
		// si el arbol esta vacion sale
		if (a == nullptr) {
			return;
		}
		else {
			// si el nodo es una hoja, mostramos el valor porque sería frontera
			if (a->left == nullptr && a->right == nullptr) {
				v.push_back(a->elem);
			}
			// miramos los dos hijos
			frontera(a->left, v);
			frontera(a->right, v);
		}
	}
};

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

#endif // !I19
