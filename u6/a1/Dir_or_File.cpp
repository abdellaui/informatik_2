#include "Dir_or_File.hpp"
//#include <iostream>

Dir_or_File::Dir_or_File(std::string name)
{
	// Evt. name.contains("/") >2 abfangen, jedoch wurde in der Aufgabenstellung erwaehnt, dass diese nur mit "/" bzw. root aufgerufen wird. Anschliessend nur noch insert-Methode....
	this->name = name;
	if(this->name.back()=='/'){
		this->is_file = false;
	}else{
		this->is_file = true;
	}
}


std::vector<std::string> Dir_or_File::split_after_slash(std::string full_path)
{
	std::vector<std::string> ret; // Init. return-Vector
	std::string toPush = ""; // Init. Variable toPush

	// Itaration durch String full_path
	for(std::string::size_type i=0; i<full_path.size(); ++i) {
		// toPush wird full_path[i] angehaengt!
		toPush += full_path.at(i);

		/*
		 * Wenn full_path[i] == / ODER full_path laenge == i+1
		 * ALSO: Wir pushen toPush, welches immer ein Char bei einer Itaration angehaengt bekommt,
		 * in den Vector, falls wir einen / erreichen oder am Ende des String sind.
		 * Nachdem pushen setzen wir toPush = "".
		 * */
		if( (full_path.at(i) == '/') || (full_path.size()==(i+1)) ) {
		    ret.push_back(toPush);
		    toPush = "";
		}
	}
	return ret;
}



void Dir_or_File::insert(std::vector<std::string> names)
{
	//std::cout << " ------ -----------  -------------"<<std::endl;
	//Dir_or_File * helperPointer = this;
	Dir_or_File * prevDir = this;
	//prevDir->entries = this->entries;
	for(std::string nowName : names){  // Iteriere names
		if(nowName.at(0)=='/'){  // Falls string mit / anfaengt abbrechen.
			//std::cout<<"Error detected!";
			break;
		}
		Dir_or_File * nowObj = new Dir_or_File(nowName);
		//std::cout << "prev   " << prevDir->name << std::endl;
		//std::cout << "now    " << nowObj->name << std::endl;

		if(prevDir!=nowObj){
			bool objNotExist = true;
			for(Dir_or_File * c : prevDir->entries){   // Iteriere Entries des Stammes, um Reduntante zu vermeiden
				if(c->name == nowObj->name){
					nowObj = c;          // Wenn es existiert ist nowObj = c (Insantz in Vector)
					objNotExist = false; // object exsist!
					break;               // breche Schleife ab!
				}
			}
			if(objNotExist){ // Wenn Insanz nicht existiert so verknuepfe es mit dem Stamm
				//std::cout << std::endl<< "                                 pointing:          "<< prevDir->name << " -> "<< nowObj->name <<std::endl;
				prevDir->entries.push_back(nowObj);

				// Das neue Element wird hinten eingefuegt und im Anschluss wird Vector sortiert.
				//SELECTION-SORT
					size_t minIndex = 0;
					for(size_t x = 0;  x < prevDir->entries.size()-1; x++){
						minIndex = x;  // Setze minIndex = 0 => erste Index
						for(size_t y = x+1; y < prevDir->entries.size(); y++){  // 1-strings.size() durchlaufen und kleinste Element finden
							if (prevDir->entries.at(y)->name < prevDir->entries.at(minIndex)->name){  // Wenn y kleiner als minIndex ist dann setze minIndex = y;
								minIndex=y;
							}
						}
						if (minIndex != x){   // Swap
							//std::cout << "swap: " << x << " min:" << minIndex << std::endl;
							Dir_or_File * helpSwap = prevDir->entries.at(x);
							prevDir->entries.at(x) = prevDir->entries.at(minIndex);
							prevDir->entries.at(minIndex) = helpSwap;
						}
					}
				// SELECTION-SORT END
			}
		}
		/*std::cout << std::endl<< "Verzeichnisinhalt von : "<< prevDir->name << " #"<< nowObj->name <<std::endl;
			for(Dir_or_File * s : prevDir->entries){
			std::cout << "                     -  "<< s->name << std::endl;
			}
		*/
		if(!nowObj->is_file){ // Wenn jetziger Instanz ein Ordner ist, so ist es prevDir -> Dieser Ordner wird jetz durchgelaufen!
			prevDir = nowObj;
		}
	}
}


/*
void Dir_or_File::output(int x){  // BAUM
	int i = x;
	for(Dir_or_File * s : this->entries){
		std::cout << std::endl;
		while(i>0){std::cout << "  ";i--;}
		i=x;
		std::cout << "|->" << s->name <<std::endl;
		if(!s->is_file){
			s->output(x+2);
		}
	}
}
void Dir_or_File::output2(std::string z){  //PFAD
	for(Dir_or_File * s : this->entries){
		std::cout << std::endl  <<  z << s->name <<std::endl;
		if(!s->is_file){
			s->output2(z+s->name);
		}
	}
}

*/