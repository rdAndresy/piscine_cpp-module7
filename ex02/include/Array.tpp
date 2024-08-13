/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelamea <bdelamea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:10:46 by benoit            #+#    #+#             */
/*   Updated: 2024/08/13 10:43:04 by bdelamea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP	
# define ARRAY_TPP	

# include "Array.hpp"

template <typename T>
Array<T>::Array(void): _len(0) {
	try {
		this->_data = new T();
	} catch (const std::bad_alloc & e) {
		std::cerr << "\033[1m\033[31mError, allocation failed: " << e.what() << "\033[0m" << std::endl;
	}
}

template <typename T>
Array<T>::Array(unsigned int n): _len(static_cast<size_t>(n)) {
	if (this->_len == 0) {
		try {
			this->_data = new T();
		} catch (const std::bad_alloc & e) {
			std::cerr << "\033[1m\033[31mError, allocation failed: " << e.what() << "\033[0m" << std::endl;
		}
	} else {
		try {
			this->_data = new T[this->_len](); // Adding the () to initialize the array
		} catch (const std::bad_alloc & e) {
			std::cerr << "\033[1m\033[31mError, allocation failed: " << e.what() << "\033[0m" << std::endl;
			this->_len = 0;
		}
	}
}

template <typename T>
Array<T>::Array(const Array & src): _len(src.size()) {
	if (src.size() == 0) {
		try {
			this->_data = new T();
			this->_data[0] = src._data[0];
		} catch (const std::bad_alloc & e) {
			std::cerr << "\033[1m\033[31mError, allocation failed: " << e.what() << "\033[0m" << std::endl;
			this->_len = 0;
		}
	} else {
		try {
			this->_data = new T[this->_len];
			for (size_t i = 0; i < this->_len; i++)
				this->_data[i] = src._data[i];
		} catch (const std::bad_alloc & e) {
			std::cerr << "\033[1m\033[31mError, allocation failed: " << e.what() << "\033[0m" << std::endl;
			this->_len = 0;
		}
	}
}

template <typename T>
Array<T>::~Array(void) {
	if (this->_len == 0)
		delete this->_data;
	else
		delete [] this->_data;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array & rhs) {
	delete [] this->_data;
	this->_len = rhs.size();
	if (rhs.size() == 0) {
		try {
			this->_data = new T();
		} catch (const std::bad_alloc & e) {
			std::cerr << "\033[1m\033[31mError, allocation failed: " << e.what() << "\033[0m" << std::endl;
			this->_len = 0;
		}
	} else {
		try {
			this->_data = new T[this->_len];
			for (size_t i = 0; i < rhs.size(); i++)
				this->_data[i] = rhs._data[i];
		} catch (const std::bad_alloc & e) {
			std::cerr << "\033[1m\033[31mError, allocation failed: " << e.what() << "\033[0m" << std::endl;
			this->_len = 0;
		}
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int n) const {
	if (this->_len == 0)
		return this->_data[0];
	else if (n >= this->_len)
		throw std::out_of_range("Index out of range");
	else
		return this->_data[n];
}

template <typename T>
size_t Array<T>::size(void) const { return this->_len; }

template <typename T>
std::ostream & operator<<(std::ostream & o, const Array<T> & src) {
	o << "[";
	if (src.size() == 0)
		o << src[0];
	else
		for (size_t i = 0; i < src.size(); i++) {
			o << src[i];
			if (i < src.size() - 1)
				o << ", ";
		}
	o << "]";
	return o;
}

#endif