#ifndef conjunto_h 
#define conjunto_h 

#include <cstddef> // size_t 
#include <stdexcept > // std::domain_error 
#include <utility > // std::moveclass set

template <typename T> 
class set { 
public: 
	set(); // constructor 
	set(set<T> const& other); // constructor por copia 
	set<T> & operator=(set<T> const& other); // operador de asignacion 
	~set(); // destructor 
	void insert(T e); 
	bool contains(T e) const; 
	void erase(T e); 
	bool empty() const; 
	size_t size() const; 

private: 
	size_t contador; 
	size_t capacidad; 
	T * datos; // sin repeticiones 
	void amplia(); 
	void libera(); 
	void copia(set<T> const& other); 
};

// Constructor 
template <typename T> 
set<T>::set() : contador(0), capacidad(8), datos(new T[capacidad]) {}

// Destructor 
template <typename T> 
set<T>::~set() { 
	libera(); 
}

// Op. privada que libera la memoria dinamica 
template <typename T> 
void set<T>::libera() { 
	delete[] datos; 
}

// constructor por copia 
template <typename T> 
set<T>::set(set<T> const& other) { 
	copia(other); 
}

// operador de asignacion 
template <typename T> 
set<T> & set<T>::operator=(set<T> const& other) { 
	if (this != &other) { 
		libera(); 
		copia(other); 
	} 
	return *this; 
}

// Op. privada que copia el contenido de un vector 
template <typename T> 
void set<T>::copia(set<T> const& other) { 
	capacidad = other.capacidad; 
	contador = other.contador; 
	datos = new T[capacidad]; 
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

// Operacion para a~nadir elementos 
template <typename T> 
void set<T>::insert(T e) { 
	if (!contains(e)) { 
		if (contador == capacidad) 
			amplia(); 
		datos[contador] = e; 
		++contador; 
	} 
}

// Op. privada que amplia la memoria del vector 
template <typename T> 
void set<T>::amplia() { 
	T * nuevos = new T[2*capacidad]; 
	for (size_t i = 0; i < capacidad; ++i) 
		nuevos[i] = std::move(datos[i]); 
	delete[] datos; 
	datos = nuevos; 
	capacidad *= 2; 
}

// Operacion que comprueba si un elemento pertenece al conjunto 
template <typename T> 
bool set<T>::contains(T e) const { 
	size_t i = 0; 
	while (i < contador && datos[i] != e) ++i; 
	return i < contador; 
}

// Operacion que elimina un elemento del conjuto 
// Lanza una excepcion si el elemento no esta 
template <typename T> 
void set<T>::erase(T e) { 
	size_t i = 0; 
	while (i < contador && datos[i] != e) 
		++i; 
	if (i < contador) { 
		datos[i] = move(datos[contador -1]); 
		--contador; 
	} else 
		throw std::domain_error("El elemento no esta"); 
}

// Comprueba si el conjunto esta vacio 
template <typename T> 
bool set<T>::empty() const { 
	return contador == 0; 
}

// Obtiene el numero de elementos del conjunto 
template <typename T> 
size_t set<T>::size() const { 
	return contador; 
}

#endif // conjunto_h
