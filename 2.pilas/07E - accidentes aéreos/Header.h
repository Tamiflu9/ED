// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#ifndef header_h
#define header_h



#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

using namespace std;

class Fecha {

private:

	int dia, mes, ano;

public:

	Fecha() {};

	Fecha(int d, int m, int a) : dia(d), mes(m) ,ano (a) {}

	int getDia() const {
		return dia;
	}

	int getMes() const {
		return mes;
	}

	int getAno() const {
		return ano;
	}

};

class Accidentes {

private:

	Fecha act;
	int victimas;

public:

	Accidentes() {};
	Accidentes(Fecha acc, int v) : act(acc), victimas(v) {};

	int getVictimas() const {
		return victimas;
	}

	Fecha getActual() {
		return act;
	}
	
};

inline std::ostream & operator<< (std::ostream & out, Fecha const & h) {
	out << std::setfill('0') << std::setw(2) << h.getDia() << '/' << std::setfill('0') << std::setw(2) << h.getMes() << '/' << std::setfill('0') << std::setw(4) << h.getAno();
	return out;
}

#endif // !header_h