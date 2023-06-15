/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:10 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/15 00:37:34 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm ( void ) :
	_name ( AFO_DEFAULT_NAME ) ,
	_target ( AFO_DEFAULT_TARGET ) ,
	_isSigned ( AFO_DEFAULT_IS_SIGNED ) ,
	_gradeToSign ( AFO_DEFAULT_GRADE_TO_SIGN ) ,
	_gradeToExecute ( AFO_DEFAULT_GRADE_TO_EXECUTE )
{
	std::cout << AFO_MSG << "AForm's Default constructor called" << std::endl;

	return;
}

AForm::AForm ( const AForm& obj ) :
	_name ( obj.getName () ) ,
	_target ( obj.getTarget () ) ,
	_isSigned ( obj.getIsSigned () ) ,
	_gradeToSign ( obj.getGradeToSign () ) ,
	_gradeToExecute ( obj.getGradeToExecute () )
{
	std::cout << AFO_MSG << "AForm's Copy constructor called" << std::endl;
	*this = obj;

	return;
}

AForm::AForm ( const std::string& name , int gradeToSign , int gradeToExecute ) :
	_name ( name ) ,
	_target ( AFO_DEFAULT_TARGET ) ,
	_isSigned ( AFO_DEFAULT_IS_SIGNED ) ,
	_gradeToSign ( gradeToSign ) ,
	_gradeToExecute ( gradeToExecute )
{
	std::cout << AFO_MSG << "AForm's Name and Grade constructor called" << std::endl;

	try
	{
		if ( this -> _gradeToSign < AFO_HIGHEST_GRADE )
			throw ( AForm::GradeTooHighException () );
		else if ( this -> _gradeToSign > AFO_LOWEST_GRADE )
			throw ( AForm::GradeTooLowException () );

		if ( this -> _gradeToExecute < AFO_HIGHEST_GRADE )
			throw ( AForm::GradeTooHighException () );
		else if ( this -> _gradeToExecute > AFO_LOWEST_GRADE )
			throw ( AForm::GradeTooLowException () );
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what () << std::endl;

		if ( this -> _gradeToSign < AFO_HIGHEST_GRADE )
			const_cast<int&> ( this -> _gradeToSign ) = AFO_HIGHEST_GRADE;

		else if ( this -> _gradeToSign > AFO_LOWEST_GRADE )
			const_cast<int&> ( this -> _gradeToSign ) = AFO_LOWEST_GRADE;

		if ( this -> _gradeToExecute < AFO_HIGHEST_GRADE )
			const_cast<int&> ( this -> _gradeToExecute ) = AFO_HIGHEST_GRADE;
		else if ( this -> _gradeToExecute > AFO_LOWEST_GRADE )
			const_cast<int&> ( this -> _gradeToExecute ) = AFO_LOWEST_GRADE;
	}

	return;
}

AForm::AForm ( const std::string& name , int gradeToSign , int gradeToExecute , const std::string& target ) :
	_name ( name ) ,
	_target ( target ) ,
	_isSigned ( AFO_DEFAULT_IS_SIGNED ) ,
	_gradeToSign ( gradeToSign ) ,
	_gradeToExecute ( gradeToExecute )
{
	std::cout << AFO_MSG << "AForm's Name, Grade and Target constructor called" << std::endl;

	try
	{
		if ( this -> _gradeToSign < AFO_HIGHEST_GRADE )
			throw ( AForm::GradeTooHighException () );
		else if ( this -> _gradeToSign > AFO_LOWEST_GRADE )
			throw ( AForm::GradeTooLowException () );

		if ( this -> _gradeToExecute < AFO_HIGHEST_GRADE )
			throw ( AForm::GradeTooHighException () );
		else if ( this -> _gradeToExecute > AFO_LOWEST_GRADE )
			throw ( AForm::GradeTooLowException () );
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what () << std::endl;

		if ( this -> _gradeToSign < AFO_HIGHEST_GRADE )
			const_cast<int&> ( this -> _gradeToSign ) = AFO_HIGHEST_GRADE;

		else if ( this -> _gradeToSign > AFO_LOWEST_GRADE )
			const_cast<int&> ( this -> _gradeToSign ) = AFO_LOWEST_GRADE;

		if ( this -> _gradeToExecute < AFO_HIGHEST_GRADE )
			const_cast<int&> ( this -> _gradeToExecute ) = AFO_HIGHEST_GRADE;
		else if ( this -> _gradeToExecute > AFO_LOWEST_GRADE )
			const_cast<int&> ( this -> _gradeToExecute ) = AFO_LOWEST_GRADE;
	}

	return;
}

AForm::~AForm ( void )
{
	std::cout << AFO_MSG << "AForm's Default destructor called" << std::endl;

	return;
}

const std::string	AForm::getName ( void ) const
{
	return ( this -> _name );
}

const std::string	AForm::getTarget ( void ) const
{
	return ( this -> _target );
}

bool	AForm::getIsSigned ( void ) const
{
	return ( this -> _isSigned );
}

int	AForm::getGradeToSign ( void ) const
{
	return ( this -> _gradeToSign );
}

int	AForm::getGradeToExecute ( void ) const
{
	return ( this -> _gradeToExecute );
}

void	AForm::setName ( const std::string& name )
{
	const_cast<std::string&> ( this -> _name ) = name;

	return;
}

void	AForm::setTarget ( const std::string& target )
{
	const_cast<std::string&> ( this -> _target ) = target;

	return;
}

void	AForm::setIsSigned ( bool isSigned )
{
	this -> _isSigned = isSigned;

	return;
}

void	AForm::setGradeToSign ( int gradeToSign )
{
	const_cast<int&> ( this -> _gradeToSign ) = gradeToSign;

	return;
}

void	AForm::setGradeToExecute ( int gradeToExecute )
{
	const_cast<int&> ( this -> _gradeToExecute ) = gradeToExecute;

	return;
}

bool	AForm::beSign ( const Bureaucrat& bureaucrat )
{
	if ( this -> _gradeToSign > bureaucrat.getGrade() )
		this -> _isSigned = true;
	try
	{
		if ( this -> _gradeToSign < bureaucrat.getGrade() )
			throw ( AForm::GradeTooLowException () );
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

	return ( this -> _isSigned );
}

bool	AForm::execute ( Bureaucrat const& executor ) const
{
	try
	{
		if ( !this -> getIsSigned () )
			throw ( AForm::FormNotSigned () );
		else if ( executor.getGrade () > this -> getGradeToExecute () )
			throw ( AForm::GradeTooLowException () );
		else
		{
			std::cout
				<< COLOR_GREEN
				<< executor.getName ()
				<< COLOR_RESET
				<< " execute "
				<< COLOR_YELLOW
				<< this -> getName()
				<< COLOR_RESET
				<< " successfully."
				<< std::endl;
			return ( true );
		}
	}
	catch ( const std::exception& e )
	{
		std::cout
			<< COLOR_GREEN
			<< executor.getName ()
			<< COLOR_RESET
			<< " couldn't execute "
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

	return ( false );
}

AForm& AForm::operator = ( const AForm& obj )
{
	if ( this != &obj )
	{
		this -> setName ( obj.getName () );
		this -> setIsSigned ( obj.getIsSigned () );
		this -> setGradeToSign ( obj.getGradeToSign () );
		this -> setGradeToExecute ( obj.getGradeToExecute () );
		this -> setTarget ( obj.getTarget () );
	}

	return ( *this );
}

std::ostream& operator << ( std::ostream& out, const AForm& obj )
{
	out 
		<< "Form "
		<< COLOR_YELLOW << obj.getName () << COLOR_RESET
		<< " with target "
		<< COLOR_YELLOW << obj.getTarget () << COLOR_RESET
		<< " is "
		<< COLOR_YELLOW << ( obj.getIsSigned () ? "signed" : "not signed" ) << COLOR_RESET
		<< " and require "
		<< COLOR_YELLOW << obj.getGradeToSign () << COLOR_RESET
		<< " grade for the sign and "
		<< COLOR_YELLOW << obj.getGradeToExecute () << COLOR_RESET
		<< " grade to execute.";

	return ( out );
}

const char*	AForm::GradeTooHighException::what() const throw ()
{
	return ( AFO_GRADE_TOO_HIGH_EXCEPTION );
}

const char*	AForm::GradeTooLowException::what() const throw ()
{
	return ( AFO_GRADE_TOO_LOW_EXCEPTION );
}

const char*	AForm::FormNotSigned::what() const throw ()
{
	return ( AFO_NOT_SIGNED );
}
