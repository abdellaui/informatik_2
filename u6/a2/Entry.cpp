#include "Entry.hpp"

Entry::Entry(unsigned char hash, std::string key, std::string value)
{	
	this->hash = hash;
	this->key = key;
	this->value = value;
}
