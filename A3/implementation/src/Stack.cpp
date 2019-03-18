//Alice Ip ipa1
// Implementation here
#include <iostream> // Standard input/output library
#include <stdexcept> // Standard exceptions for C++
#include Stack.h
#include CardTypes.h

template <class T> // Stack constructor
Stack<T>::Stack(vector<vector<T>> s : s({})) {
	this->stack = s;
}

template <class T> // Push onto stack
void Stack<T>::push(T item){

	vector<T> temp = this->stack;
	temp.pushback(item);
	return temp}

template <class T> // Pops from stack
void Stack<T>::pop(){
	if (this->queue->size() == 0)
		throw std::out_of_range("Stack is empty");
	vector<T> temp = this->stack;
	temp.pop_back();
	return temp;
}

template <class T> // Returns item at top of stack
T Stack<T>::top(){
	if (size() == 0)
		throw std::out_of_range("Stack is empty");
	vector<T> temp = this->stack;
	return this->stack->temp.back();
}

template <class T> // Returns size of stack
unsigned int Stack<T>::size(){
	return this->stack.size();
}

template <class T> 
void Stack<T>::toSeq(){
	return this->stack;
	
}

// Keep this at bottom
template class Stack<CardT>;

// intended to help with implementation
// there are several ways to make generics, but to have everyone's
// unit tests pass, we are using the same approach
//https://gitlab.cas.mcmaster.ca/smiths/se2aa4_cs2me3/blob/master/Assignments/PreviousYears/2018/A3/A3Soln/implementation/src/Seq2D.cpp

// push and pop create new stacks
// the output is a stack, and the access programs have an output
// in the case where a mutator is expected, there is no output
// and there would be a transition field instead of output field

// need to provide a default constructor in tut 09