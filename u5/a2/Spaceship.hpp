#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__

#include <string>

class Spaceship {
 public:
	 // Eigenschaften der Raumschiffe
	 std::string type;
	 int speed;
	 // Konstruktor
	 Spaceship(std::string, int);
	 
	 bool operator==(Spaceship);
};

#endif