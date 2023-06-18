/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:12:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/15 04:56:06 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX01_DOG_HPP_
#define MODULE_04_EX01_DOG_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Animal.hpp"
#include "Brain.hpp"

/* COLORS */
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* DOG CLASS */
class Dog : public Animal {
 public:
    Dog();
    Dog(Dog const& src);
    virtual ~Dog();

    Dog& operator=(Dog const& rhs);

    /* Accessors */
    Brain* getBrain(void) const;

    /* Mutators */
    void setBrain(Brain* brain);

    virtual void makeSound(void) const;

 private:
    Brain* _brain;
};

#endif  // MODULE_04_EX01_DOG_HPP_
