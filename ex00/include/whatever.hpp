/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:10:46 by benoit            #+#    #+#             */
/*   Updated: 2024/08/02 15:13:46 by bdelamea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP	
# define WHATEVER_HPP	

# include <iostream>

template <typename T>
void swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const & max(T const &x, T const &y) {
 return (x >= y ? x : y);
}

template <typename T>
T const & min(T const &x, T const &y) {
 return (x <= y ? x : y);
}

#endif