#include "Binary_heap.hpp"
//#include <iostream>
//#include <stdio.h>
Binary_heap::Binary_heap(){
	Apple dummy(0,0); // Dummy
	this->content.push_back(dummy); // Dummy in content anhaengen.
}

bool Binary_heap::is_empty(){
	return this->content.size()<2;  // Wegen Dummy size < 2 oder !size>1
}

void Binary_heap::insert(Apple a){
	this->content.push_back(a);   // neues Element wird an das Ende des Arrays angehaengt
	this->swim(this->content.size()-1); // Via swim wird der Binaere-Baum umsortiert. this->content.size()-1 wegen Dummy.
}

Apple Binary_heap::del_max(){
	if(this->is_empty()){ return Apple(0,0);}  // Wenn Array "leer", dann gebe Dummy zurück.
	Apple max = this->content.at(1);  // Da der Baum sortiert ist, befindet sich an der Stelle mit Index 1 der groesste Element.
	//std::cout << "SIZE 1 :"<<  this->content.size() << "  |  " << max.sweetness << "  |   "  << max.juicyness <<"  |   " << std::endl;
	this->exch(1,this->content.size()-1);  // Groesste Element wird mit Kleinste vertauscht, so dass sie sich am Ende befindet.
	//this->ausgabe();
    this->content.erase(this->content.begin()+this->content.size()-1);  // erase-Methode entfernt ein Element im Vektor, in diesem Falle das letze Element.
	//this->ausgabe();
	this->sink(1);  // Der Baum wird durch die Methode sink umsortiet.
    //this->ausgabe();
	return max;
}

// PRIVATE METHODEN
void Binary_heap::swim(int k){
	//std::cout << "K => " << k << " /2= " << k/2 << std::endl;

	while(k>1 && (this->content.at(k/2) < this->content.at(k))){ // Ein Knoten wird nach oben positioniert. Sehe Vorlesungsfolien.
		//std::cout << k << " x - k " << k/2 << std::endl;
		this->exch(k, k/2);
		k /= 2;
	}
}

void Binary_heap::sink(int k){
	int N = this->content.size()-1;  // Ein Knoten wird in der Baumstruktur nach unten sortiert. Sehe Vorlesungsfolien.
	while(2*k <= N){
		int j = 2*k;
		if(j < N && (this->content.at(j) < this->content.at(j+1))){
			j++;
		}
		if(this->content.at(j) < this->content.at(k)){
			break;
		}
		this->exch(k,j);
		k = j;
	}

}

void Binary_heap::exch(int i, int j){  // Qausi swap, daher selbstverstaendlich.
	Apple tmp = this->content.at(i); // Hilfsobjekt
	this->content.at(i) = this->content.at(j);
	this->content.at(j) = tmp;
}
/*
void Binary_heap::ausgabe(){
	std::cout << "----------------------" << std::endl;
	for(unsigned int x = 0; x < this->content.size(); x++){
		printf("%8d",this->content.at(x).sweetness);
		std::cout << " | " << this->content.at(x).juicyness << std::endl;
	}
	std::cout << "----------------------" << std::endl;
}
*/