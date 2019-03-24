// Alice Ip ipa1
// Implementation here
#include <iostream> // Standard input/output library
#include <stdexcept> // Standard exceptions for C++
#include <vector>

using namespace std;

#include "CardTypes.h"
#include "Stack.h"

template <class T> // Stack constructor
Stack<T>::Stack(std::vector<T> s ) 
: stack ({})
{
	this->stack = s;
}

template <class T> // Push onto stack
Stack<T> Stack<T>::push(T item)const{
	
	std::vector<T> temp = this->stack;
	temp.push_back(item);
	Stack<T> tempStack(temp);
	return tempStack;
}

template <class T> // Pops from stack
Stack<T> Stack<T>::pop() const{
	if (this->stack.size() == 0)
		throw std::out_of_range("Cannot pop if Stack is empty");
	std::vector<T> temp = this->stack;
	temp.pop_back();
	Stack<T> tempStack(temp);
	return tempStack;
}

template <class T> // Returns item at top of stack
T Stack<T>::top() const{
	if (this->stack.size() == 0)
		throw std::out_of_range("Cannot top if Stack is empty");
	return this->stack.back();
}

template <class T> // Returns size of stack
nat Stack<T>::size() const{
	
	return (this->stack).size();
}

template <class T> // Returns the vector
std::vector<T> Stack<T>::toSeq()const{
	return this->stack;
}

// Keep this at bottom
template class Stack<CardT>;
template class Stack<int>;