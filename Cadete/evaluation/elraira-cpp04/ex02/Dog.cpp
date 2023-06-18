/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:24:41 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 23:25:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << WHITE << "New Dog created!" << RESET << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(Dog const& src) {
    std::cout << WHITE << "Dog created by copy!" << RESET << std::endl;
    *this = src;
}

Dog::~Dog() {
    std::cout << RED << "Dog destroyed!" << RESET << std::endl;
    delete this->_brain;
}

Dog& Dog::operator=(Dog const& rhs) {
    if (this != &rhs) {
        this->_type = rhs._type;
        this->_brain = new Brain(*rhs._brain);
    }
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Au Au Au" << std::endl;
}

Brain* Dog::getBrain(void) const {
    return this->_brain;
}
