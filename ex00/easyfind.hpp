/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:13:13 by maustel           #+#    #+#             */
/*   Updated: 2025/04/23 12:45:23 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include <iostream>
# include <array>

template <typename T>
typename T::iterator easyfind(T& container, int index)
{
	typename T::iterator i = std::find(container.begin(), container.end(), index);

	return (i);
}

#endif