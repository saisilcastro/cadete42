/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:05:23 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 23:08:23 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.hpp"

#define TEST_TXT_0	"Bureaucrat's Default Constructor"
#define TEST_TXT_1	"Bureaucrat's Copy Constructor"
#define TEST_TXT_2	"Bureaucrat's Name and Grade Constructor"
#define TEST_TXT_3	"Bureaucrat's Getters"
#define TEST_TXT_4	"Bureaucrat's Increment and Decrement grade"
#define TEST_TXT_5	"Bureaucrat's Copy Operator"
#define TEST_TXT_6	"Bureaucrat's Exceptions"
#define TEST_TXT_7	"Bureaucrat's Sign Form Function"

#define TEST_TXT_8	"Form's Default Constructor"
#define TEST_TXT_9	"Form's Copy Constructor"
#define TEST_TXT_10	"Form's Name and Grade Constructor"
#define TEST_TXT_11	"Form's Getters"
#define TEST_TXT_12	"Form's Be Sign Function"
#define TEST_TXT_13	"Form's Copy Operator"
#define TEST_TXT_14	"Form's Exceptions"

#define TEST_0	false
#define TEST_1	false
#define TEST_2	false
#define TEST_3	false
#define TEST_4	false
#define TEST_5	false
#define TEST_6	false
#define TEST_7	true

#define TEST_8	true
#define TEST_9	true
#define TEST_10	true
#define TEST_11	true
#define TEST_12	true
#define TEST_13	true
#define TEST_14	true

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

		const Bureaucrat	allowed ( "Allowed Grant" , 21 );
		const Bureaucrat	notAllowed ( "Unallowed Blocksmith" , 142 );
		Form				permission1 ( "Permission 1" , 84 , 42 );
		Form				permission2 ( "Permission 2" , 84 , 42 );

		std::cout << std::endl;

		std::cout << allowed << std::endl;
		std::cout << notAllowed << std::endl;

		std::cout << std::endl;

		std::cout << permission1 << std::endl;
		std::cout << permission2 << std::endl;

		std::cout << std::endl;

		allowed.signForm ( permission1 );
		notAllowed.signForm ( permission2 );

		std::cout << std::endl;

		std::cout << permission1 << std::endl;
		std::cout << permission2 << std::endl;

		std::cout << std::endl;
	}
	if ( TEST_7 ) { std::cout << std::endl; }

	if ( TEST_8 )
	{
		printCommentLine ( TEST_TXT_8 );

		const Form	f1;
		const Form*	f2 = new Form ();

		std::cout << f1 << std::endl;
		std::cout << *f2 << std::endl;

		delete ( f2 );
	}
	if ( TEST_8 ) { std::cout << std::endl; }

	if ( TEST_9 )
	{
		printCommentLine ( TEST_TXT_9 );

		const Form	original;
		const Form	copy = original;

		std::cout << "original: " << original << std::endl;
		std::cout << "copy    : " << copy << std::endl;
	}
	if ( TEST_9 ) { std::cout << std::endl; }

	if ( TEST_10 )
	{
		printCommentLine ( TEST_TXT_10 );

		const Form	cadetSignInPermission ( "Space Cadet Special Sign In Permission" , 42 , 21 );

		std::cout << cadetSignInPermission << std::endl;
	}
	if ( TEST_10 ) { std::cout << std::endl; }

	if ( TEST_11 )
	{
		printCommentLine ( TEST_TXT_11 );

		const Form	drLightSignIn ( "New robot squad" , 19 , 87 );

		std::cout << drLightSignIn << std::endl;
		std::cout << "Name: " << drLightSignIn.getName () << std::endl;
		std::cout << "Is Signed: " << drLightSignIn.getIsSigned () << std::endl;
		std::cout << "Grade To Sign: " << drLightSignIn.getGradeToSign () << std::endl;
		std::cout << "Grade To Execute: " << drLightSignIn.getGradeToExecute () << std::endl;
}
	if ( TEST_11 ) { std::cout << std::endl; }

	if ( TEST_12 )
	{
		printCommentLine ( TEST_TXT_12 );

		const Bureaucrat	marvin ( "Marvin The Paranoid Android" , 1 );
		Form				doorLock ( "Door 42" , 21 , 42 );

		std::cout << marvin << std::endl;
		std::cout << doorLock << std::endl;

		doorLock.beSign ( marvin );

		std::cout << marvin << std::endl;
		std::cout << doorLock << std::endl;

	}
	if ( TEST_12 ) { std::cout << std::endl; }

	if ( TEST_13 )
	{
		printCommentLine ( TEST_TXT_13 );

		const Form	zirox ( "Zirox" , 25 , 52 );
		Form		photoKopie;

		std::cout << "zirox: " << zirox << std::endl;
		std::cout << "photoKopie: " << photoKopie << std::endl;

		photoKopie = zirox;

		std::cout << "zirox: " << zirox << std::endl;
		std::cout << "photoKopie: " << photoKopie << std::endl;
	}
	if ( TEST_13 ) { std::cout << std::endl; }

	if ( TEST_14 )
	{
		printCommentLine ( TEST_TXT_14 );

		const Bureaucrat	steve ( "steve" , 120 );
		Form				bedrock ( "Bedrock dig permission" , 1 , 1 );

		std::cout << steve << std::endl;
		std::cout << bedrock << std::endl;
		bedrock.beSign ( steve );
		std::cout << steve << std::endl;
		std::cout << bedrock << std::endl;

	}
	if ( TEST_14 ) { std::cout << std::endl; }

	return ( 0 );
}
