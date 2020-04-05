//Name :- Fyaz Manknojiya
//Student id :- 200429859

#include <iostream>
#include <string>
#include <cassert>
#include <stdlib.h>

using namespace std;

struct SparseArrayNode {
int index;
string value; 
SparseArrayNode* next;
};

class SparseArray{
private:
bool isAnyDefault () const;
bool isSorted () const;
const SparseArrayNode* getExactNode (int index) const;
SparseArrayNode* getExactNode (int index);
SparseArrayNode* getPreviousNode (int index);
SparseArrayNode* copyLinkedList (const SparseArrayNode* p_old_head) const;
bool invariant () const;
string defaultValue;
SparseArrayNode* headPointer;

public:
SparseArray ();
SparseArray (const string& default_value);
SparseArray (const SparseArray& to_copy);
~SparseArray ();
SparseArray& operator= (const SparseArray& to_copy);
bool isEmpty () const;
const string& getDefaultValue () const;
bool isSet (int index) const;
const string& getAt (int index) const;
unsigned int getNodeCount () const;
void printNodes () const;
void insert (int index, const string& value);
void remove (int index);
void clear ();
};

