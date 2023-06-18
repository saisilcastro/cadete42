/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:06:25 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/15 04:56:53 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX02_AANIMAL_HPP_
#define MODULE_04_EX02_AANIMAL_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Brain.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* AANIMAL CLASS */
class AAnimal {
 public:
    AAnimal();
    AAnimal(std::string type);
    AAnimal(AAnimal const& src);
    virtual ~AAnimal();

    AAnimal& operator=(AAnimal const& rhs);

    /* Accessors */
    std::string getType(void) const;

    /* Mutators */
    void setType(std::string type);

    virtual void makeSound(void) const = 0;
    virtual Brain* getBrain(void) const = 0;

 protected:
    std::string _type;
    
};

#endif  // MODULE_04_EX02_AANIMAL_HPP_
