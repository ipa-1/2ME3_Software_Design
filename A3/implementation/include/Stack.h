//Alice Ip ipa1

#ifndef A3_STACK_H_
#define A3_STACK_H_
#include <vector>
#include <iostream> // Standard input/output library
#include <stdexcept> // Standard exceptions for C++
#include "CardTypes.h"


template <class T>// Stack constructor
class Stack{

	private:
		std::vector<T> stack;

	public:
		Stack(std::vector<T> cs) ;
		Stack<T> push(T item) const;
		Stack<T> pop() const;
		T top() const;
		nat size() const;
		std::vector<T> toSeq() const;
};
#endif