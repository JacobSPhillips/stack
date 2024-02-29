#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}

//this is used to delete an entire stack without memory leaks
Stack::~Stack()
{
	// set the temp node to the top
	Node* tmp = top;
	// set up to loop until reaching the end of the stack
	while (tmp != nullptr)
	{
		// define the top as the node after
		top = top->next;
		// delete the temp node that used to be the top
		delete tmp;
		// redefine the temp node as the top
		tmp = top;
	}
}

// inserts a new node on the top of the stack
void Stack::push(int data)
{
	// initialize the new data as 'tmp'
	Node* tmp = new Node(data);
	// sets the temp node's next to be the top
		// does this to keep the stack connected
	tmp->next = top;
	// defines the top as the new temp node
	top = tmp;
}

ostream& operator<<(ostream& os, Stack& right)
{
	right.display(os); // call the display method for the linkedList

	return os; // return the updated ostream 
}

// this will print the items in the stack
void Stack::display(ostream& os)
{
	Node* tmp = top; // set the node to the head

	while (tmp != nullptr)
	{
		os << tmp->data << " "; // output the data stored in the current node and end the line

		tmp = tmp->next;
	}
	os << endl;
}

// this deletes the top node of the stack
bool Stack::pop()
{
	// defines a temp node as the top
	Node* tmp = top;

	// it will return false if the stack is empty
	if (top == nullptr)
	{
		return false;
	}

	// moves the top to the next (node under the top) 
	top = top->next;
	// deletes the temp that is still connected to what was previously the top
	delete tmp;

	return true;
}

// returns the data at the top of the node
bool Stack::peek(int& data)
{
	// checks if stack is empty
	if (top == nullptr) { return false; }

	data = top->data;

	return true;
}
