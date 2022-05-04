//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate the implementation of hash tables and searchable link lists in C++
//04/05/2022
//Hashtable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "SearchableListMgr.h"

using namespace std;
class HashTable
{
private:
	SearchableListMgr* table {nullptr};
	int Hash(Person* p);  //Hash = (sum(int a : name) + birth_day + birth_month + birth_year) % 100, which will produce values in the range 0-99, inclusive

	/*
	string name = "FRANKLIN, ANTHONY";
	int total{ 0 };
	for (int a : name)
	{
		total += a;
	}
	total += 5;
	total += 20;
	total += 1980;
	cout << format("\nTotal before % : {}", total);  //PRODUCES 3223 (NOT within our range)
	total = abs(total) % 100;
	cout << format("\nTotal after % : {}", total);	//PRODUCES 23 (IS within our range)
	
	*****************************************************************************************
	*****************************************************************************************

	for (int a : name)
	{
		total += a;
	}
	total += -5;
	total += -20;
	total += -1980;
	cout << format("\nTotal before % : {}", total);  //PRODUCES -787 (NOT within our range)
	total = abs(total) % 100;						//Convert to abs value to eliminate potential negative ints; 0 will remain 0
	cout << format("\nTotal after % : {}", total);	//PRODUCES 87 (IS within our range)

	*****************************************************************************************
	*****************************************************************************************

	total = 999999 % 100;
	cout << format("\nTotal after % : {}", total);  //PRODUCES 99 (within our range)

	*/
public:
	HashTable();					//constructor

	void HashFunction(Person* p);	//hash function for storing a Person key into an index


	//finds and returns the Person pointer that matches exactly.  Also returns the index of the found person. Else returns -1
	int GetValue(string name, int mm, int dd, int yy, Person** value);


	//analyze how well the table is balanced
	void AnalyzeTable(int distribution[], int total);

	//destructor
	~HashTable();
};



#endif // !HASHTABLE_H
