/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:44:38 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 20:50:38 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
    std::cout << WHITE << "New Animal created"
        << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << WHITE << " New " << this->_type << "Animal created"
        << RESET << std::endl;
}

Animal::Animal(Animal const& src) {
    std::cout << WHITE << "Animal Copy Constructor called"
        << RESET << std::endl;
    *this = src;
}

Animal::~Animal() {
    if (this->_type != "") {
        std::cout << WHITE << "Animal of type " << this->_type
		    << " destroyed" << RESET << std::endl;
    } else {
        std::cout << WHITE << "Animal destroyed" << RESET << std::endl;
    }
}

Animal& Animal::operator=(Animal const& rhs) {
    std::cout << WHITE << "Animal Assignation operator called"
        << RESET << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }

    return (*this);
}

std::string Animal::getType(void) const {
    return (this->_type);
}

void Animal::setType(std::string type) {
    this->_type = type;
}

void Animal::makeSound(void) const {
    std::cout << WHITE << "Random Animal sound" << RESET << std::endl;
}

