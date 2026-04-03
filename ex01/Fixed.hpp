/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:08:11 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/01 15:08:12 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed{
	private:
		int _value;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed& other);
		~Fixed();

		void	setRawBits( int const raw );
		int		getRawBits( void ) const;

		float	toFloat ( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream& out, const Fixed &num);
#endif
