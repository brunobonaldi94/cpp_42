/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:33:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/19 23:15:29 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain const & src);
		Brain & operator=(Brain const & rhs);

		std::string *getIdeas(void) const;
		void setIdeas(std::string const *ideas);
		std::string getIdeaByIndex(int index) const;
		void setIdeaByIndex(int index, std::string idea);

	private:
		static const int MAX_IDEAS = 100;
		std::string ideas[MAX_IDEAS];
};

#endif
