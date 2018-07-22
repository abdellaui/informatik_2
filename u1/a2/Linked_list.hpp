#ifndef LINKED_LIST 
#define LINKED_LIST
#include <string>
class Linked_list{

		    std::string data;           // String data 
		    Linked_list * nexts;        // Zeiger auf naechste Element

	public:	
		Linked_list(std::string);	// Konsturktor
		void set(std::string);		// Setter
		std::string get();			// Getter
		Linked_list * next();				// Zeiger auf naechste Knoten
		Linked_list * insert_at_index(unsigned int, Linked_list *); // Einfuegen am beliebigen Index
		Linked_list * remove_at_index(unsigned int); // Loeschen am beliebigen Index

};
#endif