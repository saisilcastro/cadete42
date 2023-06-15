/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:12:39 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/06/14 09:12:39 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>
# include <exception>
# include <iostream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "color.hpp"

# define ROB_MSG		"[ " COLOR_MAGENTA "ROB" COLOR_RESET " ] "

# define ROB_DEFAULT_NAME				"RobotomyRequestForm"
# define ROB_DEFAULT_GRADE_TO_SIGN		72
# define ROB_DEFAULT_GRADE_TO_EXECUTE	45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm ( void );
		RobotomyRequestForm ( const RobotomyRequestForm& obj );
		RobotomyRequestForm ( const std::string& target );
		virtual ~RobotomyRequestForm ( void );

		bool	execute ( Bureaucrat const& executor ) const;

		RobotomyRequestForm&	operator = ( const RobotomyRequestForm& obj );
};

#endif // ROBOTOMYREQUESTFORM_HPP
