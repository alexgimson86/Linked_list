#include "List.h"
#include"iostream"
#include<cassert>
using namespace std;


//***********************************************************
// List_3358: default constructor
// Preconditions: None.
// Postconditions: list is empty, cursor at EOL.
List_3358::List_3358()
{
	head = NULL;
	cursor = NULL;
	tail = NULL;
}
//***********************************************************
// List_3358: copy constructor
// Preconditions: None
// Postconditions: New list is created, which is a deep copy of src List.
//   Cursor position is preserved.
List_3358::List_3358(const List_3358 & src)
{
	head = NULL;
	tail = NULL;
	cursor = NULL;
	int count = 0;

	Node * n = src.head;

	//find where the cursor is in src list
	while (n != src.cursor && n != NULL)
	{
		n = n->next;
		count++;
	}

	n = src.head;

	while (n != NULL)
	{
		insert(n->value);
		n = n->next;
	}

	cursor = head;
	//set new list to the cursor position of the other
	for (int i = 0; i < count; i++)
		cursor = cursor->next;
}
List_3358& List_3358::operator =(const List_3358 &rhs)
{
	int count = 0;
	if (this != &rhs)
	{
		Node *p = head;
		
		while (p != NULL)
		{
			Node *q = p->next;
			delete p;
			p = q;
		}

		p = rhs.head;

		while (p != NULL)
		{
			insert(p->value);
			p = p->next;
		}

		p = rhs.head;

		while (p != NULL && p != rhs.cursor)
		{
			p = p->next;
			count++;
		}

		cursor = head;

		for (int i = 0; i < count; i++)
			cursor = cursor->next;
	}
	return *this;
}
//************************************
// insert:
// Preconditions: List is not full.
// Postconditions: The item has been inserted into the list, the cursor
//   points to the same element it did before the insert.
//   The new item is the predecessor of the element at the cursor.
//   If the cursor is at EOL, the new item is the last element.
void List_3358::insert(const int & item)
{
	Node *newNode = new Node;
	newNode->value = item;

	//will insert when head is null, list is empty
	if (!head)
	{
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
		newNode->previous = NULL;
	}
	else
	{
		//if cursor is NULL add node to end of list
		//make tail point to newnode and set tail
		//next pointer to null
		if (cursor == NULL)
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
			tail->next = NULL;
		}
		//this is if the cursor isnt the head
		//insert node in front of the node the cursor is 
		//pointing to
		else if (cursor->previous != NULL)
		{
			Node *previousNode = cursor->previous;
			newNode->next = cursor;
			cursor->previous = newNode;

			previousNode->next = newNode;
			newNode->previous = previousNode;
		}
		//if cursor is pointing to head the newnode
		//will be the first in the list
		//set newnode previous pointer to NULL
		else
		{
			newNode->next = cursor;
			cursor->previous = newNode;
			newNode->previous = NULL;
			head = newNode;
		}
	}
}
//************************************
// remove:
// Preconditions: Cursor is not at EOL and list is not empty.
// Postconditions: The item at the original cursor is removed from the list.
//   The cursor points to that item's successor,
//   or EOL if the removed item was the last element in the list.
void List_3358::remove()
{
	//if the cursor isnt NULL or the 
	//list isnt empty, just in case
	if (cursor != NULL && head != NULL)
	{
		Node *p = cursor->previous;

		//cursor points to head
		if (cursor == head)
		{    
			//if there is only one node in the list
			//delete it and set everything to null
			if (head->next == NULL)
			{
				delete cursor;
				head = NULL;
				cursor = NULL;
				tail = NULL;
			}
			//there is more than one node in the list
			else
			{
				head = cursor->next;
				delete cursor;
				cursor = head;
				cursor->previous = NULL;
			}

		}
		//cursor is pointing to tail
		else if (cursor == tail)
		{
			//cursor is on last element of the list
			//delete that element and move tail to 
			//previous node and set cursor to NULL
			tail = cursor->previous;
			delete cursor;
			cursor = NULL;
			tail->next = cursor;
		}
		else
		{   
			//if cursor isnt pointing to either head or tail
			p->next = cursor->next;
			delete cursor;
			cursor = p->next;
			cursor->previous = p;

		}
	}
}
	
//************************************
// resetFront:
// Preconditions: None.
// Postconditions: Cursor points to the first element in the list,
//   or EOL if the list is empty.

void List_3358::resetFront()
{
	cursor = head;
}
//************************************
// resetBack:
// Preconditions: None.
// Postconditions: Cursor points to the last element in the list.
//   or EOL if the list is empty.

void List_3358::resetBack()
{
	cursor = tail;
}
//************************************
// advance:
// Preconditions: None.
// Postconditions: Cursor points to the successor of the element it was
//   previously pointing to.  If it was the last element, it is now EOL.
//   If it was EOL, it remains EOL.

void List_3358::advance()
{
	//make sure cursor doesnt equal null, then advance it
	if (cursor != NULL)
		cursor = cursor->next;
}
//************************************
// backup:
// Preconditions: None.
// Postconditions: Cursor points to the predecessor of the element it was
//   previously pointing to.  If it was the first element, it is now EOL.
//   If it was EOL, it remains EOL.

void List_3358::backup()
{
	//same as advance just backing up
	if (cursor != NULL)
		cursor = cursor->previous;
}
//*******************
// isEmpty:
// Preconditions: None.
// Postconditions: Returns true if the list contains no elements,
//   and false otherwise.

bool List_3358::isEmpty() const
{
	//returns true if list is empty by checking
	//if head is null
	if (head == NULL)
		return true;

	else 
		return false;
}
//*******************
// atEOL:
// Preconditions: None.
// Postconditions: Returns true if the cursor is at EOL,
//   and false otherwise.

bool List_3358::atEOL()const
{
	if (cursor == NULL)
		return true;
	
	else 
		return false;
}
//*******************
// getCurrent:
// Preconditions: Cursor is not at EOL.
// Postconditions: Returns a copy of the element at the cursor.

int List_3358::getCurrent()const
{
	assert(cursor != NULL);
		return cursor->value;
}
//*******************
// isFull:
// Preconditions: None.
// Postconditions: Return value is true if the list contains its capacity
//  of elements, and false otherwise.

bool List_3358::isFull() const
{
	//always false, list is never full
	return false;
}
//***********************************************************
// ~List_3358: destructor
// Preconditions: None.
// Postconditions: List is destroyed, if dynamically allocated.
List_3358::~List_3358()
{
	Node * n = head;

	//while n doesnt equal null
	while (n)
	{
		//set p one ahead of n
		Node *p = n->next;
		delete n;
		//increment n
		n = p;
	}

	//set all pointers to null
	tail = NULL;
	head = NULL;
	cursor = NULL;
}
void List_3358::bubbleSort()
{
	Node * p = head;
	int i = 0;
	int temp;
	while (p->next != NULL)
	{
		for (Node *n = head; n != tail; n = n->next)
		{
			if (n->value > n->next->value)
			{
				temp = n->value;
				n->value = n->next->value;
				n->next->value = temp;
			}
		}
		p = p->next;
	}
}
