//Alice Ip ipa1
// Implementation here
#include <iostream> // Standard input/output library
#include <stdexcept> // Standard exceptions for C++
#include <vector>
#include "CardTypes.h"



template <class T> // Stack constructor
Stack::Stack(vector<T> s ) 
: s (vector<T> {})
{
	this->stack = s;
}

template <class T> // Push onto stack
vector<T> Stack::push(T item){
	std::vector<T> temp = this->stack;
	temp.push_back(item);
	return temp;
}

template <class T> // Pops from stack
vector<T> Stack::pop(){
	if (this->queue->size() == 0)
		throw std::out_of_range("Stack is empty");
	std::vector<T> temp
	std::vector<T> temp = this->stack;
	temp.pop_back();
	return temp;
}

template <class T> // Returns item at top of stack
T Stack::top(){
	if (this.size() == 0)
		throw std::out_of_range("Stack is empty");
	std::vector<T> temp = this->stack;
	return this->stack->temp.back();
}

template <class T> // Returns size of stack
nat Stack::size(){
	return this->stack.size();
}

vector<T> emplate <class T> // Returns the vector
void Stack::toSeq(){
	return this->stack;
}

// Keep this at bottom
template class Stack<CardT>;