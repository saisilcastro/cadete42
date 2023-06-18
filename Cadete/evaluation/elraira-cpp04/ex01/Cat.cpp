/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:09:56 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 22:54:24 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << WHITE << "New Cat created!" << RESET << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(Cat const& src) {
    std::cout << WHITE << "Cat created by copy!" << RESET << std::endl;
    *this = src;
}

Cat::~Cat() {
    std::cout << RED << "Cat destroyed!" << RESET << std::endl;
    delete this->_brain;
}

Cat& Cat::operator=(Cat const& rhs) {
    if (this != &rhs) {
        this->_type = rhs._type;
        this->_brain = new Brain(*rhs._brain);
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Miau Miau Miau" << std::endl;
}

Brain* Cat::getBrain(void) const {
    return this->_brain;
}
