/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:37:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/25 19:19:56 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

class Harl
{
	public:
		Harl();
		~Harl();

		void	complain( std::string level );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};
