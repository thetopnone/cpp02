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

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
Point a(0, 0);
Point b(3, 1);
Point c(4, -1);

{
	Point point(1, 0);
	std::cout << "The point " << point << " is: ";
	if (bsp(a,b,c,point) == true){
		std::cout << "Inside" << std::endl;
	}
	else
		std::cout << "Outside" << std::endl;
}
{
	Point point(0, 0);
	std::cout << "The point " << point << " is: ";
	if (bsp(a,b,c,point) == true){
		std::cout << "Inside" << std::endl;
	}
	else
		std::cout << "Outside" << std::endl;
}
{
	Point point(0.5, 2);
	std::cout << "The point " << point << " is: ";
	if (bsp(a,b,c,point) == true){
		std::cout << "Inside" << std::endl;
	}
	else
		std::cout << "Outside" << std::endl;
}
return (0);
}
