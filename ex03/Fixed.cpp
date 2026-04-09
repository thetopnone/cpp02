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
{}

Fixed::Fixed(const int val)
{
	_value = val << _fractionalBits;
}

Fixed::Fixed(const float val)
{
	_value = static_cast<int>(roundf(val * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
	:_value(0)
{
	this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){}

bool Fixed::operator>(const Fixed& other) const{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const{
	return (!(*this < other));
}

bool Fixed::operator<=(const Fixed& other) const{
	return (!(*this > other));
}

bool Fixed::operator==(const Fixed& other) const{
	return (!(*this > other) && !(*this < other));
}

bool Fixed::operator!=(const Fixed& other) const{
	return (!(*this == other));
}

Fixed Fixed::operator+(const Fixed& other) const{
	Fixed ret;

	ret.setRawBits(this->_value + other._value);
	return (ret);
}

Fixed Fixed::operator-(const Fixed& other) const{
	Fixed ret;
	
	ret.setRawBits(this->_value - other._value);
	return (ret);
}

Fixed Fixed::operator*(const Fixed& other) const{
	Fixed ret;
	int64_t result;

	result = static_cast<int64_t>(this->_value) * static_cast<int64_t>(other._value);
	if (result >= 0)
		result += (1LL << (_fractionalBits - 1));
	else
		result -= + (1LL << (_fractionalBits - 1));
	ret.setRawBits(static_cast<int>(result >> _fractionalBits));
	return (ret);
}

Fixed Fixed::operator/(const Fixed& other) const{
	Fixed ret;
	int64_t result;

	result = (static_cast<int64_t>(this->_value) << _fractionalBits) / other._value;
	if (result >= 0)
		result += (1LL << (_fractionalBits - 1));
	else
		result -= (1LL << (_fractionalBits - 1));
	ret.setRawBits(static_cast<int>(result));
	return (ret);
}

//pre-increment
Fixed &Fixed::operator++(){
	this->_value++;
	return (*this);
}

//post-increment
Fixed Fixed::operator++(int){
	Fixed old(*this);

	++(*this);
	return (old);
}

//pre-decrement
Fixed &Fixed::operator--(){
	this->_value--;
	return (*this);
}

//post-decrement
Fixed Fixed::operator--(int){
	Fixed old(*this);

	--(*this);
	return (old);
}

int	Fixed::getRawBits( void ) const{
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

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a,const Fixed& b){
	Fixed r(a);
	Fixed l(b);

	if (r <= l)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a,const Fixed& b){
	Fixed r(a);
	Fixed l(b);
	
	if (r >= l)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream& out, const Fixed &num){
	return out << num.toFloat();
}

