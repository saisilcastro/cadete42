/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:05:49 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 09:57:46 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

# include "color.hpp"
# include "AForm.hpp"

# define BUR_MSG		"[ " COLOR_GREEN "BUR" COLOR_RESET " ] "

# define BUR_HIGHEST_GRADE	1
# define BUR_LOWEST_GRADE	150

# define BUR_DEFAULT_NAME	"unknown"
# define BUR_DEFAULT_GRADE	BUR_LOWEST_GRADE

# define BUR_GRADE_TOO_HIGH_EXCEPTION	"Grade too high"
# define BUR_GRADE_TOO_LOW_EXCEPTION	"Grade too low"

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat ( void );
		Bureaucrat ( const Bureaucrat& obj );
		Bureaucrat ( const std::string& name , int grade );
		virtual ~Bureaucrat ( void );

		const std::string	getName ( void ) const;
		int 				getGrade ( void ) const;

		void	incrementGrade ( void );
		void	decrementGrade ( void );

		void	signForm ( AForm& form ) const;
		void	executeForm ( AForm& form ) const;

		Bureaucrat&	operator = ( const Bureaucrat& obj );

	private:
		const std::string	_name;
		int					_grade;
		class				GradeTooHighException;
		class				GradeTooLowException;
};

std::ostream&	operator << ( std::ostream& out, const Bureaucrat& obj );

class	Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw ();
};

class	Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw ();
};

#endif // BUREAUCRAT_HPP
