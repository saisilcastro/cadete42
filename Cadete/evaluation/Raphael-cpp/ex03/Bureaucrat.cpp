/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:05:45 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 09:59:49 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ) :
	_name ( BUR_DEFAULT_NAME ) ,
	_grade ( BUR_DEFAULT_GRADE )
{
	std::cout << BUR_MSG << "Bureaucrat's Default constructor called" << std::endl;

	return;
}

Bureaucrat::Bureaucrat ( const Bureaucrat& obj ) :
	_name ( obj.getName () ),
	_grade ( obj.getGrade () )
{
	std::cout << BUR_MSG << "Bureaucrat's Copy constructor called" << std::endl;
	*this = obj;

	return;
}

Bureaucrat::Bureaucrat ( const std::string& name , int grade ) :
	_name ( name ) ,
	_grade ( grade )
{
	std::cout << BUR_MSG << "Bureaucrat's Name and Grade constructor called" << std::endl;

	try
	{
		if ( this -> _grade < BUR_HIGHEST_GRADE )
			throw ( Bureaucrat::GradeTooHighException () );
		else if ( this -> _grade > BUR_LOWEST_GRADE )
			throw ( Bureaucrat::GradeTooLowException () );
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what () << std::endl;
		if ( this -> _grade < BUR_HIGHEST_GRADE )
			this -> _grade = BUR_HIGHEST_GRADE;
		else if ( this -> _grade > BUR_LOWEST_GRADE )
			this -> _grade = BUR_LOWEST_GRADE;
	}

	return;
}

Bureaucrat::~Bureaucrat ( void )
{
	std::cout << BUR_MSG << "Bureaucrat's Default destructor called" << std::endl;

	return;
}

const std::string	Bureaucrat::getName ( void ) const
{
	return ( this -> _name );
}

int	Bureaucrat::getGrade ( void ) const
{
	return ( this -> _grade );
}

void	Bureaucrat::incrementGrade ( void )
{
	this -> _grade--;

	try
	{
		if ( this -> _grade < BUR_HIGHEST_GRADE )
			throw ( Bureaucrat::GradeTooHighException () );
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what () << std::endl;
		this -> _grade = BUR_HIGHEST_GRADE;
	}
}

void	Bureaucrat::decrementGrade ( void )
{
	this -> _grade++;

	try
	{
		if ( this -> _grade > BUR_LOWEST_GRADE )
			throw ( Bureaucrat::GradeTooLowException () );
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what () << std::endl;
		this -> _grade = BUR_LOWEST_GRADE;
	}
}

void	Bureaucrat::signForm ( AForm& form ) const
{
	try
	{
		if ( form.beSign ( *this ) )
		{
			std::cout
				<< COLOR_GREEN
				<< this -> getName()
				<< COLOR_RESET
				<< " signed "
				<< COLOR_YELLOW
				<< form.getName ()
				<< COLOR_RESET
				<< std::endl;
		}
	}
	catch ( const std::exception& e )
	{
		std::cout
			<< COLOR_GREEN
			<< this -> getName()
			<< COLOR_RESET
			<< " couldn't sign "
			<< COLOR_YELLOW
			<< form.getName ()
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

void	Bureaucrat::executeForm ( AForm& form ) const
{
	try
	{
		if ( form.execute ( *this ) )
		{
			std::cout
				<< COLOR_GREEN
				<< this -> getName()
				<< COLOR_RESET
				<< " executed "
				<< COLOR_YELLOW
				<< form.getName ()
				<< COLOR_RESET
				<< std::endl;
		}
	}
	catch ( const std::exception& e )
	{
		std::cout
			<< COLOR_GREEN
			<< this -> getName()
			<< COLOR_RESET
			<< " couldn't execute "
			<< COLOR_YELLOW
			<< form.getName ()
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

Bureaucrat&	Bureaucrat::operator = ( const Bureaucrat& obj )
{
	if ( this != &obj )
	{
		const_cast<std::string&> ( this -> _name ) = obj.getName ();
		this -> _grade = obj.getGrade ();
	}

	return ( *this );
}

std::ostream&	operator << ( std::ostream& out, const Bureaucrat& obj )
{
	out 
		<< COLOR_GREEN
		<< obj.getName ()
		<< COLOR_RESET
		<< ", bureaucrat grade "
		<< COLOR_GREEN
		<< obj.getGrade ()
		<< COLOR_RESET
		<< '.';

	return ( out );
}

const char*	Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ( BUR_GRADE_TOO_HIGH_EXCEPTION );
}

const char*	Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ( BUR_GRADE_TOO_LOW_EXCEPTION );
}
