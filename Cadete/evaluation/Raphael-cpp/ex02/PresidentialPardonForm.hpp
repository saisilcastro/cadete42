/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:30:15 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 09:30:15 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <exception>
# include <iostream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "color.hpp"

# define PRE_MSG		"[ " COLOR_CYAN "PRE" COLOR_RESET " ] "

# define PRE_DEFAULT_NAME				"PresidentialPardonForm"
# define PRE_DEFAULT_GRADE_TO_SIGN		25
# define PRE_DEFAULT_GRADE_TO_EXECUTE	5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm ( void );
		PresidentialPardonForm ( const PresidentialPardonForm& obj );
		PresidentialPardonForm ( const std::string& target );
		virtual ~PresidentialPardonForm ( void );

		bool	execute ( Bureaucrat const& executor ) const;

		PresidentialPardonForm&	operator = ( const PresidentialPardonForm& obj );
};

#endif // PRESIDENTIALPARDONFORM_HPP
