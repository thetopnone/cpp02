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

class Fixed{
	private:
		int value;
		static const int f_bits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed& other);
		~Fixed();

		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
};
#endif
