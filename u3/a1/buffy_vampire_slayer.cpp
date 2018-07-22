#include "buffy_vampire_slayer.hpp"
#include <iostream>

// take all powers and count those of the zombies and vampires
// we return a struct that carries the counter of both creature types
creature_counts count_creatures(int N, int creature_powers[]) {
	
	// this will be our return element
	creature_counts counts;
	
	// these will carry the overall powers of both creature types
	int sum_zombie_powers = 0;
	int sum_vampire_powers = 0;
	
	int count_zombies = 0;
	int count_vampires = 0;
	
	for(int x = 0; x < N; x++){
		if(creature_powers[x]%2==0){
			sum_zombie_powers += creature_powers[x];
			count_zombies++;
		}else{
			sum_vampire_powers += creature_powers[x];
			count_vampires++;
		}

	}
	
	counts.zombie_count = count_zombies;
	counts.vampire_count = count_vampires;
	
	counts.zombie_sum = sum_zombie_powers;
	counts.vampire_sum = sum_vampire_powers;
	
	return counts;
}

void swap(int *a,int *b) {
	int help = *a;
		 *a = *b;
		 *b = help;
}

int *sort(int *elements, int length) {
	int minIndex;

	/*
	 * Eigentlich:
	 * int maxInt = std::numeric_limits<int>::max();
	 * Jedoch: da auf weiter Biblotheke versichtet wird, improvisiere ich folgend:
	 * int maxInt = 0;                         => 00000000000000000000000000000000
	 * maxInt = ~maxInt;                       => 11111111111111111111111111111111
	 * maxInt =  (unsigned int) maxInt >> 1;   => 01111111111111111111111111111111
	 * Somit hat man den max. Wert für int in bsp.weise 32-Bit
	 * 
	 */

	int maxInt = 0;   // Setze quasi alle Bits 0
	maxInt = ~maxInt; // Bit-Komplement => Alle 0'en werden 1'en;
	maxInt = (unsigned int) maxInt >> 1; // Ein Bit um rechts verschieben, zuerst jedoch typcasten, wegen bit-Konstellation, erste Bit != 0 => u_int.
	for(int x = 0;  x < length-1; x++){
		minIndex = x;
		for(int y = x+1; y < length; y++){

			/*
			 * Ich addiere bei geraden Zahlen die max. Int-Wert, sodass der aktuelle (gerade) Wert negativ betrachtet wird,
			 * - ("künstliches" overflowing des Wertebereiches) - 
			 * somit ist Kriterium : gerade < ungerade  erfüllt.
			 * 
			 */

			int a = (elements[y]%2==0? elements[y]+maxInt : elements[y]);  // Wenn elements[y] gerade, dann addiere maxInt, so das diese "overflowed" wird.
			int b = (elements[minIndex]%2==0? elements[minIndex]+maxInt : elements[minIndex]); // Wenn elements[minIndex] gerade, dann addiere maxInt, so das diese "overflowed" wird.
			if (a < b){
	        	minIndex=y;
	       	}
		}
		if (minIndex != x){
			swap(&elements[minIndex], &elements[x]);
		}
	}
	return elements;
}


int *create_attack_plan(int N, int *elements, creature_counts counts) {
	int * attack_plan= new int[N+2];      // Dyn. Array +2 der Ausgangsarray, da Summe der Z./V. dazukommen
	for(int x = 0, y = 0; x < N+1; x++, y++){
		if(x==counts.zombie_count){   //  An das Ende der geradezahligen Folge counts.zombie_count einfügen! 
			attack_plan[x]=counts.zombie_sum;
			x++;					// Array Index +1 da neuer Eintrag, s.o.
		}
		attack_plan[x]=elements[y];  // Übernehme die elements-Array in die attack_plan Array.
	}
	
	attack_plan[N+1] = counts.vampire_sum;  // Ende der Array = Summe der Vampire 

	return attack_plan;
}