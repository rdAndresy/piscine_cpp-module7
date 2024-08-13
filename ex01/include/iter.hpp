/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:10:46 by benoit            #+#    #+#             */
/*   Updated: 2024/08/13 10:28:27 by bdelamea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP	
# define ITER_HPP	

# include <iostream>

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

std::ostream &	operator<<(std::ostream & o, const Test & rhs);

// Iter template function
template <typename T, typename U, typename V>
void iter(T & addr, const U len, V & f) {
	for (U i = 0; i < len; i++)
		f(addr[i]);
}

// Very particular case of const function, not sure of it's relevant
template <typename T, typename U, typename V>
void iter(T & addr, const U len, const V & f) {
	for (U i = 0; i < len; i++)
		f(addr[i]);
}

// Print template function
template <typename T>
void print(T val) { std::cout << val << " "; }

// Increment template function
template <typename T>
void increment(T &val) { val += 1; }

#endif