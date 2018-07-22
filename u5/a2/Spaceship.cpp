#include "Spaceship.hpp"

Spaceship::Spaceship(std::string type, int speed){ // Was bitte soll ich hier kommentieren!? Ist ein Konstruktor.
	this->type = type;	// Parameter werden in eigene Attribute übernommen.
	this->speed = speed;
}

bool Spaceship::operator==(Spaceship other){
	return ((this->speed/100)==(other.speed/100)); // Dividiere durch 100, da letze 2 Nachkommerstellen irrelavent sind.
		// Nach Division vergleiche auf Gleichheit der Attribute.
}