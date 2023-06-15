/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:00:33 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/15 00:34:49 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern ( void )
{
	std::cout << INT_MSG << "Intern's Default constructor called" << std::endl;

	return;
}

Intern::Intern ( const Intern& obj )
{
	std::cout << INT_MSG << "Intern's Copy constructor called" << std::endl;
	*this = obj;

	return;
}

Intern::~Intern ( void )
{
	std::cout << INT_MSG << "Intern's Default destructor called" << std::endl;

	return;
}

static AForm* newPresidentialPardonForm ( std::string target )
{ return ( new PresidentialPardonForm ( target ) ); }

static AForm* newRobotomyRequestForm ( std::string target )
{ return ( new RobotomyRequestForm ( target ) ); }

static AForm* newShrubberyCreationForm ( std::string target )
{ return ( new ShrubberyCreationForm ( target ) ); }

AForm*	Intern::makeForm ( const std::string& form , const std::string& target )
{
	std::string formList[4] =
	{
		"presidential pardon",
		"",
		"robotomy request",
		"shrubbery creation"
	};
	AForm* ( *make_form[4] ) ( std::string target) =
	{
		&newPresidentialPardonForm,
		NULL,
		&newRobotomyRequestForm,
		&newShrubberyCreationForm,
	};

	if ( form != formList[0] && form != formList[2] && form != formList[3] )
		std::cout
			<< "Can't create "
			<< COLOR_YELLOW << form << COLOR_RESET
			<< " because wrong form name."
			<< std::endl;
	else
		return ( make_form[(int) form[0] - 112] ( target ) );
	return ( NULL );
}

Intern&	Intern::operator = ( const Intern& obj )
{
	( void ) obj;

	return ( *this );
}


std::ostream&	operator << ( std::ostream& out, const Intern& obj )
{
	( void ) obj;
	out 
		<< "This is a "
		<< COLOR_YELLOW << "Intern" << COLOR_RESET
		<< " class. "
		<< "You can use "
		<< COLOR_YELLOW << "<Intern>.makeForm ( <Form> , <target> );" << COLOR_RESET
		<< " to create a form.";

	return ( out );
}
