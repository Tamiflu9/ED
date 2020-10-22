#ifndef ipud_h
#define ipud_h

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

using cancion = string;
using artista = string;
using duracion = int;

class iPud {
private:
	unordered_map<cancion, pair<artista, duracion>> ipud;
	list<cancion> listaRep;
	list<cancion> reproducidas;
public:

	iPud() {};
	
	/* addSong(S,A,D): Anade la cancion S (un string) del artista A (un string) con duracion D (un int) al iPud. 
	Si ya existe una cancion con el mismo nombre la operacion dara error. */
	void addSong(cancion s, artista a, duracion d) {
		auto it = ipud.insert({ s, {a,d} });

		if (!it.second) {
			throw domain_error("ERROR addSong");
		}
	}

	/* addToPlaylist(S): Anade la cancion S al final de la lista de reproduccion. Si la cancion ya se
	encontraba en la lista entonces no se anade (es decir, la lista no tiene canciones repetidas). Si la
	cancion no esta en el iPud se devuelve error. */
	void addToPlayList(cancion s) {
		auto it = ipud.find(s);
		if (it != ipud.end()) {
			auto i = find(listaRep.begin(), listaRep.end(), s);

			if (i == listaRep.end()) {
				listaRep.push_back(s);
			}
		}
		else {
			throw domain_error("ERROR addToPlayList");
		}
	}

	/* current(): Devuelve la primera cancion de la lista de reproduccion. Si la lista de reproduccion es
	vacıa se devuelve error. */
	cancion current() {
		if (!listaRep.empty()) {
			return listaRep.front();
		}
		else {
			throw domain_error("ERROR current");
		}
	}

	/* play(): La primera cancion de la lista de reproduccion abandona la lista de reproduccion y se
	registra como reproducida. Si la lista es vacıa la accion no tiene efecto. */
	cancion play() {
		if (!listaRep.empty()) {
			string s = listaRep.front();
			reproducidas.push_back(s);
			listaRep.pop_front();
			return s;
		}
		else {
			throw domain_error("No hay canciones en la lista");
		}
	}

	/* totalTime(): Devuelve la suma de las duraciones de las canciones que integran la lista de reproduccion actual.
	Si es vacıa se devuelve 0. */
	duracion totalTime() {
		int tiempo = 0;
		if (!listaRep.empty()) {
			for (auto i = listaRep.begin(); i != listaRep.end(); ++i) {
				auto it = ipud.find(*i);
				tiempo += it->second.second;
			}
		}
		return tiempo;
	}

	/* recent(N): Obtiene la lista con las N (mayor que 0) ultimas canciones que se han reproducido
	(mediante la operacion play), de la mas reciente a la mas antigua. Si el numero de canciones
	reproducidas es menor que N se devolveran todas. La lista no tiene repeticiones, de manera que si
	una cancion se ha reproducido mas de una vez solo figurara la reproduccion mas reciente. */
	list<cancion> recent(int n) {
		list<cancion> l;
		if (reproducidas.empty()) {
			throw domain_error("No hay canciones recientes");
		}

		if (reproducidas.size() > n) {
			auto it = reproducidas.end();
			for (int i = 0; i < n; i++) {
				l.push_back(*it);
				--it;
			}
		}
		else {
			for (auto i = reproducidas.begin(); i != reproducidas.end(); ++i) {
				l.push_back(*i);
			}
		}
	
		return l;
	}

	/* deleteSong(S): Elimina todo rastro de la cancion S del iPud. Si la cancion no existe la operacion no tiene efecto. */
	void deleteSong(cancion s) {
		if (ipud.find(s) != ipud.end()) {
			ipud.erase(s);
			auto i = find(listaRep.begin(), listaRep.end(), s);
			if (i != listaRep.end()) {
				listaRep.erase(i);
			}
			auto j = find(reproducidas.begin(), reproducidas.end(), s);
			if (j != reproducidas.end()) {
				reproducidas.erase(j);
			}
		}
		else {
			throw domain_error("ERROR deleteSong");
		}
	}
};

#endif