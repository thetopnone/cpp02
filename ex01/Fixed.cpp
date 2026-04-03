/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:08:03 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/01 15:08:04 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
	:_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	_value = val << _fractionalBits;
}

Fixed::Fixed(const float val){
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(val * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
	:_value(0)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream& out, const Fixed &num){
	return out << num.toFloat();
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw){
	_value = raw;
}

float Fixed::toFloat( void ) const{
	return(static_cast<float>(_value) / (1 << _fractionalBits));
}

int	Fixed::toInt( void ) const{
	return(static_cast<int>(_value) / (1 << _fractionalBits));
}
