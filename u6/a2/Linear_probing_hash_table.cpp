#include "Linear_probing_hash_table.hpp"

Linear_probing_hash_table::Linear_probing_hash_table()
{
	table.resize(256, nullptr);

}

int Linear_probing_hash_table::get_index(unsigned char hash, std::string key)
{
	int index = -1;
	bool overflowed = false;
	unsigned char x = (hash%256);

	/*
	 * SUCHE DAS ELEMENT IM HASHTABLE
	 * ITERIERE SOLANGE this->table.at(x)->key==key
	 *
	 * */

	while(true){
		if(this->table.at(x)==nullptr){
			index =-1;
			break;
		}else if(this->table.at(x)->key==key){
			index = x;
			break;
		}else{
			if((x >= hash && !overflowed) || (x<hash && overflowed)){ // Falls x>hash und noch kein overflow ODER x<hash und overflowed -> HINDERT ENDLOSS SCHLEIFE BEI VOLLEN HASHTABLES
				if(x==255){overflowed=true;}  // Falls am Ende gelangt, so fange am anfang, setze Attribut overflowed wahr!
				//std::cout << (int)x << std::endl;
				x = (x+1)%256; // Skalar [0-255]
			}else{
				index =-1;
				//std::cout << "break index at"<< std::endl;
				break; // Array durchgelaufen, enthaelt Elemnt nicht.
			}
		}
	}
	return index;
}


void Linear_probing_hash_table::insert(Entry *e)
{
	bool overflowed = false;
	unsigned char x = (e->hash%256);

	/*
	 * EINFUEGEN IN HASHTABLE AM X-TEN STELLE
	 *
	 * */
		while(true){
			if(this->table.at(x)==nullptr || this->table.at(x)->key==e->key){ // Wenn an der x-ten Stelle leer ist oder das gleiche, dann fuege ein oder ueberschreibe!
				this->table.at(x)=e;
				break;
			}else{
				if((x >= e->hash && !overflowed) || (x<e->hash && overflowed)){ // Falls x>hash und noch kein overflow ODER x<hash und overflowed
					if(x==255){overflowed=true;} // Falls am Ende gelangt, so fange am anfang, setze Attribut overflowed wahr!
					//std::cout << (int)x << std::endl;
					x = (x+1)%256;   // Skalar [0-255]
				}else{
					//std::cout << "break insert"<< std::endl;
					break; // Vector benoetigt mehr Kapazitaet. Kann Element nicht einfuegen!
				}
			}
		}
}     


void Linear_probing_hash_table::remove(unsigned char hash, std::string key)
{
	int hashIndex = this->get_index(hash, key); // 1.Finden des Elements:
	//std::cout <<"###############" << hashIndex << std::endl;
	if(hashIndex>-1){
		// Falls ueberhaupt dieses Element vorhanden ist.
		if(this->table.at((hashIndex+1)%256)==nullptr){
			//2.Naechste Zelle ist leer:Das Entfernen eines Eintrags geht problemlos, wenn die darauf folgende Zelleleer ist.

			this->table.at(hashIndex)=nullptr; // loeschen => nullptr
		}else{
			/*
			 * Naechste Zelle ist nicht leer:
			 * Ist  eine  folgende  Zelle  nur  belegt  worden,  weil  alle  Zellen  bis  zur
			 * zu  Entfernenden  belegt  waren  (d.h.  ihr  Hash  wuerde  es  erlauben,  sie  in  der  eben  geleerten  Zelle  zu
			 * speichern),  so  muss  man  sie  in  die  eben  geleerten  Zelle  vorziehen.  Dies  erzeugt  natuerlich  eine  neue
			 * Luecke, fuer die das gleiche gilt.
			 */

			bool overflowed = false;
			int copyHashIndex = hashIndex; // Um overflow stoppen zu koennen, da hashIndex instabil ist, zwischenspeichern.
			//std::cout <<"########x#######" << hashIndex << std::endl;
			this->table.at(hashIndex) = nullptr;

			while(table.at((hashIndex+1)%256)!=nullptr){
				//std::cout << hashIndex << std::endl;
				Entry * tempPointer = this->table.at((hashIndex+1)%256);  // Hilfspointer -> Zwischenspeicher fuer naechste Element
                this->table.at((hashIndex+1)%256) = nullptr;              // Loesche naechsten Element
                this->insert(tempPointer);							// Fuege "naechste Element" neu ein, so dass es seinen "richtigen Platz" annimmt!
				if((hashIndex >= copyHashIndex && !overflowed) || (hashIndex<copyHashIndex && overflowed)){  // Falls x>hash und noch kein overflow ODER x<hash und overflowed -> HINDERT ENDLOSS SCHLEIFE BEI VOLLEN HASHTABLES
					if(hashIndex==255){overflowed=true;} // Falls am Ende gelangt, so fange am anfang, setze Attribut overflowed wahr!

					hashIndex = (hashIndex+1)%256; // Skalar [0-255]
				}else{
					//std::cout << "break delete"<< std::endl;
					break;
				}
			}
		}

	}
}

/*
void Linear_probing_hash_table::output(){
	std::cout<< "---------------------------"<<std::endl;
	std::cout << std::setw(5);
	std::cout<< "Index";
	std::cout<< "  |  ";
	std::cout<< std::setw(5);
	std::cout<< "Hash";
	std::cout<< "  |  ";
	std::cout<< std::setw(25);
	std::cout<< "Key";
	std::cout<< "  |  ";
	std::cout<< "Value";
	std::cout<< std::endl<< std::endl;
	for(size_t x = 0; x<this->table.size();x++){
		if(this->table.at(x)!=nullptr){
		std::cout << std::setw(5);
		std::cout<< x;
		std::cout<< "  |  ";
		std::cout<< std::setw(5);
		std::cout<< (int)this->table.at(x)->hash;
		std::cout<< "  |  ";
		std::cout<< std::setw(25);
		std::cout<<  this->table.at(x)->key;
		std::cout<< "  |  ";
		std::cout<< this->table.at(x)->value;
		std::cout<< std::endl;
		}else{
			/*

			std::cout << std::setw(5);
			std::cout<< x;
			std::cout<< "  |  ";
			std::cout<<"#################    NULL    ####################"<< std::endl;

			*\/
		}
	}

}
*/