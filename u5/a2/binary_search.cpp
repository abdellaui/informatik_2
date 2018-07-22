#include "binary_search.hpp"

int binary_search_upper(std::vector<Spaceship> ships, Spaceship ship){
	int retInt = 0; // return Int, init.Wert -1, = nicht gefunden
	int lo = 0; // low Index
	int hi = ships.size()-1; // high Index
	int laenge = hi; // Array max Index
	int m = 0;	// Mitte init.
	while(true){  // ENDLOSSCHLEIFE, Abbruchbedingung im Body!
		m = lo+((hi-lo+1)/2); // Mitte mit padding lo
		if(lo>hi){ // wenn low>hight dann ist gesuchtes Item nicht im Array
			retInt = -1; // ship nicht gefunden!
			break;
		}
		if(ships.at(m).speed == ship.speed){ // Wenn Item mit Index m == Gesuchtes
			retInt = m;						 // Dann setzte Rueckgabe Index = m
			while(retInt<laenge && (ships.at(retInt)==ships.at(retInt+1))){ // Solange retInt kleiner als laenge des Array und Item[retInt] gleicher Klasse mit Item[retInt+1]
				retInt++;												  // steigere retInt++, quasi gebe das groeßte Item in der Kategorie/Klasse.
			}
			break;
		}else if(ship.speed>ships.at(m).speed){ // Wenn Gesuchtes größer als Mitte
			lo = m+1; // Dann setze low Index = m, somit wird die eine Hälfte ignoriert.
		}else{
			hi = m-1;	 // Sonst, lo bleibt gleich hight ist m-1, somit wird rechte Helfte ignoriert.
		}
	}

	return retInt;  // Da eine aufsteigend nach Geschwindigkeit sortierten Liste übergeben wird, ist das Letze Item das Größte.
}
