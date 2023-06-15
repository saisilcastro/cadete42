/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:05:23 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 23:08:28 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "color.hpp"

#define TEST_TXT_0	"Default Constructor"
#define TEST_TXT_1	"Copy Constructor"
#define TEST_TXT_2	"Name and Grade Constructor"
#define TEST_TXT_3	"Getters"
#define TEST_TXT_4	"Increment and Decrement grade"
#define TEST_TXT_5	"Copy Operator"
#define TEST_TXT_6	"Exceptions"

#define TEST_0	true
#define TEST_1	true
#define TEST_2	true
#define TEST_3	true
#define TEST_4	true
#define TEST_5	true
#define TEST_6	true

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

	return ( 0 );
}
