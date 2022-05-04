//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate the implementation of hash tables and searchable link lists in C++
//04/05/2022
//SearchableListMgr.cpp

#include "SearchableListMgr.h"

SearchableListMgr::SearchableListMgr()
{
}

int SearchableListMgr::IsPresent(string name, int mm, int dd, int yy, Person** pPer)
{
	Person* p = new Person(name, mm, dd, yy);
	string n = p->GetName();
	PersonNode* np = first;
	if (count == 0) 
	{
		*pPer = NULL;
		return -1;
	}
	for(int i {0}; i < count; i++)
	{
		//Checks if name and birthdays match before returning Person*		
		if (np->GetPerson()->GetFullDesc() == p->GetFullDesc())
		{
			*pPer = np->GetPerson();
			return i;
			break;
		}
		else if (np->GetNext()->GetPerson()->GetName() > n) //Since nodes are sorted by using Insert() member function, we can stop if next name is < target name
		{
			*pPer = NULL;
			return -1;
		} 

		else np = np->GetNext(); //else goes to next person in node
	}
	*pPer = NULL;
	return -1;
		
}
