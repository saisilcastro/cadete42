/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:10 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 20:40:23 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form ( void ) :
	_name ( FOR_DEFAULT_NAME ) ,
	_isSigned ( FOR_DEFAULT_IS_SIGNED ) ,
	_gradeToSign ( FOR_DEFAULT_GRADE_TO_SIGN ) ,
	_gradeToExecute ( FOR_DEFAULT_GRADE_TO_EXECUTE )
{
	std::cout << FOR_MSG << "Form's Default constructor called" << std::endl;

	return;
}

Form::Form ( const Form& obj ) :
	_name ( obj.getName () ) ,
	_isSigned ( obj.getIsSigned () ) ,
	_gradeToSign ( obj.getGradeToSign () ) ,
	_gradeToExecute ( obj.getGradeToExecute () )
{
	std::cout << FOR_MSG << "Form's Copy constructor called" << std::endl;
	*this = obj;

	return;
}

Form::Form ( const std::string& name , int gradeToSign , int gradeToExecute) :
	_name ( name ) ,
	_isSigned ( FOR_DEFAULT_IS_SIGNED ) ,
	_gradeToSign ( gradeToSign ) ,
	_gradeToExecute ( gradeToExecute )
{
	std::cout << FOR_MSG << "Form's Name and Grade constructor called" << std::endl;

	try
	{
		if ( this -> _gradeToSign < FOR_HIGHEST_GRADE )
			throw ( Form::GradeTooHighException () );
		else if ( this -> _gradeToSign > FOR_LOWEST_GRADE )
			throw ( Form::GradeTooLowException () );

		if ( this -> _gradeToExecute < FOR_HIGHEST_GRADE )
			throw ( Form::GradeTooHighException () );
		else if ( this -> _gradeToExecute > FOR_LOWEST_GRADE )
			throw ( Form::GradeTooLowException () );
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what () << std::endl;

		if ( this -> _gradeToSign < FOR_HIGHEST_GRADE )
			const_cast<int&> ( this -> _gradeToSign ) = FOR_HIGHEST_GRADE;

		else if ( this -> _gradeToSign > FOR_LOWEST_GRADE )
			const_cast<int&> ( this -> _gradeToSign ) = FOR_LOWEST_GRADE;

		if ( this -> _gradeToExecute < FOR_HIGHEST_GRADE )
			const_cast<int&> ( this -> _gradeToExecute ) = FOR_HIGHEST_GRADE;
		else if ( this -> _gradeToExecute > FOR_LOWEST_GRADE )
			const_cast<int&> ( this -> _gradeToExecute ) = FOR_LOWEST_GRADE;
	}

	return;
}

Form::~Form ( void )
{
	std::cout << FOR_MSG << "Form's Default destructor called" << std::endl;

	return;
}

const std::string	Form::getName ( void ) const
{
	return ( this -> _name );
}

bool	Form::getIsSigned ( void ) const
{
	return ( this -> _isSigned );
}

int	Form::getGradeToSign ( void ) const
{
	return ( this -> _gradeToSign );
}

int	Form::getGradeToExecute ( void ) const
{
	return ( this -> _gradeToExecute );
}

void	Form::beSign ( const Bureaucrat& bureaucrat )
{
	if ( this -> _gradeToSign > bureaucrat.getGrade() )
		this -> _isSigned = true;
	try
	{
		if ( this -> _gradeToSign < bureaucrat.getGrade() )
			throw ( Form::GradeTooLowException () );
	}
	catch ( const std::exception& e )
	{
		std::cout
			<< COLOR_GREEN
			<< bureaucrat.getName ()
			<< COLOR_RESET
			<< " couldn't sign "
			<< COLOR_YELLOW
			<< this -> getName()
			<< COLOR_RESET
			<< " because "
			<< COLOR_RED
			<< e.what ()
			<< COLOR_RESET
			<< '.'
			<< std::endl;
	}

	return;
}

Form& Form::operator = ( const Form& obj )
{
	if ( this != &obj )
	{
		const_cast<std::string&> ( this -> _name ) = obj.getName ();
		this -> _isSigned = obj.getIsSigned ();
		const_cast<int&> ( this -> _gradeToSign ) = obj.getGradeToSign ();
		const_cast<int&> ( this -> _gradeToExecute ) = obj.getGradeToExecute ();
	}

	return ( *this );
}

std::ostream& operator << ( std::ostream& out, const Form& obj )
{
	out 
		<< "Form "
		<< COLOR_YELLOW << obj.getName () << COLOR_RESET
		<< " is "
		<< COLOR_YELLOW << ( obj.getIsSigned () ? "signed" : "not signed" ) << COLOR_RESET
		<< " and require "
		<< COLOR_YELLOW << obj.getGradeToSign () << COLOR_RESET
		<< " grade for the sign and "
		<< COLOR_YELLOW << obj.getGradeToExecute () << COLOR_RESET
		<< " grade to execute.";

	return ( out );
}

const char* Form::GradeTooHighException::what() const throw ()
{
	return ( BUR_GRADE_TOO_HIGH_EXCEPTION );
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return ( BUR_GRADE_TOO_LOW_EXCEPTION );
}
