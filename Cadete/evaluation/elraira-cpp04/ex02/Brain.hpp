/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:15:54 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/15 04:56:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX02_BRAIN_HPP_
#define MODULE_04_EX02_BRAIN_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* COLORS */
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* BRAIN CLASS */
class Brain {
 public:
    Brain();
    Brain(Brain const& src);
    ~Brain();

    Brain& operator=(Brain const& rhs);

    /* Accessors */
    void getIdeas(int index) const;

 private:
    std::string _ideas[100];
};

#endif  // MODULE_04_EX02_BRAIN_HPP_
