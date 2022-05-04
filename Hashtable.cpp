//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate the implementation of hash tables and searchable link lists in C++
//04/05/2022
//Hashtable.cpp

#include "Hashtable.h"

int HashTable::Hash(Person* p)
{
    int hashTotal = 0;
    string name = p->GetName();
    for (int a : name)
    {
        hashTotal += a;
    }
    hashTotal += p->GetBirthDay().GetDay();
    hashTotal += p->GetBirthDay().GetMonth();
    hashTotal += p->GetBirthDay().GetYear();
    return hashTotal % 100;
}

HashTable::HashTable()
{
    table = new SearchableListMgr[100];
}

void HashTable::HashFunction(Person* p)
{
    table[Hash(p)].Insert(p);
}

int HashTable::GetValue(string name, int mm, int dd, int yy, Person** value)
{
    Person** p = value;
    int tableSize = 100;
    if (table[Hash(*p)].IsPresent(name, mm, dd, yy, p) != -1) //Here we utilize our Hash() member funtion on our target name, so we can look in the correct
        {                                                         //array index position instead of iterating through the entire array.
            return Hash(*p);
        }

    return -1;
}

void HashTable::AnalyzeTable(int distribution[], int total)
{
    for (int i{ 0 }; i < total; i++)
    {
        distribution[i] = table[i].Size();
    }
}

HashTable::~HashTable()
{
    delete[] table;
}
