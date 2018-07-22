#include "selection_string.hpp"

#include <iostream>

std::vector<std::string> selection_sort (std::vector<std::string> strings, char c) {
	unsigned int minIndex;
	for(unsigned int x = 0;  x < strings.size()-1; x++){
		minIndex = x;  // Setze minIndex = 0 => erste Index
		for(unsigned int y = x+1; y < strings.size(); y++){  // 1-strings.size() durchlaufen und kleinste Element finden

			if (compare_by_frequency(strings[y], strings[minIndex], c)){  // Wenn y kleiner als minIndex ist dann setze minIndex = y;
	        	minIndex=y;
	       	}
		}
		if (minIndex != x){   // Swap
			std::string help = strings[x];
			strings[x] = strings[minIndex];
			strings[minIndex] = help;
		}
	}

	return strings;
}

int compare_by_frequency(std::string a, std::string b, char c) {
	int aZ = 0;  // Summe der Vorkommnisse in a
	int bZ = 0;  // Summe der Vorkommnisse in b
	for(unsigned int x=0; x<a.length(); x++){ // Iteriere durch string a
		if(a.at(x)==c){  // a[x] == c, dann aZ++;
			aZ++;
		}
	}
	for(unsigned x=0; x<b.length(); x++){  // Iteriere durch string b
		if(b.at(x)==c){  // b[x] == c, dann bZ++;
			bZ++;
		}
	}
	return (aZ<bZ?1:0); // Wenn erste Wort kleiner, dann return 1 sonst 0;
}