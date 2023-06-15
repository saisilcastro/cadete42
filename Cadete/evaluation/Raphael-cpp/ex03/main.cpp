/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:05:23 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/15 00:38:25 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "color.hpp"

#define TEST_TXT_0	"Bureaucrat's Default Constructor"
#define TEST_TXT_1	"Bureaucrat's Copy Constructor"
#define TEST_TXT_2	"Bureaucrat's Name and Grade Constructor"
#define TEST_TXT_3	"Bureaucrat's Getters"
#define TEST_TXT_4	"Bureaucrat's Increment and Decrement grade"
#define TEST_TXT_5	"Bureaucrat's Copy Operator"
#define TEST_TXT_6	"Bureaucrat's Exceptions"

#define TEST_TXT_7	"ShrubberyCreationForm"
#define TEST_TXT_8	"RobotomyRequestForm"
#define TEST_TXT_9	"PresidentialPardonForm"
#define TEST_TXT_10	"Bureaucrat execute"

#define TEST_TXT_11	"Intern"

#define TEST_0	false
#define TEST_1	false
#define TEST_2	false
#define TEST_3	false
#define TEST_4	false
#define TEST_5	false
#define TEST_6	false

#define TEST_7	false
#define TEST_8	false
#define TEST_9	false
#define TEST_10	false

#define TEST_11	true

static void printCommentLine ( const std::string& text )
{
	if ( text == "" )
		std::cout << std::endl;
	std::cout << COLOR_INVERT << "[ ";

	std::cout << text;
	for ( size_t i = 0 ; i < 77 - text.size () && text.size () < 78 ; i++ )
		std::cout << " " ;
	std::cout << "]" ;

	std::cout << COLOR_RESET << '\n' << std::endl;
}

int	main ( void )
{
	std::cout << std::endl;

	if ( TEST_0 )
	{
		printCommentLine ( TEST_TXT_0 );

		const Bureaucrat	b1;
		const Bureaucrat*	b2 = new Bureaucrat ();

		std::cout << b1 << std::endl;
		std::cout << *b2 << std::endl;

		delete ( b2 );
	}
	if ( TEST_0 ) { std::cout << std::endl; }

	if ( TEST_1 )
	{
		printCommentLine ( TEST_TXT_1 );

		const Bureaucrat	original;
		const Bureaucrat	copy = original;

		std::cout << "original: " << original << std::endl;
		std::cout << "copy    : " << copy << std::endl;

	}
	if ( TEST_1 ) { std::cout << std::endl; }

	if ( TEST_2 )
	{
		printCommentLine ( TEST_TXT_2 );

		const Bureaucrat	hermes ( "Hermes Conrad" , 38 );

		std::cout << hermes << std::endl;
	}
	if ( TEST_2 ) { std::cout << std::endl; }

	if ( TEST_3 )
	{
		printCommentLine ( TEST_TXT_3 );

		const Bureaucrat	morgan ( "Morgan Proctor" , 19 );

		std::cout << morgan << std::endl;
		std::cout << "Name: " << morgan.getName () << std::endl;
		std::cout << "Grade: " << morgan.getGrade () << std::endl;
	}
	if ( TEST_3 ) { std::cout << std::endl; }

	if ( TEST_4 )
	{
		printCommentLine ( TEST_TXT_4 );

		{
			Bureaucrat	b42 ( "number 42" , 42 );

			std::cout << b42 << std::endl;
			b42.incrementGrade ();
			std::cout << b42 << std::endl;
			b42.decrementGrade ();
			std::cout << b42 << std::endl;
		}
		std::cout << std::endl;

		{
			Bureaucrat	b1 ( "number 1" , 1 );

			std::cout << b1 << std::endl;
			b1.decrementGrade ();
			std::cout << b1 << std::endl;
			b1.incrementGrade ();
			std::cout << b1 << std::endl;
		}
		std::cout << std::endl;

		{
			Bureaucrat	b150 ( "number 150" , 150 );

			std::cout << b150 << std::endl;
			b150.incrementGrade ();
			std::cout << b150 << std::endl;
			b150.decrementGrade ();
			std::cout << b150 << std::endl;
		}
		std::cout << std::endl;
	}
	if ( TEST_4 ) { std::cout << std::endl; }

	if ( TEST_5 )
	{
		printCommentLine ( TEST_TXT_5 );

		const Bureaucrat	gemini ( "Gemini Klone Doppelganger" , 52 );
		Bureaucrat			genimi;

		std::cout << "gemini: " << gemini << std::endl;
		std::cout << "genimi: " << genimi << std::endl;

		genimi = gemini;

		std::cout << "gemini: " << gemini << std::endl;
		std::cout << "genimi: " << genimi << std::endl;
	}
	if ( TEST_5 ) { std::cout << std::endl; }

	if ( TEST_6 )
	{
		printCommentLine ( TEST_TXT_6 );

		{
			Bureaucrat	b0 ( "number 0" , 0 );

			std::cout << b0 << std::endl;
		}
		std::cout << std::endl;
		{
			Bureaucrat	b9000 ( "number 9000" , 9000 );

			std::cout << b9000 << std::endl;
		}
		std::cout << std::endl;
		{
			Bureaucrat	b1 ( "number 1" , 1 );

			std::cout << b1 << std::endl;
			b1.incrementGrade ();
			std::cout << b1 << std::endl;
		}
		std::cout << std::endl;
		{
			Bureaucrat	b150 ( "number 150" , 150 );

			std::cout << b150 << std::endl;
			b150.decrementGrade ();
			std::cout << b150 << std::endl;
		}
	}
	if ( TEST_6 ) { std::cout << std::endl; }

	if ( TEST_7 )
	{
		printCommentLine ( TEST_TXT_7 );

		ShrubberyCreationForm	scf042 ("florest");
		const Bureaucrat		g1 ("Gregory, the first", 1);

		std::cout << scf042 << std::endl;
		std::cout << g1 << std::endl;

		scf042.execute ( g1 );
		std::cout << scf042 << std::endl;
		scf042.beSign ( g1 );
		std::cout << scf042 << std::endl;
		scf042.execute ( g1 );
		std::cout << scf042 << std::endl;

	}
	if ( TEST_7 ) { std::cout << std::endl; }

	if ( TEST_8 )
	{
		printCommentLine ( TEST_TXT_8 );

		RobotomyRequestForm	rrf021 ("A random human");
		const Bureaucrat	g2 ("Gregory, the second", 2);

		std::cout << rrf021 << std::endl;
		std::cout << g2 << std::endl;

		rrf021.beSign ( g2 );
		for ( int i = 0 ; i < 10 ; i++ )
			rrf021.execute ( g2 );
	}
	if ( TEST_8 ) { std::cout << std::endl; }

	if ( TEST_9 )
	{
		printCommentLine ( TEST_TXT_9 );

		PresidentialPardonForm	ppf084 ("florest");
		const Bureaucrat		g3 ("Gregory, the third", 3);

		std::cout << ppf084 << std::endl;
		std::cout << g3 << std::endl;

		ppf084.execute ( g3 );
		std::cout << ppf084 << std::endl;
		ppf084.beSign ( g3 );
		std::cout << ppf084 << std::endl;
		ppf084.execute ( g3 );
		std::cout << ppf084 << std::endl;
	}
	if ( TEST_9 ) { std::cout << std::endl; }

	if ( TEST_10 )
	{
		printCommentLine ( TEST_TXT_10 );

		ShrubberyCreationForm	scf168 ("Greg's House");
		const Bureaucrat	g4 ("Gregory Forever", 4);

		g4.executeForm ( scf168 );
		g4.signForm ( scf168 );
		g4.executeForm ( scf168 );
	}
	if ( TEST_10 ) { std::cout << std::endl; }

	if ( TEST_11 )
	{
		printCommentLine ( TEST_TXT_11 );

		Intern	formMaker;

		std::cout << formMaker << std::endl;

		AForm* nil000 = formMaker.makeForm ( "invalid" , "I. N. Valider" );
		AForm* ppf084 = formMaker.makeForm ( "presidential pardon" , "Laura Mugger" );
		AForm* rrf021 = formMaker.makeForm ( "robotomy request" , "Louis Botmein" );
		AForm* scf168 = formMaker.makeForm ( "shrubbery creation" , "Unshruber Valley" );

		if ( nil000 )
			std::cout << *nil000 << std::endl;
		else
			std::cout << "NULL" << std::endl;
		std::cout << *ppf084 << std::endl;
		std::cout << *rrf021 << std::endl;
		std::cout << *scf168 << std::endl;

		delete ( nil000 );
		delete ( ppf084 );
		delete ( rrf021 );
		delete ( scf168 );
	}
	if ( TEST_11 ) { std::cout << std::endl; }

	return ( 0 );
}
