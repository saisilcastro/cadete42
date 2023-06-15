#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif
