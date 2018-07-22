#include "fastest_of_class.hpp"

std::vector<Spaceship> fastest_of_class(std::vector<Spaceship> ship){
	std::vector<Spaceship> ausgabe; // Array in welches Items eingefuegt werden, die ausgegeben werden sollen.
	for(int x = 0; x < ship.size();x++){
		x = binary_search_upper(ship, ship.at(x)); // Finde Index von  max. Wert in der Klasse Array[x], diese wird neue x, somit durchlaufen wir jede Klasse nur einmal.
		ausgabe.push_back(ship.at(x)); // Speichere Array im Index in Ausgabe Array. (Max. der Klasse des jeweiligen Array[x] )
	}
	return ausgabe;
}