/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:43:18 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/13 09:55:06 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	// Fixed a;
	// // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const b( Fixed( 0.00f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// // std::cout << ++a << std::endl;
	// // std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;
	
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
