#pragma once
#include "Node.h"
#include <iostream>

using namespace std;
class Stack
{
private:
	Node* top;

public:
	Stack();
	~Stack();

	void push(int data);
	void display(ostream& os);
	bool pop();
	bool peek(int &data);

	friend ostream& operator<<(ostream& os, Stack& right);
};

