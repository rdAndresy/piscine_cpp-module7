/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:28:38 by benoit            #+#    #+#             */
/*   Updated: 2024/08/02 15:49:06 by bdelamea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

Test::Test(): _x(0) {}
Test::Test(int x): _x(x) {}
Test::Test(const Test &src) { this->_x = src._x; }
Test::~Test() {}
int Test::getX() const { return this->_x; }
Test & Test::operator=(const Test &rhs) { this->_x = rhs._x; return *this; }
Test & Test::operator+=(int i) { this->_x += i; return *this; }
std::ostream & operator<<(std::ostream & o, const Test & rhs) { o << rhs.getX(); return (o); }

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
	char arr2[] = {'a', 'b', 'c', 'd', 'e'};
	float arr3[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	Test arr4[] = {Test(1), Test(2), Test(3), Test(4), Test(5)};
	
    const int len = 5;

	std::cout << "\033[1;1mArray of int\033[0m" << std::endl;
    std::cout << "Original: ";
    iter(arr1, len, print<int>);
    std::cout << std::endl;
    iter(arr1, len, increment<int>);
    std::cout << "Modified: ";
    iter(arr1, len, print<int>);
    std::cout << std::endl;

	std::cout << "\033[1;1mArray of char\033[0m" << std::endl;
    std::cout << "Original: ";
    iter(arr2, len, print<char>);
    std::cout << std::endl;
    iter(arr2, len, increment<char>);
    std::cout << "Modified: ";
    iter(arr2, len, print<char>);
    std::cout << std::endl;

	std::cout << "\033[1;1mArray of float\033[0m" << std::endl;
    std::cout << "Original: ";
    iter(arr3, len, print<float>);
    std::cout << std::endl;
    iter(arr3, len, increment<float>);
    std::cout << "Modified: ";
    iter(arr3, len, print<float>);
    std::cout << std::endl;

	std::cout << "\033[1;1mArray of Obj\033[0m" << std::endl;
    std::cout << "Original: ";
    iter(arr4, len, print<Test>);
    std::cout << std::endl;
    iter(arr4, len, increment<Test>);
    std::cout << "Modified: ";
    iter(arr4, len, print<Test>);
    std::cout << std::endl;

    return 0;
}