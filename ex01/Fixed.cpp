/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:56:51 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/12 10:52:44 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

Fixed &	Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	int	set;

	set = rhs.getRawBits();
	setRawBits(set);
	return (*this);
}

Fixed::Fixed(int const argInt)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = argInt << this->number_fractional_bits;
}

Fixed::Fixed(float const argFloat)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = (int)roundf(argFloat * (1 << this->number_fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->fixed_point_value >> this->number_fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point_value / (1 << this->number_fractional_bits));
}

std::ostream & operator<<(std::ostream & o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}
