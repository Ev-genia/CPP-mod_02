/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:55:28 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/12 17:09:44 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					fixed_point_value;
	static const int	number_fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &src);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	Fixed & operator=(const Fixed &rhs);

	Fixed(const int bitsInt);
	Fixed(const float bitsFloat);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	int		operator>(const Fixed &rhs) const;
	int		operator<(const Fixed &rhs) const;
	int		operator>=(const Fixed &rhs) const;
	int		operator<=(const Fixed &rhs) const;
	int		operator==(const Fixed &rhs) const;
	int		operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;
	
	Fixed	operator++(int i);//i++
	Fixed	operator--(int i);//i--
	Fixed	&operator++(void);//++i
	Fixed	&operator--(void);//--i

	static 		 Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static 		 Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream & o, const Fixed &rhs);

#endif
