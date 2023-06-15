#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &src);
        ~Span();

        class NotEnoughRoomException: public std::exception {
			virtual const char *what(void) const throw() {
				return ("Not enough space in Span to add new number.");
			}
		};
        
		class NotEnoughElementsException: public std::exception {
			virtual const char *what(void) const throw() {
				return ("Not enough elements to find a valid Span.");
			}
		};

        Span &operator=(Span const &rhs);

        void    addNumber(int n);
        int     shortestSpan();
        int     longestSpan();
        void    fillVector(unsigned int n);

    private:
        unsigned int        _n;
        std::vector<int>    _numbers;
};

#endif
