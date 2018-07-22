#ifndef SIMPLE_CLASS 
#define SIMPLE_CLASS
class Simple_class {
		int eingabe;		 // private Attribut eingabe der Klasse -> beinhalt den Integer
	public:
		Simple_class(int x); // der altbekannte Konsturktor
		int get();			 // get-Methode
		void set(int x);	 // set-Methode
};
#endif 