
#include <iostream>


class Bruch {
public:
	int zaehler;
	int nenner;

	void set(int x, int y) {
		zaehler = x;
		nenner = y;
	}

	void set_bruch() {
		std::cout << "\n==Bruch einlesen==\n";
		std::cout << "Zaehler = ";
		std::cin >> zaehler;
		std::cout << "Nenner = ";
		std::cin >> nenner;
	}

	void ausgabe() {
		std::cout << zaehler << "/" << nenner;
	}

	//Bruch auf gleichen Nenner bringen (ggT)
	int ggt_bruch() {
		int ggt;
		int a, b;
		if (zaehler>nenner) {
			a = zaehler;
			b = nenner;
		}
		else {
			a = nenner;
			b = zaehler;
		}
		while (b != 0) {
			int t = a % b;
			a = b;
			b = t;
		}
		ggt=a;
		return ggt;
	}


	void kuerzen() {
		Bruch g;
		if (zaehler == 0) {
			std::cout << " (Gekuerzt: 0)";
		}
		else if (nenner==zaehler) {
			std::cout << " (Gekuerzt: 1)";
			this->nenner=1;
			this->zaehler=1;
		}
		else if (zaehler!=1 && nenner==1) {
			std::cout << " (Gekuerzt: " << zaehler << ")";
		}
		else if (zaehler!=1 && nenner!=1) {
			if (zaehler>nenner && (this->ggt_bruch()>1)) {
				if (zaehler%nenner == 0) {
				g.zaehler = zaehler/this->ggt_bruch();
				g.nenner = nenner/this->ggt_bruch();
				std::cout << " (Gekuerzt: " << g.zaehler << "/" << g.nenner << " oder " << g.zaehler/g.nenner << ")";
				}
				else {
					g.zaehler = zaehler/this->ggt_bruch();
					g.nenner = nenner/this->ggt_bruch();
					std::cout << " (Gekuerzt: " << g.zaehler << "/" << g.nenner << ")";
				}
			}
			if (nenner>zaehler && (this->ggt_bruch()>1)) {
				g.zaehler = zaehler/this->ggt_bruch();
				g.nenner = nenner/this->ggt_bruch();
				std::cout << " (Gekuerzt: " << g.zaehler << "/" << g.nenner << ")";
			}
		}
	}



	//Multiplizieren von 2 Brüchen
	Bruch mult(Bruch bruch2) {
		Bruch mult;
		mult.zaehler = this->zaehler*bruch2.zaehler;
		mult.nenner = this->nenner*bruch2.nenner;
		return mult;
	}



	//Dividieren von 2 Brüchen
	Bruch divid(Bruch bruch2) {
		Bruch divid;
		Bruch temp = bruch2;
		temp.nenner = bruch2.zaehler;
		temp.zaehler = bruch2.nenner;
		divid = this->mult(temp);
		return divid;
	}



	//Subtrahieren
	Bruch subtr(Bruch b2) {
		Bruch sub;
		sub.zaehler = this->zaehler*b2.nenner - b2.zaehler*this->nenner;
		sub.nenner = this->nenner*b2.nenner;
		return sub;
	}

	//Addieren
	Bruch add(Bruch b2) {
		Bruch add;
		add.zaehler = this->zaehler*b2.nenner + b2.zaehler*this->nenner;
		add.nenner = this->nenner*b2.nenner;
		return add;
	}

	void ausgabe_add(Bruch b2, Bruch e) {
		std::cout << std::endl;
		this->ausgabe();
		std::cout << " + ";
		b2.ausgabe();
		std::cout << " = ";
		e.ausgabe();
		e.kuerzen();
	}

	void ausgabe_sub(Bruch b2, Bruch e) {
		std::cout << std::endl;
		this->ausgabe();
		std::cout << " - ";
		b2.ausgabe();
		std::cout << " = ";
		e.ausgabe();
		e.kuerzen();
	}

	void ausgabe_mult(Bruch b2, Bruch e) {
		std::cout << std::endl;
		this->ausgabe();
		std::cout << " * ";
		b2.ausgabe();
		std::cout << " = ";
		e.ausgabe();
		e.kuerzen();
	}

	void ausgabe_div(Bruch b2, Bruch e) {
		std::cout << std::endl;
		this->ausgabe();
		std::cout << " / ";
		b2.ausgabe();
		std::cout << " = ";
		e.ausgabe();
		e.kuerzen();
	}




};


int main() {

	Bruch b1;
	Bruch b2;

	//Brüche einlesen
	b1.set_bruch();
	b2.set_bruch();

	//Ausgabe b1
	std::cout << "\nBruch 1 = ";
	b1.ausgabe();
	b1.kuerzen();

	//Ausgabe b2
	std::cout << "\nBruch 2 = ";
	b2.ausgabe();
	b2.kuerzen();


	Bruch mult = b1.mult(b2);		//Multiplizieren
	Bruch divid = b1.divid(b2);		//Dividieren
	Bruch add = b1.add(b2);			//Addieren
	Bruch subt = b1.subtr(b2);		//Subtrahieren


	//Ergebnisse der Rechnungen
	std::cout<<std::endl;
	b1.ausgabe_add(b2, add);
	b1.ausgabe_sub(b2, subt);
	b1.ausgabe_mult(b2, mult);
	b1.ausgabe_div(b2, divid);


	return 0;
}
