#include <iostream>
#include <string.h>
#include <typeinfo>
#include <cstdlib>
#include <string>
#include "IObject.h"
#include "Multimap.h"

using namespace std;

bool IntObject::less(IObject* Obj)
{
    IntObject* IntObj = dynamic_cast<IntObject*>(Obj);
    return(n<IntObj->n);
}

IObject* IntObject::clone()
{
    return new IntObject(n);
}

void IntObject::show()
{
	cout << n;
}

bool CharObject::less(IObject* Obj)
{
    CharObject* CharObj = dynamic_cast<CharObject*>(Obj);
    return(c < CharObj->c);
}

IObject* CharObject::clone()
{
    return new CharObject(c);
}

void CharObject::show()
{
	cout << c;
}

bool StringObject::less(IObject* Obj)
{
    StringObject* StringObj = dynamic_cast<StringObject*>(Obj);
    return(s < StringObj->s);
}

IObject* StringObject::clone()
{
    return new StringObject(s);
}

void StringObject::show()
{
	cout << s;
}
