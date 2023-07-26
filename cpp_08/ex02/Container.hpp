/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:07:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/25 19:19:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>

template <typename T, class TBase>
class Container: public TBase 
{
	public:
		Container();
		Container(Container const &src);
		~Container();
		Container &operator=(Container const &rhs);

		void push(T const &value);
		void pop(void);
		T &top(void);
};

# include "Container.tpp"

#endif
