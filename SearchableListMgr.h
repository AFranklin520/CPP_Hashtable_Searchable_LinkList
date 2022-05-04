//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate the implementation of hash tables and searchable link lists in C++
//04/05/2022
//SearchableListMgr.cpp

#ifndef SEARCHABLE_LIST_MGR_H
#define SEARCHABLE_LIST_MGR_H
#include "ListMgr.h"
#include "FranklinPersonGen/PersonGen.h"

class SearchableListMgr : public ListMgr
{
private:

public:
	SearchableListMgr();

	//Search for a Person based on name and birthday
	//Returns node number if the person is present in the list, -1 if not.
	//It also returns a Person* if it finds the Person. 
	//nullptr if the person is not found. 

	int IsPresent(string name, int mm, int dd, int yy, Person** pPer);

};


#endif
