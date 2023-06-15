/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:26:59 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/13 18:26:59 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm ( void ) :
	AForm ( SHR_DEFAULT_NAME , SHR_DEFAULT_GRADE_TO_SIGN , SHR_DEFAULT_GRADE_TO_EXECUTE )
{
	std::cout << SHR_MSG << "ShrubberyCreationForm's Default constructor called" << std::endl;

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm& obj ) : AForm ( obj )
{
	std::cout << SHR_MSG << "ShrubberyCreationForm's Copy constructor called" << std::endl;
	*this = obj;

	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
	std::cout << SHR_MSG << "ShrubberyCreationForm's Default destructor called" << std::endl;

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const std::string& target ) :
	AForm ( SHR_DEFAULT_NAME , SHR_DEFAULT_GRADE_TO_SIGN , SHR_DEFAULT_GRADE_TO_EXECUTE , target )
{
	std::cout << SHR_MSG << "ShrubberyCreationForm's Target constructor called" << std::endl;

	return;
}

bool	ShrubberyCreationForm::execute ( Bureaucrat const& executor ) const
{
	try
	{
		if ( !this -> getIsSigned () )
			throw ( AForm::FormNotSigned () );
		else if ( this -> getGradeToExecute () < executor.getGrade () )
			throw ( AForm::GradeTooLowException () );
		else
		{
			std::ofstream	file;

			file.open ( ( this -> getTarget () + "_shrubbery" ).c_str () );
			file << "     222222222211              22223322111100                         11        \n";
			file << "   0222222332220011          22222222222222222211               11001122211     \n";
			file << "  10222223300333223322      2222333322333322222211          1122222222322222211 \n";
			file << "002223322332233222333322    00223322002222222222222200     003322332223333222200\n";
			file << "003003333222222233222222   000223333223322003333222200   00222233332223322222222\n";
			file << "222223333223333233222200  002222222222333333333322222200 00223322332233322222222\n";
			file << std::endl;
			file.close();

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

ShrubberyCreationForm&	ShrubberyCreationForm::operator = ( const ShrubberyCreationForm& obj )
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
