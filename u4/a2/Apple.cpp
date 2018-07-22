#include "Apple.hpp"			// Import der Klassendeklaration

Apple::Apple(int s, int j){		// Definition -> Konstruktor mit Parameter
	this->sweetness = s;
	this->juicyness = j;
}

bool Apple::operator<(Apple other){
		return ( (this->sweetness*3 + this->juicyness) < (other.sweetness*3 + other.juicyness) );  // Sweetness exakt *3 mehr Gewichtung.
}