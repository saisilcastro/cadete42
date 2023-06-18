/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:53:45 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/15 04:55:20 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX00_DOG_HPP_
#define MODULE_04_EX00_DOG_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Animal.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define RED "\033[0;31m"

/* DOG CLASS */
class Dog : public Animal {
 public:
    Dog();
    Dog(Dog const& src);
    virtual ~Dog();

    Dog& operator=(Dog const& rhs);

    virtual void makeSound(void) const;
};

#endif  // MODULE_04_EX00_DOG_HPP_
