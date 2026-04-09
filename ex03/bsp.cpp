/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:23:43 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/08 18:23:44 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point pointVector(Point const& start, Point const& end){
	Fixed	newX = end.getX() - start.getX();
	Fixed	newY = end.getY() - start.getY();

	Point	v(newX.toFloat(), newY.toFloat());
	return (v);
}

//Matrix Form : v1.x v1.y
//				v2.x v2.y
Fixed	determinant(Point const& v1, Point const& v2){
	Fixed n(v1.getX().toFloat() * v2.getY().toFloat() - v1.getY().toFloat() * v2.getX().toFloat());
	return (n);
}

int	verifyTriangle(Point const a, Point const b, Point const c){
	Fixed	d1 = determinant(b,c);
	Fixed	d2 = determinant(a,c);
	Fixed	d3 = determinant(a,b);

	if ((d1 - d2 + d3) == Fixed(0))
		return (0);
	return (1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Point	_ab = pointVector(a,b);
	Point	_bc = pointVector(b,c);
	Point	_ca = pointVector(c,a);

	Point	_ap = pointVector(a,point);
	Point	_bp = pointVector(b,point);
	Point	_cp = pointVector(c,point);

	Fixed	d1 = determinant(_ap,_ab);
	Fixed	d2 = determinant(_bp, _bc);
	Fixed	d3 = determinant(_cp,_ca);

	if ((d1 * d2 * d3) == Fixed(0))
		return (true);
	return (!((d1 < 0 || d2 < 0 || d3 < 0) && (d1 > 0 || d2 > 0 || d3 > 0)));
}
