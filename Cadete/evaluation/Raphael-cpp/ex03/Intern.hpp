/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:00:28 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 23:48:27 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"
# include "color.hpp"

# define INT_MSG	"[ " COLOR_YELLOW "INT" COLOR_RESET " ] "

class	Intern
{
	public:
		Intern ( void );
		Intern ( const Intern& obj );
		virtual ~Intern ( void );

		AForm*	makeForm ( const std::string& form , const std::string& target );

		Intern&	operator = ( const Intern& obj );
};

std::ostream&	operator << ( std::ostream& out, const Intern& obj );

#endif // INTERN_HPP
