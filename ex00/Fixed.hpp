/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:55:28 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/12 10:45:35 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	// ◦ An integer to store the fixed-point number value.
	int	fixed_point_value;
	// ◦ A static constant integer to store the number of fractional bits. Its value
	// will always be the integer literal 8
	static const int	number_fractional_bits = 8;
public:
	// ◦ A default constructor that initializes the fixed-point number value to 0.
	Fixed();
	// ◦ A destructor.
	~Fixed();
	// ◦ A copy constructor.
	Fixed(const Fixed &src);
	// ◦ A member function int getRawBits( void ) const;
	// that returns the raw value of the fixed-point value.
	int		getRawBits( void ) const;
	// ◦ A member function void setRawBits( int const raw );
	// that sets the raw value of the fixed-point number.
	void	setRawBits( int const raw );
	// ◦ A copy assignment operator overload.
	Fixed & operator=(const Fixed &rhs);
};

#endif
