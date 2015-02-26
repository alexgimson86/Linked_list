// A cursor based List ADT
//
// The elements in the collection are all of the same type.
// -It has a finite length (the number of elements).
// -The elements are arranged sequentially:
// o There is a first element and a last element
// o Every element except the last has a unique successor
// o Every element except the first has a unique predecessor
// It has a current position, called the cursor, which points to either
// -one of the elements in the collection OR
// -none of the elements.  This is called EOL (End Of List).
//
// This class uses a doubly linked list to implement the list ADT.


class List_3358 {

public:

	//***********************************************************
	// List_3358: default constructor
	// Preconditions: None.
	// Postconditions: list is empty, cursor at EOL.

	List_3358();

	//***********************************************************
	// List_3358: copy constructor
	// Preconditions: None
	// Postconditions: New list is created, which is a deep copy of src List.
	//   Cursor position is preserved.

	List_3358(const List_3358 & src);

	List_3358& operator=(const List_3358 &rhs);

	//***********************************************************
	// ~List_3358: destructor
	// Preconditions: None.
	// Postconditions: List is destroyed, if dynamically allocated.

	~List_3358();


	//************************************
	// insert:
	// Preconditions: List is not full.
	// Postconditions: The item has been inserted into the list, the cursor
	//   points to the same element it did before the insert.
	//   The new item is the predecessor of the element at the cursor.
	//   If the cursor is at EOL, the new item is the last element.

	void insert(const int & item);

	
	//************************************
	// remove:
	// Preconditions: Cursor is not at EOL and list is not empty.
	// Postconditions: The item at the original cursor is removed from the list.
	//   The cursor points to that item's successor,
	//   or EOL if the removed item was the last element in the list.

	void remove();

	
	//************************************
	// resetFront:
	// Preconditions: None.
	// Postconditions: Cursor points to the first element in the list,
	//   or EOL if the list is empty.

	void resetFront();

	//************************************
	// resetBack:
	// Preconditions: None.
	// Postconditions: Cursor points to the last element in the list.
	//   or EOL if the list is empty.
	
	void resetBack();


	//************************************
	// advance:
	// Preconditions: None.
	// Postconditions: Cursor points to the successor of the element it was
	//   previously pointing to.  If it was the last element, it is now EOL.
	//   If it was EOL, it remains EOL.
	void advance();

	//************************************
	// advance:
	// Preconditions: None.
	// Postconditions: Cursor points to the predecessor of the element it was
	//   previously pointing to.  If it was the first element, it is now EOL.
	//   If it was EOL, it remains EOL.
	
	void backup();

	
	//*******************
	// isEmpty:
	// Preconditions: None.
	// Postconditions: Returns true if the list contains no elements,
	//   and false otherwise.


	bool isEmpty() const;

	
	//*******************
	// atEOL:
	// Preconditions: None.
	// Postconditions: Returns true if the cursor is at EOL,
	//   and false otherwise.

	
	bool atEOL() const;

	
	//*******************
	// isFull:
	// Preconditions: None.
	// Postconditions: Return value is true if the list contains its capacity
	//  of elements, and false otherwise.

	bool isFull() const;


	//*******************
	// getCurrent:
	// Preconditions: Cursor is not at EOL.
	// Postconditions: Returns a copy of the element at the cursor.

	int getCurrent() const;
	void bubbleSort();



private:

	// Node type for doubly linked list.
	struct Node {
		int value;
		Node* next;
		Node* previous;
	};

	Node* head;       // first element
	Node* tail;       // last element
	Node* cursor;     // current element

};