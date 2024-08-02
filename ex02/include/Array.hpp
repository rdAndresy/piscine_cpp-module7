/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:10:46 by benoit            #+#    #+#             */
/*   Updated: 2024/08/02 16:30:05 by bdelamea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP	
# define ARRAY_HPP	

# include <iostream>

template <typename T>
class Array {
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array & src);
		Array & operator=(const Array & rhs);
		~Array(void);

	private:
		T* _data;
		t_size len;
		t_size size(void) const;
}

#endif