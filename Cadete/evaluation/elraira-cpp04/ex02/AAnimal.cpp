/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:06:16 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 23:20:34 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << WHITE << "New generic Animal created!" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) {
    std::cout << WHITE << "New " << type << " created!" << RESET << std::endl;
    this->_type = type;
}

AAnimal::AAnimal(AAnimal const& src) {
    std::cout << WHITE << "Animal created by copy!" << RESET << std::endl;
    *this = src;
}

AAnimal::~AAnimal() {
    std::cout << RED << "Animal destroyed!" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const& rhs) {
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

std::string AAnimal::getType(void) const {
    return this->_type;
}

void AAnimal::setType(std::string type) {
    this->_type = type;
}

void AAnimal::makeSound(void) const {
    std::cout << "Generic Animal Sound" << std::endl;
}
