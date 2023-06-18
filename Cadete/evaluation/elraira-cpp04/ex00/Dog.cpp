/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:53:39 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 21:06:53 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << WHITE << "New Dog created"
        << RESET << std::endl;
    this->_type = "Dog";
}

Dog::Dog(Dog const& src) {
    std::cout << WHITE << "Dog Copy Constructor called"
        << RESET << std::endl;
    *this = src;
}

Dog::~Dog() {
    std::cout << WHITE << "Dog " << this->getType() << " destroyed"
        << RESET << std::endl;
}

Dog& Dog::operator=(Dog const& rhs) {
    std::cout << WHITE << "Dog Assignation operator called"
        << RESET << std::endl;
    if (this != &rhs) {
        this->setType(rhs.getType());
    }

    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << WHITE << "Au Au" << RESET << std::endl;
}
