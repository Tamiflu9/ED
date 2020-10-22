#include "Header.h"
#include <string>
#include <algorithm>

using namespace std;

horas Harray[1000];
horas Carray[1000];

void resuelveCaso() {
	int nTrenes, nConsultas;
	int h, m, s;
	char c;
	cin >> nTrenes >> nConsultas;

	while (nTrenes != 0 && nConsultas != 0) {
		for (int i = 0; i < nTrenes; i++) {
			cin >> h >> c >> m >> c >> s;
			horas horas(h,m,s);
			Harray[i] = horas;
		}
		sort(Harray, Harray + nTrenes);

		for (int i = 0; i < nConsultas; i++) {
			try {
				cin >> h >> c >> m >> c >> s;
				horas horasC(h, m, s);
				Carray[i] = horasC;
				int j = 1;

				while (Carray[i].operator<(Harray[j-1]) && j <= nTrenes) {
					j++;
					if (j <= nTrenes) {
						cout << Harray[j - 1] << endl;
					}
					else {
						cout << "NO" << endl;
					}
				}
			}
			catch (std::invalid_argument & ia) {
				std::cout << ia.what() << endl;
			}
		}
		cout << "---" << endl;
		cin >> nTrenes >> nConsultas;
	}

	
	
}

int main() {
	resuelveCaso();
	return 0;
}