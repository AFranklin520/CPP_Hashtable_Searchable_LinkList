//Anthony Franklin afranklin18@cnm.edu
//FranklinP5
//03/15/2022

//PersonNode.h


// This is the linked list node class used by the ListMgr class.

#ifndef _PERSON_NODE_H
#define _PERSON_NODE_H

#include <iostream>
#include "FranklinPersonGen/Person.h"

class PersonNode
{
   private:
      PersonNode *prev, *next;
      Person* person;

   public:
      PersonNode() { next = prev = nullptr; }

      ~PersonNode()
      {
          delete GetPerson(); //Destructing our person object
      }

      void SetPrev(PersonNode *p) { prev = p; }
      void SetNext(PersonNode *n) { next = n; }
      void SetPerson(Person* p) { person = p; }

      PersonNode *GetPrev() { return prev; }
      PersonNode *GetNext() { return next; }
      Person* GetPerson() { return person; }
};

#endif
