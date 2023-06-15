#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() { }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) {
	*this = src;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	*this = rhs;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack<T>() { }

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
	return this->c.end();
}
