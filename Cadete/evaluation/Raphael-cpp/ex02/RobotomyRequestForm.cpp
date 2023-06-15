/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:12:32 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 09:12:32 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm ( void ) :
	AForm ( ROB_DEFAULT_NAME , ROB_DEFAULT_GRADE_TO_SIGN , ROB_DEFAULT_GRADE_TO_EXECUTE )
{
	std::cout << ROB_MSG << "RobotomyRequestForm's Default constructor called" << std::endl;

	return;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm& obj ) : AForm ( obj )
{
	std::cout << ROB_MSG << "RobotomyRequestForm's Copy constructor called" << std::endl;
	*this = obj;

	return;
}

RobotomyRequestForm::~RobotomyRequestForm ( void )
{
	std::cout << ROB_MSG << "RobotomyRequestForm's Default destructor called" << std::endl;

	return;
}

RobotomyRequestForm::RobotomyRequestForm ( const std::string& target ) :
	AForm ( ROB_DEFAULT_NAME , ROB_DEFAULT_GRADE_TO_SIGN , ROB_DEFAULT_GRADE_TO_EXECUTE , target )
{
	std::cout << ROB_MSG << "RobotomyRequestForm's Target constructor called" << std::endl;

	return;
}

bool	RobotomyRequestForm::execute ( Bureaucrat const& executor ) const
{
	try
	{
		if ( !this -> getIsSigned () )
			throw ( AForm::FormNotSigned () );
		else if ( this -> getGradeToExecute () < executor.getGrade () )
			throw ( AForm::GradeTooLowException () );
		else
		{
			static bool	firstRun = true;

			if ( firstRun )
			{
				std::srand ( std::time ( 0 ) );
				firstRun = false;
			}
			std::cout << "Make drilling noises..." << std::endl;
			if ( std::rand () % 2 )
				std::cout
					<< COLOR_GREEN
					<< this -> getTarget ()
					<< " has been robotomized successfully."
					<< COLOR_RESET
					<< std::endl;
			else
				std::cout
					<< COLOR_RED
					<< this -> getTarget ()
					<< " has NOT been robotomized, robotomy fail."
					<< COLOR_RESET
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

RobotomyRequestForm&	RobotomyRequestForm::operator = ( const RobotomyRequestForm& obj )
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
