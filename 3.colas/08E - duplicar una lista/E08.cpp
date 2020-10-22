#include "E08.h"

bool casos() {
	ListaDuplica<int> l;

	if (!cin) {
		return false;
	}

	int v;
	cin >> v;

	while (v != 0) {
		l.push(v);
		cin >> v;
	}

	l.duplica();
	l.print();

	return true;
}

int main() {
	while (casos());
	return 0;
}