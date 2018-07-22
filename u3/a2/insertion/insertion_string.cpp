#include "insertion_string.hpp"

#include <iostream>

std::vector<std::string> insertion_sort (std::vector<std::string> strings, char c){
	unsigned int number_of_strings = strings.size();
	for(unsigned int x = 0; x<number_of_strings; x++){ // Iteriere durch Array
		for(unsigned int y = x; y>0 && compare_by_frequency(strings[y], strings[y-1], c); y--){  // Paarweise vergleichen
			std::string help = strings[y];  // Swap
			strings[y] = strings[y-1];
			strings[y-1] = help;
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