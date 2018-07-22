#include <string>
#include "Queue.hpp"

Queue::Queue(){ // Konstruktor 
    this->head = NULL;
}

void Queue::push(std::string c){        // Laut Aufgabestellung soll ein Knoten am ENDE eingefügt werden.
    Linked_list * p = new Linked_list(c);             // Erzeuge Insantz der Klasse Linked_list mit String c
    Linked_list * m = this->head;
    unsigned int x = 0;             // Hilfsvariable um den Index zu bestimmen
    while(m != NULL){               // Itteration durch head um das Ende der Queue zu finden
        m = m->next();
        x++;
    }
    this->head = this->head->insert_at_index(x, p);
}

std::string Queue::pop(){
    std::string hilfe = this->head->get();  // via Hilfsvariable zwischenspeichern
    this->head = this->head->remove_at_index(0);    // Am Anfang wird ein Element entfernt
    return hilfe;                       // Zwischenspeicher "hilfe" ausgeben.
}   

bool Queue::has_next(){
    if(this->head != NULL && (this->head->get().size()>0 || this->head->next() != NULL)){ // Wenn head != NULL UND Wenn data mehr als 0 Zeichen beinhalten ODER next-Zeiger nicht leer ist
		return true;
	} else {
		return false;
	}
}