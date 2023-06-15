/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:11 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/13 18:23:55 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>

# include "Bureaucrat.hpp"
# include "color.hpp"

# define FOR_MSG		"[ " COLOR_YELLOW "FOR" COLOR_RESET " ] "

# define FOR_HIGHEST_GRADE	1
# define FOR_LOWEST_GRADE	150

# define FOR_DEFAULT_NAME				"unknown"
# define FOR_DEFAULT_IS_SIGNED			false
# define FOR_DEFAULT_GRADE_TO_SIGN		FOR_HIGHEST_GRADE
# define FOR_DEFAULT_GRADE_TO_EXECUTE	FOR_HIGHEST_GRADE

# define FOR_GRADE_TOO_HIGH_EXCEPTION	"Grade too high"
# define FOR_GRADE_TOO_LOW_EXCEPTION	"Grade too low"

class	Bureaucrat;

class	Form
{
	public:
		Form ( void );
		Form ( const Form& obj );
		Form ( const std::string& name , int gradeToSign , int gradeToExecute);
		virtual ~Form ( void );

		const std::string	getName ( void ) const;
		bool				getIsSigned ( void ) const;
		int					getGradeToSign ( void ) const;
		int					getGradeToExecute ( void ) const;

		void	beSign ( const Bureaucrat& bureaucrat );

		Form& operator = ( const Form& obj );

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		class				GradeTooHighException;
		class				GradeTooLowException;
};

std::ostream& operator << ( std::ostream& out, const Form& obj );

class	Form::GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw ();
};

class	Form::GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw ();
};

#endif // FORM_HPP
