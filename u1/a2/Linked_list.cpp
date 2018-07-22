#include <string>
#include "Linked_list.hpp"

Linked_list::Linked_list(std::string s){ // Konstruktor
	this->set(s);
	this->nexts = NULL;		// Init.konsturktor besetzt nexts mit NULL, jedoch wegen Aufgabenstellung doppelt init.
}

void Linked_list::set(std::string s){ // Setter data
	this->data = s;
}

std::string Linked_list::get(){	// Getter data
	return this->data;
}

Linked_list * Linked_list::next(){ // Getter nexts-Pointer
	return this->nexts;
}

Linked_list * Linked_list::insert_at_index(unsigned int i, Linked_list* liste){
	if(liste->next() == NULL){  // Wenn Liste ein Ende hat
		if(i == 0){ // Wenn Start der Liste sich aendert
			liste->nexts = this;	// liste zeigt auf this
			return liste;			// liste wird in this überschrieben
		} else {
			unsigned int x = 1;					// Variable zum Iterieren.
			Linked_list * help = this;		// Hilfszeiger auf this
			help->nexts = this->next();	
			while(x<i && help->next()){       // Solange x kleiner i UND der Naechste hat einen Element
				help = help->next();			// nächster Knoten
				x++;
			}

			liste->nexts = help->next();	// liste zeigt auf help->nexts
			help->nexts = liste;		//help zeigt auf liste, somit wird die Liste zwischen 2 Knoten evt Knoten und NULL eingebunden

			help = NULL; // delete
			return this;
		}
	} else {
		return NULL;	// Wenn eingefügte Liste weitere Elemente hat, dann return NULL
	}

}

Linked_list * Linked_list::remove_at_index(unsigned int i){
            Linked_list * alt = this;	// Hilfvariable alt
            Linked_list * aktuell = alt->next();	// Hilfvariable aktuell
            if(i==0) {				// Wenn Listeanfang gelöscht wird
            	delete alt;         // alt wird nicht mehr benötigt daher delete
                alt = aktuell;		// alt = nächster
                return alt;			
            } else {
            unsigned int x = 1;
	            while(x < i && aktuell != NULL){			// Liste iterieren 
	                alt = aktuell;	// alt wird aktuell
	                aktuell = alt->next();	// aktuell wird alt->nexts
	                x++;
	            }
				alt->nexts = aktuell->next();	// Zeiger auf nächste Zeige -> Das gelöschte Element wird quasi übersprungen
				delete aktuell;  // aktuell wird übersprungen daher delete
	                
            }
            return this;
}
