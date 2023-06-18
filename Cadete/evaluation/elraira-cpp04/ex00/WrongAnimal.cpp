/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:02:07 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 21:04:42 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << WHITE << "New WrongAnimal created"
        << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << WHITE << "WrongAnimal " << this->_type << " created"
        << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src) {
    std::cout << WHITE << "WrongAnimal Copy Constructor called"
        << RESET << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal() {
    if (this->_type != "") {
        std::cout << WHITE << "WrongAnimal of type " << this->_type
            << " destroyed" << RESET << std::endl;
	} else {
        std::cout << WHITE << "WrongAnimal destroyed" << RESET << std::endl;
	}
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
    std::cout << WHITE << "WrongAnimal Assignation operator called"
        << RESET << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }

    return (*this);
}

std::string WrongAnimal::getType(void) const {
    return (this->_type);
}

void WrongAnimal::setType(std::string type) {
    this->_type = type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << WHITE << "... WrongAnimal sound" << RESET << std::endl;
}
