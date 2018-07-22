#include "Hash_table.hpp"
Hash_table::Hash_table(){
	this->bewertung = std::vector<int>(256,-1);   // bewertung = 256 ints mit -1 Wert
}

void Hash_table::put(std::string title, int value){ // Wandelt String zu einem Index 0-255-> Array mit Index bekommt value als Wert
	if(value>=0 && value<=10){						// Bewertungskalar von 0-10 ueberpruefen.
		this->bewertung.at(string_hash(title))= value;  // bewertung[string_hash(title)] = value
	}
}

int Hash_table::get(std::string title){	// Wandelt String zu einem Index 0-255 -> Gibt Wert von Array mit Index uas;
	return this->bewertung.at(string_hash(title)); // return bewertung[string_hash(title)]
}

