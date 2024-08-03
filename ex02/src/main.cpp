/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:28:38 by benoit            #+#    #+#             */
/*   Updated: 2024/08/03 13:42:53 by bdelamea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

Test::Test(): _x(0) {}
Test::Test(int x): _x(x) {}
Test::Test(const Test &src) { this->_x = src._x; }
Test::~Test() {}
int Test::getX() const { return this->_x; }
Test & Test::operator=(const Test &rhs) { this->_x = rhs._x; return *this; }
Test & Test::operator+=(int i) { this->_x += i; return *this; }
std::ostream & operator<<(std::ostream & o, const Test & rhs) { o << rhs.getX(); return (o); }

int main( void ) {
	try {	
		Array<double> arrayDouble;
		Array<char> arrayChar(10);
		Array<int> arrayInt(10);
		Array<std::string> arrayString(10);
		Array<Test> arrayObj(100);
		
		std::cout << "\033[1marrayDouble\033[0m" << std::endl;
		std::cout << "Original:" << std::endl;
		for (size_t i = 0; i < 10; i++)
			arrayDouble[i] =  i;
		std::cout << arrayDouble << std::endl;
		
		std::cout << "\033[1marrayChar\033[0m" << std::endl;
		std::cout << "Original:" << std::endl;
		for (size_t i = 0; i < arrayChar.size(); i++)
			arrayChar[i] = 'a' + i;
		std::cout << arrayChar << std::endl;
		std::cout << "Modified:" << std::endl;
		for (size_t i = 0; i < arrayChar.size(); i++)
			arrayChar[i] += 1;
		std::cout << arrayChar << std::endl;
		
		std::cout << "\033[1marrayString\033[0m" << std::endl;
		std::cout << "Original:" << std::endl;
		for (size_t i = 0; i < arrayString.size(); i++)
			arrayString[i] = "string";
		std::cout << arrayString << std::endl;
		std::cout << "Modified:" << std::endl;
		for (size_t i = 0; i < arrayString.size(); i++)
			arrayString[i] = "#####";
		std::cout << arrayString << std::endl;

		std::cout << "\033[1marrayObj\033[0m" << std::endl;
		for (size_t i = 0; i < arrayObj.size(); i++)
			arrayObj[i] = Test(i);
		std::cout << arrayObj << std::endl;
		
		std::cout << "\033[1marrayInt\033[0m" << std::endl;
		for (size_t i = 0; i < arrayInt.size(); i++)
			arrayInt[i] = i;
		std::cout << arrayInt << std::endl;
		
		std::cout << "\033[1mCopy constructor Array\033[0m" << std::endl;
		Array<int> arrayIntCopy(arrayInt);
		std::cout << arrayIntCopy << std::endl;
		
		std::cout << "\033[1mAssignation operator Array\033[0m" << std::endl;
		Array<int> arrayIntAssign = arrayInt;
		std::cout << arrayIntAssign << std::endl;
		
	} catch (std::exception &e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return 0;
}