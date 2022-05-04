//Anthony Franklin afranklin18@cnm.edu
//FranklinP5
//03/15/2022

//ListMgr.h


#ifndef _LIST_MGR_H
#define _LIST_MGR_H

#include "PersonNode.h"
#include <string>
#include <iostream>

class ListMgr
{
protected:
   int count{0}; //Num PersonNodes currently in list
   PersonNode* first{ nullptr }, * last{ nullptr };
   void Delete(PersonNode* temp);
public:
    ListMgr() = default;

    //Use insert with LL creation for ordered list
    void Insert(Person* p);

    //Sorts the list alphabetically
    void Sort();
    
    //Person* input, added to the front of the list
   void Push_front(Person *p);

   //Person* input, added to the end of the list
   void Push_back(Person *p);

   //Removes from the front of the list
   void Pop_front();

   //Removes from the end of the list
   void Pop_back();

   //Returns the number of PersonNodes in the list
   int Size(){return count;}

   //Returns a pointer to the first Person
   Person* Front();

   //Returns a pointer to the last Person
   Person* Back();

   //Returns a pointer if Matching Person is found else returns nullptr;
   //bool Find(Person* p);

   //Returns true if the list is empty, false if not
   bool Empty() { return count == 0; }

   //Removes any (and all) PersonNode from the list that contains "n" in name
   //n could be full or partial name
   void Remove(string n);

   //Removes the PersonNode at position pos.
   //Note: first string is #1
   void Erase( int pos );

   //Clears all PersonNodes from the list
   void Clear();

   //Shows the list, names only. First line states number in list
   //Second, 3rd, + lines shows names of people in the list. 
   //Place several names on one line. 
   //Separate names using obvious symbol, such as --> or :: 
   void Show();

   //This show function returns a string that has the same features
   //of the show(), except it has been stringstreamed into a string
   string ShowString();

   //Destructor, clears the list
   ~ListMgr();

};

#endif