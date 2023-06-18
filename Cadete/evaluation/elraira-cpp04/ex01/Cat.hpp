/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:07:57 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/15 04:56:03 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX01_CAT_HPP_
#define MODULE_04_EX01_CAT_HPP_

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

/* CAT CLASS */
class Cat : public Animal {
 public:
    Cat();
    Cat(Cat const& src);
    virtual ~Cat();

    Cat& operator=(Cat const& rhs);

    /* Accessors */
    Brain* getBrain(void) const;

    virtual void makeSound(void) const;

 private:
    Brain* _brain;
};

#endif  // MODULE_04_EX01_CAT_HPP_

