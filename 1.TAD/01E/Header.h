#ifndef _HORAS
#define _HORAS

#include <iostream>
#include <iomanip>
#include <algorithm>

class horas {
private:
	int _hora;
	int _minuto;
	int _segundo;
	static bool check(int h, int m, int s) {
		return h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
	}

public:
	horas() {};

	horas(int h, int m, int s) {
		if (!check(h, m, s))
			throw std::invalid_argument("ERROR");
		else {
			_hora = h; _minuto = m; _segundo = s;
		}
	}
	// observadoras
	int getHora() const { return _hora; }
	int getMinuto() const { return _minuto; }
	int getSegundo() const { return _segundo; }

	// operador de comparacion
	bool operator< (horas const& h) const {
		if (_hora < h._hora) return true;
		else if (_hora > h._hora) return false;
		else if (_minuto < h._minuto) return true;
		else if (_minuto > h._minuto) return false;
		else return _segundo < h._segundo;
	}
};

inline std::ostream & operator<<(std::ostream & salida, horas const& h) {
	salida << std::setfill('0') << std::setw(2) << h.getHora() << ':'
		<< std::setfill('0') << std::setw(2) << h.getMinuto() << ':'
		<< std::setfill('0') << std::setw(2) << h.getSegundo();
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, horas & h) {
	char aux; int hr, m, s;
	entrada >> hr >> aux >> m >> aux >> s;
	h = horas(hr, m, s);
	return entrada;
}

#endif
