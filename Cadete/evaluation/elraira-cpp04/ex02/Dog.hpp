/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:23:39 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/15 04:57:09 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX02_DOG_HPP
#define MODULE_04_EX02_DOG_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "AAnimal.hpp"
#include "Brain.hpp"

/* COLORS */
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* DOG CLASS */
class Dog : public AAnimal {
 public:
    Dog();
    Dog(Dog const& src);
    virtual ~Dog();

    Dog& operator=(Dog const& rhs);

    /* Accessors */
    Brain* getBrain(void) const;

    virtual void makeSound(void) const;

 private:
    Brain* _brain;
};

#endif  // MODULE_04_EX02_DOG_HPP

