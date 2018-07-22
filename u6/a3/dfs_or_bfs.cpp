#include "dfs_or_bfs.hpp"
void add_neighbors(Undirected_graph g, std::deque<int> &to_visit, int next, bool dfs)
{
	/*

	std::cout <<"  ###############################" << std::endl;
	(push_front, push_back)  bzw.  entfernt  (pop_front, pop_back)
	std::cout << "DFS: "<< ((dfs)?"true":"false") << std::endl;
	std::cout << "next: "<< next << std::endl;
	std::cout << "Graph: "<< std::endl;
	g.output();
	std::cout << "Dqeue: "<< std::endl;
	for(size_t x = 0; x<to_visit.size();x++){
		std::cout << "         "<< to_visit.at(x) << std::endl;
	}
	*/
	if(dfs){ // Depth First Search

		/*
		 * IM SKIRPT WIRD TIEFENSUCHE WIE FOLGT DARGESTELLT:
		 *

		for(int toPush : g.adjacency_lists.at(next)) {
			//std::cout << "    pushing     "<< f << std::endl;
			to_visit.push_front(toPush);
		}


		 */


		// JEDOCH SOLLEN WIR ZUERST DIE KLEINSTEN WERTE ANSCHAUEN, DAHER EIN REVERSE ITERATION DES SET'S
		std::set<int>::reverse_iterator rit;
		for (rit=g.adjacency_lists.at(next).rbegin(); rit != g.adjacency_lists.at(next).rend(); ++rit){
			//std::cout << "    pushing     "<< *rit << std::endl;
			to_visit.push_front(*rit);
		}

	}else{  // Breadth First Search
		for(int toPush : g.adjacency_lists.at(next)) {
			//std::cout << "    pushing     "<< f << std::endl;
			to_visit.push_back(toPush);
		}
	}

}


std::vector<int> dfs_or_bfs(Undirected_graph g, int start_node, bool dfs)
{
	std::vector<int> visited; // Durchlaufene Knoten
	std::set<int> had;        // Bereits durchlaufene Knoten; set für schnellen member-check
	std::deque<int> to_visit; // Worklist

	// Der Startknoten kommt in die Worklist
	to_visit.push_back(start_node);

	// Solange es was zu tun gibt...
	while(!to_visit.empty())
	{
		// ... entnimm' den nächsten zu untersuchenden Knoten
		int next = to_visit.front();
		to_visit.pop_front();

		// Wenn dieser noch nicht untersucht wurde...
		if(had.find(next) == had.end())
		{
			// ... dann wird er jetzt untersucht:
			had.insert(next);        // Er wurde bereits durchlaufen
			visited.push_back(next); // und gehört damit in die Ergebnisliste.

			// Zudem müssen die Kinder des Knotens auch durchsucht werden:
			add_neighbors(g, to_visit, next, dfs);
		}
	}

	return visited;
}
