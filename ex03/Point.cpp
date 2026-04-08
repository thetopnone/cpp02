/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:23:48 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/08 18:23:50 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point( void )
	:x(0)
	,y(0)
{}

Point::Point(float const x, float const y)
	:x(x)
	,y(y)
{}

Point::Point(Point const& other)
	:x(Fixed(other.getX()))
	,y(Fixed(other.getY()))
{}

Point &Point::operator=(Point const& other){
	(void)other;
	return (*this);
}

Point::~Point( void ){}

Fixed const& Point::getX( void ) const{
	return (x);
}

Fixed const& Point::getY( void ) const{
	return (y);
}

std::ostream& operator<<(std::ostream& out, Point const& point){
	return out << '(' << point.getX() << ',' << point.getY() << ')';
}
