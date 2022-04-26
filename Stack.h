#pragma once
#include "Coordinates.h" 
#include <iostream>
#include <iomanip> 
#include <ctime>
// struct with coordinates
typedef struct stack_node
{
Coordinates data;
// pointer on next elem
	stack_node* next;
// constructor 
	stack_node() {
	next = NULL;
	}
} *stack_nd;
// stack class realization 
class Stack {
private:
	int stack_size;
	// pointer on up node 
	stack_nd up_node;
public:
	// constructors 
	Stack();
	explicit Stack(int size);
	// copy constructro 
	Stack(const Stack& obj);
	// pop and push node 
	Coordinates popNode();
	void pushNode(Coordinates dt); Coordinates& getUpData();
	// GUI func
	void displayStack();
	// check empty or not
	bool isEmpty();
	//return ref on up node 
	Coordinates& getLinkUp() {
	return up_node->data;
}
// return sub-stack
Stack operator()(int skip_nodes, char& fl_err);
// help overloads
Stack operator=(const Stack& second);
// overloads
char operator!=(const Stack& second); 
char operator==(const Stack& second);
bool operator>(const Stack& second); 
bool operator<(const Stack& second); 
bool operator<=(const Stack& second); 
bool operator>=(const Stack& second);
// destructor
~Stack();
};

