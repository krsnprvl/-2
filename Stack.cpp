#include "Stack.h"
// default constructor
Stack::Stack() {
	stack_size = 1;
	// allocate mmemory
	up_node = (stack_nd) new stack_node;
	// set next as null
	up_node->next = 0;
}
// constructor with size
Stack::Stack(int size) {
	stack_size = size;
	up_node = 0;
	stack_nd tmp_dt;
	for (int i = 0; i < stack_size; ++i) {
		// save last up_node
		tmp_dt = up_node;
		// allocate memory for node
		up_node = (stack_nd) new stack_node;
		// allocate random mem
		up_node->data = Coordinates(static_cast<float>(rand() % 301 - 101) + 0.5,
			static_cast<float>(rand() % 301
				- 101) + 0.3,
			static_cast<float>(rand() % 301
				- 101) + 0.1);
		up_node->next = tmp_dt;
	}
}
// rewrite
// copy constructor
Stack::Stack(const Stack& obj) {
	// save stack size
	this->stack_size = obj.stack_size;
	// save up nodes
	stack_nd this_up = (stack_nd) new stack_node;
	stack_nd obj_up = obj.up_node;
	this->up_node = this_up;
	for (int i = 0; i < stack_size; ++i) {
		this_up->data = obj_up->data;
		if (stack_size != stack_size - 1) {
			this_up->next = (stack_nd) new stack_node;
			this_up = this_up->next;
			obj_up = obj_up->next;
		}
	}
}
//=======================================================
// pop node
Coordinates Stack::popNode() {
	// if empty stack
	if (up_node == NULL || stack_size == 0) {
		std::cout << "EMPTY_STACK;" << std::endl;
		return Coordinates();
	}
	// save data and pointer
	Coordinates tmp = up_node->data;
	stack_nd dl_nd = up_node;
	// decrement size of stack
	stack_size--;
	// free mem
	up_node = up_node->next;
	delete dl_nd;
	// return data
	return tmp;
}
// push node
void Stack::pushNode(Coordinates dt) {
	// alocate mem
	stack_nd tmp = new stack_node;
	// incriment size of stack
	stack_size++;
	// save data
	tmp->data = dt;
	// save next pointer
	tmp->next = up_node;
	up_node = tmp;
}
Coordinates& Stack::getUpData() {
	return (this->up_node->data);
}
// GUI
void Stack::displayStack() {
	// it's empty stack
	if (this->isEmpty()) {
		std::cout << "[!!]:> EMPTY_STACK" << std::endl;
		return;
	}
	Coordinates tmp_data;
	int number = 1;
	// header
	std::cout << std::setiosflags(std::ios::left) << std::setfill('=') << std::setw(52) <<
		"=" << std::endl;
	std::cout << std::setfill(' ') << std::setw(14) << "| NUMBER |" << std::setw(14)
		<< " " << std::setw(23) << "DATA IN NODE" << " | " << std::endl;
	std::cout << std::setfill('=') << std::setw(52) << "=" << std::endl;
	// copy stack
	Stack tmp(*this);
	// display stack
	while (!tmp.isEmpty()) {
		tmp_data = tmp.popNode();
		// display info
		std::cout << std::setiosflags(std::ios::right) << std::setfill(' ') << "| " <<
			std::setw(9) << number << " |" << std::setiosflags(std::ios::left) << std::setw(4) << " x:" << std::setprecision(4) << std::setw(8) << tmp_data.getX
			()
			<< std::setw(4) << "|y: " << std::setprecision(4)
			<< std::setw(8) << tmp_data.getY() << std::setw(4) << "|z: "
			<< std::setprecision(4) << std::setw(8) << tmp_data.getZ() << " |" <<
			std::endl;
		std::cout << std::setfill('=') << std::setw(52) << "=" << std::endl;
		// incriment number
		number++;
	}
	// restore flag
	std::cout.unsetf(std::ios::right);
}
// check empty or not
bool Stack::isEmpty() {
	return (stack_size == 0) ? 1 : 0;
}
// free mem
Stack::~Stack() {
	// while not empty
	while (!isEmpty())
		popNode();
}
//===========================================================================================
Stack Stack::operator()(int skip_nodes, char& fl_err) {
	Stack tmp(*this);
	int i = 0;
	fl_err = true;
	// check parametrs
	if (skip_nodes >= 0 && skip_nodes < stack_size)
		while (i != skip_nodes && !tmp.isEmpty()) {
			tmp.popNode();
			i++;
		}
	else {
		// return null stack
		std::cout << "[!!]:> BAD_NUMBER;\n";
		fl_err = false;
		return Stack();
	}
	// return stack
	return tmp;
}
Stack Stack::operator=(const Stack& second) {
	// free mem
	this->~Stack();
	this->stack_size = second.stack_size;
	// save up nodes
	stack_nd this_up = (stack_nd) new stack_node;
	stack_nd obj_up = second.up_node;
	this->up_node = this_up;
	for (int i = 0; i < stack_size; ++i) {
		this_up->data = obj_up->data;
		if (stack_size != stack_size - 1) {
			this_up->next = (stack_nd) new stack_node;
			this_up = this_up->next;
			obj_up = obj_up->next;
		}
	}
	return *this;
}
// overloads
// equal
char Stack::operator==(const Stack& second) {
	Stack first(*this), second_tmp(second);
	// res_fl it's flag of equals
	// 1. res_fl == 0 then not equal
	// 2. res_fl == 1 then equal only size
	// 3. res_fl == 2 then full equal (size and nodes data)
	char res_fl = 0;
	Coordinates tmp_1, tmp_2;
	// if equals sizes
	if (stack_size == second.stack_size) {
		res_fl = 2;
		// check data in nodes
		while (!first.isEmpty() && !second_tmp.isEmpty()) {
			// get data from nodes
			tmp_1 = first.popNode();
			tmp_2 = second_tmp.popNode();
			// if different data in node
			if (tmp_1 != tmp_2) {
				res_fl = 1;
				break;
			}
		}
	}
	return res_fl;
}
// not equal
char Stack::operator!=(const Stack& second) {
	char tmp_res = (*this == second);
	// for !=
	// 1. 0 it's equal size and data
	// 2. 1 it's equal only size
	// 3. 2 full not equal
	// if it's not equals
	switch (tmp_res)
	{
	case 1:
		return tmp_res;
	case 2:
		return false;
	default:
		return 2;
	}
}
// use only stack size (not watch data in nodes)
bool Stack::operator>(const Stack& second) {
	if (this->stack_size > second.stack_size)
		return true;
	return false;
}
bool Stack::operator<(const Stack& second) {
	if (this->stack_size < second.stack_size)
		return true;
	return false;
}
bool Stack::operator<=(const Stack& second) {
	if (this->stack_size <= second.stack_size)
		return true;
	return false;
}
bool Stack::operator>=(const Stack& second) {
	if (this->stack_size >= second.stack_size)
		return true;
	return false;
}