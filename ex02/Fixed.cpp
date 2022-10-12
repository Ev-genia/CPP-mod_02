/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:56:51 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/12 17:41:09 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

Fixed &	Fixed::operator=(const Fixed &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	int	set;

	set = rhs.getRawBits();
	setRawBits(set);
	return (*this);
}

Fixed::Fixed(const int argInt)
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(argInt << this->number_fractional_bits);
}

Fixed::Fixed(const float argFloat)
{
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(argFloat * (1 << this->number_fractional_bits)));
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->number_fractional_bits);
}

float	Fixed::toFloat(void) const
{
	float	f;
	
	f = (float)this->getRawBits() / (1 << this->number_fractional_bits);
	return (f);
}

std::ostream & operator<<(std::ostream & o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}

int		Fixed::operator<(const Fixed &rhs) const
{
	if (this->fixed_point_value < rhs.getRawBits())
		return (1);
	return (0);
}

int		Fixed::operator>(const Fixed &rhs) const
{
	if (this->fixed_point_value > rhs.getRawBits())
		return (1);
	return (0);
}

int		Fixed::operator<=(const Fixed &rhs) const
{
	if (this->fixed_point_value <= rhs.getRawBits())
		return (1);
	return (0);
}

int		Fixed::operator>=(const Fixed &rhs) const
{
	if (this->fixed_point_value >= rhs.getRawBits())
		return (1);
	return (0);
}

int		Fixed::operator==(const Fixed &rhs) const
{
	if (this->fixed_point_value == rhs.getRawBits())
		return (1);
	return (0);
}

int		Fixed::operator!=(const Fixed &rhs) const
{
	if (this->fixed_point_value != rhs.getRawBits())
		return (1);
	return (0);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	// Fixed	fObj;

	// fObj.setRawBits(this->toFloat() + rhs.toFloat());
	Fixed	fObj(this->toFloat() + rhs.toFloat());

	return (fObj);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	// Fixed	fObj;

	// fObj.setRawBits(this->toFloat() - rhs.toFloat());
	Fixed	fObj(this->toFloat() - rhs.toFloat());
	return (fObj);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	// Fixed	fObj;

	// fObj.setRawBits(this->toFloat() * rhs.toFloat());

	Fixed	fObj(this->toFloat() * rhs.toFloat());
	
	return (fObj);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	// Fixed	fObj;

	// fObj.setRawBits(this->getRawBits() / rhs.getRawBits());

	Fixed	fObj(this->getRawBits() / rhs.getRawBits());

	return (fObj);
}

Fixed	Fixed::operator++(int)
{
	Fixed	fObj;

	fObj = *this;
	this->fixed_point_value += 1;
	return (fObj);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fObj;

	fObj = *this;
	this->fixed_point_value -= 1;
	return (fObj);
}

Fixed	&Fixed::operator++(void)
{
	this->fixed_point_value += 1;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
