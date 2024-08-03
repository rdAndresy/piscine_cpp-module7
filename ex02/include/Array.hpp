/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:10:46 by benoit            #+#    #+#             */
/*   Updated: 2024/08/03 13:35:48 by bdelamea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP	
# define ARRAY_HPP	

# include <iostream>
# include <stdexcept>
# include <string>

class Test {
	public:
		Test();
		Test(int x);
		Test(const Test &src);
		~Test();
		Test &operator=(const Test &rhs);
		Test &operator+=(int i);
		int getX() const;

	private:
		int _x;
};

template <typename T>
class Array {
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array & src);
		~Array(void);
		
		Array & operator=(const Array & rhs);
		T & operator[](unsigned int n) const;
		
		size_t	size(void) const;

	private:
		T*		_data;
		size_t	_len;
};

template <typename T>
std::ostream & operator<<(std::ostream & o, const Array<T> & src);

#endif