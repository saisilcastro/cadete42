/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:30:28 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 09:30:28 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm ( void ) :
	AForm ( PRE_DEFAULT_NAME , PRE_DEFAULT_GRADE_TO_SIGN , PRE_DEFAULT_GRADE_TO_EXECUTE )
{
	std::cout << PRE_MSG << "PresidentialPardonForm's Default constructor called" << std::endl;

	return;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm& obj ) : AForm ( obj )
{
	std::cout << PRE_MSG << "PresidentialPardonForm's Copy constructor called" << std::endl;
	*this = obj;

	return;
}

PresidentialPardonForm::~PresidentialPardonForm ( void )
{
	std::cout << PRE_MSG << "PresidentialPardonForm's Default destructor called" << std::endl;

	return;
}

PresidentialPardonForm::PresidentialPardonForm ( const std::string& target ) :
	AForm ( PRE_DEFAULT_NAME , PRE_DEFAULT_GRADE_TO_SIGN , PRE_DEFAULT_GRADE_TO_EXECUTE , target )
{
	std::cout << PRE_MSG << "PresidentialPardonForm's Target constructor called" << std::endl;

	return;
}

bool	PresidentialPardonForm::execute ( Bureaucrat const& executor ) const
{
	try
	{
		if ( !this -> getIsSigned () )
			throw ( AForm::FormNotSigned () );
		else if ( this -> getGradeToExecute () < executor.getGrade () )
			throw ( AForm::GradeTooLowException () );
		else
		{
			std::cout << this -> getTarget () << " has been pardoned by Zaphod Beeblebrox." << std::endl;

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

PresidentialPardonForm&	PresidentialPardonForm::operator = ( const PresidentialPardonForm& obj )
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
