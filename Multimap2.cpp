#include <iostream>
#include <string.h>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include "IObject.h"
#include "Multimap.h"

using namespace std;

Multimap::Multimap(int _k=3)
{
	pair = new KeyVal[_k];
	k = 0;
	kMax = _k;
}

Multimap::Multimap(const Multimap &obj)
{
	k = obj.k;
	kMax = obj.kMax;
	pair = new KeyVal[k];
	for (int i=0; i<k; i++)
		pair[k] = obj.pair[k];
}

int checkType(IObject* obj)
{
	if (typeid(*obj) == typeid(IntObject))
		return 1;
	if (typeid(*obj) == typeid(CharObject))
		return 2;
	if (typeid(*obj) == typeid(StringObject))
		return 3;
	return 0;
}

void Multimap::add(IObject* key, IObject* val)
{
	static int AllKeysType=0;
	static int AllValsType=0;
	static int Temp=0;

	if (!Temp)
	{
		AllKeysType = checkType(key);
		AllValsType = checkType(val);
		Temp = 1;
	}
	if (checkType(key) != AllKeysType || checkType(val) != AllValsType)
	{
		cout << "Memory was not allocated: The types of keys/values are different" << endl;
		return;
	}
	if (k == kMax)
	{
		kMax *= 2;
		pair = (KeyVal*) realloc(pair, kMax*sizeof(KeyVal));
		if (pair == NULL)
			exit(10);
	}

	pair[k].key = key->clone();
	pair[k].value = val->clone();
	
    k++;
	qsort((void*)pair, k, sizeof(KeyVal), differ);

}

void Multimap::erase(IObject* obj)
{
	if (k>0 && typeid(*pair[0].key)==typeid(*obj))
		for (int i=0; i<k; i++)
			if (!pair[i].key->less(obj) && !obj->less(pair[i].key))
			{
				delete pair[i].key;
				delete pair[i].value;
				for (int j=i; j<k-1; j++)
				{
					pair[i].key = pair[i+1].key;
					pair[i].value = pair[i+1].value;
				}
				k--;
				break;
			}
}

IObject* Multimap::find(IObject* obj)
{
	int first = 0;
	int avg = 0;
	int last = k-1;
	
	if (last == -1)
		cout << "\nMap is empty" << endl;
	while (first < last)
	{
		avg = first + (last - first)/2;
		(obj->less(pair[avg].key) || (!obj->less(pair[avg].key) && !pair[avg].key->less(obj))) ? 
			last = avg : first = avg + 1;
	}
	if (!pair[last].key->less(obj) && !obj->less(pair[last].key))
		return pair[last].value;
	cout << "\nElement is not found" << endl;
}

ostream& operator<<(ostream& out, const Multimap& map)
{
	for (int i=0; i< map.k; i++)
	{
		cout << "\t( ";
		map.pair[i].key->show();
		cout << ": ";
		map.pair[i].value->show();
		cout << ")" << endl;
	}
	cout << endl;
}

Multimap::~Multimap()
{
	for (int i=0; i<k; i++)
	{
		delete pair[i].key;
		delete pair[i].value;
	}
	delete pair;
}

int differ(const void *a,const void *b)
{
	KeyVal *x=(KeyVal *)a;
	KeyVal *y=(KeyVal *)b;
	return (x->key->less(y->key)) ? -1 : 1;
}










