#pragma once

#ifndef I21
#define I21

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T>(l, e, r) {};

	int dim() {
		return diametro(this->raiz);
	}

private:
	int diametro(Link a, int &altura) {
		// si el arbol es vacio la altura es 0 y el diametro es 0 tambien
		if (a == nullptr) {
			altura = 0;
			return 0;
		}
		else {
			int altIz, altDr;
			int dimIz = diametro(a->left, altIz);
			int dimDr = diametro(a->right, altDr);

			// la altura es la suma de del maximo entre las alturas de los hijos + 1
			altura = 1 + max(altDr, altIz);

			// el diametro es el maximo valor entre el camino mas largo que pasa por la raiz (1+altura de los hijos) 
			//o el mayor de los diametros de los hijos
			return max(1 + altIz + altDr, max(dimDr, dimIz));
		}
	}

	int diametro(Link arbol) {
		int altura;
		return diametro(arbol, altura);
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

#endif // !I21

