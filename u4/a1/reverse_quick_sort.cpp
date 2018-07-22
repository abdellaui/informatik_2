#include "reverse_quick_sort.hpp"
void reverse_quick_sort(std::vector<Orange> *oranges, int left, int right){
    if (left < right){
        Orange pivot = oranges->at(right);
        int i = left-1; // index of smaller element

        //PARTITION
    	int pi = 0;   //pi is partitioning index
    	    for (int j = left; j < right; j++){
    	    	// If current element is bigger than pivot
    	        if (pivot < oranges->at(j)){
    	            i++;
    	            // swap oranges[i] and oranges[j]
    	            Orange tmp = oranges->at(i);
    	            oranges->at(i) = oranges->at(j);
    	            oranges->at(j) = tmp;
    	        }
    	    }
    	    // swap oranges[i+1] and oranges[right] (or pivot)
            Orange tmp = oranges->at(i+1);
            oranges->at(i+1) = oranges->at(right);
            oranges->at(right) = tmp;
    	    pi = i + 1;  // oranges[pi] now it is at right place


    	//REKRUSION
        // Recursively sort elements before
        // partition and after partition
    	reverse_quick_sort(oranges, left, pi - 1);
    	reverse_quick_sort(oranges, pi + 1, right);
    }
}