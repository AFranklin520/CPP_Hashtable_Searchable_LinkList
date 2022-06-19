//Anthony Franklin afranklin18@cnm.edu
//FranklinP5
//03/15/2022

//ListMgr.cpp


#include "ListMgr.h"

//ListMgr::ListMgr(): first{nullptr}, last{nullptr}
//{
//
//}

void ListMgr::Insert(Person* p)
{
	PersonNode* np = first;
	PersonNode* newNode = new PersonNode;
	if (count == 0 || p->GetName() < first->GetPerson()->GetName())
	{
		Push_front(p);
		return;
	}

	if (p->GetName() > last->GetPerson()->GetName())
	{
		Push_back(p);
		return;
	}
	else
	{
			
		while (np->GetNext())
		{
			if (p->GetName() >= np->GetPerson()->GetName() && p->GetName() <= np->GetNext()->GetPerson()->GetName())
			{
				newNode->SetPerson(p);
				PersonNode* after = np->GetNext();
				newNode->SetNext(after);
				np->SetNext(newNode);
				after->SetPrev(newNode);
				newNode->SetPrev(np);
				count++;
				break;
			}
			np = np->GetNext();
		}
	}
}
void ListMgr::Sort()
{
	PersonNode* temp = first;
	ListMgr* lm = new ListMgr;

	//TODO: Instead of all this, try while(last){}
	if (Empty() || count == 1) return;
	while (temp->GetNext())
	{
		Person* p = new Person;
		*p = *temp->GetPerson();
		temp = temp->GetNext();
		Pop_front();
		lm->Insert(p);
		
	}
	Person* p = new Person;
	*p = *last->GetPerson();
	Pop_back();
	lm->Insert(p);
	
//Not sure why this duplicate code is present.
// 	lm->Show();
// 	PersonNode* temp2 = lm->first;
// 	while (temp2->GetNext())
// 	{
// 		Person* p = new Person;
// 		*p = *temp2->GetPerson();
// 		temp2 = temp2->GetNext();
// 		lm->Pop_front();
// 		Insert(p);
// 	}
// 	Person* p2 = new Person;
// 	*p2 = *lm->last->GetPerson();
// 	lm->Pop_back();
// 	Insert(p2);
// 	delete lm;
// 	Show();
}

void ListMgr::Delete(PersonNode* temp)
{
	PersonNode* before = temp->GetPrev();
	PersonNode* after = temp->GetNext();
	before->SetNext(after);
	after->SetPrev(before);
	delete temp;
	--count;
}

void ListMgr::Push_front(Person* p)
{
	PersonNode* np = new PersonNode();
	np->SetPerson(p);
	if (count == 0)
	{
		first = np;
		last = np;
	}
	else
	{
		np->SetNext(first); //NP's next is the current first
		first->SetPrev(np); //Current first's previous is now NP
		first = np; //First now points at NP's location
		first->SetPrev(nullptr);
	}
	count++;
}


void ListMgr::Push_back(Person* p)
{
	PersonNode* np = new PersonNode();
	np->SetPerson(p);
	if (count == 0)
	{
		first = np;
		last = np;
	}
	else
	{
		PersonNode* temp = last;
		np->SetPrev(temp);
		temp->SetNext(np);
		last = np;
		last->SetNext(nullptr);
	}
	++count;
}

void ListMgr::Pop_front()
{
	if (Empty()) return;
	PersonNode* np = first->GetNext();
	delete first;
	if(count == 1 )
	{
		count = 0;
		return;
	}
	first = np;
	first->SetPrev(nullptr);
	--count;
}

void ListMgr::Pop_back()
{
	if (Empty()) return;
	PersonNode* np = last;
	np = last->GetPrev();
	delete last;
	if (count == 1)
	{
		count = 0;
		return;
	}
	last = np;
	last->SetNext(nullptr);
	--count;
}

Person* ListMgr::Front()
{ 
	//if (Empty()) return 0;
	return first->GetPerson();
}

Person* ListMgr::Back()
{
	//if (count == 0) return 0;
	return last->GetPerson();
}

void ListMgr::Remove(string n)
{
	transform(n.begin(), n.end(), n.begin(), ::toupper); //Need to match the case the names come in.
	PersonNode* np = first;
	if (count == 0) return;
	for (int i{ 0 }; i < count; i++)
	{
		if (np->GetPerson()->GetName().find(n) != string::npos)
		{
			if (i == 0)
			{
				np = np->GetNext();
				Pop_front();
				i--; //Count will not advance if first item was removed.
			}
			else if (i == count - 1)
			{
				Pop_back();
				break;
			}
			else
			{
				np = np->GetNext();
				Delete(np->GetPrev());
				--i; //Item at this position was deleted, so we need to check the current item at this position.
				--count;
			}
		}
		else
		{
			np = np->GetNext();
		}
	}
}

void ListMgr::Erase(int pos)
{
	if (pos > count || pos < 1 || Empty()) return;
	PersonNode* np = first;

	for (int i{ 0 }; i < count; i++)
	{
		if (i == pos - 1)
		{
			
			if (i == 0)
			{
				Pop_front();
			}
			else if (i == count - 1)
			{
				Pop_back();
			}
			else
			{
				np = np->GetNext();
				Delete(np->GetPrev());
				--count;
			}
			break;
		}
		else
		{
			np = np->GetNext();
		}
	}
}

void ListMgr::Clear()
{
	
	if (Empty()) return;
	while (count != 0)
	{
		Pop_front();
	}
}

void ListMgr::Show()
{
	int entries{ 0 };
	PersonNode* np = first;
	if (count == 0)
	{
		cout << "\nThis list is empty!";
		return;
	}
	cout << "\nNumber of persons in the link list: " << to_string(count) + "\n";
	while (np -> GetNext() != nullptr)
	{
		cout << np->GetPerson()->GetName() << " --> ";
		np = np->GetNext();
		entries++;
		if (entries == 4)
		{
			cout << "\n";
			entries = 0;
		}
	}
	cout << np->GetPerson()->GetName();
}

string ListMgr::ShowString()
{
	int entries{ 0 };
	string output;
	if (!(count >= 0))
	{
		output = "\nThis list doesn't exist anymore, if, in fact, it ever did!";
		return output;
	}
	if (Empty())
	{
		output = "\nThis list is already empty, unable to clear it!";
		return output;
	}
	output += "\nNumber of persons in the link list: " + to_string(count) + "\n";
	PersonNode* np = first;
	while (np->GetNext())
	{
		output += np->GetPerson()->GetName() + " --> ";
		np = np->GetNext();
		entries++;
		if (entries == 4)
		{
			output += "\n";
			entries = 0;
		}
	}
	output +=  np->GetPerson()->GetName();
	return output;
}

ListMgr::~ListMgr()
{
	cout << "\nThe list is now out of scope and will begin destructors: \n";
	if (Empty())
	{
		return;
	}
	PersonNode* np = first;
	while (np->GetNext() != nullptr)
	{
		if (count == 1)
		{
			delete first;
			count = 0;
			break;
		}
		else
		{
			np = np->GetNext();
			delete first;
			first = np;
			first->SetPrev(nullptr);
		}
		--count;
	}
	delete last;
	count = 0;
}
