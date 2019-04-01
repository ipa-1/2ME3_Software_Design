/**
 * \file Stack.h
 * \author Emily Horsman <horsmane@mcmaster.ca>
 * \brief Provides an abstract data type (ADT) for a first-in-last-out data
 *   structure which can transition to/from a std::vector.
 */
#ifndef A3_STACK_H_
#define A3_STACK_H_

#include <vector>

/**
 * \brief ADT for a first-in-last-out data structure which can transition
 *        to/from a std::vector.
 */
template <class T>
class Stack {
 private:
  std::vector<T> m_s;

 public:
  /**
   * \brief Default constructor for Stack.
   *
   * \details This is a language-specific implementation detail and is
   *   deliberately not in the specification. It should not be used.
   */
  Stack();

  /**
   * \brief Constructs a new Stack instance from a given sequence.
   * \param s The initial sequence. The last member of the vector will be
   *   the top of the stack. The memory contained by the vector will be
   *   copied.
   */
  explicit Stack(const std::vector<T> s);
  // Note! You could use a reference or pointer for this parameter.
  // This would be a wiser choice. We have avoided these in the sample solution
  // to increase accessibility. As it is now, C++ will simply make copies of
  // the data structure and its contents (or "move" it, if the compiler deems
  // that a viable optimization).

  /**
   * \brief Returns a new stack with the given item at the top. Does not
   *   modify the original stack.
   * \param v The item to add to the top of the stack.
   */
  Stack<T> push(const T v) const;

  /**
   * \brief Returns the item on the top of the stack.
   * \throws std::out_of_range if the stack does not contain any items.
   */
  T top() const;

  /**
   * \brief Removes the element at the top of the stack and returns the
   *   remaining stack. Does not modify the original stack.
   * \throws std::out_of_range if the stack does not contain any items.
   */
  Stack<T> pop() const;

  /**
   * \brief Gets the number of items in the stack.
   */
  size_t size() const;

  /**
   * \brief Returns a sequence of the members of this stack.
   * \details The first item was the first item inserted. The last item
   *   is the first item that would be popped off. This getter is
   *   intended for a View module to translate state into view.
   * \returns A copy of the sequence.
   */
  std::vector<T> toSeq() const;
};

#endif
