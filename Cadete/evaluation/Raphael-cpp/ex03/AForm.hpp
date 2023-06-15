/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:11 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 14:44:47 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>

# include "Bureaucrat.hpp"
# include "color.hpp"

# define AFO_MSG		"[ " COLOR_YELLOW "AFO" COLOR_RESET " ] "

# define AFO_HIGHEST_GRADE	1
# define AFO_LOWEST_GRADE	150

# define AFO_DEFAULT_NAME				"unknown"
# define AFO_DEFAULT_TARGET				"unknown"
# define AFO_DEFAULT_IS_SIGNED			false
# define AFO_DEFAULT_GRADE_TO_SIGN		AFO_HIGHEST_GRADE
# define AFO_DEFAULT_GRADE_TO_EXECUTE	AFO_HIGHEST_GRADE

# define AFO_GRADE_TOO_HIGH_EXCEPTION	"Grade too high"
# define AFO_GRADE_TOO_LOW_EXCEPTION	"Grade too low"
# define AFO_NOT_SIGNED					"Form not signed"

class	Bureaucrat;

class	AForm
{
	public:
		AForm ( void );
		AForm ( const AForm& obj );
		AForm ( const std::string& name , int gradeToSign , int gradeToExecute );
		AForm ( const std::string& name , int gradeToSign , int gradeToExecute , const std::string& target );
		virtual ~AForm ( void );

		const std::string	getName ( void ) const;
		const std::string	getTarget ( void ) const;
		bool				getIsSigned ( void ) const;
		int					getGradeToSign ( void ) const;
		int					getGradeToExecute ( void ) const;

		void	setName ( const std::string& name );
		void	setTarget ( const std::string& target );
		void	setIsSigned ( bool isSigned );
		void	setGradeToSign ( int gradeToSign );
		void	setGradeToExecute ( int gradeToExecute );

		bool			beSign ( const Bureaucrat& bureaucrat );
		virtual bool	execute ( Bureaucrat const& executor ) const = 0;

		AForm&	operator = ( const AForm& obj );

		class	GradeTooHighException;
		class	GradeTooLowException;
		class	FormNotSigned;

	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream&	operator << ( std::ostream& out, const AForm& obj );

class	AForm::GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw ();
};

class	AForm::GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw ();
};

class	AForm::FormNotSigned : public std::exception
{
	public:
		const char* what() const throw ();
};

#endif // AFORM_HPP
