/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:51:35 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 21:13:43 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << WHITE << "New Cat created" << RESET << std::endl;
    this->setType("Cat");
}

Cat::Cat(Cat const& src) {
    std::cout << WHITE << "Cat Copy Constructor called"
        << RESET << std::endl;
    *this = src;
}

Cat::~Cat() {
    std::cout << WHITE << "Cat " << this->getType() << " destroyed"
        << RESET << std::endl;
}

Cat& Cat::operator=(Cat const& rhs) {
    std::cout << WHITE << "Cat Assignation operator called"
        << RESET << std::endl;
    if (this != &rhs) {
        this->setType(rhs.getType());
    }

    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << WHITE << "Miau Miau" << RESET << std::endl;
}


