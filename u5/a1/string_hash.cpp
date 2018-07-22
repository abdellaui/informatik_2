#include "string_hash.hpp"

unsigned char string_hash(std::string s) {
	if(s==""||s.size()<=0){  // Falls String s leer, dann gebe 0b00000000 zurueck.
		return 0b00000000;
	}
	// für das Hashing werden verschiedene Berechnungen auf dem String s durchgeführt
	// das Ergebnis soll in einem int zwischengespeichert werden
	int ret = 0;
   

	std::string head = s.substr(0,  s.size()-1); // 0 bis letzet Zeichen
	unsigned char tail = s[s.size()-1]; // Letzter Zeichen
	ret = string_hash(head)^tail;  // XOR
	ret = ((ret << 1) | (ret >> (sizeof(unsigned char)*8-1))); //Byte verschiebt sich um ein Bit (<<1), daraufhin wird das erste Bit(>>7) des unveränderten Bytes hinten mit der bitweise Oder-Operator angehängt.
	/* Beispiele:
		10 00 00 00 << 1 | 10 00 00 00 >> 7
	    00 00 00 00      | 00 00 00 01
	 => 00 00 00 01

		10 00 10 00 << 1 | 10 00 10 00 >> 7
	    00 01 00 00      | 00 00 00 01
	 => 00 01 00 01 

		10 10 10 10 << 1 | 10 10 10 10 >> 7
	    01 01 01 00      | 00 00 00 01
	 => 01 01 01 01 

		11 11 11 00 << 1 | 11 11 11 00 >> 7
	    11 11 10 00      | 00 00 00 01
	 => 11 11 10 01
	*/
	// weil später ein char als key verwendet wird, muss hier noch ein cast durchgeführt werden
	return (unsigned char)ret;
}