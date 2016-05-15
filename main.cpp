#include <iostream>
#include <string.h>
#include <string>
#include "Multimap.h"
#include "IObject.h"

using namespace std;

int main() {
	Multimap map(2);
	
    IntObject* io = new IntObject(3);
    IntObject* io2 = new IntObject(1);
    IntObject* io3 = new IntObject(2);
	CharObject* co = new CharObject('r');
	CharObject* co2 = new CharObject('e');
	CharObject* co3 = new CharObject('d');
	StringObject* so = new StringObject("kto");
	
	map.add(io, co);
	map.add(io2, co2);
	map.add(io3, co3);
	//map.add(co, so);
	cout << map << endl;
	
	IObject* srch = new IntObject(2);
	IObject* _value = map.find(srch);
	_value->show();
	cout<<endl;

	map.erase(srch);
	cout << map <<endl;

	map.add(io, so);
	cout << map <<endl;

    delete io;
	delete io2;
	delete io3;
	delete co;
	delete co2;
	delete co3;
	delete so;
}
