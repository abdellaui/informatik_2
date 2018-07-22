#include <string>
#include <iostream>

#include "tensorflow/cc/client/client_session.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/framework/tensor.h"


using namespace std;
class Linked_list{

            string data;           // String data
            Linked_list * nexts = NULL;        // Zeiger auf naechste Element

    public:
        Linked_list(string);    // Konsturktor
        void set(string);       // Setter
        string get();           // Getter
        Linked_list * next();               // Zeiger auf naechste Knoten
        Linked_list * insert_at_index(unsigned int, Linked_list *); // Einfuegen am beliebigen Index
        Linked_list * remove_at_index(unsigned int); // Loeschen am beliebigen Index

};

Linked_list::Linked_list(string s){
    this->set(s);
    this->nexts = NULL;
}

void Linked_list::set(string s){
    this->data = s;
}

string Linked_list::get(){
    return this->data;
}

Linked_list * Linked_list::next(){
    return this->nexts;
}

Linked_list * Linked_list::insert_at_index(unsigned int i, Linked_list* liste){
    if(liste->next() == NULL){  // Wenn Liste ein Ende hat
        if(i == 0){ // Wenn Start der Liste sich aendert
            liste->nexts = this;
            return liste;
        } else {
            unsigned int x = 1;                 // Variable zum Iterieren.
            Linked_list * help = this;
            help->nexts = this->next();
            while(x<i && help->next()){       // Solange x kleiner i UND der Naechste hat einen Element
                help = help->next();
                x++;
            }

            liste->nexts = help->next();
            help->nexts = liste;
            //delete help;

            help = NULL; // delete
            return this;
        }
    } else {
        return NULL;
    }

}

Linked_list * Linked_list::remove_at_index(unsigned int i){
            Linked_list * alt = this;
            Linked_list * aktuell = alt->next();
            if(i==0) {
                delete alt;
                alt = aktuell;
                //delete alt;
                return alt;
            } else {
            unsigned int x = 1;
            while(aktuell != NULL && x < i){
                if(x == i){
                    alt->nexts = aktuell->next();
                    delete aktuell;
                    break;
                }
                alt = aktuell;
                aktuell = alt->next();
                x++;
            }
            }
            //delete aktuell;
            return this;

}

class Queue{
        Linked_list * head = NULL; // interne Liste
    public:
        Queue();
        void push(string);
        string pop();
        bool has_next();
};

Queue::Queue(){ // Konstruktor
}

void Queue::push(string c){
    Linked_list * p = new Linked_list(c);             // Erzeuge Insantz der Klasse Linked_list mit String c
    Linked_list * n = this->head;
    Linked_list * m = n;
    unsigned int x = 0;
    while(m != NULL){
        m = m->next();
        x++;
    }
    this->head = this->head->insert_at_index(x, p);
}

string Queue::pop(){
    cout << "----------- POP LIST ---------" << endl;
    //if(this->has_next()){
    string s = this->head->get();
    this->head = this->head->remove_at_index(0);
    return s;
    //}
}

bool Queue::has_next(){
    if(
    this->head != NULL && (this->head->get().size()>0 || this->head->next() != NULL)
    //this->head->get().size()>0 ||
    //this->head->next() != NULL
    //true
    ){ // Wenn data mehr als 0 Zeichen beinhalten ODER next-Zeiger nicht leer ist
        return true;
    } else {
        return false;
    }
}

int main(){

 using namespace tensorflow;
  using namespace tensorflow::ops;
  Scope root = Scope::NewRootScope();
  
    Linked_list * a = new Linked_list("a");
    Linked_list * b = new Linked_list("b");
    Linked_list * c = new Linked_list("c");
    Linked_list * d = new Linked_list("d");
    Linked_list * e = new Linked_list("e");
    Linked_list * f = new Linked_list("f");
    Linked_list * dsf = new Linked_list("sa");

    a = a->insert_at_index(0,b);
    a = a->insert_at_index(0,c);
    a = a->insert_at_index(0,d);
    a = a->insert_at_index(0,e);
    a = a->insert_at_index(0,dsf);
    a = a->insert_at_index(0,f);
    a = a->remove_at_index(0);
    a = a->remove_at_index(2);
    int i = 0;
    cout << "----------- DEBUG LINKED_LIST LIST ---------" << endl;
    while(a != NULL){
        cout << i++;
        cout << a->get() << endl;
        a = a->next();
    }
     cout << "----------- DEBUG QUEUE LIST ---------" << endl;
    Queue * q = new Queue();
    q->push("A");
        cout << q->pop() << endl;
    q->push("B");
    q->push("C");
    q->push("D");
    q->push("E");
    q->push("F");
    cout << q->pop() << endl;
    cout << q->pop() << endl;
    cout << q->pop() << endl;
    cout << q->pop() << endl;
    cout << q->pop() << endl;
    q->push("C");
    q->push("D");
    q->push("E");
    q->push("F");
    cout << q->pop() << endl;
    cout << q->pop() << endl;
    cout << q->pop() << endl;

    Queue asd;
    asd.push("A");
    string str = asd.pop();
    cout << str<<endl;
    bool cd = asd.has_next();
    cout << cd<<endl;
return 0;
}
