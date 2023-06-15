/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:26:57 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/13 18:26:57 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <fstream>
# include <iostream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "color.hpp"

# define SHR_MSG		"[ " COLOR_BLUE "SHR" COLOR_RESET " ] "

# define SHR_DEFAULT_NAME				"ShrubberyCreationForm"
# define SHR_DEFAULT_GRADE_TO_SIGN		145
# define SHR_DEFAULT_GRADE_TO_EXECUTE	137

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm ( void );
		ShrubberyCreationForm ( const ShrubberyCreationForm& obj );
		ShrubberyCreationForm ( const std::string& target );
		virtual ~ShrubberyCreationForm ( void );

		bool	execute ( Bureaucrat const& executor ) const;

		ShrubberyCreationForm&	operator = ( const ShrubberyCreationForm& obj );
};

#endif // SHRUBBERYCREATIONFORM_HPP
