#pragma once

#ifndef I20
#define I20

#include "bintree_eda.h"

#include <iostream>
#include <string>
#include <fstream>

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T>(l, e, r) {};

	T mini() {
		return minimo(this->raiz);
	}

private:
	T minimo(Link a) {
		if (a->left == nullptr && a->right == nullptr) {
			return a->elem;
		}
		else {
			T m = a->elem;
			if (a->left != nullptr) {
				T aux = minimo(a->left);
				m = std::min(m, aux);
			}
			if (a->right != nullptr) {
				T aux = minimo(a->right);
				m = std::min(m, aux);
			}

			return m;
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

#endif // !I20
