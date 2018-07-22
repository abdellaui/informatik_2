#include "Undirected_graph.hpp"

Undirected_graph::Undirected_graph(int number_of_nodes){
	this->adjacency_lists = std::vector< std::set<int> >(number_of_nodes);
}

void Undirected_graph::add_edge(int node_1, int node_2){
	/*
	Redundanz wird nicht ueberpruft da laut http://www.cplusplus.com/reference/set/set/insert/:

	"Because elements in a set are unique, the insertion operation checks whether each 
	inserted element is equivalent to an element already in the container,
	 and if so, the element is not inserted, returning an iterator to this 
	 existing element (if the function returns a value)."
	 
	*/
	this->adjacency_lists.at(node_1).insert(node_2);
	this->adjacency_lists.at(node_2).insert(node_1);
}

/*
void Undirected_graph::output(){

	for(size_t x = 0; x<this->adjacency_lists.size(); x++){
		std::cout << "##################################"<< std::endl;
		std::cout << x << std::endl;
		for(int f : this->adjacency_lists.at(x)) {
		  std::cout <<"          "<< x << "    "<< f << std::endl;
		}

	}
}
*/
