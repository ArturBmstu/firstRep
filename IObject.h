#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class IObject {
public:
    	virtual bool less(IObject*)=0;
    	virtual IObject* clone()=0;
	virtual void show() = 0;
    	virtual ~IObject() {};
};

class IntObject:public IObject {
    	int n;
public:
    	IntObject(int _n=0): n(_n) {};
	int get() {return n;};
	void set(int _n) {n=_n;};
    	bool less(IObject*);
    	IObject* clone();
	void show();
    	~IntObject() {};
};

class CharObject:public IObject {
    	char c;
public:
    	CharObject(char _c='0'): c(_c) {};
	char get() {return c;};
    	bool less(IObject*);
    	IObject* clone();
	void show();
    	~CharObject() {};
};

class StringObject:public IObject {
    	string s;
public:
    	StringObject(string _s=""): s(_s) {};   
	string get() {return s;};	
	bool less(IObject*);
    	IObject* clone();
	void show();
    	~StringObject() {};
};
