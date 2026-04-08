/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:24:09 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/08 18:24:11 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const& other);
		Point &operator=(Point const& other);
		~Point();

		Fixed const &getX( void ) const;
		Fixed const &getY( void ) const;
};

std::ostream& operator<<(std::ostream& out, Point const& point);
#endif
