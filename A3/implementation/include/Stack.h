//Alice Ip ipa1

#ifndef A3_STACK_H_
#define A3_STACK_H_
#endif

#include <vector>
#include <iostream> // Standard input/output library
#include <stdexcept> // Standard exceptions for C++
#include CardTypes.h

template <class T> // Stack constructor

class Stack{

	private:
		stack;

	public:
		Stack();
		void push(T item);
		void pop();
		T top();
		unsigned int size();
		void toSeq();
}