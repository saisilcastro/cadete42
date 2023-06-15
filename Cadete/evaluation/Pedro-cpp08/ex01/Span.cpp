#include "Span.hpp"

Span::Span() { }

Span::Span(unsigned int n): _n(n), _numbers(0) { }

Span::Span(const Span &src) {
    *this = src;
}

Span::~Span() { }

Span	&Span::operator=(const Span &rhs) {
	this->_numbers = rhs._numbers;
	this->_n = rhs._n;
	return *this;
}

void	Span::addNumber(int n) {
	if (this->_numbers.size() >= this->_n)
		throw Span::NotEnoughRoomException();
	else
		this->_numbers.push_back(n);
}

int Span::shortestSpan() {
    if (_numbers.size() <= 1)
        throw Span::NotEnoughElementsException();

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    
    int min = tmp[1] - tmp[0];
    for (size_t i = 2; i < tmp.size(); i++) {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

int Span::longestSpan() {
    if (_numbers.size() <= 1)
        throw Span::NotEnoughElementsException();
    
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::fillVector(unsigned int n) {
    for (unsigned int i = 0; i < n; i++) 
        _numbers.push_back(i);
}
