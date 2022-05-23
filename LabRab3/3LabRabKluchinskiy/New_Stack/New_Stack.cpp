// New_Stack.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "C:\Users\avdot\Desktop\LabRab3\3LabRabKluchinskiy\Unique_ptr\Unique_ptr.cpp"
// TODO: This is an example of a library function
template<typename U>
class Node {
public:
	Node(const U& core) {
		this->core = core;
	}
	~Node() {
		cout << "Destr Node\n";
	}
	my_unique_ptr<Node<U>> prev;
	U core;
};

template <typename T>
class my_stack {
public:
	my_stack();
	~my_stack();


	void push(T core);
	void pop();
	T& top();
	bool empty();

	//void print();

	int size();

private:

	my_unique_ptr<Node<T>> head;
	int number_of_nodes;
};

template<typename T>
my_stack<T>::my_stack()
{
	this->number_of_nodes = 0;
}

template<typename T>
my_stack<T>::~my_stack()
{
}

template<typename T>
void my_stack<T>::push(T core)
{
	my_unique_ptr<Node<T>> ptr(new Node<T>(core));
	if (number_of_nodes) {
		ptr->prev = head;
		head = ptr;
	}
	else {
		head = ptr;
	}
	++number_of_nodes;
}

template<typename T>
void my_stack<T>::pop()
{
	if (!number_of_nodes) {
		return;
	}
	else if (number_of_nodes == 1) {
		head.~my_unique_ptr();
		head.make_null();
	}
	else {
		head.del_with_change(head->prev);
	}
	--number_of_nodes;
}

template<typename T>
T& my_stack<T>::top()
{
	if (number_of_nodes) { return head->core; }
}

template<typename T>
bool my_stack<T>::empty()
{
	return !number_of_nodes;
}


template<typename T>
int my_stack<T>::size()
{
	return number_of_nodes;
}
