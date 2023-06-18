/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:14:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 21:03:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_WRONGCAT_HPP
#define MODULE_04_WRONGCAT_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "WrongAnimal.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define RED "\033[0;31m"

/* WRONGCAT CLASS */
class WrongCat : public WrongAnimal {
 public:
    WrongCat();
    WrongCat(WrongCat const& src);
    ~WrongCat();

    WrongCat& operator=(WrongCat const& rhs);

    void makeSound(void) const;
};

#endif  // MODULE_04_WRONGCAT_HPP
