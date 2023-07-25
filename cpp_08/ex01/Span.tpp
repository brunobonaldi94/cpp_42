/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:11:39 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/24 22:26:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator it_begin, Iterator it_end)
{
	int qtyAdd = std::distance(it_begin, it_end);
	if (qtyAdd + this->_Multiset.size() > this->_N)
		throw Span::NoSpaceException();
	this->_Multiset.insert(it_begin, it_end);
}
