/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:55:13 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 21:03:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX00_WRONGANIMAL_HPP_
#define MODULE_04_EX00_WRONGANIMAL_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define RED "\033[0;31m"

/* WRONGANIMAL CLASS */
class WrongAnimal {
 public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const& src);
    ~WrongAnimal();

    WrongAnimal& operator=(WrongAnimal const& rhs);

    /* Accessors */
    std::string getType(void) const;

    /* Mutators */
    void setType(std::string type);

    void makeSound(void) const;

 protected:
    std::string _type;
};

#endif  // MODULE_04_EX00_WRONGANIMAL_HPP_
