
#include <iostream>
#include <cmath>

class Punkt {
public:
	double x;
	double y;

	void einlesen() {
		std::cout << "==Koordinaten einlesen==\n";
		std::cout << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
	}

	void ausgabe() {
		std::cout << "(" << x << "|" << y << ")";
	}

	double abstand(Punkt P2) {
		double a = (P2.x) - (this->x);
		double b = (P2.y) - (this->y);
		double z = pow(a, 2) + pow (b, 2);
		double abstand = sqrt(z);
		return abstand;
	}

	void ausgabe_abstand(Punkt P2) {
		std::cout << "Der Abstand von ";
		this->ausgabe();
		std::cout << " zu ";
		P2.ausgabe();
		std::cout << " ist " << this->abstand(P2) << std::endl;
	}

	Punkt addiere(Punkt P2, Punkt neu) {
		neu.x = this->x + P2.x;
		neu.y = this->y + P2.y;
		return neu;
	}

	void ausgabe_add(Punkt P2) {
		std::cout << "Wenn wir beide Koordinaten addieren, kommen wir zu ";
		Punkt P3;
		this->addiere(P2, P3).ausgabe();
		std::cout << std::endl;

	}

};


int main() {

	//Instanziieren
	Punkt k1;
	Punkt k2;

	//Einlesen
	k1.einlesen();
	k2.einlesen();

	//Abstand mit geeignetem Kommentar ausgeben
	k1.ausgabe_abstand(k2);
	k1.ausgabe_add(k2);

	return 0;
}
