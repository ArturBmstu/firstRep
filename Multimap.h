#include <iostream>
#include <string.h>
#include <string>

using namespace std;

typedef struct {
    IObject *key;
    IObject *value;
} KeyVal;

class Multimap {
    KeyVal* pair;
    int k;
	int kMax;
public:
    Multimap(int);
    Multimap(const Multimap&);
    void add(IObject*, IObject*);
    void erase(IObject*);
    IObject* find(IObject*);
	friend ostream& operator<< (ostream&, const Multimap&);
    ~Multimap();
};

int differ(const void *,const void *);
