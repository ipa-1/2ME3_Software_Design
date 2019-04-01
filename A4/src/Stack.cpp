/**
 * \file Stack.cpp
 * \author Emily Horsman <horsmane@mcmaster.ca>
 */
#include <stdexcept>
#include <vector>

#include "CardTypes.h"
#include "Stack.h"

template <class T>
Stack<T>::Stack(): m_s() {}

template <class T>
Stack<T>::Stack(const std::vector<T> s)
: m_s(s) {}

template <class T>
size_t Stack<T>::size() const {
  return m_s.size();
}

template <class T>
Stack<T> Stack<T>::push(const T v) const {
  std::vector<T> new_vector(m_s);
  new_vector.push_back(v);
  // Utilizing C++'s move semantics.
  return Stack<T>(new_vector);
}

template <class T>
Stack<T> Stack<T>::pop() const {
  if (m_s.empty()) {
    throw std::out_of_range("STACK_EMPTY");
  }

  std::vector<T> new_vector(m_s.cbegin(), m_s.cend() - 1);
  // Utilizing C++'s move semantics.
  return Stack<T>(new_vector);
}

template <class T>
T Stack<T>::top() const {
  if (m_s.empty()) {
    throw std::out_of_range("STACK_EMPTY");
  }

  return m_s.back();
}

template <class T>
std::vector<T> Stack<T>::toSeq() const {
  return std::vector<T>(m_s.cbegin(), m_s.cend());
}

template class Stack<CardT>;
