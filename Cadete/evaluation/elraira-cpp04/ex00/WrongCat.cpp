/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:16:32 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 21:27:33 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    this->setType("WrongCat");
    std::cout << WHITE << "New WrongCat created"
        << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const& src) {
    std::cout << WHITE << "WrongCat Copy Constructor called"
        << RESET << std::endl;
    *this = src;
}

WrongCat::~WrongCat() {
    std::cout << WHITE << "WrongCat " << this->getType() << " destroyed"
        << RESET << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
    std::cout << WHITE << "WrongCat Assignation operator called"
        << RESET << std::endl;
    if (this != &rhs) {
        this->setType(rhs.getType());
    }

    return (*this);
}

void WrongCat::makeSound(void) const {
    std::cout << WHITE << "Muau Muau" << RESET << std::endl;
}

