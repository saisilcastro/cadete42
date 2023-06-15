/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:05:49 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/13 18:24:14 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

# include "color.hpp"

# define BUR_MSG	"[ " COLOR_GREEN "BUR" COLOR_RESET " ] "
# define HIG_MSG	"[ " COLOR_RED "HIG" COLOR_RESET " ] "
# define LOW_MSG	"[ " COLOR_RED "LOW" COLOR_RESET " ] "

# define HIGHEST_GRADE	1
# define LOWEST_GRADE	150

# define DEFAULT_NAME	"unknown"
# define DEFAULT_GRADE	LOWEST_GRADE

# define GRADE_TOO_HIGH_EXCEPTION	HIG_MSG "Grade too high"
# define GRADE_TOO_LOW_EXCEPTION	LOW_MSG "Grade too low"

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

		Bureaucrat& operator = ( const Bureaucrat& obj );

	private:
		const std::string	_name;
		int					_grade;

		class				GradeTooHighException;
		class				GradeTooLowException;
};

std::ostream& operator << ( std::ostream& out, const Bureaucrat& obj );

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
