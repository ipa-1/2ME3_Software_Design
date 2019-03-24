/**
 *  \file Stack.h
 *  \author Alice Ip ipa1
 *  \brief A class that represents a generic stack with typical stack functions
 */

#ifndef A3_STACK_H_
#define A3_STACK_H_
#include <vector>
#include <iostream> // Standard input/output library
#include <stdexcept> // Standard exceptions for C++
#include "CardTypes.h"

/**
 *  \brief adds a item of the type T to the stack
 *  \details
 *  \param item, the item to add to the stack
 */
template <class T>
class Stack{

	private:
		/// A vector to store a sequence
		std::vector<T> stack;

	public:
	    /**
	     *  \brief Constructor for the stack
	     *  \param cs a vector representing the 
	     *   initial values in the stack
	     */
		Stack(std::vector<T> cs) ;

	    /**
	     *  \brief Adds a item of the type T to the stack
	     *  \param item, the item to add to the stack
	     *  \return A new stack with the desired item added
	     */
		Stack<T> push(T item) const;

	    /**
	     *  \brief Pops an item from the stack
	     *  \return A new stack with the top value 
	     *   popped off of the stack
	     */
		Stack<T> pop() const;

	    /**
	     *  \brief Obtains the top value of stack and returns it
	     *  \return item on the top of the stack
	     */
		T top() const;

	    /**
	     *  \brief Obtains the size of the stack and returns it
	     *  \return Size of the current stack
	     */
		nat size() const;

	    /**
	     *  \brief Returns the vector in the stack
	     *  \return the vector stored in the stack
	     */
		std::vector<T> toSeq() const;
};
#endif