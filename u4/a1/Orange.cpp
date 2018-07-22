#include "Orange.hpp"				// Import der Klassendeklaration

Orange::Orange(int s, int j){		// Definition -> Konstruktor mit Parameter 
	this->sweetness = s;
	this->juicyness = j;
}

bool Orange::operator<(Orange other){
	if(this->sweetness == other.sweetness){ // Falls beide Orangen gleich suess sind, dann spielt die Saftigkeit eine Rolle, sonst sehe unten
		return (this->juicyness < other.juicyness);
	}else{
		return (this->sweetness < other.sweetness); // die Orange, die suesser ist hat mehr Gewichtung.
	}

}