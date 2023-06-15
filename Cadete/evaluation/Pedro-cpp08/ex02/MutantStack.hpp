#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <string>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack<T>();
		MutantStack<T>(const MutantStack<T> &src);
		~MutantStack<T>();

		MutantStack<T>	&operator=(const MutantStack<T> &rhs);

		typedef typename std::stack<T>::container_type::iterator	iterator;
		
		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"

#endif
