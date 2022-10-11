/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:55:28 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/11 20:35:51 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	fixed_point_value;
	static const int	number_fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &src);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	Fixed & operator=(const Fixed &f);

	Fixed(int const bitsInt);
	Fixed(float const bitsFloat);
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, const Fixed &f);

#endif
