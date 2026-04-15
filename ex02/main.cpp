/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:08:20 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/01 15:08:21 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed c(1.25f);
std::cout << "\n--Increments and decrements testing--\n";
std::cout << "a: " << a << std::endl;
std::cout << "++a: " << ++a << std::endl;
std::cout << "a: " << a << std::endl;
std::cout << "a++: " << a++ << std::endl;
std::cout << "a: " << a << std::endl;
std::cout << "c: " << c << std::endl;
std::cout << "--c: " << --c << std::endl;
std::cout << "c: " << c << std::endl;
std::cout << "c--: " << c-- << std::endl;
std::cout << "c: " << c << std::endl;
std::cout << "\n--Division and min max methods testing--\n";
c++;
c++;
std::cout << "restored c: " << c <<std::endl;
std::cout << "c / 2: " << (c / 2) << std::endl;
std::cout << "max(a,c): " << Fixed::max( a, c ) << std::endl;
std::cout << "min(a,b): " << Fixed::min( a, b ) << std::endl;
return (0);
}
