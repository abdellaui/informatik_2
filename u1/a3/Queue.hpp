#ifndef QUEUE_MEINS 
#define QUEUE_MEINS
#include <string>
#include "../a2/Linked_list.hpp" 

class Queue{
		Linked_list * head; // interne Liste, laut Aufgabenstellung soll auf NULL zeigen.
	public:
		Queue();
		void push(std::string);
		std::string pop();
		bool has_next();
};
#endif