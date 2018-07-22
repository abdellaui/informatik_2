#include "Simple_class.hpp"				// Import der Klassendeklaration

Simple_class::Simple_class(int x){		// Definition -> Konstruktor mit Parameter 
	this->eingabe = x;					// this-Zeiger auf privat Attribut eingabe
}

int Simple_class::get(){				// Getter
	return this->eingabe;				// this-Zeiger auf privat Attribut eingabe
}

void Simple_class::set(int x){			// Setter
	this->eingabe = x;					// this-Zeiger auf privat Attribut eingabe wird ueberschrieben
}